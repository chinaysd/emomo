
#define  __UART_SEND_DATA__		  //annie 					//�ô��ڷ�ʽ������


#ifdef __UART_SEND_DATA__
#include "..\sif\uart.h"
#include "..\sif\data_type.h"	
#include "..\sif\SC91F832_C.H"		
#include  "lib\SensorMethod.H"

/************************************************************************/
/* ��̬�ֲ���������                                            			 */
/************************************************************************/

BOOL m_sys_1ms;	 					//ϵͳ1msʱ��

unsigned int g_100us_count;			//100us����

#define  C_TX_OUTPUT		(BS(P1CFG1,4),BC(P1CFG1,5))    //p16
#define  C_RX_INPUT			(BC(P3CFG1,6),BS(P3CFG1,7))  	//p17

#define	UART_TXD  		P16			//���Ϳ�
#define UART_RXD		P17				//�������ݿ�


BOOL g_sent_flag;		//���ͱ�־


/************************************************************************/
/* �ڲ���������                                                         */
/************************************************************************/

void Ini_Timer1(void);    //��ʱ��1��ʼ��
void Uart_sent_data(INT8U *t_data,INT8U t_data_length);	//��������

static void uart_sent_byte(INT8U t_byte);	//����һ���ֽ�
static void Uart_sent_data_Real(void);	   //��������ʵ��

void Uart_receive_data(void);


void InitUart(void)
{
	C_TX_OUTPUT;
	C_RX_INPUT;
	Ini_Timer1(); 
}


//******************************************************************
// ������	��void Ini_Timer1(void)  
// ����		��
// ����		����ʱ��1��ʼ��
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�����
// ��ע		��
//******************************************************************

#define 	C_BAUD_BPS			9600	  		//������
#define		C_DELAY_TIME		(((10 * 1000) / C_BAUD_BPS) * 100) 		 // ��ʱʱ�� ��λ(us)		1s/������
#define     C_DELAY_TIME_COUNT	 ((C_DELAY_TIME * C_SYS_FOSC) / C_FREQ_DIV) //+ (C_DELAY_TIME * C_SYS_FOSC) % C_FREQ_DIV)		//(����ֵ �� ��ʱʱ�� �� ��Ƶֵ)
#define		C_T1_COUNT_H  		(65536 - C_DELAY_TIME_COUNT) / 256
#define 	C_T1_COUNT_L		(65536 - C_DELAY_TIME_COUNT) % 256


void Ini_Timer1(void)    
{
	TMOD	|=	C_T1_MODE_1;			//T1 ������ʽ1
	TMCON	|=  C_T1_CLK_4;    			//fsys=fosc/4����Ϊ4��Ƶ��

	TH1	=	C_T1_COUNT_H;
	TL1	=	C_T1_COUNT_L;
	
	ET1	= 	disable;					//�رն�ʱ���ж�	
	TR1	= 	disable;					//�رն�ʱ��
}



void Time1(void) interrupt TIMER_1_INTERRUPT
{
	TH1	=	C_T1_COUNT_H;
	TL1	=	C_T1_COUNT_L;

	Uart_sent_data_Real();	 	//��������
}	

//******************************************************************
// ������	��void uart_sent_byte(INT8U t_byte)
// ����		��
// ����		������һ���ֽ�
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//******************************************************************

INT8U uart_bit_count;					//����λ����
INT8U uart_sent_buff;					//���ͻ���
void uart_sent_byte(INT8U t_byte)
{
	if(uart_bit_count == 0) 
	{
		UART_TXD = 0;	   		//�ȷ���ʼλ 0
		uart_bit_count++;				//����
		uart_sent_buff = t_byte;
	}
	else if(uart_bit_count < 9)
	{
		UART_TXD = uart_sent_buff & 0x01;		//�ȷ���λ
		uart_sent_buff >>= 1;
		uart_bit_count++;						//����
	}
	else
	{
		UART_TXD = 1;	   				    	//����ֹλ1
		uart_bit_count = 0;
	}	
}
//******************************************************************
// ������	��void Uart_sent_data(INT8U *t_data,INT8U t_data_length)
// ����		��
// ����		����������
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��	1ms����һ���ֽ�
//******************************************************************
INT8U *g_sent_data;		// Ҫ���͵�����
INT8U g_data_length;	// ���ݳ���

