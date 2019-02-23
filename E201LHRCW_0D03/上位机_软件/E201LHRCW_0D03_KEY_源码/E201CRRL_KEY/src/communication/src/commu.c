#include "commu.h"

int Commu_Init(void){
	extern int Serial_Port_Init(unsigned char ID,unsigned long BaudRate);

	return Serial_Port_Init(1,(unsigned long)9600);
}

int Commu_Sent(COMMU_BUF_t *p){
	extern unsigned char Serial_SentByte(unsigned char data);
	char i ;
	for(i = 0;i < BUF_SIZE;i ++)
		Serial_SentByte(p->Buf[i]);
	return 1;
}




