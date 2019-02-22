#include "voice_data.h"
#include "string.h"

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;

void Voice_Send_Byte(unsigned char voice_byte)
{
    SSDAT = voice_byte;
    while(!Uart1SendFlag);
	Uart1SendFlag = 0;
}


unsigned char Voice_Send_Data(VOICE_PROTOCOL_TX *p)
{
    static unsigned char i;
    for(i = 0 ; i < VOICE_BUF_SIZE; i ++)
    {
       Voice_Send_Byte(p->Voice_Buf[i]); 
    }
    return 0;
}


unsigned char Voice_Protocol_Send(unsigned char id,unsigned char addr,unsigned int voice_data_t)
{
    VOICE_PROTOCOL_TX voice_buf;
    memset(&voice_buf,0,sizeof(voice_buf));
    voice_buf.Voice_Data_Format.ID         =    id;
    voice_buf.Voice_Data_Format.ADDR       =    addr;
    voice_buf.Voice_Data_Format.ID_ADDR    =    0x00;
    voice_buf.Voice_Data_Format.DATA1      =    Hight(voice_data_t);
    voice_buf.Voice_Data_Format.DATA2      =    Low(voice_data_t);
    voice_buf.Voice_Data_Format.CHECKSUM   =    (unsigned char)(voice_buf.Voice_Data_Format.ID+voice_buf.Voice_Data_Format.ADDR+voice_buf.Voice_Data_Format.ID_ADDR+voice_buf.Voice_Data_Format.DATA1+voice_buf.Voice_Data_Format.DATA2);
    voice_buf.Voice_Data_Format.STOP1      =    0xfb;
    return  Voice_Send_Data(&voice_buf);
}



