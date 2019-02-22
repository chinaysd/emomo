#include "bsp_uart1.h"
#include "string.h"

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;
/*****************************************************
*�������ƣ�void Uart1_Init(uint Freq,unsigned long int baud)
*�������ܣ�Uart1�жϳ�ʼ��
*��ڲ�����Freq-��Ƶ��baud-������
*���ڲ�����Freq,baud
*****************************************************/
void Uart1_Init(unsigned int Freq)
{
	P1CON &= 0xF5;   //TX����Ϊǿ��������ߣ�RX����Ϊ���������
	P1PH  |= 0x0A;
	
	OTCON = 0xC0;    //���нӿ�SSIѡ��Uart1ͨ��
	SSCON0 = 0x50;   //����ͨ�ŷ�ʽΪģʽһ���������
	SSCON1 = Freq*1000000/baud;   //�����ʵ�λ����
	SSCON2 = (Freq*1000000/baud)>>8;   //�����ʸ�λ����
	IE1 = 0x01;      //����SSI�ж�
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

