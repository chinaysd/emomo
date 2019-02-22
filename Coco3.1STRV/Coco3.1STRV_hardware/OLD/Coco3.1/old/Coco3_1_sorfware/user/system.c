#include "system.h"
TIMEOUT_PARA TimeOut_Para[2];
Pushrod_Para_t Pushrod_Para[PUSHROD_NUM];

extern PROCOTOL_BUF_R Rev_Para;
uint32_t temp;


void System_Init(void)
{
  static uint8_t i;
  BackCall_Clk(Clk_Init);
  TimeOutDet_Init();
  BackCall_Led(Led_Init);
  for(i = 0;i < PUSHROD_NUM;i++)
  {
    Pushrod_Para[i].ID = i;
    Pushrod_App_Init(&Pushrod_Para[i]);
  }
  Timer_Init();
  Uart_Init();
  WatchDog_Enable();
  Interrupt_Enable();
}

void System_Handle(void)
{
  WatchDog_Clear();
  if(TimeOutDet_Check(&TimeOut_Para[0]))
  {
     TimeOut_Record(&TimeOut_Para[0],Delay_Time);
     static uint8_t Cnt;
     ++ Cnt;
     if(Cnt & 0x01)
     {
       BackCall_Led(Led_Open);
     }
     else
     {
       BackCall_Led(Led_Close);
     }
  }
  if(Serial_Get_Status())
  {
    temp = (uint16_t)Get_32bit(Rev_Para.Rev_Format_r.DATA1,Rev_Para.Rev_Format_r.DATA2);
    memset(&Rev_Para,0,sizeof(Rev_Para));
   switch(temp)
   {
   case 0x01:
             PUSH1A_SET(1);
             PUSH2A_SET(0);
             PUSH1B_SET(0);
             PUSH2B_SET(0);
             PUSH1C_SET(0);
             PUSH2C_SET(0);
             break;
   case 0x02:
             PUSH1A_SET(0);
             PUSH2A_SET(1);
             PUSH1B_SET(0);
             PUSH2B_SET(0);
             PUSH1C_SET(0);
             PUSH2C_SET(0);
             break;
   case 0x04:
             PUSH1A_SET(0);
             PUSH2A_SET(0);
             PUSH1B_SET(1);
             PUSH2B_SET(0);
             PUSH1C_SET(0);
             PUSH2C_SET(0);
             break;
   case 0x10:
             PUSH1A_SET(0);
             PUSH2A_SET(0);
             PUSH1B_SET(0);
             PUSH2B_SET(1);
             PUSH1C_SET(0);
             PUSH2C_SET(0);
             break;
   case 0x20:
             PUSH1A_SET(0);
             PUSH2A_SET(0);
             PUSH1B_SET(0);
             PUSH2B_SET(0);
             PUSH1C_SET(1);
             PUSH2C_SET(0);
             break;
   case 0x40:
             PUSH1A_SET(0);
             PUSH2A_SET(0);
             PUSH1B_SET(0);
             PUSH2B_SET(0);
             PUSH1C_SET(0);
             PUSH2C_SET(1);
             break;
   default:
             PUSH1A_SET(0);
             PUSH2A_SET(0);
             PUSH1B_SET(0);
             PUSH2B_SET(0);
             PUSH1C_SET(0);
             PUSH2C_SET(0);
             break;
   }
  }
}