#include "bsp_uart1.h"
#include "string.h"

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;
/*****************************************************
*函数名称：void Uart1_Init(uint Freq,unsigned long int baud)
*函数功能：Uart1中断初始化
*入口参数：Freq-主频，baud-波特率
*出口参数：Freq,baud
*****************************************************/
void Uart1_Init(unsigned int Freq)
{
	P1CON &= 0xF5;   //TX设置为强推挽输出高，RX设置为输入带上拉
	P1PH  |= 0x0A;
	
	OTCON = 0xC0;    //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;   //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;   //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 = 0x01;      //开启SSI中断
}

void BackCall_Uart1(unsigned int Freq,void (*ptr)(unsigned int))
{
	(*ptr)(Freq);
}

void Uart1_Buf_TX(unsigned char DATA)
{
	SSDAT = DATA;
	while(!Uart1SendFlag);
	Uart1SendFlag = 0;
}

unsigned char Send_Data(PROTOCOL_TX *p)
{
	unsigned char i;
	for(i = 0 ;i < BUF_SIZE; i++)
	{
		Uart1_Buf_TX(p->Buf[i]);
	}
	return 1;
}

unsigned char Protocol_tx(unsigned char addr,unsigned char id,unsigned char TX_DATA)
{
	PROTOCOL_TX buf;
	memset(&buf,0,sizeof(buf));
	buf.Buf_Format_t.ADDR       = addr;
	buf.Buf_Format_t.ID         = id;
	buf.Buf_Format_t.DATA1      = TX_DATA;//Hight(TX_DATA);
	//buf.Buf_Format_t.DATA2      = Low(TX_DATA);
	buf.Buf_Format_t.CHECKSUM   = (unsigned char)(buf.Buf_Format_t.ADDR + buf.Buf_Format_t.ID + buf.Buf_Format_t.DATA1/* + buf.Buf_Format_t.DATA2*/);
	//buf.Buf_Format_t.STOP1      = 0x0d;
	//buf.Buf_Format_t.STOP2      = 0x0a;
  return Send_Data(&buf);
}

