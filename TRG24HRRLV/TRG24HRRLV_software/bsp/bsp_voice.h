#ifndef _BSP_VOICE_H_
#define _BSP_VOICE_H_

#include "sc92f732x_c.h"

#define VOICE_SEND_SUCCESS     0
#define VOICE_SEND_ERROR       1

#define      VOICE_BUF_SIZE      7

#define      VOICE_Hight(x)      (((x)>>8)&0xff)
#define      VOICE_Low(x)        ((x)&0xff)


typedef struct
{
    unsigned char VOICE_ADDR;
    unsigned char VOICE_ID;
    unsigned char VOICE_TEST;
    unsigned char VOICE_DATA1;
    unsigned char VOICE_DATA2;
    unsigned char VOICE_CHECKSUM;
    unsigned char VOICE_STOP1;
}
VOICE_DATA_PARA;

typedef union
{
   unsigned char VOICE_Buf[VOICE_BUF_SIZE];
   VOICE_DATA_PARA Voice_Data;
}
VOICE_PROTOCOL;









unsigned char Voice_Protocol_Send(unsigned char voice_addr,unsigned char voice_id,unsigned int voice_data);










#endif


