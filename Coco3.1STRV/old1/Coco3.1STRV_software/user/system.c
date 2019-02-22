#include "system.h"

TIMEOUT_PARA TimeOut_Para[2];
unsigned char Data;

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;

char rev_cmp_flag = 0;
extern char Rev_Flag;

unsigned char Get_Key;

void Key_Handle(unsigned char Key)
{
    Get_Key = Key;
	if(PUSH_TEMP_DIRECTION_PIN)
	{
	    if(Get_Key == MSG_KEY_NONE)
	    {
	      Rev_Data_Handle();  
	      if(!Rev_Flag)
	      {
	         Data =  0;  
	      }           
	    }
	    else if(Get_Key == MSG_KEY1_LONGPRESS)
	    {
	      Data =  HEAD_UP;
	      Rev_Flag = 0;
	    }
		else if(Get_Key == MSG_KEY3_LONGPRESS)
	    {
	      Data =  HEAD_DOWN; 
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY2_LONGPRESS)
	    {
	      Data =  HOME_POSITION; 
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY4_LONGPRESS)
	    {
	      Data =  LARBUM_DOWN;
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY5_LONGPRESS)
	    {
	      Data =  LARBUM_UP;  
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY6_LONGPRESS)
	    {
	      Data =  OPEN;
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY7_LONGPRESS)
	    {
	      Data =  CLOSE; 
	      Rev_Flag = 0;        
	    }
	}
	else
	{
	   if(Get_Key == MSG_KEY_NONE)
	    {
	      Rev_Data_Handle();  
	      if(!Rev_Flag)
	      {
	         Data =  0;  
	      }           
	    }
	    else if(Get_Key == MSG_KEY1_LONGPRESS)
	    {
	      Data =  HEAD_DOWN;
	      Rev_Flag = 0;
	    }
		else if(Get_Key == MSG_KEY3_LONGPRESS)
	    {
	      Data =  HEAD_UP; 
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY2_LONGPRESS)
	    {
	      Data =  HOME_POSITION; 
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY4_LONGPRESS)
	    {
	      Data =  LARBUM_UP;
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY5_LONGPRESS)
	    {
	      Data =  LARBUM_DOWN;  
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY6_LONGPRESS)
	    {
	      Data =  CLOSE;
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY7_LONGPRESS)
	    {
	      Data =  OPEN; 
	      Rev_Flag = 0;        
	    } 
	}
}

void System_Init(void)
{
   TimeOutDet_Init();
   Timer_Init();
   Led_App_Handle(LED_NUM);
   Push_Temp_Direction();
   Key_Init();
   Key_Register(Key_Handle);
   Uart_Init(12,9600);
   #ifdef WATCH_DOG_ENABLE
   WDTCON |= 0X01; 
   #endif
   EA = 1; 
}

void System_Handle(void)
{
   #ifdef WATCH_DOG_CLEAR
   WDTCON |= 0X10; 
   #endif
   P00 = 1;
   Key_Poll();   
   if(TimeOutDet_Check(&TimeOut_Para[0]))
   {
       TimeOut_Record(&TimeOut_Para[0],40);
       Protocol_Send(IC_ADDR,IC_ID,Data);
   }      
}


/**************************************************
*函数名称：void timer0/1/2() interrupt 1/3/5
*函数功能：定时器中断产生方波
*入口参数：void
*出口参数：void
**************************************************/
void timer0() interrupt 1
{
  TL0 = (65536 - 5900)%256;
  TH0 = (65536 - 5900)/256;	
  TimeOutDet_DecHandle();  
}

void timer1() interrupt 3
{

}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零

}

void Uart1_Int() interrupt 7   //Uart1中断函数
{

	if(SSCON0&0x02)    //发送标志位判断
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))//接收标志位判断
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
        Serial_Rev_IQH();
	}
    
}


