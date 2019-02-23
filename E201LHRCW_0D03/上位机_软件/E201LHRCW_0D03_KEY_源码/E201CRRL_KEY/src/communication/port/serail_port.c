#include "stm8s_conf.h"



/*
	@function : serial communicate initialize
*/
int Serial_Port_Init(unsigned char ID,unsigned long BaudRate){
	/* USART configured as follow:
        - BaudRate = BaudRate   
        - Word Length = 8 Bits
        - One Stop Bit
        - no parity
        - Receive and transmit enabled
        - UART Clock disabled
  */
  	if(ID == 1){	
		UART1_DeInit();
		UART1_Init(BaudRate, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
			UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE);
		UART1_ITConfig(UART1_IT_RXNE,DISABLE);
		UART1_ITConfig(UART1_IT_TXE, DISABLE);
		UART1_ClearFlag(UART1_FLAG_RXNE);
		UART1_Cmd(ENABLE);
	}else{
		return 0;
	}
	return 1;
}

u8  UART_SentByte(u8 data){
	while(UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET);
	UART1_SendData8((u8)data);
	return 1;
}

u8 UART_SentString(u8 *data,u16 len){
	u16 i=0;
	for(;i<len;i++){
		UART_SentByte(data[i]);
	}
	return 1;
}

u8 UART_RevByte(void){
	while(UART1_GetFlagStatus(UART1_FLAG_RXNE)==RESET);
	return (UART1_ReceiveData8());
}



