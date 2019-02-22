#include "system.h"

TIMEOUT_PARA TimeOut_Para[2];
PUSH_STATUS_PARA_t Push_Status_Para;
DEMO_STATUS_PARA_t Demo_Status_Para;

unsigned char Data;

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;

char rev_cmp_flag = 0;
extern char Rev_Flag;

unsigned char Get_Key;


/***********推杆停止时所发送的数据******************/
void Push_Stop_Send_Data(void)
{
    if(!Push_Status_Para.Key_Push_Stop_Flag){
    Push_Status_Para.Key_Push_Stop_Flag = 1;
    Push_Status_Para.Key_Push_Start_Flag = 0;
    Voice_Protocol_Send(0xA5, 0xFA,0X0100);
    }
}
/*****************************************************************/

/**********推杆运行时所发送的数据*******************/
void Push_Start_Send_Data(void)
{
    if(!Push_Status_Para.Key_Push_Start_Flag){
    Push_Status_Para.Key_Push_Start_Flag = 1;
    Push_Status_Para.Key_Push_Stop_Flag = 0;
    Voice_Protocol_Send(0xA5, 0xFA,0X0101);
    }
}
/****************************************************************/

/*********开始演示时所发送的数据********************/
#if 0
void Demo_Start_Send_Data(void)
{
   if(!Demo_Status_Para.Demo_Start_Flag)
   {
   	Demo_Status_Para.Demo_Start_Flag = 1;
	Demo_Status_Para.Demo_Stop_Flag = 0;
	Voice_Protocol_Send(0xA5, 0xFA,0X0A01);
   }
}
#endif
/****************************************************************/

/*********停止演示时所发送的数据********************/
void Demo_Stop_Send_Data(void)
{
     if(Demo_Status_Para.Demo_Flag)
     {
	 Demo_Status_Para.Demo_Flag = 0;
 	 if(!Demo_Status_Para.Demo_Stop_Flag)
	 {
		  Demo_Status_Para.Demo_Stop_Flag = 1;
		  Demo_Status_Para.Demo_Start_Flag = 0;
		  Voice_Protocol_Send(0xA5, 0xFA,0X0A00);
	 }
     }
}
/****************************************************************/

/***********************座椅打开控制**********************/
void SeatOpen_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  OPEN;
	    	Push_Status_Para.Push_Auto_Close_Flag = 1;
	    	Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	    	Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************座椅收回控制*********************/
void SeatClose_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  CLOSE;
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0; 
	}
}
/****************************************************************/

/***********************头枕打开控制**********************/
void HeadUp_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  HEAD_UP;
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************头枕收回控制*********************/
void HeadDown_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  HEAD_DOWN; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************腰推打开控制**********************/
void LumberUp_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  LARBUM_UP; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************腰推收回控制*********************/
void LumberDown_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  LARBUM_DOWN;
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************腿部打开控制**********************/
void LegUp_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  FOOT_UP;
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/***********************腿部收回控制*********************/
void LegDown_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  FOOT_DOWN; 
	      Push_Status_Para.Push_Auto_Close_Flag = 1;
	      Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	      Push_Status_Para.Push_Auto_Close_Cnts   = 0; 
	}
      
}
/****************************************************************/

/*********************复位控制******************************/
void HomePosition_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  HOME_POSITION; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/********************* 推杆停止控制***********************/
void Push_Stop_Control(void)
{
	if(Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 0;
		Data =  0; 
	      Push_Status_Para.Push_Auto_Close_Flag = 0;
	      Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	      Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/*********************睡觉位置控制************************/
void Sleep_Position_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  SLEEP_POSITION; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/*********************看电视位置控制************************/
void WatchTV_Position_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  WATCH_TV_POSITION; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/

/*********************阅读位置位置控制************************/
void Read_Position_Control(void)
{
	if(!Push_Status_Para.PushOnlyOne_Flag)
	{
		Push_Status_Para.PushOnlyOne_Flag = 1;
		Data =  READING_POSITION; 
	       Push_Status_Para.Push_Auto_Close_Flag = 1;
	       Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	       Push_Status_Para.Push_Auto_Close_Cnts   = 0;
	}
}
/****************************************************************/



void Key_Handle(unsigned char Key)
{
    Get_Key = Key;
	if(PUSH_TEMP_DIRECTION_PIN == 0)
	{
	    if(Get_Key == MSG_KEY_NONE)
	    {
	      Rev_Data_Handle();  
	      if(!Rev_Flag)
	      {
	         Push_Stop_Send_Data();
		  Push_Stop_Control();
	      }           
	    }
	    else if(Get_Key == MSG_KEY1_LONGPRESS)
	    {
	      Demo_Stop_Send_Data();
	      Push_Start_Send_Data();
	      HeadUp_Control();
	      Rev_Flag = 0;
	    }
		else if(Get_Key == MSG_KEY3_LONGPRESS)
	    {
	      Demo_Stop_Send_Data();
	      Push_Start_Send_Data();
		HeadDown_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY2_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      HomePosition_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY4_LONGPRESS)   
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
		LegUp_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY5_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
		LumberUp_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY6_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      SeatOpen_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY7_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
		SeatClose_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY8_LONGPRESS)//
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      LED_SET(1);
	      LumberDown_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY9_LONGPRESS)//
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      LED_SET(1);
	      LegDown_Control(); 
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
	         Push_Stop_Send_Data();
		  Push_Stop_Control();
	      }           
	    }
	    else if(Get_Key == MSG_KEY1_LONGPRESS)
	    {
	      Demo_Stop_Send_Data();
	      Push_Start_Send_Data();
	      HeadUp_Control();
	      Rev_Flag = 0;
	    }
		else if(Get_Key == MSG_KEY3_LONGPRESS)
	    {
	      Demo_Stop_Send_Data();
	      Push_Start_Send_Data();
	      HeadDown_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY2_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      HomePosition_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY4_LONGPRESS)   
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	       LumberUp_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY5_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
		LumberDown_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY6_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      SeatClose_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY7_LONGPRESS)
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      SeatOpen_Control();
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY8_LONGPRESS)//
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      LED_SET(1);
	      LegDown_Control(); 
	      Rev_Flag = 0;        
	    }
	    else if(Get_Key == MSG_KEY9_LONGPRESS)//
	    {
		Demo_Stop_Send_Data();
             Push_Start_Send_Data();
	      LED_SET(1);
	      LegUp_Control();
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
   Key_Poll();   
   P00 = 1;
   if(TimeOutDet_Check(&TimeOut_Para[0]))
   {
       TimeOut_Record(&TimeOut_Para[0],40);
       Protocol_Send(IC_ADDR,IC_ID,Data);
   } 
   if(Push_Status_Para.Push_Auto_Close_Cnts > Push_Auto_Close_Time)//30秒后推杆自动关闭
  {
  	Push_Stop_Send_Data();
       Push_Stop_Control();
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
  if(Push_Status_Para.Push_Auto_Close_Flag)
  {
  	Push_Status_Para.Push_Auto_Close_Cnt1s ++;
  }
  if(Push_Status_Para.Push_Auto_Close_Cnt1s > Auto_Close_Time1s)//一秒的时间段
  {
  	Push_Status_Para.Push_Auto_Close_Cnt1s = 0;
	Push_Status_Para.Push_Auto_Close_Cnts ++;
  }
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


