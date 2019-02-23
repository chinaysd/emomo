   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  57                     ; 8 int Serial_Port_Init(unsigned char ID,unsigned long BaudRate){
  59                     	switch	.text
  60  0000               _Serial_Port_Init:
  62  0000 88            	push	a
  63       00000000      OFST:	set	0
  66                     ; 17   	if(ID == 1){	
  68  0001 a101          	cp	a,#1
  69  0003 263a          	jrne	L33
  70                     ; 18 		UART1_DeInit();
  72  0005 cd0000        	call	_UART1_DeInit
  74                     ; 19 		UART1_Init(BaudRate, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
  74                     ; 20 			UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TX_ENABLE);
  76  0008 4b04          	push	#4
  77  000a 4b80          	push	#128
  78  000c 4b00          	push	#0
  79  000e 4b00          	push	#0
  80  0010 4b00          	push	#0
  81  0012 1e0b          	ldw	x,(OFST+11,sp)
  82  0014 89            	pushw	x
  83  0015 1e0b          	ldw	x,(OFST+11,sp)
  84  0017 89            	pushw	x
  85  0018 cd0000        	call	_UART1_Init
  87  001b 5b09          	addw	sp,#9
  88                     ; 21 		UART1_ITConfig(UART1_IT_RXNE,DISABLE);
  90  001d 4b00          	push	#0
  91  001f ae0255        	ldw	x,#597
  92  0022 cd0000        	call	_UART1_ITConfig
  94  0025 84            	pop	a
  95                     ; 22 		UART1_ITConfig(UART1_IT_TXE, DISABLE);
  97  0026 4b00          	push	#0
  98  0028 ae0277        	ldw	x,#631
  99  002b cd0000        	call	_UART1_ITConfig
 101  002e 84            	pop	a
 102                     ; 23 		UART1_ClearFlag(UART1_FLAG_RXNE);
 104  002f ae0020        	ldw	x,#32
 105  0032 cd0000        	call	_UART1_ClearFlag
 107                     ; 24 		UART1_Cmd(ENABLE);
 109  0035 a601          	ld	a,#1
 110  0037 cd0000        	call	_UART1_Cmd
 113                     ; 28 	return 1;
 115  003a ae0001        	ldw	x,#1
 118  003d 84            	pop	a
 119  003e 81            	ret
 120  003f               L33:
 121                     ; 26 		return 0;
 123  003f 5f            	clrw	x
 126  0040 84            	pop	a
 127  0041 81            	ret
 163                     ; 31 u8  UART_SentByte(u8 data){
 164                     	switch	.text
 165  0042               _UART_SentByte:
 167  0042 88            	push	a
 168       00000000      OFST:	set	0
 171  0043               L75:
 172                     ; 32 	while(UART1_GetFlagStatus(UART1_FLAG_TXE)==RESET);
 174  0043 ae0080        	ldw	x,#128
 175  0046 cd0000        	call	_UART1_GetFlagStatus
 177  0049 4d            	tnz	a
 178  004a 27f7          	jreq	L75
 179                     ; 33 	UART1_SendData8((u8)data);
 181  004c 7b01          	ld	a,(OFST+1,sp)
 182  004e cd0000        	call	_UART1_SendData8
 184                     ; 34 	return 1;
 186  0051 a601          	ld	a,#1
 189  0053 5b01          	addw	sp,#1
 190  0055 81            	ret
 244                     ; 37 u8 UART_SentString(u8 *data,u16 len){
 245                     	switch	.text
 246  0056               _UART_SentString:
 248  0056 89            	pushw	x
 249  0057 89            	pushw	x
 250       00000002      OFST:	set	2
 253                     ; 38 	u16 i=0;
 255  0058 5f            	clrw	x
 256  0059 1f01          	ldw	(OFST-1,sp),x
 258  005b 200f          	jra	L511
 259  005d               L111:
 260                     ; 40 		UART_SentByte(data[i]);
 262  005d 1e03          	ldw	x,(OFST+1,sp)
 263  005f 72fb01        	addw	x,(OFST-1,sp)
 264  0062 f6            	ld	a,(x)
 265  0063 addd          	call	_UART_SentByte
 267                     ; 39 	for(;i<len;i++){
 269  0065 1e01          	ldw	x,(OFST-1,sp)
 270  0067 1c0001        	addw	x,#1
 271  006a 1f01          	ldw	(OFST-1,sp),x
 272  006c               L511:
 275  006c 1e01          	ldw	x,(OFST-1,sp)
 276  006e 1307          	cpw	x,(OFST+5,sp)
 277  0070 25eb          	jrult	L111
 278                     ; 42 	return 1;
 280  0072 a601          	ld	a,#1
 283  0074 5b04          	addw	sp,#4
 284  0076 81            	ret
 309                     ; 45 u8 UART_RevByte(void){
 310                     	switch	.text
 311  0077               _UART_RevByte:
 315  0077               L331:
 316                     ; 46 	while(UART1_GetFlagStatus(UART1_FLAG_RXNE)==RESET);
 318  0077 ae0020        	ldw	x,#32
 319  007a cd0000        	call	_UART1_GetFlagStatus
 321  007d 4d            	tnz	a
 322  007e 27f7          	jreq	L331
 323                     ; 47 	return (UART1_ReceiveData8());
 325  0080 cd0000        	call	_UART1_ReceiveData8
 329  0083 81            	ret
 342                     	xdef	_UART_RevByte
 343                     	xdef	_UART_SentString
 344                     	xdef	_UART_SentByte
 345                     	xdef	_Serial_Port_Init
 346                     	xref	_UART1_ClearFlag
 347                     	xref	_UART1_GetFlagStatus
 348                     	xref	_UART1_SendData8
 349                     	xref	_UART1_ReceiveData8
 350                     	xref	_UART1_ITConfig
 351                     	xref	_UART1_Cmd
 352                     	xref	_UART1_Init
 353                     	xref	_UART1_DeInit
 372                     	end
