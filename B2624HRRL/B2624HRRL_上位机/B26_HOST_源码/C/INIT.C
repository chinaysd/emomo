#include "h/INIT.H"
#include "h\UART.h"
#include "H/SC93F833X_C.H"
unsigned char count_250us_time,count_level;
unsigned char lock = 1;
unsigned int count_1ms_time;
extern unsigned int motro_count0,motro_count1,auto_close_heat_cnt,auto_close_mass_cnt;
extern unsigned char up_flag,down_flag,auto_close_heat,auto_close_mass;
extern unsigned int u16TimeLock;
extern unsigned char RED_LIGHT,Flag;
extern unsigned long MyKey_Buf_Data;
extern void UART_TX_byte(unsigned char DATA);
void GPIO_INIT(void)
{
  P0CON |= 7 << 0;			   //设置P00,P01,P02为强推挽IO
//  P0PH  = 0x00;
  P2CON |= 1 << 5;		       //设置P25为强推挽IO
//  P2PH  = 0x00;

  IO_LED_FOOT_LIGHT_OFF;	     //脚灯关闭
  IO_RED_LIGHT_OFF;           //红灯关闭
  IO_MOTOR_ONE_OFF;			 //升降马达1关闭
  IO_MOTOR_TWO_OFF;			 //升降马达2关闭
}

void Timer0_Init(void)
{ 
	//TMCON = 0X07;    //------111 ;Timer0、Tiemr1和Tiemr2选择时钟Fsys
	//T0设置
	//TMOD = 0x44;     //0001 0001  ;Timer0和Timer1设置工作方式1
	TL0 = (65536 - 605)%256;    //溢出时间：时钟为Fsys，则6000*（1/Fsys）=250us;
	TH0 = (65536 - 605)/256;
	TR0 = 0;
	ET0 = 1;//定时器0允许
	TR0 = 1;//打开定时器0
	//T2设置
	T2MOD=0x00;
	T2CON=0x00;	 //设置为16位重载寄存器
	RCAP2H=(65536-1000)/256;     //溢出时间：时钟为Fsys，则12000*（1/Fsys）=0.5ms;
	RCAP2L=(65536-1000)%256;
	TR2 = 0;
	ET2 = 1;//定时器2允许
	TR2 = 1;//打开定时器2	
}

void TIMER1_INIT(void)
{
  	//TMCON = 0X07;    //------111 ;Timer0、Tiemr1和Tiemr2选择时钟Fsys
    //T1设置
	//TMOD = 0x44;
	TL1 = (65536 - 6060)%256;   //溢出时间：时钟为Fsys，则24000*（1/Fsys）=1ms;
	TH1 = (65536 - 6060)/256;
	TR1 = 0;
	ET1 = 1;//定时器1允许
	TR1 = 1;//打开定时器1
    
}

void timer1() interrupt 3
{
    TL1 = (65536 - 6060)%256;
	TH1 = (65536 - 6060)/256;
	//P01 = ~P01;
//	IO_LED_FOOT_LIGHT_PIN =~ IO_LED_FOOT_LIGHT_PIN;
	

}



void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零
//    P02=~P02;
//    P25 = ~P25;
}


