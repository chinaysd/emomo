   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  46                     ; 26 int IIC_Port_Init(int ID){
  48                     	switch	.text
  49  0000               _IIC_Port_Init:
  51  0000 89            	pushw	x
  52       00000000      OFST:	set	0
  55                     ; 27 	if(ID == 0){
  57  0001 a30000        	cpw	x,#0
  58  0004 262a          	jrne	L72
  59                     ; 28 		GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
  61  0006 4bf0          	push	#240
  62  0008 4b40          	push	#64
  63  000a ae500a        	ldw	x,#20490
  64  000d cd0000        	call	_GPIO_Init
  66  0010 85            	popw	x
  67                     ; 29 		SDA0_Set(1);
  69  0011 4b40          	push	#64
  70  0013 ae500a        	ldw	x,#20490
  71  0016 cd0000        	call	_GPIO_WriteHigh
  73  0019 84            	pop	a
  74                     ; 30 		GPIO_Init(SCL0_PORT, SCL0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
  76  001a 4bf0          	push	#240
  77  001c 4b80          	push	#128
  78  001e ae500a        	ldw	x,#20490
  79  0021 cd0000        	call	_GPIO_Init
  81  0024 85            	popw	x
  82                     ; 31 		SCL0_Set(1);
  84  0025 4b80          	push	#128
  85  0027 ae500a        	ldw	x,#20490
  86  002a cd0000        	call	_GPIO_WriteHigh
  88  002d 84            	pop	a
  90  002e 202f          	jra	L13
  91  0030               L72:
  92                     ; 32 	}else if(ID == 1){
  94  0030 1e01          	ldw	x,(OFST+1,sp)
  95  0032 a30001        	cpw	x,#1
  96  0035 262d          	jrne	L33
  97                     ; 33 		GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
  99  0037 4bf0          	push	#240
 100  0039 4b04          	push	#4
 101  003b ae500f        	ldw	x,#20495
 102  003e cd0000        	call	_GPIO_Init
 104  0041 85            	popw	x
 105                     ; 34 		SDA1_Set(1);
 107  0042 4b04          	push	#4
 108  0044 ae500f        	ldw	x,#20495
 109  0047 cd0000        	call	_GPIO_WriteHigh
 111  004a 84            	pop	a
 112                     ; 35 		GPIO_Init(SCL1_PORT, SCL1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
 114  004b 4bf0          	push	#240
 115  004d 4b08          	push	#8
 116  004f ae500f        	ldw	x,#20495
 117  0052 cd0000        	call	_GPIO_Init
 119  0055 85            	popw	x
 120                     ; 36 		SCL1_Set(1);
 122  0056 4b08          	push	#8
 123  0058 ae500f        	ldw	x,#20495
 124  005b cd0000        	call	_GPIO_WriteHigh
 126  005e 84            	pop	a
 128  005f               L13:
 129                     ; 40 	return 1;
 131  005f ae0001        	ldw	x,#1
 133  0062 2001          	jra	L6
 134  0064               L33:
 135                     ; 38 		return 0;
 137  0064 5f            	clrw	x
 139  0065               L6:
 141  0065 5b02          	addw	sp,#2
 142  0067 81            	ret
 186                     ; 45 int IIC_Port_SDA_Set(int ID,int Func){
 187                     	switch	.text
 188  0068               _IIC_Port_SDA_Set:
 190  0068 89            	pushw	x
 191       00000000      OFST:	set	0
 194                     ; 46 	if(ID == 0){
 196  0069 a30000        	cpw	x,#0
 197  006c 2628          	jrne	L16
 198                     ; 47 		if(Func == 0){
 200  006e 1e05          	ldw	x,(OFST+5,sp)
 201  0070 260d          	jrne	L36
 202                     ; 48 			GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_IN_FL_NO_IT);
 204  0072 4b00          	push	#0
 205  0074 4b40          	push	#64
 206  0076 ae500a        	ldw	x,#20490
 207  0079 cd0000        	call	_GPIO_Init
 209  007c 85            	popw	x
 211  007d 2041          	jra	L37
 212  007f               L36:
 213                     ; 49 		}else if(Func == 1){
 215  007f 1e05          	ldw	x,(OFST+5,sp)
 216  0081 a30001        	cpw	x,#1
 217  0084 260d          	jrne	L76
 218                     ; 50 			GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
 220  0086 4bf0          	push	#240
 221  0088 4b40          	push	#64
 222  008a ae500a        	ldw	x,#20490
 223  008d cd0000        	call	_GPIO_Init
 225  0090 85            	popw	x
 227  0091 202d          	jra	L37
 228  0093               L76:
 229                     ; 52 			return 0;
 231  0093 5f            	clrw	x
 233  0094 202a          	jra	L21
 234  0096               L16:
 235                     ; 54 	}else if(ID == 1){
 237  0096 1e01          	ldw	x,(OFST+1,sp)
 238  0098 a30001        	cpw	x,#1
 239  009b 2629          	jrne	L57
 240                     ; 55 		if(Func == 0){
 242  009d 1e05          	ldw	x,(OFST+5,sp)
 243  009f 260d          	jrne	L77
 244                     ; 56 			GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_IN_FL_NO_IT);
 246  00a1 4b00          	push	#0
 247  00a3 4b04          	push	#4
 248  00a5 ae500f        	ldw	x,#20495
 249  00a8 cd0000        	call	_GPIO_Init
 251  00ab 85            	popw	x
 253  00ac 2012          	jra	L37
 254  00ae               L77:
 255                     ; 57 		}else if(Func == 1){
 257  00ae 1e05          	ldw	x,(OFST+5,sp)
 258  00b0 a30001        	cpw	x,#1
 259  00b3 260e          	jrne	L301
 260                     ; 58 			GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
 262  00b5 4bf0          	push	#240
 263  00b7 4b04          	push	#4
 264  00b9 ae500f        	ldw	x,#20495
 265  00bc cd0000        	call	_GPIO_Init
 267  00bf 85            	popw	x
 269  00c0               L37:
 270                     ; 65 }
 271  00c0               L21:
 274  00c0 5b02          	addw	sp,#2
 275  00c2 81            	ret
 276  00c3               L301:
 277                     ; 60 			return 0;
 279  00c3 5f            	clrw	x
 281  00c4 20fa          	jra	L21
 282  00c6               L57:
 283                     ; 63 		return 0;
 285  00c6 5f            	clrw	x
 287  00c7 20f7          	jra	L21
 341                     ; 70 int IIC_Port_Write(int ID,int Func,int Data){
 342                     	switch	.text
 343  00c9               _IIC_Port_Write:
 345  00c9 89            	pushw	x
 346       00000000      OFST:	set	0
 349                     ; 71 	if(ID == 0){
 351  00ca a30000        	cpw	x,#0
 352  00cd 2646          	jrne	L731
 353                     ; 72 		if(Func == 0){
 355  00cf 1e05          	ldw	x,(OFST+5,sp)
 356  00d1 261c          	jrne	L141
 357                     ; 73 			SDA0_Set(Data);
 359  00d3 1e07          	ldw	x,(OFST+7,sp)
 360  00d5 270c          	jreq	L61
 361  00d7 4b40          	push	#64
 362  00d9 ae500a        	ldw	x,#20490
 363  00dc cd0000        	call	_GPIO_WriteHigh
 365  00df 5b01          	addw	sp,#1
 366  00e1 200a          	jra	L02
 367  00e3               L61:
 368  00e3 4b40          	push	#64
 369  00e5 ae500a        	ldw	x,#20490
 370  00e8 cd0000        	call	_GPIO_WriteLow
 372  00eb 5b01          	addw	sp,#1
 373  00ed               L02:
 375  00ed 206e          	jra	L151
 376  00ef               L141:
 377                     ; 74 		}else if(Func == 1){
 379  00ef 1e05          	ldw	x,(OFST+5,sp)
 380  00f1 a30001        	cpw	x,#1
 381  00f4 261c          	jrne	L541
 382                     ; 75 			SCL0_Set(Data);
 384  00f6 1e07          	ldw	x,(OFST+7,sp)
 385  00f8 270c          	jreq	L22
 386  00fa 4b80          	push	#128
 387  00fc ae500a        	ldw	x,#20490
 388  00ff cd0000        	call	_GPIO_WriteHigh
 390  0102 5b01          	addw	sp,#1
 391  0104 200a          	jra	L42
 392  0106               L22:
 393  0106 4b80          	push	#128
 394  0108 ae500a        	ldw	x,#20490
 395  010b cd0000        	call	_GPIO_WriteLow
 397  010e 5b01          	addw	sp,#1
 398  0110               L42:
 400  0110 204b          	jra	L151
 401  0112               L541:
 402                     ; 77 			return 0;
 404  0112 5f            	clrw	x
 406  0113 2048          	jra	L63
 407  0115               L731:
 408                     ; 79 	}else if(ID == 1){
 410  0115 1e01          	ldw	x,(OFST+1,sp)
 411  0117 a30001        	cpw	x,#1
 412  011a 2647          	jrne	L351
 413                     ; 80 		if(Func == 0){
 415  011c 1e05          	ldw	x,(OFST+5,sp)
 416  011e 261c          	jrne	L551
 417                     ; 81 			SDA1_Set(Data);
 419  0120 1e07          	ldw	x,(OFST+7,sp)
 420  0122 270c          	jreq	L62
 421  0124 4b04          	push	#4
 422  0126 ae500f        	ldw	x,#20495
 423  0129 cd0000        	call	_GPIO_WriteHigh
 425  012c 5b01          	addw	sp,#1
 426  012e 200a          	jra	L03
 427  0130               L62:
 428  0130 4b04          	push	#4
 429  0132 ae500f        	ldw	x,#20495
 430  0135 cd0000        	call	_GPIO_WriteLow
 432  0138 5b01          	addw	sp,#1
 433  013a               L03:
 435  013a 2021          	jra	L151
 436  013c               L551:
 437                     ; 82 		}else if(Func == 1){
 439  013c 1e05          	ldw	x,(OFST+5,sp)
 440  013e a30001        	cpw	x,#1
 441  0141 261d          	jrne	L161
 442                     ; 83 			SCL1_Set(Data);
 444  0143 1e07          	ldw	x,(OFST+7,sp)
 445  0145 270c          	jreq	L23
 446  0147 4b08          	push	#8
 447  0149 ae500f        	ldw	x,#20495
 448  014c cd0000        	call	_GPIO_WriteHigh
 450  014f 5b01          	addw	sp,#1
 451  0151 200a          	jra	L43
 452  0153               L23:
 453  0153 4b08          	push	#8
 454  0155 ae500f        	ldw	x,#20495
 455  0158 cd0000        	call	_GPIO_WriteLow
 457  015b 5b01          	addw	sp,#1
 458  015d               L43:
 460  015d               L151:
 461                     ; 90 }
 462  015d               L63:
 465  015d 5b02          	addw	sp,#2
 466  015f 81            	ret
 467  0160               L161:
 468                     ; 85 			return 0;
 470  0160 5f            	clrw	x
 472  0161 20fa          	jra	L63
 473  0163               L351:
 474                     ; 88 		return 0;
 476  0163 5f            	clrw	x
 478  0164 20f7          	jra	L63
 522                     ; 92 int IIC_Port_Read(int ID ,int Func ){
 523                     	switch	.text
 524  0166               _IIC_Port_Read:
 526  0166 89            	pushw	x
 527       00000000      OFST:	set	0
 530                     ; 93 	if(ID == 0){
 532  0167 a30000        	cpw	x,#0
 533  016a 262b          	jrne	L112
 534                     ; 94 		if(Func == 0){
 536  016c 1e05          	ldw	x,(OFST+5,sp)
 537  016e 260e          	jrne	L312
 538                     ; 95 			return SDA0_Read();
 540  0170 4b40          	push	#64
 541  0172 ae500a        	ldw	x,#20490
 542  0175 cd0000        	call	_GPIO_ReadInputPin
 544  0178 5b01          	addw	sp,#1
 545  017a 5f            	clrw	x
 546  017b 97            	ld	xl,a
 548  017c 2013          	jra	L24
 549  017e               L312:
 550                     ; 96 		}else if(Func == 1){
 552  017e 1e05          	ldw	x,(OFST+5,sp)
 553  0180 a30001        	cpw	x,#1
 554  0183 260f          	jrne	L712
 555                     ; 97 			return SCL0_Read();
 557  0185 4b80          	push	#128
 558  0187 ae500a        	ldw	x,#20490
 559  018a cd0000        	call	_GPIO_ReadInputPin
 561  018d 5b01          	addw	sp,#1
 562  018f 5f            	clrw	x
 563  0190 97            	ld	xl,a
 565  0191               L24:
 567  0191 5b02          	addw	sp,#2
 568  0193 81            	ret
 569  0194               L712:
 570                     ; 99 			return 0;
 572  0194 5f            	clrw	x
 574  0195 20fa          	jra	L24
 575  0197               L112:
 576                     ; 101 	}else if(ID == 1){
 578  0197 1e01          	ldw	x,(OFST+1,sp)
 579  0199 a30001        	cpw	x,#1
 580  019c 262a          	jrne	L522
 581                     ; 102 		if(Func == 0){
 583  019e 1e05          	ldw	x,(OFST+5,sp)
 584  01a0 260e          	jrne	L722
 585                     ; 103 			return SDA1_Read();
 587  01a2 4b04          	push	#4
 588  01a4 ae500f        	ldw	x,#20495
 589  01a7 cd0000        	call	_GPIO_ReadInputPin
 591  01aa 5b01          	addw	sp,#1
 592  01ac 5f            	clrw	x
 593  01ad 97            	ld	xl,a
 595  01ae 20e1          	jra	L24
 596  01b0               L722:
 597                     ; 104 		}else if(Func == 1){
 599  01b0 1e05          	ldw	x,(OFST+5,sp)
 600  01b2 a30001        	cpw	x,#1
 601  01b5 260e          	jrne	L332
 602                     ; 105 			return SCL1_Read();
 604  01b7 4b08          	push	#8
 605  01b9 ae500f        	ldw	x,#20495
 606  01bc cd0000        	call	_GPIO_ReadInputPin
 608  01bf 5b01          	addw	sp,#1
 609  01c1 5f            	clrw	x
 610  01c2 97            	ld	xl,a
 612  01c3 20cc          	jra	L24
 613  01c5               L332:
 614                     ; 107 			return 0;
 616  01c5 5f            	clrw	x
 618  01c6 20c9          	jra	L24
 619  01c8               L522:
 620                     ; 110 		return 0;
 622  01c8 5f            	clrw	x
 624  01c9 20c6          	jra	L24
 637                     	xdef	_IIC_Port_Read
 638                     	xdef	_IIC_Port_Write
 639                     	xdef	_IIC_Port_SDA_Set
 640                     	xdef	_IIC_Port_Init
 641                     	xref	_GPIO_ReadInputPin
 642                     	xref	_GPIO_WriteLow
 643                     	xref	_GPIO_WriteHigh
 644                     	xref	_GPIO_Init
 663                     	end
