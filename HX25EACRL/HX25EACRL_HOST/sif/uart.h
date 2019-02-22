#ifndef _S_TIMER_INTERRUPT_C_HEADER
#define _S_TIMER_INTERRUPT_C_HEADER

#define  __UART_SEND_DATA__							//�ô��ڷ�ʽ������


#ifdef __UART_SEND_DATA__

#include "sif\data_type.h"	

/************************************************************************/
/* �жϱ�־����                                                         */
/************************************************************************/

#define TIMER_0_INTERRUPT	1			//��ʱ��0
#define TIMER_1_INTERRUPT	3			//��ʱ��1

/************************************************************************/
/* ʱ������     ������ʽ1                                                  		 */
/************************************************************************/

#define C_SYS_FOSC			16					//ϵͳ���� 8M

#define C_FREQ_DIV			4					//ϵͳ��Ƶ��  4��Ƶ   

#define C_REGULAR_TIME		35				    //��ʱʱ��  ����λus��	  50us

#define C_ALL_COUNT			((C_REGULAR_TIME * C_SYS_FOSC) / C_FREQ_DIV + (C_REGULAR_TIME * C_SYS_FOSC) % C_FREQ_DIV)		//(����ֵ �� ��ʱʱ�� �� ��Ƶֵ)

#define C_HIGH_COUNT	 	(65536 - C_ALL_COUNT) / 256

#define C_LOW_COUNT			(65536 - C_ALL_COUNT) % 256



/************************************************************************/
/* ��ʱ��0��ʱʱ��    		   					                        */
/************************************************************************/

#define		C_T0_COUNT_L	C_LOW_COUNT		
#define		C_T0_COUNT_H	C_HIGH_COUNT		

/************************************************************************/
/*��ʱ������ģʽ����				                                               */
/************************************************************************/

#define 	C_TO_CLK_4	 		0x01		//TO����Ƶ�� 4��Ƶ
#define		C_TO_CLK_12			0x00		//TO����Ƶ�� 12��Ƶ

#define 	C_T1_CLK_4	 		0x02		//T1����Ƶ�� 4��Ƶ
#define		C_T1_CLK_12			0x00		//T1����Ƶ�� 12��Ƶ

#define     C_TO_MODE_0	 		0x00	 		//13λ��ʱ��
#define     C_TO_MODE_1			0x01		    //16λ��ʱ��
#define     C_TO_MODE_2			0x02			//8λ�Զ���װ
#define     C_TO_MODE_3			0x03			//TL0��TO������Ϊ��ʱ\������ TH0��T1��������ʱ��

#define     C_T1_MODE_0	 		(0x00 << 4)	 		//13λ��ʱ��
#define     C_T1_MODE_1			(0x01 << 4)		    //16λ��ʱ��
#define     C_T1_MODE_2			(0x02 << 4)			//8λ�Զ���װ
#define     C_T1_MODE_3			(0x03 << 4)			//ֹͣ����

//����ʱ������ GATE �� C/T��Ĭ��ֵ0
//GATE �� 0 �� TR �� 1 ʱ�򿪶�ʱ��
//C/T 0: ��ʱ�� ������Դ��Fosc��Ƶ  1�� ������

/************************************************************************/
/* �ⲿ���ú���                                                         */
/************************************************************************/

extern void Ini_Timer1(void) ;	 //��ʱ��1��ʼ��
extern void Uart_sent_data(INT8U *t_data,INT8U t_data_length);	//��������
extern void Uart_sent_1byte(INT8U t_data);
extern void get_data(void);

extern void InitUart(void); 
extern void UartSendTkData(void);


#endif 

#endif
