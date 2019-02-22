#include "system.h"

TIMEOUT_PARA TimeOut_Para[2];
PUSH_STATUS_PARA_t Push_Status_Para;
DEMO_STATUS_PARA_t Demo_Status_Para;

unsigned char Data;

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;

char rev_cmp_flag = 0;
extern char Rev_Flag;

unsigned char Get_Key;


/***********�Ƹ�ֹͣʱ�����͵�����******************/
void Push_Stop_Send_Data(void)
{
    if(!Push_Status_Para.Key_Push_Stop_Flag){
    Push_Status_Para.Key_Push_Stop_Flag = 1;
    Push_Status_Para.Key_Push_Start_Flag = 0;
    Voice_Protocol_Send(0xA5, 0xFA,0X0100);
    }
}
/*****************************************************************/

/**********�Ƹ�����ʱ�����͵�����*******************/
void Push_Start_Send_Data(void)
{
    if(!Push_Status_Para.Key_Push_Start_Flag){
    Push_Status_Para.Key_Push_Start_Flag = 1;
    Push_Status_Para.Key_Push_Stop_Flag = 0;
    Voice_Protocol_Send(0xA5, 0xFA,0X0101);
    }
}
/****************************************************************/

/*********��ʼ��ʾʱ�����͵�����********************/
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

/*********ֹͣ��ʾʱ�����͵�����********************/
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

/***********************���δ򿪿���**********************/
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

/***********************�����ջؿ���*********************/
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

/***********************ͷ��򿪿���**********************/
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

/***********************ͷ���ջؿ���*********************/
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

/***********************���ƴ򿪿���**********************/
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

/***********************�����ջؿ���*********************/
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

/***********************�Ȳ��򿪿���**********************/
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

/***********************�Ȳ��ջؿ���*********************/
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

/*********************��λ����******************************/
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

/********************* �Ƹ�ֹͣ����***********************/
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

/*********************˯��λ�ÿ���************************/
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

/*********************������λ�ÿ���************************/
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

/*********************�Ķ�λ��λ�ÿ���************************/
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
   if(Push_Status_Para.Push_Auto_Close_Cnts > Push_Auto_Close_Time)//30����Ƹ��Զ��ر�
  {
  	Push_Stop_Send_Data();
       Push_Stop_Control();
  }
}


/**************************************************
*�������ƣ�void timer0/1/2() interrupt 1/3/5
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
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
  if(Push_Status_Para.Push_Auto_Close_Cnt1s > Auto_Close_Time1s)//һ���ʱ���
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
	TF2 = 0;   //�������

}

void Uart1_Int() interrupt 7   //Uart1�жϺ���
{

	if(SSCON0&0x02)    //���ͱ�־λ�ж�
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))//���ձ�־λ�ж�
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
             Serial_Rev_IQH();
	}
    
}


