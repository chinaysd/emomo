#include "bsp_uart.h"

PROCOTOL_BUF_R Rev_Para;

uint8_t res_num,My_KeyValue;

void Uart_Init(void)
{
  UART1_DeInit();
  UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
  UART1_Cmd(ENABLE);
}

uint8_t Serial_Get_Status(void)
{
  if(res_num & 0x80)
  {
    res_num = 0;
    return 1;
  }
  else
  {
    return 0;
  }
}

void Serial_Rev_IQH(void)
{
  My_KeyValue = UART1_ReceiveData8();
  //while(UART1_GetITStatus(UART1_IT_RXNE) == SET);
  if((res_num & 0x80) == 0)
  {
    if(res_num & 0x40)
    {
      if(My_KeyValue == 0x0a)
      {
        res_num |= 0x80;
      }
      else
      {
        res_num = 0;
      }
    }
    else
    {
      if(My_KeyValue == 0x0d)
      {
        res_num |= 0x40;
      }
      else
      {
        Rev_Para.buf[res_num] = My_KeyValue;
        res_num ++;
        if(Rev_Para.buf[0] != 0x01)
        {
          res_num = 0;
        }
        if(res_num > SIZE_BUF)
        {
          res_num = 0;
        }
      }
    }
  }
}




