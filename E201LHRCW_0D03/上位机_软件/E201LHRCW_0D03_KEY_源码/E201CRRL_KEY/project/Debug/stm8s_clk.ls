   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
   4                     .const:	section	.text
   5  0000               _HSIDivFactor:
   6  0000 01            	dc.b	1
   7  0001 02            	dc.b	2
   8  0002 04            	dc.b	4
   9  0003 08            	dc.b	8
  10  0004               _CLKPrescTable:
  11  0004 01            	dc.b	1
  12  0005 02            	dc.b	2
  13  0006 04            	dc.b	4
  14  0007 08            	dc.b	8
  15  0008 0a            	dc.b	10
  16  0009 10            	dc.b	16
  17  000a 14            	dc.b	20
  18  000b 28            	dc.b	40
  47                     ; 67 void CLK_DeInit(void)
  47                     ; 68 {
  49                     	switch	.text
  50  0000               _CLK_DeInit:
  54                     ; 70     CLK->ICKR = CLK_ICKR_RESET_VALUE;
  56  0000 350150c0      	mov	20672,#1
  57                     ; 71     CLK->ECKR = CLK_ECKR_RESET_VALUE;
  59  0004 725f50c1      	clr	20673
  60                     ; 72     CLK->SWR  = CLK_SWR_RESET_VALUE;
  62  0008 35e150c4      	mov	20676,#225
  63                     ; 73     CLK->SWCR = CLK_SWCR_RESET_VALUE;
  65  000c 725f50c5      	clr	20677
  66                     ; 74     CLK->CKDIVR = CLK_CKDIVR_RESET_VALUE;
  68  0010 351850c6      	mov	20678,#24
  69                     ; 75     CLK->PCKENR1 = CLK_PCKENR1_RESET_VALUE;
  71  0014 35ff50c7      	mov	20679,#255
  72                     ; 76     CLK->PCKENR2 = CLK_PCKENR2_RESET_VALUE;
  74  0018 35ff50ca      	mov	20682,#255
  75                     ; 77     CLK->CSSR = CLK_CSSR_RESET_VALUE;
  77  001c 725f50c8      	clr	20680
  78                     ; 78     CLK->CCOR = CLK_CCOR_RESET_VALUE;
  80  0020 725f50c9      	clr	20681
  82  0024               L52:
  83                     ; 79     while ((CLK->CCOR & CLK_CCOR_CCOEN)!= 0)
  85  0024 c650c9        	ld	a,20681
  86  0027 a501          	bcp	a,#1
  87  0029 26f9          	jrne	L52
  88                     ; 81     CLK->CCOR = CLK_CCOR_RESET_VALUE;
  90  002b 725f50c9      	clr	20681
  91                     ; 82     CLK->HSITRIMR = CLK_HSITRIMR_RESET_VALUE;
  93  002f 725f50cc      	clr	20684
  94                     ; 83     CLK->SWIMCCR = CLK_SWIMCCR_RESET_VALUE;
  96  0033 725f50cd      	clr	20685
  97                     ; 85 }
 100  0037 81            	ret
 238                     ; 424 void CLK_HSIPrescalerConfig(CLK_Prescaler_TypeDef HSIPrescaler)
 238                     ; 425 {
 239                     	switch	.text
 240  0038               _CLK_HSIPrescalerConfig:
 242  0038 88            	push	a
 243       00000000      OFST:	set	0
 246                     ; 428     assert_param(IS_CLK_HSIPRESCALER_OK(HSIPrescaler));
 248                     ; 431     CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
 250  0039 c650c6        	ld	a,20678
 251  003c a4e7          	and	a,#231
 252  003e c750c6        	ld	20678,a
 253                     ; 434     CLK->CKDIVR |= (uint8_t)HSIPrescaler;
 255  0041 c650c6        	ld	a,20678
 256  0044 1a01          	or	a,(OFST+1,sp)
 257  0046 c750c6        	ld	20678,a
 258                     ; 436 }
 261  0049 84            	pop	a
 262  004a 81            	ret
 297                     ; 517 void CLK_SYSCLKConfig(CLK_Prescaler_TypeDef CLK_Prescaler)
 297                     ; 518 {
 298                     	switch	.text
 299  004b               _CLK_SYSCLKConfig:
 301  004b 88            	push	a
 302       00000000      OFST:	set	0
 305                     ; 523     if (((uint8_t)CLK_Prescaler & (uint8_t)0x80) == 0x00) /* Bit7 = 0 means HSI divider */
 307  004c a580          	bcp	a,#128
 308  004e 2614          	jrne	L121
 309                     ; 525         CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_HSIDIV);
 311  0050 c650c6        	ld	a,20678
 312  0053 a4e7          	and	a,#231
 313  0055 c750c6        	ld	20678,a
 314                     ; 526         CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_HSIDIV);
 316  0058 7b01          	ld	a,(OFST+1,sp)
 317  005a a418          	and	a,#24
 318  005c ca50c6        	or	a,20678
 319  005f c750c6        	ld	20678,a
 321  0062 2012          	jra	L321
 322  0064               L121:
 323                     ; 530         CLK->CKDIVR &= (uint8_t)(~CLK_CKDIVR_CPUDIV);
 325  0064 c650c6        	ld	a,20678
 326  0067 a4f8          	and	a,#248
 327  0069 c750c6        	ld	20678,a
 328                     ; 531         CLK->CKDIVR |= (uint8_t)((uint8_t)CLK_Prescaler & (uint8_t)CLK_CKDIVR_CPUDIV);
 330  006c 7b01          	ld	a,(OFST+1,sp)
 331  006e a407          	and	a,#7
 332  0070 ca50c6        	or	a,20678
 333  0073 c750c6        	ld	20678,a
 334  0076               L321:
 335                     ; 534 }
 338  0076 84            	pop	a
 339  0077 81            	ret
 429                     ; 592 uint32_t CLK_GetClockFreq(void)
 429                     ; 593 {
 430                     	switch	.text
 431  0078               _CLK_GetClockFreq:
 433  0078 5209          	subw	sp,#9
 434       00000009      OFST:	set	9
 437                     ; 595     uint32_t clockfrequency = 0;
 439  007a 96            	ldw	x,sp
 440  007b 1c0005        	addw	x,#OFST-4
 441  007e cd0000        	call	c_ltor
 443                     ; 596     CLK_Source_TypeDef clocksource = CLK_SOURCE_HSI;
 445  0081 7b09          	ld	a,(OFST+0,sp)
 446  0083 97            	ld	xl,a
 447                     ; 597     uint8_t tmp = 0, presc = 0;
 449  0084 7b09          	ld	a,(OFST+0,sp)
 450  0086 97            	ld	xl,a
 453  0087 7b09          	ld	a,(OFST+0,sp)
 454  0089 97            	ld	xl,a
 455                     ; 600     clocksource = (CLK_Source_TypeDef)CLK->CMSR;
 457  008a c650c3        	ld	a,20675
 458  008d 6b09          	ld	(OFST+0,sp),a
 459                     ; 602     if (clocksource == CLK_SOURCE_HSI)
 461  008f 7b09          	ld	a,(OFST+0,sp)
 462  0091 a1e1          	cp	a,#225
 463  0093 2642          	jrne	L171
 464                     ; 604         tmp = (uint8_t)(CLK->CKDIVR & CLK_CKDIVR_HSIDIV);
 466  0095 c650c6        	ld	a,20678
 467  0098 a418          	and	a,#24
 468  009a 6b09          	ld	(OFST+0,sp),a
 469                     ; 605         tmp = (uint8_t)(tmp >> 3);
 471  009c 7b09          	ld	a,(OFST+0,sp)
 472  009e 44            	srl	a
 473  009f 44            	srl	a
 474  00a0 44            	srl	a
 475  00a1 6b09          	ld	(OFST+0,sp),a
 476                     ; 606         presc = HSIDivFactor[tmp];
 478  00a3 7b09          	ld	a,(OFST+0,sp)
 479  00a5 5f            	clrw	x
 480  00a6 97            	ld	xl,a
 481  00a7 d60000        	ld	a,(_HSIDivFactor,x)
 482  00aa 6b09          	ld	(OFST+0,sp),a
 483                     ; 607         clockfrequency = HSI_VALUE / presc;
 485  00ac 7b09          	ld	a,(OFST+0,sp)
 486  00ae b703          	ld	c_lreg+3,a
 487  00b0 3f02          	clr	c_lreg+2
 488  00b2 3f01          	clr	c_lreg+1
 489  00b4 3f00          	clr	c_lreg
 490  00b6 96            	ldw	x,sp
 491  00b7 1c0001        	addw	x,#OFST-8
 492  00ba cd0000        	call	c_rtol
 494  00bd ae2400        	ldw	x,#9216
 495  00c0 bf02          	ldw	c_lreg+2,x
 496  00c2 ae00f4        	ldw	x,#244
 497  00c5 bf00          	ldw	c_lreg,x
 498  00c7 96            	ldw	x,sp
 499  00c8 1c0001        	addw	x,#OFST-8
 500  00cb cd0000        	call	c_ludv
 502  00ce 96            	ldw	x,sp
 503  00cf 1c0005        	addw	x,#OFST-4
 504  00d2 cd0000        	call	c_rtol
 507  00d5 201c          	jra	L371
 508  00d7               L171:
 509                     ; 609     else if ( clocksource == CLK_SOURCE_LSI)
 511  00d7 7b09          	ld	a,(OFST+0,sp)
 512  00d9 a1d2          	cp	a,#210
 513  00db 260c          	jrne	L571
 514                     ; 611         clockfrequency = LSI_VALUE;
 516  00dd aef400        	ldw	x,#62464
 517  00e0 1f07          	ldw	(OFST-2,sp),x
 518  00e2 ae0001        	ldw	x,#1
 519  00e5 1f05          	ldw	(OFST-4,sp),x
 521  00e7 200a          	jra	L371
 522  00e9               L571:
 523                     ; 615         clockfrequency = HSE_VALUE;
 525  00e9 ae2400        	ldw	x,#9216
 526  00ec 1f07          	ldw	(OFST-2,sp),x
 527  00ee ae00f4        	ldw	x,#244
 528  00f1 1f05          	ldw	(OFST-4,sp),x
 529  00f3               L371:
 530                     ; 618     return((uint32_t)clockfrequency);
 532  00f3 96            	ldw	x,sp
 533  00f4 1c0005        	addw	x,#OFST-4
 534  00f7 cd0000        	call	c_ltor
 538  00fa 5b09          	addw	sp,#9
 539  00fc 81            	ret
 574                     	xdef	_CLKPrescTable
 575                     	xdef	_HSIDivFactor
 576                     	xdef	_CLK_GetClockFreq
 577                     	xdef	_CLK_SYSCLKConfig
 578                     	xdef	_CLK_HSIPrescalerConfig
 579                     	xdef	_CLK_DeInit
 580                     	xref.b	c_lreg
 581                     	xref.b	c_x
 600                     	xref	c_ludv
 601                     	xref	c_rtol
 602                     	xref	c_ltor
 603                     	end
