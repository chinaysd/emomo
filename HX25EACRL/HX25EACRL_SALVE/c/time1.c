#include "time1.h"


void Time1_Init(void)
{
   	TMCON=0x07;							//------111 ;Timer0��Tiemr1��Tiemr2ѡ��ʱ��Fsys
	TMOD=0x11;  						//0001 0001  ;Timer0��Timer1���ù�����ʽ1	
//T1����   	
   	TH1=(65536 - 3000)/256;		      //�����ƵΪ24M��ʱ��Fsys��24M*24000=1ms;
   	TL1=(65536 - 3000)%256;
   	TR1=0;
   	ET1=1;
   	TR1=1;
	EA=1;
}