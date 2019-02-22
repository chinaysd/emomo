#ifndef _UART1_H_
#define _UART1_H_

#include "sc92f837x_c.h"

#define BUF_SIZE      4
#define Hight(x)      ((x>>8)&0xff)
#define Low(x)        ((x)&0xff)

#define Get_32bit(x,y)		((x << 8) | y) & 0XFFFF

#define baud     9600
#define IC_ADDR  0Xff
#define IC_ID    0X55
#define UNDATA   0X00

typedef struct
{
	unsigned char ADDR;
	unsigned char ID;
	unsigned char DATA1;
	//unsigned char DATA2;
	unsigned char CHECKSUM;
	//unsigned char STOP1;
	//unsigned char STOP2;
}
BUF_FORMAT_TX;

typedef union
{
	BUF_FORMAT_TX Buf_Format_t;
	unsigned char Buf[BUF_SIZE];
}
PROTOCOL_TX;


void Uart1_Init(unsigned int Freq);

void Uart1_Buf_TX(unsigned char DATA);

unsigned char Protocol_tx(unsigned char addr,unsigned char id,unsigned char TX_DATA);

//void BackCall_Uart1(unsigned int n,unsigned long int m,void (*ptr)(unsigned int,unsigned long int));
//void BackCall_Uart1(unsigned int Freq,unsigned long int baud,void (*ptr)(unsigned int,unsigned long int));
void BackCall_Uart1(unsigned int Freq,void (*ptr)(unsigned int));




#endif


