#include	"h\SC91F831_C.h"
#include	"lib\SensorMethod.h"	   //包含touchkey外部调用接口函数
#include	"config.h"
#include	"init.h"
#include    "intrins.h"

void GPIO_init()
{
	IO_SENDER_MODE;
	IO_SWITCH_MODE;
	IO_SWITCH_LIGHT_MODE;
	IO_LED_LIGHT_MODE;
	IO_LED_PUSHRODA_H_MODE;
	IO_LED_PUSHRODA_L_MODE;
	IO_LED_MASSAGE_MODE;
	IO_LED_COLD_MODE;

	SENDER_WRITE_1;
	LED_SWITCH_OFF;
	LED_LIGHT_OFF;
	LED_PUSHRODA_H_OFF;
	LED_PUSHRODA_L_OFF;
	LED_MASSAGE_OFF;
	LED_COLD_OFF;
}

void Time1_init()
{
   TMOD|=0x10;				//16位定时Timer1
   TMCON|=0x02;				//10--Fosc/4;00--Fosc/12	
   TH1=(65535-1000)/256;    //Fosc/4;1000= 1/4M*1000=0.25ms;
   TL1=(65535-1000)%256;
   TR1=0;					//定时器T1的运行控制位。打开timer1前，先清TR1
   ET1=1;
   TR1=1;
}

