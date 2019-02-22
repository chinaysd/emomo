#include	"h\SC91F831_C.h"
#include	"lib\SensorMethod.h"	   //包含touchkey外部调用接口函数
#include	"config.h"
#include	"key.h"
#include    "intrins.h"
#include	"init.h"
#include	"hex2bin.h"
#include	"command.h"

//*****************************************************************
//#include    "sif\Sif_bus.h"        //调试文件，原厂提供 量产后可以取消(SIF通讯采集数据)
//*****************************************************************	     

INT8U  Timer5msCnt;					   //5ms计数
bit    btimer5ms;					   //5ms标志

extern INT8U key_press_flag,key_cnt_flag;
extern INT16U key_cnt;
extern INT8U heat_switch;
extern INT16U heat_switch_cnt;
extern INT8U heat_cnt;


INT8U   commandTmp;
INT16U  u16Cnt1S;

unsigned int Key_Buf;				   //保存TouchKeyScan()的返回值

void main()
{
	RSTCFG|=0x20;					   		//设置P10的复位功能为普通IO功能
	WDTCR = 0x90;			             	//1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
	EA=1;							   		//总中断打开
	GPIO_init();
	TouchKeyInit();							//触摸按键初始化 
	Time1_init();							//0.25ms定时
    
	 LED_SWITCH_OFF;
     //LED_SWITCH_ON;
     LED_LIGHT_ON;
	 LED_PUSHRODA_L_ON;
	 LED_PUSHRODA_H_ON;
	 LED_MASSAGE_ON;
     LED_COLD_ON;					

	 while(1)
	 { 	
		//Debug_SenddataRestart();          //调试数据需要用到的函数，量产后可以取消(SIF通讯采集数据)

		if(SOCAPI_TouchKeyStatus&0x80)		// Bit7：一轮按键扫描是否完成
		{
		   WDTCR = 0x90;				    //1--1 -- 00    开WDT,WDT清0,WDT 262ms溢出;烧录时，可Code Option选择ENWDT
		   WDTCR |= 0x10;					//清看门狗，Code Option选择ENWDT
		   SOCAPI_TouchKeyStatus&=0x7f;	    //清掉 Bit7：一轮扫描完成标志
		   Key_Buf=TouchKeyScan();			//数据算法处理后，读取键值	
		   TouchKeyRestart();			    //启动下一轮扫描
		}
							
		if(btimer5ms)						// 每5ms取一次Key_Buf处理
		{
		   btimer5ms=0;	

		   if(TouchKey_Flag == disable)	    //触摸按键失效
		   {
		   	  Key_Buf = 0x0000;
		   }	  		    
		   Keyfunction();					// Key_Buf处理
		}
	 }				
}

void Timer1()  interrupt	3	//0.25ms中断
{
	TH1=(65535-1000)/256;
	TL1=(65535-1000)%256;		   //再次装入初值

    if(key_cnt_flag){
		key_cnt ++;
	}
	if(++Timer5msCnt>=20)		   //5ms计数；
	{
	   Timer5msCnt=0;
	   btimer5ms=1;				   //每5ms置1；
	}

	++u16Cnt1S;
	if (4000 == u16Cnt1S) 
	{//1S基础计时器
		u16Cnt1S = 0x0;
		if(heat_switch == 1)//定时30min自动关闭发热布
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
		{//如果马达连续震动了15分钟，自动关闭马达
			++u16Cnt15Minutes;
			if (900 == u16Cnt15Minutes) 
			{//15分钟计时器         15 * 60 = 900s
				turnOffMassage();
			}
		}

		if (isColding) 
		{//如果连续制冷4小时，自动关闭机器
			++u16Cnt4hours;
			if (14400 == u16Cnt4hours)
			{//4小时计时器               4 * 60 * 60 = 14400s
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
		{//有按键按下，并且还没有通过去抖动处理
			bProcessKey = true;
		}
		if (bProcessKey) 
		{
			compareKeyValue(P4);
		}
	}

	u8SenderCnt++;

	if (200 == u8SenderCnt) 
	{//每50ms之内发送一次数据 ，即 发送数据所需时间 + 发送间隔 = 50
		u8SenderCnt = 0;
		processSender = true;
		commandTmp = command;
	}
	if (processSender) 
	{

		//发送信息头
		u8SendHeaderCnt++;
		if (u8SendHeaderCnt < 20) 	 //输出19*0.25=4.75ms低电平
		{
			SENDER_WRITE_0;
		} 
		else 
		{
			if (index > 0) 
			{
				if (commandTmp & 0x80) 
				{//输出数据1
					u8Send1Cnt++;
					if (u8Send1Cnt < 9) 
					{
						SENDER_WRITE_1;   //输出8*0.25=2ms高电平
					}
					else
					{
						if (u8Send1Cnt < 10)   //输出2*0.25=0.5ms低电平
						{
							SENDER_WRITE_0;
						} 
						else
						{//输出数据1操作完成
							u8Send1Cnt = 0;
							commandTmp <<= 1;
							index--;
						}
					}
				}
				else
				{ //输出数据0
					u8Send0Cnt++;
					if (u8Send0Cnt < 5) 
					{//输出了1ms的高电平
						SENDER_WRITE_1;
					} 
					else
					{
						if (u8Send0Cnt < 10)  //输出4*0.25=1ms高电平
						{
							SENDER_WRITE_0;
						} 
						else 
						{ //输出数据0操作完成
							u8Send0Cnt = 0;
							u8Send0Cnt = 0;
							commandTmp <<= 1;
							index--;
						}
					}
				}
			} 
			else 
			{//送数完成，开始输出信息结束符
				u8SendEnderCnt++;
				SENDER_WRITE_0;//输出低电平
				if (24 == u8SendEnderCnt)	   //输出23*0.25=5.75ms低电平后，接着输出高电平，一个byte的数发送完毕
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





