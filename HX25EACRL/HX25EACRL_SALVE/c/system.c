#include "system.h"

unsigned char Cnt200ms;
/*发热布标志位*/
unsigned char LED_SWITCH_OPEN_FLAG,LED_SWITCH_CLOSE_FLAG;
unsigned int  u8cnt2s_open,u8cnt2s_close;
unsigned char share_flag,share1_flag,SET;

 
/******************************/
extern unsigned int AdcValue;
extern unsigned char Data;
extern TIMEOUT_PARA Shake_Time[2];

void System_Init(void)
{
  TimeOutDet_Init();
  Push_Init();
  Heat_Init();
  Cool_Init();
  LED_Init();
  P17 = 0;
  Time1_Init();
}
unsigned char last_rev = 0,mode_type;

void System_Handle(void)
{
#if ADCDIS
  if(Cnt200ms >= 4)      //200ms 检测一次
  {
    Cnt200ms = 0;
    ADCwork(AIN7,1);
  }
#endif
if((Data & 0xFF) != 0x00)
{
    switch (Data & 0xFF)
    {
       case 0x01:
                 P0 |= 0X03;
                 break;
       case 0x02:
                 P0 &= ~0X02;
                 break;
       case 0x04:
                 P0 &= ~0X03;
                 break;
       case 0x20:
                 P1 |= 0X41;//制冷，风扇
                 P05 = 1;//绿灯
                 break;
       case 0x40:
                 P1 &= ~0X41; 
                 P05 = 0;
                 break;
       case 0x08:
	           PushA1_Open();
	           break;
	   case 0x10:
			   PushA2_Close();
	           break;
	   case 0xA0://打开推杆  
			   PushB2_Close();
		        break;	 
	   case 0xC0://降低推杆
			   PushB1_Open();
		       break;
       default:
                 break;
    }
}
else
{
     PushA1_Stop();
     PushA2_Stop();
	 PushB1_Stop();
     PushB2_Stop();
}
#if 0//PUSHEN

if((Data&0xE0)!=0)
{
	switch(Data&0xE0)
    {
	 
	 default: break;
    }
}
if((Data&0xE0)==0)
{
   	 PushA1_Stop();
     PushA2_Stop();
	 PushB1_Stop();
     PushB2_Stop();
}
#endif

  
}
