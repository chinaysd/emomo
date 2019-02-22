
#define  __UART_SEND_DATA__		  //annie 					//用串口方式送数据


#ifdef __UART_SEND_DATA__
#include "..\sif\uart.h"
#include "..\sif\data_type.h"	
#include "..\sif\SC91F832_C.H"		
#include  "lib\SensorMethod.H"

/************************************************************************/
/* 静态局部变量定义                                            			 */
/************************************************************************/

BOOL m_sys_1ms;	 					//系统1ms时基

unsigned int g_100us_count;			//100us计数

#define  C_TX_OUTPUT		(BS(P1CFG1,4),BC(P1CFG1,5))    //p16
#define  C_RX_INPUT			(BC(P3CFG1,6),BS(P3CFG1,7))  	//p17

#define	UART_TXD  		P16			//发送口
#define UART_RXD		P17				//接收数据口


BOOL g_sent_flag;		//发送标志


/************************************************************************/
/* 内部函数声明                                                         */
/************************************************************************/

void Ini_Timer1(void);    //定时器1初始化
void Uart_sent_data(INT8U *t_data,INT8U t_data_length);	//发送数据

static void uart_sent_byte(INT8U t_byte);	//发送一个字节
static void Uart_sent_data_Real(void);	   //发送数据实体

void Uart_receive_data(void);


void InitUart(void)
{
	C_TX_OUTPUT;
	C_RX_INPUT;
	Ini_Timer1(); 
}


//******************************************************************
// 函数名	：void Ini_Timer1(void)  
// 作者		：
// 功能		：定时器1初始化
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：
// 备注		：
//******************************************************************

#define 	C_BAUD_BPS			9600	  		//波特率
#define		C_DELAY_TIME		(((10 * 1000) / C_BAUD_BPS) * 100) 		 // 延时时间 单位(us)		1s/波特率
#define     C_DELAY_TIME_COUNT	 ((C_DELAY_TIME * C_SYS_FOSC) / C_FREQ_DIV) //+ (C_DELAY_TIME * C_SYS_FOSC) % C_FREQ_DIV)		//(晶振值 × 定时时间 ÷ 分频值)
#define		C_T1_COUNT_H  		(65536 - C_DELAY_TIME_COUNT) / 256
#define 	C_T1_COUNT_L		(65536 - C_DELAY_TIME_COUNT) % 256


void Ini_Timer1(void)    
{
	TMOD	|=	C_T1_MODE_1;			//T1 工作方式1
	TMCON	|=  C_T1_CLK_4;    			//fsys=fosc/4设置为4分频率

	TH1	=	C_T1_COUNT_H;
	TL1	=	C_T1_COUNT_L;
	
	ET1	= 	disable;					//关闭定时器中断	
	TR1	= 	disable;					//关闭定时器
}



void Time1(void) interrupt TIMER_1_INTERRUPT
{
	TH1	=	C_T1_COUNT_H;
	TL1	=	C_T1_COUNT_L;

	Uart_sent_data_Real();	 	//发送数据
}	

//******************************************************************
// 函数名	：void uart_sent_byte(INT8U t_byte)
// 作者		：
// 功能		：发送一个字节
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
//******************************************************************

INT8U uart_bit_count;					//发送位计数
INT8U uart_sent_buff;					//发送缓存
void uart_sent_byte(INT8U t_byte)
{
	if(uart_bit_count == 0) 
	{
		UART_TXD = 0;	   		//先发起始位 0
		uart_bit_count++;				//计数
		uart_sent_buff = t_byte;
	}
	else if(uart_bit_count < 9)
	{
		UART_TXD = uart_sent_buff & 0x01;		//先发低位
		uart_sent_buff >>= 1;
		uart_bit_count++;						//计数
	}
	else
	{
		UART_TXD = 1;	   				    	//发终止位1
		uart_bit_count = 0;
	}	
}
//******************************************************************
// 函数名	：void Uart_sent_data(INT8U *t_data,INT8U t_data_length)
// 作者		：
// 功能		：发送数据
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：	1ms发送一个字节
//******************************************************************
INT8U *g_sent_data;		// 要发送的数据
INT8U g_data_length;	// 数据长度

INT8U uart_byte_count;				//发送字节计数

void Uart_sent_data(INT8U *t_data,INT8U t_data_length)
{
	ET1	= 	enable;					//开中断	
	TR1	= 	enable;					//开定时器

	g_sent_data = t_data;			  //数据

    g_data_length = t_data_length;	 //数据长度
	
	uart_bit_count = 0;			 //清位计数

	uart_byte_count = 0;		// 清字节计数

	g_sent_flag = true;	   		//置发送标志
}

//******************************************************************
// 函数名	：void Uart_sent_data_Real(void)
// 作者		：
// 功能		：发送数据实体
// 参数		：无
// 返回值	：无
// 调用全局变量：无
// 修改全局变量：无
// 备注		：
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

			ET1	= 	disable;					//关闭定时器中断	
			TR1	= 	disable;					//关闭定时器
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


#define  BEGIN_CHANNEL_INDEX   0		//检测第几个有效的通道
#define  OUTPUT_CHANNEL_COUNT   8		// 共输出几个通道数据， 大概每次4个， 大了UartBuf数组溢出

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