INT8U uart_byte_count;				//�����ֽڼ���

void Uart_sent_data(INT8U *t_data,INT8U t_data_length)
{
	ET1	= 	enable;					//���ж�	
	TR1	= 	enable;					//����ʱ��

	g_sent_data = t_data;			  //����

    g_data_length = t_data_length;	 //���ݳ���
	
	uart_bit_count = 0;			 //��λ����

	uart_byte_count = 0;		// ���ֽڼ���

	g_sent_flag = true;	   		//�÷��ͱ�־
}

//******************************************************************
// ������	��void Uart_sent_data_Real(void)
// ����		��
// ����		����������ʵ��
// ����		����
// ����ֵ	����
// ����ȫ�ֱ�������
// �޸�ȫ�ֱ�������
// ��ע		��
//******************************************************************
void Uart_sent_data_Real(void)
{
	if(g_sent_flag)
	{
		if(uart_byte_count < g_data_length)
		{
			uart_sent_byte(g_sent_data[uart_byte_count]);
			if(uart_bit_count == 0)
			{
				uart_byte_count++;
			}
		}
		else
		{
			uart_byte_count = 0;
			g_sent_flag = false;

			ET1	= 	disable;					//�رն�ʱ���ж�	
			TR1	= 	disable;					//�رն�ʱ��
		}	
	}	
}

unsigned char  Uart_Is_Send_Over(void)
{
	if(g_sent_flag)
			return 1;
	else 
		return 0;
}

enum
	{
		UART_START,
		UART_DATA_ONE,
		UART_DATA,
		UART_STOP
	};



////////////////////////////////////////////////////////////////////////

#ifdef __UART_SEND_DATA__
char gUartSendChannel = 0; 

unsigned char  xdata UartBuf[120]= {59,0x31,0x32,0x33,0x34,0x35,0X0D,0X0A};


#define  BEGIN_CHANNEL_INDEX   0		//���ڼ�����Ч��ͨ��
#define  OUTPUT_CHANNEL_COUNT   8		// ���������ͨ�����ݣ� ���ÿ��4���� ����UartBuf�������

char SetUartData(void)
{
	char i;
	char index; 
	char result = 0; 
	i = 0; 

	index = 0; 
	
	
	gUartSendChannel = BEGIN_CHANNEL_INDEX; 

////// rawdata

for(index = 0; index < OUTPUT_CHANNEL_COUNT; index++)
{
	UartBuf[i++]  = 59;
	result = RawData[gUartSendChannel]/10000;	
	if(result != 0)
			UartBuf[i++] = result+0x30; 
						
	result = RawData[gUartSendChannel]%10000/1000; 
	UartBuf[i++] = result+0x30;
	
	result = RawData[gUartSendChannel]%1000/100;	
	UartBuf[i++] = result+0x30;
	
	result = RawData[gUartSendChannel]%100/10;	
	UartBuf[i++] = result+0x30;
	
	result = RawData[gUartSendChannel]%10;	
	UartBuf[i++] = result+0x30;

//// baseline;
	UartBuf[i++] = 59;

	result = BaseLine[gUartSendChannel]/10000;	
	if(result != 0)
				UartBuf[i++] = result+0x30; 
							
		result = BaseLine[gUartSendChannel]%10000/1000; 
		UartBuf[i++] = result+0x30;
		
		result = BaseLine[gUartSendChannel]%1000/100; 
		UartBuf[i++] = result+0x30;
		
		result = BaseLine[gUartSendChannel]%100/10;	
		UartBuf[i++] = result+0x30;
		
		result = BaseLine[gUartSendChannel]%10;	
		UartBuf[i++] = result+0x30;

		
		UartBuf[i++] = 59;
		
		gUartSendChannel ++;
}
////////////////////////////////////////////////////////////////////////////
	{
		UartBuf[i++] = 0x0d;
		UartBuf[i++] = 0x0a; 
		gUartSendChannel = BEGIN_CHANNEL_INDEX; 
	}

	return i; 

}

void UartSendTkData(void)
{
	if(Uart_Is_Send_Over() == 0)
	{
	    char i; 
		i = SetUartData(); 	
		Uart_sent_data(UartBuf,i);//i
	}
}


#endif 


#endif 


