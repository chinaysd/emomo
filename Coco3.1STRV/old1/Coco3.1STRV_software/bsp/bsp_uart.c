#include "bsp_uart.h"
#include "string.h"

unsigned char Uart1SendFlag,Uart1ReceiveFlag;
unsigned char Rev_String[REV_BUF_SIZE];

char Rev_Flag;

extern unsigned char Data;
extern char rev_cmp_flag;

/***************************************************接收数据的变量定义****************************************/
unsigned char Rev_Num,Rev_Sum;
unsigned int Temp;


void Uart_Init(unsigned char Freq,unsigned int baud)
{
    P1CON &= 0xF5;                     //TX设置为强推挽输出高，RX设置为输入带上拉
	P1PH  |= 0x0A;
	
	OTCON = 0xC0;                      //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;                     //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;        //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 = 0x01;                        //开启SSI中断     
}



/*************************************发送数据子函数*****************************************/

void Uart1_Buf_TX(unsigned char DATA)
{
	SSDAT = DATA;
	while(!Uart1SendFlag);
	Uart1SendFlag = 0;
}

unsigned char Send_Data(PROTOCOL_TX *p)
{
    unsigned char i;
    for(i = 0; i < BUF_SIZE; i++)
    {
      Uart1_Buf_TX(p->Buf[i]);
    }
    return 0;
}    

unsigned char Protocol_Send(unsigned char id,unsigned char addr,unsigned char TX_DATA)
{
  PROTOCOL_TX buf;
  memset(&buf,0,sizeof(buf));
  buf.Buf_Format.ID        = id;
  buf.Buf_Format.ADDR      = addr;
  buf.Buf_Format.DATA1     = TX_DATA;
  buf.Buf_Format.CHECKSUM  = (unsigned char)(buf.Buf_Format.ID + buf.Buf_Format.ADDR + buf.Buf_Format.DATA1);   
  return Send_Data(&buf);    
}

/******************************************接收子函数********************************************/

unsigned char Rev_Byte(void)
{
    return SSDAT;
}

unsigned char IF_REV_STRING(void)
{
  if(Rev_Num & 0x80)
  {
      Rev_Num = 0x00;
      return 1;
  }
  else 
  {
      return 0;
  }
}

void Serial_Rev_IQH(void)
{

	volatile unsigned char Res;
    Res = Rev_Byte();
	#if 0
	rev_buf[rev_num_] = Res;
	
	rev_num_ ++;
	
	if(rev_num_ ++ >= REV_BUF_SIZE-1){
		rev_num_ = 0;
		rev_cmp_flag = 1;
	}
	if(rev_num_ > 1){
		if(rev_buf[0] != 0xa5){
			rev_num_ = 0;
		}
	}
    #else
    if((Rev_Num & 0X80) == 0)
    {
        if(Rev_Num &0x40)
        {
        
            if(Res == 0xfb)
            {
               Rev_Num |= 0x80; 
                rev_cmp_flag = 1;
            }
            else
            {
               Rev_Num &= 0x00;
            }
        }
        else
        {
        	if(Rev_Num == 5){
	            if(Res == Rev_Sum)
	            {
	                Rev_Num |= 0x40;
	            }else{
					Rev_Num = 0;
				}
        	}
            Rev_String[Rev_Num] = Res;
            Rev_Num ++;
            Rev_Sum = (unsigned char)(Rev_String[0] + Rev_String[1] + Rev_String[2] + Rev_String[3] + Rev_String[4]); 
			if(Rev_String[0] != 0xA5)
            {
              Rev_Num = 0x00; 
              Rev_Sum = 0;
            }
        }
    }
	#endif
}

void Rev_Data_Handle(void)
{
   if(IF_REV_STRING())
   {
       Temp = (unsigned int)Get_32Bit(Rev_String[3],Rev_String[4]);     
       memset(&Rev_String,0,sizeof(Rev_String));
       switch (Temp)
       {
           case 0x0100:
                      Data = 0x00;
                      Rev_Flag = 1;
                      break;
           case 0x0101:
                      Data = OPEN;
                      Rev_Flag = 1;
                      break;
           case 0x0102:
                      Data = CLOSE;
                      Rev_Flag = 1;
                      break;
           case 0x0103:
                      Data = OPEN;
                      Rev_Flag = 1;
                      break;
           case 0x0104:
                      Data = HOME_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x0105:                         
                      Data = SLEEP_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x0106:
                      Data = WATCH_TV_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x0107:
                      Data = READING_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x0108:
                      Data = SET_SLEEP_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x0109:
                      Data = SET_WATCH_TV_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x010A:
                      Data = SET_READING_POSITION;
                      Rev_Flag = 1;
                      break;
           case 0x010B:
                      Data = HEAD_UP;
                      Rev_Flag = 1;
                      break;
           case 0x010C:
                      Data = HEAD_DOWN;
                      Rev_Flag = 1;
                      break;
           case 0x010D:
                      Data = LARBUM_UP;
                      Rev_Flag = 1;
                      break;
           case 0x010E:
                      Data = LARBUM_DOWN;
                      Rev_Flag = 1;
                      break;
           case 0x0201:
                      Data = FOOT_LIGHT_OPEN;
                      Rev_Flag = 1;
                      break;
           case 0x0200:
                      Data = FOOT_LIGHT_CLOSE;
                      Rev_Flag = 1;
                      break;
           case 0x0301:
                      Data = MASS_OPEN;
                      Rev_Flag = 1;
                      break;
           case 0x0300:
                      Data = MASS_CLOSE;
                      Rev_Flag = 1;
                      break;
           case 0x0401:
                      Data = HEAT_ON;
                      Rev_Flag = 1;
                      break;
           case 0x0402:
                      Data = HEAT_OFF;
                      Rev_Flag = 1;
                      break;
           default:
                      Data = 0x00;
                      break;
       }
   }       
}






