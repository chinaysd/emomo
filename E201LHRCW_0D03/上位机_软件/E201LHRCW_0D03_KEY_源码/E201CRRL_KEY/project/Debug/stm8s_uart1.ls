   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  32                     ; 46 void UART1_DeInit(void)
  32                     ; 47 {
  34                     	switch	.text
  35  0000               _UART1_DeInit:
  39                     ; 50     (void)UART1->SR;
  41  0000 c65230        	ld	a,21040
  42  0003 97            	ld	xl,a
  43                     ; 51     (void)UART1->DR;
  45  0004 c65231        	ld	a,21041
  46  0007 97            	ld	xl,a
  47                     ; 53     UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
  49  0008 725f5233      	clr	21043
  50                     ; 54     UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */
  52  000c 725f5232      	clr	21042
  53                     ; 56     UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
  55  0010 725f5234      	clr	21044
  56                     ; 57     UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
  58  0014 725f5235      	clr	21045
  59                     ; 58     UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
  61  0018 725f5236      	clr	21046
  62                     ; 59     UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
  64  001c 725f5237      	clr	21047
  65                     ; 60     UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */
  67  0020 725f5238      	clr	21048
  68                     ; 62     UART1->GTR = UART1_GTR_RESET_VALUE;
  70  0024 725f5239      	clr	21049
  71                     ; 63     UART1->PSCR = UART1_PSCR_RESET_VALUE;
  73  0028 725f523a      	clr	21050
  74                     ; 64 }
  77  002c 81            	ret
 380                     .const:	section	.text
 381  0000               L01:
 382  0000 00000064      	dc.l	100
 383                     ; 83 void UART1_Init(uint32_t BaudRate, UART1_WordLength_TypeDef WordLength, 
 383                     ; 84                 UART1_StopBits_TypeDef StopBits, UART1_Parity_TypeDef Parity, 
 383                     ; 85                 UART1_SyncMode_TypeDef SyncMode, UART1_Mode_TypeDef Mode)
 383                     ; 86 {
 384                     	switch	.text
 385  002d               _UART1_Init:
 387  002d 520c          	subw	sp,#12
 388       0000000c      OFST:	set	12
 391                     ; 87     uint32_t BaudRate_Mantissa = 0, BaudRate_Mantissa100 = 0;
 393  002f 96            	ldw	x,sp
 394  0030 1c0009        	addw	x,#OFST-3
 395  0033 cd0000        	call	c_ltor
 399  0036 96            	ldw	x,sp
 400  0037 1c0005        	addw	x,#OFST-7
 401  003a cd0000        	call	c_ltor
 403                     ; 90     assert_param(IS_UART1_BAUDRATE_OK(BaudRate));
 405                     ; 91     assert_param(IS_UART1_WORDLENGTH_OK(WordLength));
 407                     ; 92     assert_param(IS_UART1_STOPBITS_OK(StopBits));
 409                     ; 93     assert_param(IS_UART1_PARITY_OK(Parity));
 411                     ; 94     assert_param(IS_UART1_MODE_OK((uint8_t)Mode));
 413                     ; 95     assert_param(IS_UART1_SYNCMODE_OK((uint8_t)SyncMode));
 415                     ; 98     UART1->CR1 &= (uint8_t)(~UART1_CR1_M);  
 417  003d 72195234      	bres	21044,#4
 418                     ; 101     UART1->CR1 |= (uint8_t)WordLength;
 420  0041 c65234        	ld	a,21044
 421  0044 1a13          	or	a,(OFST+7,sp)
 422  0046 c75234        	ld	21044,a
 423                     ; 104     UART1->CR3 &= (uint8_t)(~UART1_CR3_STOP);  
 425  0049 c65236        	ld	a,21046
 426  004c a4cf          	and	a,#207
 427  004e c75236        	ld	21046,a
 428                     ; 106     UART1->CR3 |= (uint8_t)StopBits;  
 430  0051 c65236        	ld	a,21046
 431  0054 1a14          	or	a,(OFST+8,sp)
 432  0056 c75236        	ld	21046,a
 433                     ; 109     UART1->CR1 &= (uint8_t)(~(UART1_CR1_PCEN | UART1_CR1_PS  ));  
 435  0059 c65234        	ld	a,21044
 436  005c a4f9          	and	a,#249
 437  005e c75234        	ld	21044,a
 438                     ; 111     UART1->CR1 |= (uint8_t)Parity;  
 440  0061 c65234        	ld	a,21044
 441  0064 1a15          	or	a,(OFST+9,sp)
 442  0066 c75234        	ld	21044,a
 443                     ; 114     UART1->BRR1 &= (uint8_t)(~UART1_BRR1_DIVM);  
 445  0069 725f5232      	clr	21042
 446                     ; 116     UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVM);  
 448  006d c65233        	ld	a,21043
 449  0070 a40f          	and	a,#15
 450  0072 c75233        	ld	21043,a
 451                     ; 118     UART1->BRR2 &= (uint8_t)(~UART1_BRR2_DIVF);  
 453  0075 c65233        	ld	a,21043
 454  0078 a4f0          	and	a,#240
 455  007a c75233        	ld	21043,a
 456                     ; 121     BaudRate_Mantissa    = ((uint32_t)CLK_GetClockFreq() / (BaudRate << 4));
 458  007d 96            	ldw	x,sp
 459  007e 1c000f        	addw	x,#OFST+3
 460  0081 cd0000        	call	c_ltor
 462  0084 a604          	ld	a,#4
 463  0086 cd0000        	call	c_llsh
 465  0089 96            	ldw	x,sp
 466  008a 1c0001        	addw	x,#OFST-11
 467  008d cd0000        	call	c_rtol
 469  0090 cd0000        	call	_CLK_GetClockFreq
 471  0093 96            	ldw	x,sp
 472  0094 1c0001        	addw	x,#OFST-11
 473  0097 cd0000        	call	c_ludv
 475  009a 96            	ldw	x,sp
 476  009b 1c0009        	addw	x,#OFST-3
 477  009e cd0000        	call	c_rtol
 479                     ; 122     BaudRate_Mantissa100 = (((uint32_t)CLK_GetClockFreq() * 100) / (BaudRate << 4));
 481  00a1 96            	ldw	x,sp
 482  00a2 1c000f        	addw	x,#OFST+3
 483  00a5 cd0000        	call	c_ltor
 485  00a8 a604          	ld	a,#4
 486  00aa cd0000        	call	c_llsh
 488  00ad 96            	ldw	x,sp
 489  00ae 1c0001        	addw	x,#OFST-11
 490  00b1 cd0000        	call	c_rtol
 492  00b4 cd0000        	call	_CLK_GetClockFreq
 494  00b7 a664          	ld	a,#100
 495  00b9 cd0000        	call	c_smul
 497  00bc 96            	ldw	x,sp
 498  00bd 1c0001        	addw	x,#OFST-11
 499  00c0 cd0000        	call	c_ludv
 501  00c3 96            	ldw	x,sp
 502  00c4 1c0005        	addw	x,#OFST-7
 503  00c7 cd0000        	call	c_rtol
 505                     ; 124     UART1->BRR2 |= (uint8_t)((uint8_t)(((BaudRate_Mantissa100 - (BaudRate_Mantissa * 100)) << 4) / 100) & (uint8_t)0x0F); 
 507  00ca 96            	ldw	x,sp
 508  00cb 1c0009        	addw	x,#OFST-3
 509  00ce cd0000        	call	c_ltor
 511  00d1 a664          	ld	a,#100
 512  00d3 cd0000        	call	c_smul
 514  00d6 96            	ldw	x,sp
 515  00d7 1c0001        	addw	x,#OFST-11
 516  00da cd0000        	call	c_rtol
 518  00dd 96            	ldw	x,sp
 519  00de 1c0005        	addw	x,#OFST-7
 520  00e1 cd0000        	call	c_ltor
 522  00e4 96            	ldw	x,sp
 523  00e5 1c0001        	addw	x,#OFST-11
 524  00e8 cd0000        	call	c_lsub
 526  00eb a604          	ld	a,#4
 527  00ed cd0000        	call	c_llsh
 529  00f0 ae0000        	ldw	x,#L01
 530  00f3 cd0000        	call	c_ludv
 532  00f6 b603          	ld	a,c_lreg+3
 533  00f8 a40f          	and	a,#15
 534  00fa ca5233        	or	a,21043
 535  00fd c75233        	ld	21043,a
 536                     ; 126     UART1->BRR2 |= (uint8_t)((BaudRate_Mantissa >> 4) & (uint8_t)0xF0); 
 538  0100 96            	ldw	x,sp
 539  0101 1c0009        	addw	x,#OFST-3
 540  0104 cd0000        	call	c_ltor
 542  0107 a604          	ld	a,#4
 543  0109 cd0000        	call	c_lursh
 545  010c b603          	ld	a,c_lreg+3
 546  010e a4f0          	and	a,#240
 547  0110 b703          	ld	c_lreg+3,a
 548  0112 3f02          	clr	c_lreg+2
 549  0114 3f01          	clr	c_lreg+1
 550  0116 3f00          	clr	c_lreg
 551  0118 b603          	ld	a,c_lreg+3
 552  011a ca5233        	or	a,21043
 553  011d c75233        	ld	21043,a
 554                     ; 128     UART1->BRR1 |= (uint8_t)BaudRate_Mantissa;           
 556  0120 c65232        	ld	a,21042
 557  0123 1a0c          	or	a,(OFST+0,sp)
 558  0125 c75232        	ld	21042,a
 559                     ; 131     UART1->CR2 &= (uint8_t)~(UART1_CR2_TEN | UART1_CR2_REN); 
 561  0128 c65235        	ld	a,21045
 562  012b a4f3          	and	a,#243
 563  012d c75235        	ld	21045,a
 564                     ; 133     UART1->CR3 &= (uint8_t)~(UART1_CR3_CPOL | UART1_CR3_CPHA | UART1_CR3_LBCL); 
 566  0130 c65236        	ld	a,21046
 567  0133 a4f8          	and	a,#248
 568  0135 c75236        	ld	21046,a
 569                     ; 135     UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & (uint8_t)(UART1_CR3_CPOL | 
 569                     ; 136                                               UART1_CR3_CPHA | UART1_CR3_LBCL));  
 571  0138 7b16          	ld	a,(OFST+10,sp)
 572  013a a407          	and	a,#7
 573  013c ca5236        	or	a,21046
 574  013f c75236        	ld	21046,a
 575                     ; 138     if ((uint8_t)(Mode & UART1_MODE_TX_ENABLE))
 577  0142 7b17          	ld	a,(OFST+11,sp)
 578  0144 a504          	bcp	a,#4
 579  0146 2706          	jreq	L371
 580                     ; 141         UART1->CR2 |= (uint8_t)UART1_CR2_TEN;  
 582  0148 72165235      	bset	21045,#3
 584  014c 2004          	jra	L571
 585  014e               L371:
 586                     ; 146         UART1->CR2 &= (uint8_t)(~UART1_CR2_TEN);  
 588  014e 72175235      	bres	21045,#3
 589  0152               L571:
 590                     ; 148     if ((uint8_t)(Mode & UART1_MODE_RX_ENABLE))
 592  0152 7b17          	ld	a,(OFST+11,sp)
 593  0154 a508          	bcp	a,#8
 594  0156 2706          	jreq	L771
 595                     ; 151         UART1->CR2 |= (uint8_t)UART1_CR2_REN;  
 597  0158 72145235      	bset	21045,#2
 599  015c 2004          	jra	L102
 600  015e               L771:
 601                     ; 156         UART1->CR2 &= (uint8_t)(~UART1_CR2_REN);  
 603  015e 72155235      	bres	21045,#2
 604  0162               L102:
 605                     ; 160     if ((uint8_t)(SyncMode & UART1_SYNCMODE_CLOCK_DISABLE))
 607  0162 7b16          	ld	a,(OFST+10,sp)
 608  0164 a580          	bcp	a,#128
 609  0166 2706          	jreq	L302
 610                     ; 163         UART1->CR3 &= (uint8_t)(~UART1_CR3_CKEN); 
 612  0168 72175236      	bres	21046,#3
 614  016c 200a          	jra	L502
 615  016e               L302:
 616                     ; 167         UART1->CR3 |= (uint8_t)((uint8_t)SyncMode & UART1_CR3_CKEN);
 618  016e 7b16          	ld	a,(OFST+10,sp)
 619  0170 a408          	and	a,#8
 620  0172 ca5236        	or	a,21046
 621  0175 c75236        	ld	21046,a
 622  0178               L502:
 623                     ; 169 }
 626  0178 5b0c          	addw	sp,#12
 627  017a 81            	ret
 682                     ; 177 void UART1_Cmd(FunctionalState NewState)
 682                     ; 178 {
 683                     	switch	.text
 684  017b               _UART1_Cmd:
 688                     ; 179     if (NewState != DISABLE)
 690  017b 4d            	tnz	a
 691  017c 2706          	jreq	L532
 692                     ; 182         UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD); 
 694  017e 721b5234      	bres	21044,#5
 696  0182 2004          	jra	L732
 697  0184               L532:
 698                     ; 187         UART1->CR1 |= UART1_CR1_UARTD;  
 700  0184 721a5234      	bset	21044,#5
 701  0188               L732:
 702                     ; 189 }
 705  0188 81            	ret
 830                     ; 205 void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
 830                     ; 206 {
 831                     	switch	.text
 832  0189               _UART1_ITConfig:
 834  0189 89            	pushw	x
 835  018a 89            	pushw	x
 836       00000002      OFST:	set	2
 839                     ; 207     uint8_t uartreg = 0, itpos = 0x00;
 841  018b 7b01          	ld	a,(OFST-1,sp)
 842  018d 97            	ld	xl,a
 845  018e 7b02          	ld	a,(OFST+0,sp)
 846  0190 97            	ld	xl,a
 847                     ; 210     assert_param(IS_UART1_CONFIG_IT_OK(UART1_IT));
 849                     ; 211     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 851                     ; 214     uartreg = (uint8_t)((uint16_t)UART1_IT >> 0x08);
 853  0191 7b03          	ld	a,(OFST+1,sp)
 854  0193 6b01          	ld	(OFST-1,sp),a
 855                     ; 216     itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));
 857  0195 7b04          	ld	a,(OFST+2,sp)
 858  0197 a40f          	and	a,#15
 859  0199 5f            	clrw	x
 860  019a 97            	ld	xl,a
 861  019b a601          	ld	a,#1
 862  019d 5d            	tnzw	x
 863  019e 2704          	jreq	L61
 864  01a0               L02:
 865  01a0 48            	sll	a
 866  01a1 5a            	decw	x
 867  01a2 26fc          	jrne	L02
 868  01a4               L61:
 869  01a4 6b02          	ld	(OFST+0,sp),a
 870                     ; 218     if (NewState != DISABLE)
 872  01a6 0d07          	tnz	(OFST+5,sp)
 873  01a8 272a          	jreq	L713
 874                     ; 221         if (uartreg == 0x01)
 876  01aa 7b01          	ld	a,(OFST-1,sp)
 877  01ac a101          	cp	a,#1
 878  01ae 260a          	jrne	L123
 879                     ; 223             UART1->CR1 |= itpos;
 881  01b0 c65234        	ld	a,21044
 882  01b3 1a02          	or	a,(OFST+0,sp)
 883  01b5 c75234        	ld	21044,a
 885  01b8 2045          	jra	L133
 886  01ba               L123:
 887                     ; 225         else if (uartreg == 0x02)
 889  01ba 7b01          	ld	a,(OFST-1,sp)
 890  01bc a102          	cp	a,#2
 891  01be 260a          	jrne	L523
 892                     ; 227             UART1->CR2 |= itpos;
 894  01c0 c65235        	ld	a,21045
 895  01c3 1a02          	or	a,(OFST+0,sp)
 896  01c5 c75235        	ld	21045,a
 898  01c8 2035          	jra	L133
 899  01ca               L523:
 900                     ; 231             UART1->CR4 |= itpos;
 902  01ca c65237        	ld	a,21047
 903  01cd 1a02          	or	a,(OFST+0,sp)
 904  01cf c75237        	ld	21047,a
 905  01d2 202b          	jra	L133
 906  01d4               L713:
 907                     ; 237         if (uartreg == 0x01)
 909  01d4 7b01          	ld	a,(OFST-1,sp)
 910  01d6 a101          	cp	a,#1
 911  01d8 260b          	jrne	L333
 912                     ; 239             UART1->CR1 &= (uint8_t)(~itpos);
 914  01da 7b02          	ld	a,(OFST+0,sp)
 915  01dc 43            	cpl	a
 916  01dd c45234        	and	a,21044
 917  01e0 c75234        	ld	21044,a
 919  01e3 201a          	jra	L133
 920  01e5               L333:
 921                     ; 241         else if (uartreg == 0x02)
 923  01e5 7b01          	ld	a,(OFST-1,sp)
 924  01e7 a102          	cp	a,#2
 925  01e9 260b          	jrne	L733
 926                     ; 243             UART1->CR2 &= (uint8_t)(~itpos);
 928  01eb 7b02          	ld	a,(OFST+0,sp)
 929  01ed 43            	cpl	a
 930  01ee c45235        	and	a,21045
 931  01f1 c75235        	ld	21045,a
 933  01f4 2009          	jra	L133
 934  01f6               L733:
 935                     ; 247             UART1->CR4 &= (uint8_t)(~itpos);
 937  01f6 7b02          	ld	a,(OFST+0,sp)
 938  01f8 43            	cpl	a
 939  01f9 c45237        	and	a,21047
 940  01fc c75237        	ld	21047,a
 941  01ff               L133:
 942                     ; 251 }
 945  01ff 5b04          	addw	sp,#4
 946  0201 81            	ret
 982                     ; 258 void UART1_HalfDuplexCmd(FunctionalState NewState)
 982                     ; 259 {
 983                     	switch	.text
 984  0202               _UART1_HalfDuplexCmd:
 988                     ; 260     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 990                     ; 262     if (NewState != DISABLE)
 992  0202 4d            	tnz	a
 993  0203 2706          	jreq	L163
 994                     ; 264         UART1->CR5 |= UART1_CR5_HDSEL;  /**< UART1 Half Duplex Enable  */
 996  0205 72165238      	bset	21048,#3
 998  0209 2004          	jra	L363
 999  020b               L163:
1000                     ; 268         UART1->CR5 &= (uint8_t)~UART1_CR5_HDSEL; /**< UART1 Half Duplex Disable */
1002  020b 72175238      	bres	21048,#3
1003  020f               L363:
1004                     ; 270 }
1007  020f 81            	ret
1064                     ; 278 void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
1064                     ; 279 {
1065                     	switch	.text
1066  0210               _UART1_IrDAConfig:
1070                     ; 280     assert_param(IS_UART1_IRDAMODE_OK(UART1_IrDAMode));
1072                     ; 282     if (UART1_IrDAMode != UART1_IRDAMODE_NORMAL)
1074  0210 4d            	tnz	a
1075  0211 2706          	jreq	L314
1076                     ; 284         UART1->CR5 |= UART1_CR5_IRLP;
1078  0213 72145238      	bset	21048,#2
1080  0217 2004          	jra	L514
1081  0219               L314:
1082                     ; 288         UART1->CR5 &= ((uint8_t)~UART1_CR5_IRLP);
1084  0219 72155238      	bres	21048,#2
1085  021d               L514:
1086                     ; 290 }
1089  021d 81            	ret
1124                     ; 298 void UART1_IrDACmd(FunctionalState NewState)
1124                     ; 299 {
1125                     	switch	.text
1126  021e               _UART1_IrDACmd:
1130                     ; 302     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
1132                     ; 304     if (NewState != DISABLE)
1134  021e 4d            	tnz	a
1135  021f 2706          	jreq	L534
1136                     ; 307         UART1->CR5 |= UART1_CR5_IREN;
1138  0221 72125238      	bset	21048,#1
1140  0225 2004          	jra	L734
1141  0227               L534:
1142                     ; 312         UART1->CR5 &= ((uint8_t)~UART1_CR5_IREN);
1144  0227 72135238      	bres	21048,#1
1145  022b               L734:
1146                     ; 314 }
1149  022b 81            	ret
1208                     ; 323 void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
1208                     ; 324 {
1209                     	switch	.text
1210  022c               _UART1_LINBreakDetectionConfig:
1214                     ; 325     assert_param(IS_UART1_LINBREAKDETECTIONLENGTH_OK(UART1_LINBreakDetectionLength));
1216                     ; 327     if (UART1_LINBreakDetectionLength != UART1_LINBREAKDETECTIONLENGTH_10BITS)
1218  022c 4d            	tnz	a
1219  022d 2706          	jreq	L764
1220                     ; 329         UART1->CR4 |= UART1_CR4_LBDL;
1222  022f 721a5237      	bset	21047,#5
1224  0233 2004          	jra	L174
1225  0235               L764:
1226                     ; 333         UART1->CR4 &= ((uint8_t)~UART1_CR4_LBDL);
1228  0235 721b5237      	bres	21047,#5
1229  0239               L174:
1230                     ; 335 }
1233  0239 81            	ret
1268                     ; 343 void UART1_LINCmd(FunctionalState NewState)
1268                     ; 344 {
1269                     	switch	.text
1270  023a               _UART1_LINCmd:
1274                     ; 345     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
1276                     ; 347     if (NewState != DISABLE)
1278  023a 4d            	tnz	a
1279  023b 2706          	jreq	L115
1280                     ; 350         UART1->CR3 |= UART1_CR3_LINEN;
1282  023d 721c5236      	bset	21046,#6
1284  0241 2004          	jra	L315
1285  0243               L115:
1286                     ; 355         UART1->CR3 &= ((uint8_t)~UART1_CR3_LINEN);
1288  0243 721d5236      	bres	21046,#6
1289  0247               L315:
1290                     ; 357 }
1293  0247 81            	ret
1328                     ; 364 void UART1_SmartCardCmd(FunctionalState NewState)
1328                     ; 365 {
1329                     	switch	.text
1330  0248               _UART1_SmartCardCmd:
1334                     ; 366     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
1336                     ; 368     if (NewState != DISABLE)
1338  0248 4d            	tnz	a
1339  0249 2706          	jreq	L335
1340                     ; 371         UART1->CR5 |= UART1_CR5_SCEN;
1342  024b 721a5238      	bset	21048,#5
1344  024f 2004          	jra	L535
1345  0251               L335:
1346                     ; 376         UART1->CR5 &= ((uint8_t)(~UART1_CR5_SCEN));
1348  0251 721b5238      	bres	21048,#5
1349  0255               L535:
1350                     ; 378 }
1353  0255 81            	ret
1389                     ; 387 void UART1_SmartCardNACKCmd(FunctionalState NewState)
1389                     ; 388 {
1390                     	switch	.text
1391  0256               _UART1_SmartCardNACKCmd:
1395                     ; 389     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
1397                     ; 391     if (NewState != DISABLE)
1399  0256 4d            	tnz	a
1400  0257 2706          	jreq	L555
1401                     ; 394         UART1->CR5 |= UART1_CR5_NACK;
1403  0259 72185238      	bset	21048,#4
1405  025d 2004          	jra	L755
1406  025f               L555:
1407                     ; 399         UART1->CR5 &= ((uint8_t)~(UART1_CR5_NACK));
1409  025f 72195238      	bres	21048,#4
1410  0263               L755:
1411                     ; 401 }
1414  0263 81            	ret
1471                     ; 409 void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
1471                     ; 410 {
1472                     	switch	.text
1473  0264               _UART1_WakeUpConfig:
1477                     ; 411     assert_param(IS_UART1_WAKEUP_OK(UART1_WakeUp));
1479                     ; 413     UART1->CR1 &= ((uint8_t)~UART1_CR1_WAKE);
1481  0264 72175234      	bres	21044,#3
1482                     ; 414     UART1->CR1 |= (uint8_t)UART1_WakeUp;
1484  0268 ca5234        	or	a,21044
1485  026b c75234        	ld	21044,a
1486                     ; 415 }
1489  026e 81            	ret
1525                     ; 422 void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
1525                     ; 423 {
1526                     	switch	.text
1527  026f               _UART1_ReceiverWakeUpCmd:
1531                     ; 424     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
1533                     ; 426     if (NewState != DISABLE)
1535  026f 4d            	tnz	a
1536  0270 2706          	jreq	L526
1537                     ; 429         UART1->CR2 |= UART1_CR2_RWU;
1539  0272 72125235      	bset	21045,#1
1541  0276 2004          	jra	L726
1542  0278               L526:
1543                     ; 434         UART1->CR2 &= ((uint8_t)~UART1_CR2_RWU);
1545  0278 72135235      	bres	21045,#1
1546  027c               L726:
1547                     ; 436 }
1550  027c 81            	ret
1573                     ; 443 uint8_t UART1_ReceiveData8(void)
1573                     ; 444 {
1574                     	switch	.text
1575  027d               _UART1_ReceiveData8:
1579                     ; 445     return ((uint8_t)UART1->DR);
1581  027d c65231        	ld	a,21041
1584  0280 81            	ret
1618                     ; 453 uint16_t UART1_ReceiveData9(void)
1618                     ; 454 {
1619                     	switch	.text
1620  0281               _UART1_ReceiveData9:
1622  0281 89            	pushw	x
1623       00000002      OFST:	set	2
1626                     ; 455   uint16_t temp = 0;
1628  0282 5f            	clrw	x
1629  0283 1f01          	ldw	(OFST-1,sp),x
1630                     ; 457   temp = (uint16_t)(((uint16_t)( (uint16_t)UART1->CR1 & (uint16_t)UART1_CR1_R8)) << 1);
1632  0285 c65234        	ld	a,21044
1633  0288 5f            	clrw	x
1634  0289 a480          	and	a,#128
1635  028b 5f            	clrw	x
1636  028c 02            	rlwa	x,a
1637  028d 58            	sllw	x
1638  028e 1f01          	ldw	(OFST-1,sp),x
1639                     ; 458   return (uint16_t)( (((uint16_t) UART1->DR) | temp ) & ((uint16_t)0x01FF));
1641  0290 c65231        	ld	a,21041
1642  0293 5f            	clrw	x
1643  0294 97            	ld	xl,a
1644  0295 01            	rrwa	x,a
1645  0296 1a02          	or	a,(OFST+0,sp)
1646  0298 01            	rrwa	x,a
1647  0299 1a01          	or	a,(OFST-1,sp)
1648  029b 01            	rrwa	x,a
1649  029c 01            	rrwa	x,a
1650  029d a4ff          	and	a,#255
1651  029f 01            	rrwa	x,a
1652  02a0 a401          	and	a,#1
1653  02a2 01            	rrwa	x,a
1656  02a3 5b02          	addw	sp,#2
1657  02a5 81            	ret
1691                     ; 466 void UART1_SendData8(uint8_t Data)
1691                     ; 467 {
1692                     	switch	.text
1693  02a6               _UART1_SendData8:
1697                     ; 469     UART1->DR = Data;
1699  02a6 c75231        	ld	21041,a
1700                     ; 470 }
1703  02a9 81            	ret
1737                     ; 478 void UART1_SendData9(uint16_t Data)
1737                     ; 479 {
1738                     	switch	.text
1739  02aa               _UART1_SendData9:
1741  02aa 89            	pushw	x
1742       00000000      OFST:	set	0
1745                     ; 481     UART1->CR1 &= ((uint8_t)~UART1_CR1_T8);
1747  02ab 721d5234      	bres	21044,#6
1748                     ; 483     UART1->CR1 |= (uint8_t)(((uint8_t)(Data >> 2)) & UART1_CR1_T8);
1750  02af 54            	srlw	x
1751  02b0 54            	srlw	x
1752  02b1 9f            	ld	a,xl
1753  02b2 a440          	and	a,#64
1754  02b4 ca5234        	or	a,21044
1755  02b7 c75234        	ld	21044,a
1756                     ; 485     UART1->DR   = (uint8_t)(Data);
1758  02ba 7b02          	ld	a,(OFST+2,sp)
1759  02bc c75231        	ld	21041,a
1760                     ; 486 }
1763  02bf 85            	popw	x
1764  02c0 81            	ret
1787                     ; 493 void UART1_SendBreak(void)
1787                     ; 494 {
1788                     	switch	.text
1789  02c1               _UART1_SendBreak:
1793                     ; 495     UART1->CR2 |= UART1_CR2_SBK;
1795  02c1 72105235      	bset	21045,#0
1796                     ; 496 }
1799  02c5 81            	ret
1833                     ; 503 void UART1_SetAddress(uint8_t UART1_Address)
1833                     ; 504 {
1834                     	switch	.text
1835  02c6               _UART1_SetAddress:
1837  02c6 88            	push	a
1838       00000000      OFST:	set	0
1841                     ; 506     assert_param(IS_UART1_ADDRESS_OK(UART1_Address));
1843                     ; 509     UART1->CR4 &= ((uint8_t)~UART1_CR4_ADD);
1845  02c7 c65237        	ld	a,21047
1846  02ca a4f0          	and	a,#240
1847  02cc c75237        	ld	21047,a
1848                     ; 511     UART1->CR4 |= UART1_Address;
1850  02cf c65237        	ld	a,21047
1851  02d2 1a01          	or	a,(OFST+1,sp)
1852  02d4 c75237        	ld	21047,a
1853                     ; 512 }
1856  02d7 84            	pop	a
1857  02d8 81            	ret
1891                     ; 520 void UART1_SetGuardTime(uint8_t UART1_GuardTime)
1891                     ; 521 {
1892                     	switch	.text
1893  02d9               _UART1_SetGuardTime:
1897                     ; 523     UART1->GTR = UART1_GuardTime;
1899  02d9 c75239        	ld	21049,a
1900                     ; 524 }
1903  02dc 81            	ret
1937                     ; 548 void UART1_SetPrescaler(uint8_t UART1_Prescaler)
1937                     ; 549 {
1938                     	switch	.text
1939  02dd               _UART1_SetPrescaler:
1943                     ; 551     UART1->PSCR = UART1_Prescaler;
1945  02dd c7523a        	ld	21050,a
1946                     ; 552 }
1949  02e0 81            	ret
2092                     ; 560 FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
2092                     ; 561 {
2093                     	switch	.text
2094  02e1               _UART1_GetFlagStatus:
2096  02e1 89            	pushw	x
2097  02e2 88            	push	a
2098       00000001      OFST:	set	1
2101                     ; 562     FlagStatus status = RESET;
2103  02e3 0f01          	clr	(OFST+0,sp)
2104                     ; 565     assert_param(IS_UART1_FLAG_OK(UART1_FLAG));
2106                     ; 569     if (UART1_FLAG == UART1_FLAG_LBDF)
2108  02e5 a30210        	cpw	x,#528
2109  02e8 2610          	jrne	L7501
2110                     ; 571         if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
2112  02ea 9f            	ld	a,xl
2113  02eb c45237        	and	a,21047
2114  02ee 2706          	jreq	L1601
2115                     ; 574             status = SET;
2117  02f0 a601          	ld	a,#1
2118  02f2 6b01          	ld	(OFST+0,sp),a
2120  02f4 202b          	jra	L5601
2121  02f6               L1601:
2122                     ; 579             status = RESET;
2124  02f6 0f01          	clr	(OFST+0,sp)
2125  02f8 2027          	jra	L5601
2126  02fa               L7501:
2127                     ; 582     else if (UART1_FLAG == UART1_FLAG_SBK)
2129  02fa 1e02          	ldw	x,(OFST+1,sp)
2130  02fc a30101        	cpw	x,#257
2131  02ff 2611          	jrne	L7601
2132                     ; 584         if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
2134  0301 c65235        	ld	a,21045
2135  0304 1503          	bcp	a,(OFST+2,sp)
2136  0306 2706          	jreq	L1701
2137                     ; 587             status = SET;
2139  0308 a601          	ld	a,#1
2140  030a 6b01          	ld	(OFST+0,sp),a
2142  030c 2013          	jra	L5601
2143  030e               L1701:
2144                     ; 592             status = RESET;
2146  030e 0f01          	clr	(OFST+0,sp)
2147  0310 200f          	jra	L5601
2148  0312               L7601:
2149                     ; 597         if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
2151  0312 c65230        	ld	a,21040
2152  0315 1503          	bcp	a,(OFST+2,sp)
2153  0317 2706          	jreq	L7701
2154                     ; 600             status = SET;
2156  0319 a601          	ld	a,#1
2157  031b 6b01          	ld	(OFST+0,sp),a
2159  031d 2002          	jra	L5601
2160  031f               L7701:
2161                     ; 605             status = RESET;
2163  031f 0f01          	clr	(OFST+0,sp)
2164  0321               L5601:
2165                     ; 609     return status;
2167  0321 7b01          	ld	a,(OFST+0,sp)
2170  0323 5b03          	addw	sp,#3
2171  0325 81            	ret
2206                     ; 639 void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
2206                     ; 640 {
2207                     	switch	.text
2208  0326               _UART1_ClearFlag:
2212                     ; 641     assert_param(IS_UART1_CLEAR_FLAG_OK(UART1_FLAG));
2214                     ; 644     if (UART1_FLAG == UART1_FLAG_RXNE)
2216  0326 a30020        	cpw	x,#32
2217  0329 2606          	jrne	L1211
2218                     ; 646         UART1->SR = (uint8_t)~(UART1_SR_RXNE);
2220  032b 35df5230      	mov	21040,#223
2222  032f 2004          	jra	L3211
2223  0331               L1211:
2224                     ; 651         UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
2226  0331 72195237      	bres	21047,#4
2227  0335               L3211:
2228                     ; 653 }
2231  0335 81            	ret
2313                     ; 668 ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
2313                     ; 669 {
2314                     	switch	.text
2315  0336               _UART1_GetITStatus:
2317  0336 89            	pushw	x
2318  0337 89            	pushw	x
2319       00000002      OFST:	set	2
2322                     ; 670     ITStatus pendingbitstatus = RESET;
2324  0338 7b02          	ld	a,(OFST+0,sp)
2325  033a 97            	ld	xl,a
2326                     ; 671     uint8_t itpos = 0;
2328  033b 7b01          	ld	a,(OFST-1,sp)
2329  033d 97            	ld	xl,a
2330                     ; 672     uint8_t itmask1 = 0;
2332  033e 7b02          	ld	a,(OFST+0,sp)
2333  0340 97            	ld	xl,a
2334                     ; 673     uint8_t itmask2 = 0;
2336  0341 7b02          	ld	a,(OFST+0,sp)
2337  0343 97            	ld	xl,a
2338                     ; 674     uint8_t enablestatus = 0;
2340  0344 7b02          	ld	a,(OFST+0,sp)
2341  0346 97            	ld	xl,a
2342                     ; 677     assert_param(IS_UART1_GET_IT_OK(UART1_IT));
2344                     ; 680     itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));
2346  0347 7b04          	ld	a,(OFST+2,sp)
2347  0349 a40f          	and	a,#15
2348  034b 5f            	clrw	x
2349  034c 97            	ld	xl,a
2350  034d a601          	ld	a,#1
2351  034f 5d            	tnzw	x
2352  0350 2704          	jreq	L27
2353  0352               L47:
2354  0352 48            	sll	a
2355  0353 5a            	decw	x
2356  0354 26fc          	jrne	L47
2357  0356               L27:
2358  0356 6b01          	ld	(OFST-1,sp),a
2359                     ; 682     itmask1 = (uint8_t)((uint8_t)UART1_IT >> (uint8_t)4);
2361  0358 7b04          	ld	a,(OFST+2,sp)
2362  035a 4e            	swap	a
2363  035b a40f          	and	a,#15
2364  035d 6b02          	ld	(OFST+0,sp),a
2365                     ; 684     itmask2 = (uint8_t)((uint8_t)1 << itmask1);
2367  035f 7b02          	ld	a,(OFST+0,sp)
2368  0361 5f            	clrw	x
2369  0362 97            	ld	xl,a
2370  0363 a601          	ld	a,#1
2371  0365 5d            	tnzw	x
2372  0366 2704          	jreq	L67
2373  0368               L001:
2374  0368 48            	sll	a
2375  0369 5a            	decw	x
2376  036a 26fc          	jrne	L001
2377  036c               L67:
2378  036c 6b02          	ld	(OFST+0,sp),a
2379                     ; 688     if (UART1_IT == UART1_IT_PE)
2381  036e 1e03          	ldw	x,(OFST+1,sp)
2382  0370 a30100        	cpw	x,#256
2383  0373 261c          	jrne	L7611
2384                     ; 691         enablestatus = (uint8_t)((uint8_t)UART1->CR1 & itmask2);
2386  0375 c65234        	ld	a,21044
2387  0378 1402          	and	a,(OFST+0,sp)
2388  037a 6b02          	ld	(OFST+0,sp),a
2389                     ; 694         if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
2391  037c c65230        	ld	a,21040
2392  037f 1501          	bcp	a,(OFST-1,sp)
2393  0381 270a          	jreq	L1711
2395  0383 0d02          	tnz	(OFST+0,sp)
2396  0385 2706          	jreq	L1711
2397                     ; 697             pendingbitstatus = SET;
2399  0387 a601          	ld	a,#1
2400  0389 6b02          	ld	(OFST+0,sp),a
2402  038b 2041          	jra	L5711
2403  038d               L1711:
2404                     ; 702             pendingbitstatus = RESET;
2406  038d 0f02          	clr	(OFST+0,sp)
2407  038f 203d          	jra	L5711
2408  0391               L7611:
2409                     ; 706     else if (UART1_IT == UART1_IT_LBDF)
2411  0391 1e03          	ldw	x,(OFST+1,sp)
2412  0393 a30346        	cpw	x,#838
2413  0396 261c          	jrne	L7711
2414                     ; 709         enablestatus = (uint8_t)((uint8_t)UART1->CR4 & itmask2);
2416  0398 c65237        	ld	a,21047
2417  039b 1402          	and	a,(OFST+0,sp)
2418  039d 6b02          	ld	(OFST+0,sp),a
2419                     ; 711         if (((UART1->CR4 & itpos) != (uint8_t)0x00) && enablestatus)
2421  039f c65237        	ld	a,21047
2422  03a2 1501          	bcp	a,(OFST-1,sp)
2423  03a4 270a          	jreq	L1021
2425  03a6 0d02          	tnz	(OFST+0,sp)
2426  03a8 2706          	jreq	L1021
2427                     ; 714             pendingbitstatus = SET;
2429  03aa a601          	ld	a,#1
2430  03ac 6b02          	ld	(OFST+0,sp),a
2432  03ae 201e          	jra	L5711
2433  03b0               L1021:
2434                     ; 719             pendingbitstatus = RESET;
2436  03b0 0f02          	clr	(OFST+0,sp)
2437  03b2 201a          	jra	L5711
2438  03b4               L7711:
2439                     ; 725         enablestatus = (uint8_t)((uint8_t)UART1->CR2 & itmask2);
2441  03b4 c65235        	ld	a,21045
2442  03b7 1402          	and	a,(OFST+0,sp)
2443  03b9 6b02          	ld	(OFST+0,sp),a
2444                     ; 727         if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
2446  03bb c65230        	ld	a,21040
2447  03be 1501          	bcp	a,(OFST-1,sp)
2448  03c0 270a          	jreq	L7021
2450  03c2 0d02          	tnz	(OFST+0,sp)
2451  03c4 2706          	jreq	L7021
2452                     ; 730             pendingbitstatus = SET;
2454  03c6 a601          	ld	a,#1
2455  03c8 6b02          	ld	(OFST+0,sp),a
2457  03ca 2002          	jra	L5711
2458  03cc               L7021:
2459                     ; 735             pendingbitstatus = RESET;
2461  03cc 0f02          	clr	(OFST+0,sp)
2462  03ce               L5711:
2463                     ; 740     return  pendingbitstatus;
2465  03ce 7b02          	ld	a,(OFST+0,sp)
2468  03d0 5b04          	addw	sp,#4
2469  03d2 81            	ret
2505                     ; 768 void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
2505                     ; 769 {
2506                     	switch	.text
2507  03d3               _UART1_ClearITPendingBit:
2511                     ; 770     assert_param(IS_UART1_CLEAR_IT_OK(UART1_IT));
2513                     ; 773     if (UART1_IT == UART1_IT_RXNE)
2515  03d3 a30255        	cpw	x,#597
2516  03d6 2606          	jrne	L1321
2517                     ; 775         UART1->SR = (uint8_t)~(UART1_SR_RXNE);
2519  03d8 35df5230      	mov	21040,#223
2521  03dc 2004          	jra	L3321
2522  03de               L1321:
2523                     ; 780         UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
2525  03de 72195237      	bres	21047,#4
2526  03e2               L3321:
2527                     ; 782 }
2530  03e2 81            	ret
2543                     	xdef	_UART1_ClearITPendingBit
2544                     	xdef	_UART1_GetITStatus
2545                     	xdef	_UART1_ClearFlag
2546                     	xdef	_UART1_GetFlagStatus
2547                     	xdef	_UART1_SetPrescaler
2548                     	xdef	_UART1_SetGuardTime
2549                     	xdef	_UART1_SetAddress
2550                     	xdef	_UART1_SendBreak
2551                     	xdef	_UART1_SendData9
2552                     	xdef	_UART1_SendData8
2553                     	xdef	_UART1_ReceiveData9
2554                     	xdef	_UART1_ReceiveData8
2555                     	xdef	_UART1_ReceiverWakeUpCmd
2556                     	xdef	_UART1_WakeUpConfig
2557                     	xdef	_UART1_SmartCardNACKCmd
2558                     	xdef	_UART1_SmartCardCmd
2559                     	xdef	_UART1_LINCmd
2560                     	xdef	_UART1_LINBreakDetectionConfig
2561                     	xdef	_UART1_IrDACmd
2562                     	xdef	_UART1_IrDAConfig
2563                     	xdef	_UART1_HalfDuplexCmd
2564                     	xdef	_UART1_ITConfig
2565                     	xdef	_UART1_Cmd
2566                     	xdef	_UART1_Init
2567                     	xdef	_UART1_DeInit
2568                     	xref	_CLK_GetClockFreq
2569                     	xref.b	c_lreg
2570                     	xref.b	c_x
2589                     	xref	c_lursh
2590                     	xref	c_lsub
2591                     	xref	c_smul
2592                     	xref	c_ludv
2593                     	xref	c_rtol
2594                     	xref	c_llsh
2595                     	xref	c_ltor
2596                     	end
