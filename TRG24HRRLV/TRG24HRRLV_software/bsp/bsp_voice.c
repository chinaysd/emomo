#include "bsp_voice.h"
#include "string.h"

extern unsigned char UartSendFlag;


static void Voice_Send_Byte(unsigned char voice_byte)
{
     SBUF = voice_byte;
     while(!UartSendFlag);
     UartSendFlag = 0;
}



static unsigned char Voice_Send_Data(VOICE_PROTOCOL *p)
{
     static unsigned char i;
     for(i = 0; i < VOICE_BUF_SIZE; i ++)
     {
         Voice_Send_Byte(p->VOICE_Buf[i]); 
     }
     return VOICE_SEND_SUCCESS;
}



unsigned char Voice_Protocol_Send(unsigned char voice_addr,unsigned char voice_id,unsigned int voice_data)
{
    VOICE_PROTOCOL voice_buf;
    memset(&voice_buf,0,sizeof(voice_buf));
    voice_buf.Voice_Data.VOICE_ADDR     = voice_addr;
    voice_buf.Voice_Data.VOICE_ID       = voice_id;

    voice_buf.Voice_Data.VOICE_TEST     = 0x00;
    voice_buf.Voice_Data.VOICE_DATA1    = VOICE_Hight(voice_data);
    voice_buf.Voice_Data.VOICE_DATA2    = VOICE_Low(voice_data);

    voice_buf.Voice_Data.VOICE_CHECKSUM = (unsigned char)(voice_buf.Voice_Data.VOICE_ADDR + voice_buf.Voice_Data.VOICE_ID + voice_buf.Voice_Data.VOICE_TEST + voice_buf.Voice_Data.VOICE_DATA1 + voice_buf.Voice_Data.VOICE_DATA2);
    voice_buf.Voice_Data.VOICE_STOP1    = 0xfb;

    return Voice_Send_Data(&voice_buf);
}

























