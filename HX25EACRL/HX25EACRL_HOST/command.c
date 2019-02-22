#include	"h\SC91F831_C.h"
#include	"lib\SensorMethod.h"	   //����touchkey�ⲿ���ýӿں���
#include	"config.h"
#include	"init.h"
#include    "intrins.h"
#include	"hex2bin.h"
#include	"command.h"
#include	"key.h"


INT8U   command = 0x0;
bit     switchState = 1;

bit     isColding = false;
bit     isMassaging = false;
INT16U  u16Cnt15Minutes = 0x0;
INT16U  u16Cnt4hours = 0x0;

INT8U   u8KeyValueTemp;
INT8U   compareTimes = 0;
INT8U   u8ProcessKeyCnt = 0;
bit     bProcessKey = false;
bit     bHasResult = false;

bit     processSender = false;
INT8U   index = 8;
INT8U   u8Send0Cnt, u8Send1Cnt, u8SendHeaderCnt, u8SendEnderCnt, u8SenderCnt;

extern unsigned int Cnt;
extern unsigned char Temp_Cnt;


//��״̬�Ѿ�����λ�����ƣ���λ��ֻ������и÷����ź�λ������ȥ�Ϳ��ԣ�Ŀ���ǽŵ�����λ�����ƣ����ܸ��汳��Ƶ�״̬
//bool isBackLightOn = FALSE; 
//��Ǳ���ƣ�˫ɫ�����ƣ������������ƺ�����ƣ�˫ɫ���̵ƣ�ͬʱ�����������Ϊ������ȣ���˫ɫ��ֻ���̵ƣ�����Ϩ�𣬵��ر�����ʱ���ٸ������������ָ�����Ƶ�״̬


/*
 * ��Light(�ŵ�)
 * ��3bit��1��ʾ
 * ֻ�ڴ�˫ɫ�Ƶ�HX25ϵ������Ч
 */
void turnOnBackLight(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000001);//0X01
}
/*
 * �ر� ��Light(�ŵ�)
 * ��3bit��0��ʾ
 * ֻ�ڴ�˫ɫ�Ƶ�HX25ϵ������Ч
 */
void turnOffBackLight(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000010);//0X02
}
/*
 * ��B�ƣ��̵ƣ�����ָʾ�ƣ�
 * ��4bit��1��ʾ
 * ֻ�ڴ�˫ɫ�Ƶ�HX25ϵ������Ч
 */
void turnOnColdLight(void) 
{
    command = (INT8U) ((command & _b00000000) | _b00000100);//0X04
}
/*
 * �ر�B�ƣ��̵ƣ�����ָʾ�ƣ�
 * ��4bit��0��ʾ
 * ֻ�ڴ�˫ɫ�Ƶ�HX25ϵ������Ч
 */
void turnOffColdLight(void) 
{
    command = (INT8U) ((command & _b00000000) | _b00001000);//0x08
}

/*
 * �Ƹ�A����
 * ����λ��001��ʾ
 * ֻ�ڴ�˫ɫ�Ƶ�HX25ϵ������Ч
 */
void pushrodApushHigh(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00010000);//0X10
}
/*
 * �Ƹ�A����
 * ����λ��010��ʾ
 */
void pushrodApushLow(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00100000);//0X20
}
/*
 * �Ƹ�A�������
 * ����λ��000��ʾ
 */
void pushrodAFinish(void) 
{
	command = (INT8U) ((command & _b00000000) | _b01000000);//0x40
}
/*
 * �Ƹ�B����
 * ����λ��101��ʾ
 */
void pushrodBpushHigh(void)
{
	command = (INT8U) ((command & _b00000000) | _b10000000);//0X80
}
/*
 * �Ƹ�B����
 * ����λ��110��ʾ
 */
void pushrodBpushLow(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000000);//0x00
}
/*
 * �Ƹ�B�������
 * ����λ��000��ʾ
 */
void pushrodBFinish(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000000);
}
/*
 * �����
 * ��2bit��1��ʾ
 */
