#include	"h\SC91F831_C.h"
#include	"lib\SensorMethod.h"	   //����touchkey�ⲿ���ýӿں���
#include	"config.h"
#include	"key.h"
#include    "intrins.h"
#include	"init.h"
#include	"hex2bin.h"
#include	"command.h"

//*****************************************************************
//#include    "sif\Sif_bus.h"        //�����ļ���ԭ���ṩ ���������ȡ��(SIFͨѶ�ɼ�����)
//*****************************************************************	     

INT8U  Timer5msCnt;					   //5ms����
bit    btimer5ms;					   //5ms��־

extern INT8U key_press_flag,key_cnt_flag;
extern INT16U key_cnt;
extern INT8U heat_switch;
extern INT16U heat_switch_cnt;
extern INT8U heat_cnt;


INT8U   commandTmp;
INT16U  u16Cnt1S;

unsigned int Key_Buf;				   //����TouchKeyScan()�ķ���ֵ

void main()
{
	RSTCFG|=0x20;					   		//����P10�ĸ�λ����Ϊ��ͨIO����
	WDTCR = 0x90;			             	//1--1 -- 00    ��WDT,WDT��0,WDT 262ms���;��¼ʱ����Code Optionѡ��ENWDT
	EA=1;							   		//���жϴ�
	GPIO_init();
	TouchKeyInit();							//����������ʼ�� 
	Time1_init();							//0.25ms��ʱ
    
	 LED_SWITCH_OFF;
     //LED_SWITCH_ON;
     LED_LIGHT_ON;
	 LED_PUSHRODA_L_ON;
	 LED_PUSHRODA_H_ON;
	 LED_MASSAGE_ON;
     LED_COLD_ON;					

	 while(1)
	 { 	
		//Debug_SenddataRestart();          //����������Ҫ�õ��ĺ��������������ȡ��(SIFͨѶ�ɼ�����)

		if(SOCAPI_TouchKeyStatus&0x80)		// Bit7��һ�ְ���ɨ���Ƿ����
		{
		   WDTCR = 0x90;				    //1--1 -- 00    ��WDT,WDT��0,WDT 262ms���;��¼ʱ����Code Optionѡ��ENWDT
		   WDTCR |= 0x10;					//�忴�Ź���Code Optionѡ��ENWDT
		   SOCAPI_TouchKeyStatus&=0x7f;	    //��� Bit7��һ��ɨ����ɱ�־
		   Key_Buf=TouchKeyScan();			//�����㷨����󣬶�ȡ��ֵ	
		   TouchKeyRestart();			    //������һ��ɨ��
		}
							
		if(btimer5ms)						// ÿ5msȡһ��Key_Buf����
		{
		   btimer5ms=0;	

		   if(TouchKey_Flag == disable)	    //��������ʧЧ
		   {
		   	  Key_Buf = 0x0000;
		   }	  		    
		   Keyfunction();					// Key_Buf����
		}
	 }				
}

void Timer1()  interrupt	3	//0.25ms�ж�
{
	TH1=(65535-1000)/256;
	TL1=(65535-1000)%256;		   //�ٴ�װ���ֵ

    if(key_cnt_flag){
		key_cnt ++;
	}
	if(++Timer5msCnt>=20)		   //5ms������
	{
	   Timer5msCnt=0;
	   btimer5ms=1;				   //ÿ5ms��1��
	}

	++u16Cnt1S;
	if (4000 == u16Cnt1S) 
	{//1S������ʱ��
		u16Cnt1S = 0x0;
		if(heat_switch == 1)//��ʱ30min�Զ��رշ��Ȳ�
		{
		   heat_switch_cnt++;
		   if(heat_switch_cnt == 1800)//1800
		   {
		      heat_switch_cnt = 0;
			  heat_switch = 0;
			  heat_cnt = 0;
			  turnOnColdLight();//0x01
		   }
		}

		if(Start_Counttime_A == enable)
		{
			if(++Start_Counttime_Cnt > PRESS_PUSHROD_TIMEOUT)
			{
			    Start_Counttime_A = disable;
				Start_Counttime_Cnt =0;
			    pushrodAFinish();			
			}		
		}

		if(Start_Counttime_B == enable)
		{
			if(++Start_Counttime_Cnt > PRESS_PUSHROD_TIMEOUT)
			{
			    Start_Counttime_B = disable;
				Start_Counttime_Cnt =0;
			    pushrodBFinish();			
			}		
		}

		if (isMassaging && (command & 0x4)) 
		{//��������������15���ӣ��Զ��ر����
			++u16Cnt15Minutes;
			if (900 == u16Cnt15Minutes) 
			{//15���Ӽ�ʱ��         15 * 60 = 900s
				turnOffMassage();
			}
		}

		if (isColding) 
		{//�����������4Сʱ���Զ��رջ���
			++u16Cnt4hours;
			if (14400 == u16Cnt4hours)
			{//4Сʱ��ʱ��               4 * 60 * 60 = 14400s
				shutDown();
			}
		}
	}

	if (P4 & _b00000001) 
	{
		bHasResult = false;
	}
	++u8ProcessKeyCnt;
	if (20 == u8ProcessKeyCnt) 
	{
		u8ProcessKeyCnt = 0;
		if (!(P4 & _b00000001) && !bHasResult) 
		{//�а������£����һ�û��ͨ��ȥ��������
			bProcessKey = true;
		}
		if (bProcessKey) 
		{
			compareKeyValue(P4);
		}
	}

	u8SenderCnt++;

	if (200 == u8SenderCnt) 
	{//ÿ50ms֮�ڷ���һ������ ���� ������������ʱ�� + ���ͼ�� = 50
		u8SenderCnt = 0;
		processSender = true;
		commandTmp = command;
	}
	if (processSender) 
	{

		//������Ϣͷ
		u8SendHeaderCnt++;
		if (u8SendHeaderCnt < 20) 	 //���19*0.25=4.75ms�͵�ƽ
		{
			SENDER_WRITE_0;
		} 
		else 
		{
			if (index > 0) 
			{
				if (commandTmp & 0x80) 
				{//�������1
					u8Send1Cnt++;
					if (u8Send1Cnt < 9) 
					{
						SENDER_WRITE_1;   //���8*0.25=2ms�ߵ�ƽ
					}
					else
					{
						if (u8Send1Cnt < 10)   //���2*0.25=0.5ms�͵�ƽ
						{
							SENDER_WRITE_0;
						} 
						else
						{//�������1�������
							u8Send1Cnt = 0;
							commandTmp <<= 1;
							index--;
						}
					}
				}
				else
				{ //�������0
					u8Send0Cnt++;
					if (u8Send0Cnt < 5) 
					{//�����1ms�ĸߵ�ƽ
						SENDER_WRITE_1;
					} 
					else
					{
						if (u8Send0Cnt < 10)  //���4*0.25=1ms�ߵ�ƽ
						{
							SENDER_WRITE_0;
						} 
						else 
						{ //�������0�������
							u8Send0Cnt = 0;
							u8Send0Cnt = 0;
							commandTmp <<= 1;
							index--;
						}
					}
				}
			} 
			else 
			{//������ɣ���ʼ�����Ϣ������
				u8SendEnderCnt++;
				SENDER_WRITE_0;//����͵�ƽ
				if (24 == u8SendEnderCnt)	   //���23*0.25=5.75ms�͵�ƽ�󣬽�������ߵ�ƽ��һ��byte�����������
				{
					SENDER_WRITE_1;
					index = 8;
					processSender = false;
					u8SendHeaderCnt = 0;
					u8SendEnderCnt = 0;
				}
			}
		}
	}

	return;
}





