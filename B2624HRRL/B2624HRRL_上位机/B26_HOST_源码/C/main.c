#include "H/SC93F833X_C.H"
#include "lib/SensorMethod.h"
#include "h/UART.H"
#include "h/INIT.H"

extern unsigned char count_level;
extern unsigned char count_250us_time;
extern unsigned int count_1ms_time;


//INT16U KeyDebunce;
unsigned long Key_Buf,get_key_data,KeyDebunce,MyKey_Buf_Data;
unsigned char key_press = 0,up_flag,down_flag,heat_red_flag,auto_close_heat,auto_close_mass,rev_flag = 0;
unsigned int motro_count0,motro_count1,auto_close_heat_cnt,auto_close_mass_cnt;
static unsigned char MOTRO_FLAG = 0;
unsigned int u16TimeLock = 0;
unsigned char Lock_Flag = 0,Flag = 0,RED_LIGHT = 0;
extern unsigned char lock;

unsigned char auto_close_heat_flag = 0,auto_close_mass_flag = 0;


void UART_TX_byte(unsigned char DATA)
{
   TI = 0;
   SBUF = DATA;
   while(!TI);
}

void main()
{
	uart_init();
	GPIO_INIT();
    Timer0_Init();
//  TIMER1_INIT();
    TouchKeyInit(); // ���ذ�����ʼ��
	EA = 1;
	count_level = 15;	
	while(1)
	{
		WDTCON|=0x10;
		if(SOCAPI_TouchKeyStatus&0x80) // ��Ҫ���� 2: ������ɨ��һ�ֱ�־���Ƿ���� TouchKeyScan() һ��Ҫ���ݴ˱�־λ�����
        {
			SOCAPI_TouchKeyStatus &= 0x7f;// ��Ҫ���� 3:  �����־λ�� ��Ҫ�ⲿ�����
			get_key_data = TouchKeyScan();// �������ݴ�����

			TouchKeyRestart();// ������һ��ת��
		}	

   if(get_key_data!=0)	//������
   {
	  if(++KeyDebunce>2)                 //����
	  {
	    KeyDebunce = 0;
		MyKey_Buf_Data = get_key_data;
		if(0X0008 == MyKey_Buf_Data)//   TK3,,,,,,,,,�ŵ��뱭��
		{
		  if(key_press)
		  {
			key_press = 0;
			if(count_level == 15)
			{
			  count_level = 100;
			}
			else if(count_level == 100)
			{
			  count_level = 15; 
			}			
			UART_TX_byte(0x11);          //����0x01			
		  }
		  		 
		}
		else if(0X0010 == MyKey_Buf_Data)// TK4,,,,,,,,��������
		{
		  if(key_press)
		  {
			key_press = 0;
			if(MOTRO_FLAG == 0)
			{
			  MOTRO_FLAG = 1;
			  P0 &= 0Xf9;
			  //P0 |= 1 << 2;
			  P0 |= 1 << 1;
			  motro_count0 = 0;
			  motro_count1 = 0;
			  up_flag = 1;
			  down_flag = 0;
			}
			else
			{
			  MOTRO_FLAG = 0;
			  P0 &= 0Xf9;
			  //P0 |= 1 << 1;
			  P0 |= 1 << 2;
			  motro_count0 = 0;
			  motro_count1 = 0;
			  up_flag = 0;
			  down_flag = 1;
			}			
		  }
		 
		}
		else if(0X0020 == MyKey_Buf_Data)//TK5,,,,,,,,�Ƹ�B��
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x17);           //����0x17			
		  }
		  
		}
/*******************************************************************************/
/********************������ʱ��Ҫ�ر�*******************************************/
/*******************************************************************************/
#if 1
		else if(0X4000 == MyKey_Buf_Data)//TK14,,,,,,,,,���Ȳ�&����
		{
		  if(key_press)
		  {		    
			key_press = 0;
			if(heat_red_flag == 0)
			{
			  heat_red_flag = 1;
			  IO_RED_LIGHT_ON;
			  auto_close_heat = 1;
			  auto_close_heat_cnt = 0;
			}
			else
			{
			  heat_red_flag = 0;
			  IO_RED_LIGHT_OFF;
			  auto_close_heat = 0;
			  auto_close_heat_cnt = 0;
			}
        	UART_TX_byte(0x20);	          //����0x20            		
		  }
		  
		}
#endif
/********************************************************************************/
		else if(0X8000 == MyKey_Buf_Data)//TK15,,,,,,,,,,��Ħ���
		{

		  auto_close_mass_cnt = 0;
		  if(key_press)
		  {
			key_press = 0;
			#if 1
			/***********30���Ӻ��Զ��رհ�Ħ���*********************************/
			rev_flag = ~rev_flag;
			if(rev_flag)
			{
			   auto_close_mass = 1;
			   auto_close_mass_cnt = 0;		
			}
			else
			{
			   auto_close_mass = 0;
			   auto_close_mass_cnt = 0;
			}
			/*******************************************************************/
			#endif
			
			UART_TX_byte(0x21);                //����0x21			
		  }
		  
		}
		else if(0X0100 == MyKey_Buf_Data)//TK8,,,,,,,,,,,,�Ƹ�A�ջ�
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x01);                //����0x01 			
		  }
		  
		}
		else if(0X0200 == MyKey_Buf_Data)//TK9,,,,,,,,,,,,�Ƹ�A��
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x12);                 //����0x12			
		  }
		  
		}
		else if(0X40000 == MyKey_Buf_Data)//TK18,,,,,,,,,,,,,
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x16);                  //����0x16			
		  }
		  
		}
		else if(0X80000 == MyKey_Buf_Data)//TK19,,,,,,,,�Ƹ�B�ջ�
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x02);                 //����0x02			
		  }
		 
		}
		else if(0X1000 == MyKey_Buf_Data)//TK12,,,,,,,,,,,��λ��
		{
		  if(key_press)
		  {
			key_press = 0;
			UART_TX_byte(0x09);                 //����0x09			
		  }
		  
		}
		else if(0X2000 == MyKey_Buf_Data)//TK13,,,,,,,,,,,,
		{
		  if(key_press)
		  {
			key_press = 0;
			//UART_TX_byte(0x51);			
		  }		  
		}
		else
		{
		   //UART_TX_byte(0x55);
		}
	  }
   }
     else
	{
	  key_press = 1;
	  UART_TX_byte(0x55);
	}
   if(auto_close_heat_flag)
   {
      auto_close_heat_flag = 0;
	  auto_close_heat_cnt = 0;
	  IO_RED_LIGHT_OFF;
	  heat_red_flag = 0;
      UART_TX_byte(0x20);
   }
   else if(auto_close_mass_flag)
   {
      auto_close_mass_flag = 0;
	  auto_close_mass_cnt = 0;
	  rev_flag = 0;
	  UART_TX_byte(0x21);
   }
  }	
}