void turnOnMassage(void) 
{
	command = (INT8U) ((command & _b11111011) | _b00000100);
	//isMassaging = true;
	//u16Cnt15Minutes = 0x0;
}
/*
 * ���ر�
 * ��2bit��0��ʾ
 */
void turnOffMassage(void) 
{
	command = (INT8U) ((command & _b11111011) | _b00000000);
	//isMassaging = false;
}
/*
 * ������
 * ��1bit��1��ʾ
 */
void turnOnCold(void) 
{
	command = (INT8U) ((command & _b11110101) | _b00000010);
	//isColding = true;
	//u16Cnt4hours = 0x0;
}
/*
 * �ر�����
 * ��1bit��0��ʾ
 */
void turnOffCold(void) 
{
	command = (INT8U) ((command & _b11111101) | _b00000000);
	//isColding = false;
}

void TurnOffCold_FootLight_CupLight(void)
{
    command = (INT8U) ((command & _b00000000) | _b00010000);
}
/*
 *ʹ���еĴ�������ʧЧ
 *���û������ܿ��ص�ʱ���������������
 */
void disableAllTouchKey(void) 
{
	keyStates[KEY_LOCKER] = (INT8U) ~keyStates[KEY_LOCKER];
	LED_SWITCH_ON;
	TouchKey_Flag = disable; 
	Key_Buf = 0x0000;
}
/*
 *ʹ���еĴ���������Ч
 *���û������ܿ��ص�ʱ���������������
 */
void enableAllTouchKey(void)
{
	keyStates[KEY_LOCKER] = (INT8U) ~keyStates[KEY_LOCKER];
	LED_SWITCH_OFF;
	TouchKey_Flag = enable; 
}


/*
 * �رջ���
 * ��������ȫ�����³�ʼ��
 */
void shutDown(void)
{
	disableAllTouchKey();//�رմ�������
	command = (INT8U) 0x0;//�������,�ر����ж���
	pushrodAFinish();//0x40

	isMassaging = false;//�������𶯱��
	isColding = false;//���������

    u8SenderCnt = 0;
	u8Send1Cnt = 0;
	u8Send0Cnt = 0;
		
	SENDER_WRITE_1;
    index = 8;
	processSender = false;
	u8SendHeaderCnt = 0;
    u8SendEnderCnt = 0;
    Cnt=0x00;
    Temp_Cnt = 0;

	keyStates[KEY_LIGHT] =0;
	keyStates[KEY_MASSAGE]=0;
	keyStates[KEY_COLD]=0;
	keyStates[KEY_LOCKER]=_b11111111;

	//�����׳���͵����׳���Cool�Ĺ���״̬��Light��ָʾ������ָʾ���ر�Coolʱ��Light��ָʾ��Ҳ�ر�
	//
	if ((PROGRAM_D_HX36_WITH_A_PUSHROD == u8LoadProgram)|| (PROGRAM_E_HX36_WITH_TOW_PUSHROD == u8LoadProgram)) 
	{
		LED_LIGHT_OFF;
	}

	//�����׳���Cool�Ĺ���״̬��Cool��ָʾ��ָʾ���ر�Coolʱ��Cool��ָʾ��Ҳ�ر�
	if (PROGRAM_C_HX36_WITH_A_PUSHROD == u8LoadProgram)
	{
		LED_COLD_OFF;
	}
}

void compareKeyValue(INT8U value) 	//K1 ------ P4.0
{
	if (!(value & _b00000001) == u8KeyValueTemp) 	 
	{
		compareTimes++;
	} 
	else 
	{
		compareTimes = 0x0;
	}
	u8KeyValueTemp = (INT8U)(!(value & _b00000001));

	if ((KEY_COMPARE_TIME == compareTimes)) 
	{//���50�ΰ����ж϶�һ����֤���а�������

		if (!keyStates[KEY_LOCKER]) 
		{
			disableAllTouchKey();//�����д�������ʧЧ
		} 
		else 
		{
			enableAllTouchKey();//�����д���������Ч
		}

		u8KeyValueTemp = 0x0;
		compareTimes = 0x0;

		bProcessKey = false;
		bHasResult = true;
	}
}
