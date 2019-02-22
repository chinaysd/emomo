#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "stm8s.h"
#define SIZE_BUF    7
#define Get_32bit(x,y)     ((((x) << 8)|y)&0xffff)

typedef struct
{
  uint8_t ADDR;
  uint8_t ID;
  uint8_t DATA1;
  uint8_t DATA2;
  uint8_t CHECKSUM;
  uint8_t STOP1;
  uint8_t STOP2;
}
REV_FORMAT_R;

typedef union
{
  REV_FORMAT_R Rev_Format_r;
  uint8_t buf[SIZE_BUF];
}
PROCOTOL_BUF_R;




void Uart_Init(void);
uint8_t Serial_Get_Status(void);
void Serial_Rev_IQH(void);


#endif