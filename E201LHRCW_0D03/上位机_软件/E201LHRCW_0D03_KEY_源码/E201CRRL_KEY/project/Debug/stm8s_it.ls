   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  33                     ; 50 INTERRUPT_HANDLER(NonHandledInterrupt, 25)
  33                     ; 51 {
  34                     	switch	.text
  35  0000               f_NonHandledInterrupt:
  39                     ; 55 }
  42  0000 80            	iret
  64                     ; 63 INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
  64                     ; 64 {
  65                     	switch	.text
  66  0001               f_TRAP_IRQHandler:
  70                     ; 68 }
  73  0001 80            	iret
  95                     ; 74 INTERRUPT_HANDLER(TLI_IRQHandler, 0)
  95                     ; 75 
  95                     ; 76 {
  96                     	switch	.text
  97  0002               f_TLI_IRQHandler:
 101                     ; 80 }
 104  0002 80            	iret
 126                     ; 87 INTERRUPT_HANDLER(AWU_IRQHandler, 1)
 126                     ; 88 {
 127                     	switch	.text
 128  0003               f_AWU_IRQHandler:
 132                     ; 92 }
 135  0003 80            	iret
 157                     ; 99 INTERRUPT_HANDLER(CLK_IRQHandler, 2)
 157                     ; 100 {
 158                     	switch	.text
 159  0004               f_CLK_IRQHandler:
 163                     ; 104 }
 166  0004 80            	iret
 189                     ; 111 INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
 189                     ; 112 {
 190                     	switch	.text
 191  0005               f_EXTI_PORTA_IRQHandler:
 195                     ; 116 }
 198  0005 80            	iret
 221                     ; 123 INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
 221                     ; 124 {
 222                     	switch	.text
 223  0006               f_EXTI_PORTB_IRQHandler:
 227                     ; 129 }
 230  0006 80            	iret
 253                     ; 136 INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
 253                     ; 137 {
 254                     	switch	.text
 255  0007               f_EXTI_PORTC_IRQHandler:
 259                     ; 142 }
 262  0007 80            	iret
 285                     ; 149 INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
 285                     ; 150 {
 286                     	switch	.text
 287  0008               f_EXTI_PORTD_IRQHandler:
 291                     ; 155 }
 294  0008 80            	iret
 317                     ; 162 INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
 317                     ; 163 {
 318                     	switch	.text
 319  0009               f_EXTI_PORTE_IRQHandler:
 323                     ; 175 }
 326  0009 80            	iret
 348                     ; 222 INTERRUPT_HANDLER(SPI_IRQHandler, 10)
 348                     ; 223 {
 349                     	switch	.text
 350  000a               f_SPI_IRQHandler:
 354                     ; 227 }
 357  000a 80            	iret
 380                     ; 234 INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
 380                     ; 235 {
 381                     	switch	.text
 382  000b               f_TIM1_UPD_OVF_TRG_BRK_IRQHandler:
 386                     ; 242 }
 389  000b 80            	iret
 412                     ; 249 INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
 412                     ; 250 {
 413                     	switch	.text
 414  000c               f_TIM1_CAP_COM_IRQHandler:
 418                     ; 254 }
 421  000c 80            	iret
 444                     ; 288  INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
 444                     ; 289 {
 445                     	switch	.text
 446  000d               f_TIM2_UPD_OVF_BRK_IRQHandler:
 450                     ; 291 }
 453  000d 80            	iret
 476                     ; 298  INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
 476                     ; 299 {
 477                     	switch	.text
 478  000e               f_TIM2_CAP_COM_IRQHandler:
 482                     ; 303 }
 485  000e 80            	iret
 508                     ; 340  INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
 508                     ; 341  {
 509                     	switch	.text
 510  000f               f_UART1_TX_IRQHandler:
 514                     ; 345  }
 517  000f 80            	iret
 540                     ; 352  INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
 540                     ; 353  {
 541                     	switch	.text
 542  0010               f_UART1_RX_IRQHandler:
 546                     ; 357  }
 549  0010 80            	iret
 571                     ; 365 INTERRUPT_HANDLER(I2C_IRQHandler, 19)
 571                     ; 366 {
 572                     	switch	.text
 573  0011               f_I2C_IRQHandler:
 577                     ; 370 }
 580  0011 80            	iret
 602                     ; 445  INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
 602                     ; 446  {
 603                     	switch	.text
 604  0012               f_ADC1_IRQHandler:
 608                     ; 450  }
 611  0012 80            	iret
 637                     ; 471  INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
 637                     ; 472  {
 638                     	switch	.text
 639  0013               f_TIM4_UPD_OVF_IRQHandler:
 641  0013 3b0002        	push	c_x+2
 642  0016 be00          	ldw	x,c_x
 643  0018 89            	pushw	x
 644  0019 3b0002        	push	c_y+2
 645  001c be00          	ldw	x,c_y
 646  001e 89            	pushw	x
 649                     ; 476 	TIM4_ClearFlag(TIM4_FLAG_UPDATE); 
 651  001f a601          	ld	a,#1
 652  0021 cd0000        	call	_TIM4_ClearFlag
 654                     ; 477   	TimeOutDet_DecHandle();
 656  0024 cd0000        	call	_TimeOutDet_DecHandle
 658                     ; 478 	System_TimeHandle();
 660  0027 cd0000        	call	_System_TimeHandle
 662                     ; 479  }
 665  002a 85            	popw	x
 666  002b bf00          	ldw	c_y,x
 667  002d 320002        	pop	c_y+2
 668  0030 85            	popw	x
 669  0031 bf00          	ldw	c_x,x
 670  0033 320002        	pop	c_x+2
 671  0036 80            	iret
 694                     ; 487 INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
 694                     ; 488 {
 695                     	switch	.text
 696  0037               f_EEPROM_EEC_IRQHandler:
 700                     ; 493 }
 703  0037 80            	iret
 715                     	xref	_System_TimeHandle
 716                     	xref	_TimeOutDet_DecHandle
 717                     	xdef	f_EEPROM_EEC_IRQHandler
 718                     	xdef	f_TIM4_UPD_OVF_IRQHandler
 719                     	xdef	f_ADC1_IRQHandler
 720                     	xdef	f_I2C_IRQHandler
 721                     	xdef	f_UART1_RX_IRQHandler
 722                     	xdef	f_UART1_TX_IRQHandler
 723                     	xdef	f_TIM2_CAP_COM_IRQHandler
 724                     	xdef	f_TIM2_UPD_OVF_BRK_IRQHandler
 725                     	xdef	f_TIM1_UPD_OVF_TRG_BRK_IRQHandler
 726                     	xdef	f_TIM1_CAP_COM_IRQHandler
 727                     	xdef	f_SPI_IRQHandler
 728                     	xdef	f_EXTI_PORTE_IRQHandler
 729                     	xdef	f_EXTI_PORTD_IRQHandler
 730                     	xdef	f_EXTI_PORTC_IRQHandler
 731                     	xdef	f_EXTI_PORTB_IRQHandler
 732                     	xdef	f_EXTI_PORTA_IRQHandler
 733                     	xdef	f_CLK_IRQHandler
 734                     	xdef	f_AWU_IRQHandler
 735                     	xdef	f_TLI_IRQHandler
 736                     	xdef	f_TRAP_IRQHandler
 737                     	xdef	f_NonHandledInterrupt
 738                     	xref	_TIM4_ClearFlag
 739                     	xref.b	c_x
 740                     	xref.b	c_y
 759                     	end
