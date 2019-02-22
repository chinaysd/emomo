#include "push.h"
#include "stm8s_gpio.h"
#include "TimeOut.h"

TIMEOUT_PARA share_time[2];
unsigned char share_time_flag;


extern bool bAIO,bBIO,bCIO;

/***********推杆初始化****************************************/
void Push_Init(void)
{
  GPIO_Init(PUSH_A1_PORT,PUSH_A1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(PUSH_A2_PORT,PUSH_A2_PIN,GPIO_MODE_OUT_PP_LOW_FAST);

  GPIO_Init(PUSH_B1_PORT,PUSH_B1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(PUSH_B2_PORT,PUSH_B2_PIN,GPIO_MODE_OUT_PP_LOW_FAST);

  GPIO_Init(PUSH_C1_PORT,PUSH_C1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(PUSH_C2_PORT,PUSH_C2_PIN,GPIO_MODE_OUT_PP_LOW_FAST);

  
}
/***********推杆打开****************************************/
void Push_A1_Open(void)
{
  GPIO_WriteHigh(PUSH_A1_PORT,PUSH_A1_PIN);
}
void Push_A2_Open(void)
{
  GPIO_WriteHigh(PUSH_A2_PORT,PUSH_A2_PIN);
}

void Push_B1_Open(void)
{
  GPIO_WriteHigh(PUSH_B1_PORT,PUSH_B1_PIN);
}
void Push_B2_Open(void)
{
  GPIO_WriteHigh(PUSH_B2_PORT,PUSH_B2_PIN);
}

void Push_C1_Open(void)
{
  GPIO_WriteHigh(PUSH_C1_PORT,PUSH_C1_PIN);
}
void Push_C2_Open(void)
{
  GPIO_WriteHigh(PUSH_C2_PORT,PUSH_C2_PIN);
}
/***********推杆关闭****************************************/
void Push_A1_Close(void)
{
  GPIO_WriteLow(PUSH_A1_PORT,PUSH_A1_PIN);
}
void Push_A2_Close(void)
{
  GPIO_WriteLow(PUSH_A2_PORT,PUSH_A2_PIN);
}

void Push_B1_Close(void)
{
  GPIO_WriteLow(PUSH_B1_PORT,PUSH_B1_PIN);
}
void Push_B2_Close(void)
{
  GPIO_WriteLow(PUSH_B2_PORT,PUSH_B2_PIN);
}

void Push_C1_Close(void)
{
  GPIO_WriteLow(PUSH_C1_PORT,PUSH_C1_PIN);
}
void Push_C2_Close(void)
{
  GPIO_WriteLow(PUSH_C2_PORT,PUSH_C2_PIN);
}

void Push_A1_B2_Reset(void)
{
  GPIO_WriteHigh(PUSH_A2_PORT,PUSH_A2_PIN);
  #if 1
  if(!share_time_flag)
  {
    share_time_flag = 1;
	TimeOut_Record(&share_time[0],delay_share_time);
  }
  if(TimeOutDet_Check(&share_time[0]))
  {
    GPIO_WriteHigh(PUSH_B1_PORT,PUSH_B1_PIN);
  }
  #endif
  //GPIO_WriteHigh(PUSH_B1_PORT,PUSH_B1_PIN);
}
void Push_A2_B1_Reset(void)
{
   GPIO_WriteHigh(PUSH_A1_PORT,PUSH_A1_PIN);
   #if 1
   if(!share_time_flag)
   {
      share_time_flag = 1;
	  TimeOut_Record(&share_time[0],delay_share_time);
   }
   if(TimeOutDet_Check(&share_time[0]))
   {
      GPIO_WriteHigh(PUSH_B2_PORT,PUSH_B2_PIN);
   }
   #endif
   //GPIO_WriteHigh(PUSH_B2_PORT,PUSH_B2_PIN);
   
}
void Push_A2_B2_Reset(void)
{
  GPIO_WriteHigh(PUSH_B2_PORT,PUSH_B2_PIN);
  #if 1 
  if(!share_time_flag)
  {
     share_time_flag = 1;
	 TimeOut_Record(&share_time[0],delay_share_time);
  }
  if(TimeOutDet_Check(&share_time[0]))
  {
     GPIO_WriteHigh(PUSH_A2_PORT,PUSH_A2_PIN);
  }
  #endif
   //GPIO_WriteHigh(PUSH_A2_PORT,PUSH_A2_PIN);
  
}
void Push_A1_B1_Reset(void)
{
   GPIO_WriteHigh(PUSH_A1_PORT,PUSH_A1_PIN);
   #if 1
   if(!share_time_flag)
   {
     share_time_flag = 1;
	 TimeOut_Record(&share_time[0],delay_share_time);
   }
   if(TimeOutDet_Check(&share_time[0]))
   {
     GPIO_WriteHigh(PUSH_B1_PORT,PUSH_B1_PIN); 
   } 
   #endif
   //GPIO_WriteHigh(PUSH_B1_PORT,PUSH_B1_PIN); 
}

void Push_All_Close(void)
{
  share_time_flag = 0;
  GPIO_WriteLow(PUSH_A1_PORT,PUSH_A1_PIN);
  GPIO_WriteLow(PUSH_A2_PORT,PUSH_A2_PIN);
  GPIO_WriteLow(PUSH_B1_PORT,PUSH_B1_PIN);
  GPIO_WriteLow(PUSH_B2_PORT,PUSH_B2_PIN);
  GPIO_WriteLow(PUSH_C1_PORT,PUSH_C1_PIN);
  GPIO_WriteLow(PUSH_C2_PORT,PUSH_C2_PIN);
}
/**********************************************************************************/
