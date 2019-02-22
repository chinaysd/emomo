#ifndef _S_TIMER_INTERRUPT_C_HEADER
#define _S_TIMER_INTERRUPT_C_HEADER

#define  __UART_SEND_DATA__							//用串口方式送数据


#ifdef __UART_SEND_DATA__

#include "sif\data_type.h"	

/************************************************************************/
/* 中断标志声明                                                         */
/************************************************************************/

#define TIMER_0_INTERRUPT	1			//定时器0
#define TIMER_1_INTERRUPT	3			//定时器1

/************************************************************************/
/* 时钟配置     工作方式1                                                  		 */
/************************************************************************/

#define C_SYS_FOSC			16					//系统晶振 8M

#define C_FREQ_DIV			4					//系统分频比  4分频   

#define C_REGULAR_TIME		35				    //定时时间  （单位us）	  50us

#define C_ALL_COUNT			((C_REGULAR_TIME * C_SYS_FOSC) / C_FREQ_DIV + (C_REGULAR_TIME * C_SYS_FOSC) % C_FREQ_DIV)		//(晶振值 × 定时时间 ÷ 分频值)

#define C_HIGH_COUNT	 	(65536 - C_ALL_COUNT) / 256

#define C_LOW_COUNT			(65536 - C_ALL_COUNT) % 256



/************************************************************************/
/* 定时器0定时时间    		   					                        */
/************************************************************************/

#define		C_T0_COUNT_L	C_LOW_COUNT		
#define		C_T0_COUNT_H	C_HIGH_COUNT		

/************************************************************************/
/*定时器工作模式配置				                                               */
/************************************************************************/

#define 	C_TO_CLK_4	 		0x01		//TO输入频率 4分频
#define		C_TO_CLK_12			0x00		//TO输入频率 12分频

#define 	C_T1_CLK_4	 		0x02		//T1输入频率 4分频
#define		C_T1_CLK_12			0x00		//T1输入频率 12分频

#define     C_TO_MODE_0	 		0x00	 		//13位定时器
#define     C_TO_MODE_1			0x01		    //16位定时器
#define     C_TO_MODE_2			0x02			//8位自动重装
#define     C_TO_MODE_3			0x03			//TL0由TO控制作为定时\计数器 TH0由T1控制做定时器

#define     C_T1_MODE_0	 		(0x00 << 4)	 		//13位定时器
#define     C_T1_MODE_1			(0x01 << 4)		    //16位定时器
#define     C_T1_MODE_2			(0x02 << 4)			//8位自动重装
#define     C_T1_MODE_3			(0x03 << 4)			//停止计数

//做定时器来讲 GATE 及 C/T都默认值0
//GATE 置 0 且 TR 置 1 时打开定时器
//C/T 0: 定时器 计数来源于Fosc分频  1： 计数器

/************************************************************************/
/* 外部调用函数                                                         */
/************************************************************************/

extern void Ini_Timer1(void) ;	 //定时器1初始化
extern void Uart_sent_data(INT8U *t_data,INT8U t_data_length);	//发送数据
extern void Uart_sent_1byte(INT8U t_data);
extern void get_data(void);

extern void InitUart(void); 
extern void UartSendTkData(void);


#endif 

#endif
