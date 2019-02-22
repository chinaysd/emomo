#include "time1.h"


void Time1_Init(void)
{
   	TMCON=0x07;							//------111 ;Timer0、Tiemr1和Tiemr2选择时钟Fsys
	TMOD=0x11;  						//0001 0001  ;Timer0和Timer1设置工作方式1	
//T1设置   	
   	TH1=(65536 - 3000)/256;		      //如果主频为24M和时钟Fsys则24M*24000=1ms;
   	TL1=(65536 - 3000)%256;
   	TR1=0;
   	ET1=1;
   	TR1=1;
	EA=1;
}