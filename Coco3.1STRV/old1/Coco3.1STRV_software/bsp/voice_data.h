#ifndef _VOICE_DATA_H_
#define _VOICE_DATA_H_

#include "sc92f837x_c.h"

#define VOICE_BUF_SIZE      7
#define Hight(x)            (((x)>>8)&0xff)
#define Low(x)              (x)


typedef struct
{
    unsigned char ID;
    unsigned char ADDR;
    unsigned char ID_ADDR;
    unsigned char DATA1;
    unsigned char DATA2;
    unsigned char CHECKSUM;
    unsigned char STOP1;
}
VOICE_DATA_FORMAT_TX;

typedef union
{
   unsigned char Voice_Buf[VOICE_BUF_SIZE];
   VOICE_DATA_FORMAT_TX Voice_Data_Format;
}
VOICE_PROTOCOL_TX;


unsigned char Voice_Protocol_Send(unsigned char id,unsigned char addr,unsigned int voice_data_t);










#endif