void timer0() interrupt 1
{
    TL0 = (65536 - 605)%256;
	TH0 = (65536 - 605)/256;     //100us
//	IO_LED_FOOT_LIGHT_PIN =~ IO_LED_FOOT_LIGHT_PIN;
    /*****************************������ʱ��************************/
    //if(u16TimeLock != 0x00)       u16TimeLock--;
/*********************�����������ܵı����************************/
#if 0
     if((0X4000 == MyKey_Buf_Data)&&(1 == lock))
	 {
	   MyKey_Buf_Data = 0x1111;
	   if(u16TimeLock < 20000)
	   {
	      u16TimeLock++;
	   }
	   else
	   {
	      u16TimeLock = 0;
		  IO_RED_LIGHT_ON;
		  lock = 0;
	   }
	 }
	 else if((0X4000 == MyKey_Buf_Data)&&(0 == lock))
	 {
	   MyKey_Buf_Data = 0x1111;
	   if(u16TimeLock < 20000)
	   {
	      u16TimeLock++;
	   }
	   else
	   {
	      u16TimeLock = 0;
		  IO_RED_LIGHT_OFF;
		  lock = 1;
	   }
	 }
	 else
	 {
	      //key_press = 1;
	 }
#endif

	/***************************************************************/
    /********************PWM���Ƶ�**********************************/
#if 1
    count_250us_time++;
	if(count_250us_time > 100)
	{
	  count_250us_time = 0;
	}
	if(count_250us_time >= count_level)
	{
	  IO_LED_FOOT_LIGHT_OFF;
	}
	else
	{
	  IO_LED_FOOT_LIGHT_ON;
	}
#endif
    /***************************************************************/
    /********************�����������*******************************/
    /***************************************************************/
#if 1
	if(up_flag)
	{
	   motro_count0++;
	   if(motro_count0>6000)
	   {
	      motro_count0 = 0;
		  up_flag = 0;
		  down_flag = 1;
		  P0 &= 0Xf9;
	   }
	}
	if(down_flag)
	{
	   motro_count1++;
	   if(motro_count1>6000)
	   {
	     motro_count1 = 0;
		 up_flag = 1;
		 down_flag = 0;
		 P0 &= 0Xf9;
	   }
	}
#endif
    /*****************************************************************/
    /*********************���������ͷ��Ȳ��Զ��رյĳ���*********/
    /****************************************************************/
#if 1
	if(count_1ms_time++ > 10530)
	{
	  //1s time
	  count_1ms_time = 0;
	  if(auto_close_mass)
	  {
	    if(auto_close_mass_cnt++ > auto_close_mass_time)//1800
		{
		   auto_close_mass_cnt = 0;
		   auto_close_mass = 0;
		   //�������ر�ָ��
		   //UART_TX_byte(0x21); 
		   auto_close_mass_flag = 1;
		   //rev_flag = 0;

		}
	  }
	  if(auto_close_heat)
	  {
	    if(auto_close_heat_cnt++ > auto_close_heat_time)//3600
		{
		   auto_close_heat_cnt = 0;
		   auto_close_heat = 0;
		   //���ͷ��Ȳ��ر�ָ��
		   IO_RED_LIGHT_OFF;
		   //UART_TX_byte(0x20);
		   auto_close_heat_flag = 1;
		}
	  }

	}
#endif
    /****************************************************************/
}

