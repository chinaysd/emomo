#include	"h\SC91F831_C.h"
#include	"lib\SensorMethod.h"	   //包含touchkey外部调用接口函数
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


//该状态已经由下位机控制，上位机只需把所有该发的信号位都发过去就可以，目的是脚灯由下位机控制，不能跟随背光灯的状态
//bool isBackLightOn = FALSE; 
//标记背光灯（双色灯蓝灯）亮，如果背光灯和制冷灯（双色灯绿灯）同时亮，以制冷灯为最高优先，即双色灯只亮绿灯，蓝灯熄灭，当关闭制冷时，再根据这个标记来恢复背光灯的状态


/*
 * 打开Light(脚灯)
 * 第3bit用1表示
 * 只在带双色灯的HX25系列中生效
 */
void turnOnBackLight(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000001);//0X01
}
/*
 * 关闭 打开Light(脚灯)
 * 第3bit用0表示
 * 只在带双色灯的HX25系列中生效
 */
void turnOffBackLight(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000010);//0X02
}
/*
 * 打开B灯，绿灯（制冷指示灯）
 * 第4bit用1表示
 * 只在带双色灯的HX25系列中生效
 */
void turnOnColdLight(void) 
{
    command = (INT8U) ((command & _b00000000) | _b00000100);//0X04
}
/*
 * 关闭B灯，绿灯（制冷指示灯）
 * 第4bit用0表示
 * 只在带双色灯的HX25系列中生效
 */
void turnOffColdLight(void) 
{
    command = (INT8U) ((command & _b00000000) | _b00001000);//0x08
}

/*
 * 推杆A升高
 * 高三位用001表示
 * 只在带双色灯的HX25系列中生效
 */
void pushrodApushHigh(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00010000);//0X10
}
/*
 * 推杆A降低
 * 高三位用010表示
 */
void pushrodApushLow(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00100000);//0X20
}
/*
 * 推杆A动作完成
 * 高三位用000表示
 */
void pushrodAFinish(void) 
{
	command = (INT8U) ((command & _b00000000) | _b01000000);//0x40
}
/*
 * 推杆B升高
 * 高三位用101表示
 */
void pushrodBpushHigh(void)
{
	command = (INT8U) ((command & _b00000000) | _b10000000);//0X80
}
/*
 * 推杆B降低
 * 高三位用110表示
 */
void pushrodBpushLow(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000000);//0x00
}
/*
 * 推杆B动作完成
 * 高三位用000表示
 */
void pushrodBFinish(void) 
{
	command = (INT8U) ((command & _b00000000) | _b00000000);
}
/*
 * 马达震动
 * 第2bit用1表示
 */
void turnOnMassage(void) 
{
	command = (INT8U) ((command & _b11111011) | _b00000100);
	//isMassaging = true;
	//u16Cnt15Minutes = 0x0;
}
/*
 * 马达关闭
 * 第2bit用0表示
 */
void turnOffMassage(void) 
{
	command = (INT8U) ((command & _b11111011) | _b00000000);
	//isMassaging = false;
}
/*
 * 打开制冷
 * 第1bit用1表示
 */
void turnOnCold(void) 
{
	command = (INT8U) ((command & _b11110101) | _b00000010);
	//isColding = true;
	//u16Cnt4hours = 0x0;
}
/*
 * 关闭制冷
 * 第1bit用0表示
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
 *使所有的触摸按键失效
 *在用户按上总开关的时候，这个方法被调用
 */
void disableAllTouchKey(void) 
{
	keyStates[KEY_LOCKER] = (INT8U) ~keyStates[KEY_LOCKER];
	LED_SWITCH_ON;
	TouchKey_Flag = disable; 
	Key_Buf = 0x0000;
}
/*
 *使所有的触摸按键有效
 *在用户按上总开关的时候，这个方法被调用
 */
void enableAllTouchKey(void)
{
	keyStates[KEY_LOCKER] = (INT8U) ~keyStates[KEY_LOCKER];
	LED_SWITCH_OFF;
	TouchKey_Flag = enable; 
}


/*
 * 关闭机器
 * 所有数据全部重新初始化
 */
void shutDown(void)
{
	disableAllTouchKey();//关闭触摸按键
	command = (INT8U) 0x0;//清除命令,关闭所有东西
	pushrodAFinish();//0x40

	isMassaging = false;//清掉马达震动标记
	isColding = false;//清掉制冷标记

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

	//第四套程序和第五套程序Cool的工作状态用Light的指示灯用来指示，关闭Cool时，Light的指示灯也关闭
	//
	if ((PROGRAM_D_HX36_WITH_A_PUSHROD == u8LoadProgram)|| (PROGRAM_E_HX36_WITH_TOW_PUSHROD == u8LoadProgram)) 
	{
		LED_LIGHT_OFF;
	}

	//第三套程序Cool的工作状态用Cool的指示灯指示，关闭Cool时，Cool的指示灯也关闭
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
	{//如果50次按键判断都一样，证明有按键动作

		if (!keyStates[KEY_LOCKER]) 
		{
			disableAllTouchKey();//让所有触摸按键失效
		} 
		else 
		{
			enableAllTouchKey();//让所有触摸按键有效
		}

		u8KeyValueTemp = 0x0;
		compareTimes = 0x0;

		bProcessKey = false;
		bHasResult = true;
	}
}
