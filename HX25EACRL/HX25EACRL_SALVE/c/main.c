#include "system.h"

/*************************************************************
˵����
1��Options for Target��Target1����BL51 Locate->Code Range:0x100����¼ѡ����ѡ��DISRST����λ����Ϊ��ͨIOʹ�ã�
2���ı�TEST�Ķ��壬���Էֱ���Զ�Ӧ�Ĺ��ܣ�
***************************************************************/

#define  Receive_IO_Data             P12

extern unsigned char LED_SWITCH_OPEN_FLAG,LED_SWITCH_CLOSE_FLAG;
extern unsigned int  u8cnt2s_open,u8cnt2s_close;
unsigned char LED_FLAG;
TIMEOUT_PARA Shake_Time[2];

extern unsigned char Cnt200ms;
unsigned int Cnt800ms;

extern unsigned int AdcValue;

unsigned char u8cnt50ms,u8CntMs;//50ms��ʱ

unsigned char Start_Receive_Data ;//��ʼ��������
unsigned char Value,STAT,R_Data;
unsigned char High_Leve_Time,Low_Leve_Time;//�ߵ�ƽʱ��
unsigned char Total_Data=8;    //�����ݳ���
unsigned int u16Cnt4hours;
unsigned char  u8shuttime;
unsigned char  u8Data_time;//�������ݵ�ʱ�䣬���0.5S֮��û���յ����ݣ�������Ƭ�ر�
unsigned char Flag;
unsigned char Data;			   			  			   

/*************************************************************
˵����
TEST==TEST_TIMER
1����ʱ��Ϊ���������ʽ��T��ʱ���㹫ʽ=Txʱ��Դ*��������ֵ+1-Ԥװ��ֵ��
***************************************************************/

void timer1()interrupt 3				//Timer1������ 3
{
	TH1 = (65536 - 3000)/256;		    //�ٴ�װ���ֵ
   	TL1 = (65536 - 3000)%256;			//0.25ms����һ��

	if(Cnt800ms++ > 800)                //200ms����һ��
	{
	   Cnt800ms = 0;
	   Cnt200ms++;
	}

	R_Data=Receive_IO_Data;
    if((R_Data==0)&&(Start_Receive_Data==0))  //������͵�ƽ��ʱ��
    {
	   ++u8cnt50ms;
    }
	if(R_Data==1)          //��ƽΪ��ʱ�жϵ͵�ƽ��ʱ��
	{
	 	if((15<=u8cnt50ms)&&(22>=u8cnt50ms))    //ʱ�䷶Χ�������͵�ƽ�ķ�Χ�ڣ���ʼ����
		{
			Low_Leve_Time=0;
			u8cnt50ms=0;
			High_Leve_Time=0;
			Value=0;
			Total_Data=8;
	        Start_Receive_Data=1;
	     }
	     else if(22<=u8cnt50ms)     //���� ���򲻽���
	     {
		 	Low_Leve_Time=0;
			u8cnt50ms=0;
			High_Leve_Time=0;
			Value=0;
			Total_Data=8;
	        Start_Receive_Data=0;
	     }
	     else                       //�����������
	     {
	        u8cnt50ms=0;
	     }	    
	}

	if(Start_Receive_Data)   //��ʼ��������
	{
	    if(Total_Data>0)    //���հ˴�
	    { 
			  if(R_Data==1)       //�ߵ�ƽ��ʱ��
			  {
				  Flag=1;            //�͵�ƽʱ�жϱ�־
		          High_Leve_Time++;   //�ߵ�ƽʱ�����
			  }
		      if((R_Data==0)&&(Flag==1))  //�͵�ƽʱ�жϸߵ�ƽʱ�䣬flag��־λֻ����һ�Σ�																	//ֻ�����´η�ת��ʱ����ܽ����ж�
			  { 
				  Value=Value<<1;             //�����������ƣ���λ����ֻ����λ�ߴ�
				  Flag=0;                    //���־
			      Low_Leve_Time++;            //�͵�ƽʱ�����
			      if((High_Leve_Time>=7)&&(High_Leve_Time<=10))  //�ж���Ϊ1
		          {
						 Low_Leve_Time=0;
						 High_Leve_Time=0;
						 Value |= 0x01;
						 Total_Data--;
	              }
		          else if((High_Leve_Time>=1)&&(High_Leve_Time<=6))  //�ж���Ϊ0
	              {
						 Low_Leve_Time=0;
						 High_Leve_Time=0;
						 Value &= (~0x01);
						 Total_Data--;
				  }
		      } 
			  if((High_Leve_Time>16)||(Low_Leve_Time>8))      //�ݴ����ڽ��������ݺ�����
		      {
				  Low_Leve_Time=0;
				  High_Leve_Time=0;
				  u8cnt50ms=0;
		          Start_Receive_Data=0;
				  Value=0;
				  Total_Data=8;
			  }
		  }
     else   //������ɣ�����������
     {
		  Low_Leve_Time=0;
		  High_Leve_Time=0;
		  u8cnt50ms=0;
		  Start_Receive_Data=0;
		  Data=Value;
		  Total_Data=8;
          u8Data_time=0;
		  //P00 = ~P00;

	 }
    }
}	
/*************************************************************
˵����main()

***************************************************************/
void main()
{
    P12IH;
	System_Init();
	while(1)
	{
		WDTCON |= 0x10;		    //�忴�Ź�
		System_Handle();		
	}
}