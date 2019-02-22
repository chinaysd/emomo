#include "system.h"

/*************************************************************
说明：
1、Options for Target‘Target1’：BL51 Locate->Code Range:0x100，烧录选项请选择DISRST，复位脚作为普通IO使用；
2、改变TEST的定义，可以分别测试对应的功能；
***************************************************************/

#define  Receive_IO_Data             P12

extern unsigned char LED_SWITCH_OPEN_FLAG,LED_SWITCH_CLOSE_FLAG;
extern unsigned int  u8cnt2s_open,u8cnt2s_close;
unsigned char LED_FLAG;
TIMEOUT_PARA Shake_Time[2];

extern unsigned char Cnt200ms;
unsigned int Cnt800ms;

extern unsigned int AdcValue;

unsigned char u8cnt50ms,u8CntMs;//50ms计时

unsigned char Start_Receive_Data ;//开始接收数据
unsigned char Value,STAT,R_Data;
unsigned char High_Leve_Time,Low_Leve_Time;//高电平时间
unsigned char Total_Data=8;    //总数据长度
unsigned int u16Cnt4hours;
unsigned char  u8shuttime;
unsigned char  u8Data_time;//接收数据的时间，如果0.5S之内没有收到数据，将发热片关闭
unsigned char Flag;
unsigned char Data;			   			  			   

/*************************************************************
说明：
TEST==TEST_TIMER
1、定时器为向上溢出方式，T定时计算公式=Tx时钟源*（满量程值+1-预装载值）
***************************************************************/

void timer1()interrupt 3				//Timer1向量号 3
{
	TH1 = (65536 - 3000)/256;		    //再次装入初值
   	TL1 = (65536 - 3000)%256;			//0.25ms进来一次

	if(Cnt800ms++ > 800)                //200ms进来一次
	{
	   Cnt800ms = 0;
	   Cnt200ms++;
	}

	R_Data=Receive_IO_Data;
    if((R_Data==0)&&(Start_Receive_Data==0))  //引导码低电平的时间
    {
	   ++u8cnt50ms;
    }
	if(R_Data==1)          //电平为高时判断低电平的时间
	{
	 	if((15<=u8cnt50ms)&&(22>=u8cnt50ms))    //时间范围在引导低电平的范围内，开始接收
		{
			Low_Leve_Time=0;
			u8cnt50ms=0;
			High_Leve_Time=0;
			Value=0;
			Total_Data=8;
	        Start_Receive_Data=1;
	     }
	     else if(22<=u8cnt50ms)     //大于 否则不接收
	     {
		 	Low_Leve_Time=0;
			u8cnt50ms=0;
			High_Leve_Time=0;
			Value=0;
			Total_Data=8;
	        Start_Receive_Data=0;
	     }
	     else                       //否则清除计数
	     {
	        u8cnt50ms=0;
	     }	    
	}

	if(Start_Receive_Data)   //开始接收数据
	{
	    if(Total_Data>0)    //接收八次
	    { 
			  if(R_Data==1)       //高电平的时间
			  {
				  Flag=1;            //低电平时判断标志
		          High_Leve_Time++;   //高电平时间计数
			  }
		      if((R_Data==0)&&(Flag==1))  //低电平时判断高电平时间，flag标志位只进入一次，																	//只有在下次翻转的时候才能进入判断
			  { 
				  Value=Value<<1;             //数据首先左移，八位数据只需移位七次
				  Flag=0;                    //清标志
			      Low_Leve_Time++;            //低电平时间计数
			      if((High_Leve_Time>=7)&&(High_Leve_Time<=10))  //判断码为1
		          {
						 Low_Leve_Time=0;
						 High_Leve_Time=0;
						 Value |= 0x01;
						 Total_Data--;
	              }
		          else if((High_Leve_Time>=1)&&(High_Leve_Time<=6))  //判断码为0
	              {
						 Low_Leve_Time=0;
						 High_Leve_Time=0;
						 Value &= (~0x01);
						 Total_Data--;
				  }
		      } 
			  if((High_Leve_Time>16)||(Low_Leve_Time>8))      //容错处理，在接收完数据后会进入
		      {
				  Low_Leve_Time=0;
				  High_Leve_Time=0;
				  u8cnt50ms=0;
		          Start_Receive_Data=0;
				  Value=0;
				  Total_Data=8;
			  }
		  }
     else   //接收完成，清除相关数据
     {
		  Low_Leve_Time=0;
		  High_Leve_Time=0;
		  u8cnt50ms=0;
		  Start_Receive_Data=0;
		  Data=Value;
		  Total_Data=8;
          u8Data_time=0;
		  //P00 = ~P00;

	 }
    }
}	
/*************************************************************
说明：main()

***************************************************************/
void main()
{
    P12IH;
	System_Init();
	while(1)
	{
		WDTCON |= 0x10;		    //清看门狗
		System_Handle();		
	}
}