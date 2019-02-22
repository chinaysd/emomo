#include "system.h"
TIMEOUT_PARA TimeOut_Para[2];
Pushrod_Para_t Pushrod_Para[PUSHROD_NUM];

extern PROCOTOL_BUF_R Rev_Para;
uint32_t temp;
uint8_t Key_Flag,Key1_Flag;


void System_Init(void)
{
  static uint8_t i;
  BackCall_Clk(Clk_Init);
  TimeOutDet_Init();
  BackCall_Led(Led_Init);
  Key_Init();
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
  WatchDog_Clear();//1B,2B-->Í·Õí£»1A,2A-->×ùÒÎ£»1C,2C-->ÑüÍÆ
  if(Serial_Get_Status())
  {
   temp = (uint16_t)Get_32bit(Rev_Para.Rev_Format_r.DATA1,Rev_Para.Rev_Format_r.DATA2);
   memset(&Rev_Para,0,sizeof(Rev_Para));
   if((Key_Status(KEY6_PORT,KEY6_PIN))&&(Key1_Status(KEY5_PORT,KEY5_PIN)))
   {
     switch(temp)
     {
       case 0x01:
                 if(!Key_Flag)
                 {
                   Key_Flag = 1;
                   TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                   PUSH1B_SET(0);
                   PUSH2B_SET(1);
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 { 
                   if(!Key1_Flag)
                   {
                     Key1_Flag = 1;
                     TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                     PUSH1A_SET(1);
                     PUSH2A_SET(0);
                   }
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 {
                   PUSH1C_SET(0);
                   PUSH2C_SET(1);
                 }
                 break;
       case 0x02:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(1);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x03:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(1);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x04:
                 PUSH1A_SET(1);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x05:
                 PUSH1A_SET(0);
                 PUSH2A_SET(1);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x06:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(1);
                 break;
       case 0x07:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(1);
                 PUSH2C_SET(0);
                 break;
       default:
                 Key_Flag = 0;
                 Key1_Flag = 0;
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
     }
   }
   if((0 == Key_Status(KEY6_PORT,KEY6_PIN))&&(0 == Key1_Status(KEY5_PORT,KEY5_PIN)))
   {
     switch(temp)
     {
       case 0x01:
                 if(!Key_Flag)
                 {
                   Key_Flag = 1;
                   TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                   PUSH1B_SET(0);
                   PUSH2B_SET(1);
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 { 
                   if(!Key1_Flag)
                   {
                     Key1_Flag = 1;
                     TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                     PUSH1A_SET(1);
                     PUSH2A_SET(0);
                   }
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 {
                   PUSH1C_SET(0);
                   PUSH2C_SET(1);
                 }
                 break;
       case 0x02:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(1);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x03:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(1);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x04:
                 PUSH1A_SET(0);
                 PUSH2A_SET(1);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x05:
                 PUSH1A_SET(1);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x06:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(1);
                 break;
       case 0x07:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(1);
                 PUSH2C_SET(0);
                 break;
       default:
                 Key_Flag = 0;
                 Key1_Flag = 0;
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
     }
   }
   if((Key_Status(KEY6_PORT,KEY6_PIN))&&(0 == Key1_Status(KEY5_PORT,KEY5_PIN)))
   {
     switch(temp)
     {
       case 0x01:
                 if(!Key_Flag)
                 {
                   Key_Flag = 1;
                   TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                   PUSH1B_SET(0);
                   PUSH2B_SET(1);
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 { 
                   if(!Key1_Flag)
                   {
                     Key1_Flag = 1;
                     TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                     PUSH1A_SET(1);
                     PUSH2A_SET(0);
                   }
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 {
                   PUSH1C_SET(0);
                   PUSH2C_SET(1);
                 }
                 break;
       case 0x02:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(1);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x03:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(1);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x04:
                 PUSH1A_SET(0);
                 PUSH2A_SET(1);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x05:
                 PUSH1A_SET(1);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x06:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(1);
                 break;
       case 0x07:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(1);
                 PUSH2C_SET(0);
                 break;
       default:
                 Key_Flag = 0;
                 Key1_Flag = 0;
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
     }
   }
   if(0 == (Key_Status(KEY6_PORT,KEY6_PIN))&&(Key1_Status(KEY5_PORT,KEY5_PIN)))
   {
     switch(temp)
     {
       case 0x01:
                 if(!Key_Flag)
                 {
                   Key_Flag = 1;
                   TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                   PUSH1B_SET(0);
                   PUSH2B_SET(1);
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 { 
                   if(!Key1_Flag)
                   {
                     Key1_Flag = 1;
                     TimeOut_Record(&TimeOut_Para[0],Delay_Time);
                     PUSH1A_SET(1);
                     PUSH2A_SET(0);
                   }
                 }
                 if(TimeOutDet_Check(&TimeOut_Para[0]))
                 {
                   PUSH1C_SET(0);
                   PUSH2C_SET(1);
                 }
                 break;
       case 0x02:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(1);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x03:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(1);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x04:
                 PUSH1A_SET(1);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x05:
                 PUSH1A_SET(0);
                 PUSH2A_SET(1);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(0);
                 break;
       case 0x06:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(0);
                 PUSH2C_SET(1);
                 break;
       case 0x07:
                 PUSH1A_SET(0);
                 PUSH2A_SET(0);
                 PUSH1B_SET(0);
                 PUSH2B_SET(0);
                 PUSH1C_SET(1);
                 PUSH2C_SET(0);
                 break;
       default:
                 Key_Flag = 0;
                 Key1_Flag = 0;
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
}