   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  52                     ; 7 static void IIC_Delay_us(unsigned int Delay){
  54                     	switch	.text
  55  0000               L3_IIC_Delay_us:
  57  0000 89            	pushw	x
  58  0001 88            	push	a
  59       00000001      OFST:	set	1
  62  0002 2002          	jra	L73
  63  0004               L53:
  64                     ; 10 		for(j = IIC_DelayBaseValue;j > 0;j --);
  66  0004 0f01          	clr	(OFST+0,sp)
  67  0006               L73:
  68                     ; 9 	while( Delay--){	
  70  0006 1e02          	ldw	x,(OFST+1,sp)
  71  0008 1d0001        	subw	x,#1
  72  000b 1f02          	ldw	(OFST+1,sp),x
  73  000d 1c0001        	addw	x,#1
  74  0010 a30000        	cpw	x,#0
  75  0013 26ef          	jrne	L53
  76                     ; 12 }
  79  0015 5b03          	addw	sp,#3
  80  0017 81            	ret
  83                     	xref	_IIC_Port_Init
 133                     ; 14 int IIC_Init(IIC_PARA_t *p){
 134                     	switch	.text
 135  0018               _IIC_Init:
 139                     ; 16 	return IIC_Port_Init(p->ID);
 141  0018 fe            	ldw	x,(x)
 142  0019 cd0000        	call	_IIC_Port_Init
 146  001c 81            	ret
 185                     ; 19 static void IIC_Start(IIC_PARA_t *p){
 186                     	switch	.text
 187  001d               L17_IIC_Start:
 189  001d 89            	pushw	x
 190       00000000      OFST:	set	0
 193                     ; 20 	IIC_Port_Write(p->ID, IIC_SDA, 1);
 195  001e ae0001        	ldw	x,#1
 196  0021 89            	pushw	x
 197  0022 5f            	clrw	x
 198  0023 89            	pushw	x
 199  0024 1e05          	ldw	x,(OFST+5,sp)
 200  0026 fe            	ldw	x,(x)
 201  0027 cd0000        	call	_IIC_Port_Write
 203  002a 5b04          	addw	sp,#4
 204                     ; 21 	IIC_Delay_us(IIC_DelayTime);
 206  002c 5f            	clrw	x
 207  002d add1          	call	L3_IIC_Delay_us
 209                     ; 22 	IIC_Port_Write(p->ID, IIC_SCL, 1);
 211  002f ae0001        	ldw	x,#1
 212  0032 89            	pushw	x
 213  0033 ae0001        	ldw	x,#1
 214  0036 89            	pushw	x
 215  0037 1e05          	ldw	x,(OFST+5,sp)
 216  0039 fe            	ldw	x,(x)
 217  003a cd0000        	call	_IIC_Port_Write
 219  003d 5b04          	addw	sp,#4
 220                     ; 23 	IIC_Delay_us(IIC_DelayTime);
 222  003f 5f            	clrw	x
 223  0040 adbe          	call	L3_IIC_Delay_us
 225                     ; 24 	IIC_Port_Write(p->ID, IIC_SDA, 0);
 227  0042 5f            	clrw	x
 228  0043 89            	pushw	x
 229  0044 5f            	clrw	x
 230  0045 89            	pushw	x
 231  0046 1e05          	ldw	x,(OFST+5,sp)
 232  0048 fe            	ldw	x,(x)
 233  0049 cd0000        	call	_IIC_Port_Write
 235  004c 5b04          	addw	sp,#4
 236                     ; 25 	IIC_Delay_us(IIC_DelayTime);
 238  004e 5f            	clrw	x
 239  004f adaf          	call	L3_IIC_Delay_us
 241                     ; 26 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 243  0051 5f            	clrw	x
 244  0052 89            	pushw	x
 245  0053 ae0001        	ldw	x,#1
 246  0056 89            	pushw	x
 247  0057 1e05          	ldw	x,(OFST+5,sp)
 248  0059 fe            	ldw	x,(x)
 249  005a cd0000        	call	_IIC_Port_Write
 251  005d 5b04          	addw	sp,#4
 252                     ; 27 	IIC_Delay_us(IIC_DelayTime);
 254  005f 5f            	clrw	x
 255  0060 ad9e          	call	L3_IIC_Delay_us
 257                     ; 28 }
 260  0062 85            	popw	x
 261  0063 81            	ret
 329                     ; 30 static int  IIC_WriteData(IIC_PARA_t *p,unsigned char Data){
 330                     	switch	.text
 331  0064               L311_IIC_WriteData:
 333  0064 89            	pushw	x
 334  0065 88            	push	a
 335       00000001      OFST:	set	1
 338                     ; 32 	for(i = 0;i < 8;i ++){
 340  0066 0f01          	clr	(OFST+0,sp)
 341  0068               L151:
 342                     ; 33 		if(Data & 0x80){
 344  0068 7b06          	ld	a,(OFST+5,sp)
 345  006a a580          	bcp	a,#128
 346  006c 2710          	jreq	L751
 347                     ; 34 			IIC_Port_Write(p->ID, IIC_SDA, 1);
 349  006e ae0001        	ldw	x,#1
 350  0071 89            	pushw	x
 351  0072 5f            	clrw	x
 352  0073 89            	pushw	x
 353  0074 1e06          	ldw	x,(OFST+5,sp)
 354  0076 fe            	ldw	x,(x)
 355  0077 cd0000        	call	_IIC_Port_Write
 357  007a 5b04          	addw	sp,#4
 359  007c 200c          	jra	L161
 360  007e               L751:
 361                     ; 36 			IIC_Port_Write(p->ID, IIC_SDA, 0);
 363  007e 5f            	clrw	x
 364  007f 89            	pushw	x
 365  0080 5f            	clrw	x
 366  0081 89            	pushw	x
 367  0082 1e06          	ldw	x,(OFST+5,sp)
 368  0084 fe            	ldw	x,(x)
 369  0085 cd0000        	call	_IIC_Port_Write
 371  0088 5b04          	addw	sp,#4
 372  008a               L161:
 373                     ; 38 		Data <<= 1;
 375  008a 0806          	sll	(OFST+5,sp)
 376                     ; 39 		IIC_Delay_us(IIC_DelayTime);
 378  008c 5f            	clrw	x
 379  008d cd0000        	call	L3_IIC_Delay_us
 381                     ; 40 		IIC_Port_Write(p->ID, IIC_SCL, 1);
 383  0090 ae0001        	ldw	x,#1
 384  0093 89            	pushw	x
 385  0094 ae0001        	ldw	x,#1
 386  0097 89            	pushw	x
 387  0098 1e06          	ldw	x,(OFST+5,sp)
 388  009a fe            	ldw	x,(x)
 389  009b cd0000        	call	_IIC_Port_Write
 391  009e 5b04          	addw	sp,#4
 392                     ; 41 		IIC_Delay_us(IIC_DelayTime);
 394  00a0 5f            	clrw	x
 395  00a1 cd0000        	call	L3_IIC_Delay_us
 397                     ; 42 		IIC_Port_Write(p->ID, IIC_SCL, 0);
 399  00a4 5f            	clrw	x
 400  00a5 89            	pushw	x
 401  00a6 ae0001        	ldw	x,#1
 402  00a9 89            	pushw	x
 403  00aa 1e06          	ldw	x,(OFST+5,sp)
 404  00ac fe            	ldw	x,(x)
 405  00ad cd0000        	call	_IIC_Port_Write
 407  00b0 5b04          	addw	sp,#4
 408                     ; 43 		IIC_Delay_us(IIC_DelayTime);  
 410  00b2 5f            	clrw	x
 411  00b3 cd0000        	call	L3_IIC_Delay_us
 413                     ; 32 	for(i = 0;i < 8;i ++){
 415  00b6 0c01          	inc	(OFST+0,sp)
 418  00b8 7b01          	ld	a,(OFST+0,sp)
 419  00ba a108          	cp	a,#8
 420  00bc 25aa          	jrult	L151
 421                     ; 45 	IIC_Port_SDA_Set(p->ID, IN);
 423  00be 5f            	clrw	x
 424  00bf 89            	pushw	x
 425  00c0 1e04          	ldw	x,(OFST+3,sp)
 426  00c2 fe            	ldw	x,(x)
 427  00c3 cd0000        	call	_IIC_Port_SDA_Set
 429  00c6 85            	popw	x
 430                     ; 46 	IIC_Port_Write(p->ID, IIC_SCL, 1);               
 432  00c7 ae0001        	ldw	x,#1
 433  00ca 89            	pushw	x
 434  00cb ae0001        	ldw	x,#1
 435  00ce 89            	pushw	x
 436  00cf 1e06          	ldw	x,(OFST+5,sp)
 437  00d1 fe            	ldw	x,(x)
 438  00d2 cd0000        	call	_IIC_Port_Write
 440  00d5 5b04          	addw	sp,#4
 441                     ; 47 	IIC_Delay_us(IIC_DelayTime);
 443  00d7 5f            	clrw	x
 444  00d8 cd0000        	call	L3_IIC_Delay_us
 446                     ; 49 	if(IIC_Port_Read(p->ID,IIC_SDA)){  
 448  00db 5f            	clrw	x
 449  00dc 89            	pushw	x
 450  00dd 1e04          	ldw	x,(OFST+3,sp)
 451  00df fe            	ldw	x,(x)
 452  00e0 cd0000        	call	_IIC_Port_Read
 454  00e3 5b02          	addw	sp,#2
 455  00e5 a30000        	cpw	x,#0
 456  00e8 2704          	jreq	L361
 457                     ; 50 		AckStatus = 0;
 459  00ea 0f01          	clr	(OFST+0,sp)
 461  00ec 2004          	jra	L561
 462  00ee               L361:
 463                     ; 53 		AckStatus = 1;
 465  00ee a601          	ld	a,#1
 466  00f0 6b01          	ld	(OFST+0,sp),a
 467  00f2               L561:
 468                     ; 55 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 470  00f2 5f            	clrw	x
 471  00f3 89            	pushw	x
 472  00f4 ae0001        	ldw	x,#1
 473  00f7 89            	pushw	x
 474  00f8 1e06          	ldw	x,(OFST+5,sp)
 475  00fa fe            	ldw	x,(x)
 476  00fb cd0000        	call	_IIC_Port_Write
 478  00fe 5b04          	addw	sp,#4
 479                     ; 56 	IIC_Delay_us(IIC_DelayTime);  
 481  0100 5f            	clrw	x
 482  0101 cd0000        	call	L3_IIC_Delay_us
 484                     ; 57 	IIC_Port_SDA_Set(p->ID, OUT);
 486  0104 ae0001        	ldw	x,#1
 487  0107 89            	pushw	x
 488  0108 1e04          	ldw	x,(OFST+3,sp)
 489  010a fe            	ldw	x,(x)
 490  010b cd0000        	call	_IIC_Port_SDA_Set
 492  010e 85            	popw	x
 493                     ; 58 	return AckStatus;
 495  010f 7b01          	ld	a,(OFST+0,sp)
 496  0111 5f            	clrw	x
 497  0112 97            	ld	xl,a
 500  0113 5b03          	addw	sp,#3
 501  0115 81            	ret
 540                     ; 61 static void IIC_Stop(IIC_PARA_t *p){
 541                     	switch	.text
 542  0116               L761_IIC_Stop:
 544  0116 89            	pushw	x
 545       00000000      OFST:	set	0
 548                     ; 62 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 550  0117 5f            	clrw	x
 551  0118 89            	pushw	x
 552  0119 ae0001        	ldw	x,#1
 553  011c 89            	pushw	x
 554  011d 1e05          	ldw	x,(OFST+5,sp)
 555  011f fe            	ldw	x,(x)
 556  0120 cd0000        	call	_IIC_Port_Write
 558  0123 5b04          	addw	sp,#4
 559                     ; 63 	IIC_Delay_us(IIC_DelayTime);
 561  0125 5f            	clrw	x
 562  0126 cd0000        	call	L3_IIC_Delay_us
 564                     ; 64 	IIC_Port_Write(p->ID, IIC_SCL, 1);
 566  0129 ae0001        	ldw	x,#1
 567  012c 89            	pushw	x
 568  012d ae0001        	ldw	x,#1
 569  0130 89            	pushw	x
 570  0131 1e05          	ldw	x,(OFST+5,sp)
 571  0133 fe            	ldw	x,(x)
 572  0134 cd0000        	call	_IIC_Port_Write
 574  0137 5b04          	addw	sp,#4
 575                     ; 65 	IIC_Delay_us(IIC_DelayTime);
 577  0139 5f            	clrw	x
 578  013a cd0000        	call	L3_IIC_Delay_us
 580                     ; 66 	IIC_Port_Write(p->ID, IIC_SDA, 1);
 582  013d ae0001        	ldw	x,#1
 583  0140 89            	pushw	x
 584  0141 5f            	clrw	x
 585  0142 89            	pushw	x
 586  0143 1e05          	ldw	x,(OFST+5,sp)
 587  0145 fe            	ldw	x,(x)
 588  0146 cd0000        	call	_IIC_Port_Write
 590  0149 5b04          	addw	sp,#4
 591                     ; 67 	IIC_Delay_us(IIC_DelayTime);
 593  014b 5f            	clrw	x
 594  014c cd0000        	call	L3_IIC_Delay_us
 596                     ; 68 	IIC_Delay_us(1000);
 598  014f ae03e8        	ldw	x,#1000
 599  0152 cd0000        	call	L3_IIC_Delay_us
 601                     ; 69 }
 604  0155 85            	popw	x
 605  0156 81            	ret
 644                     ; 71 static void IIC_Nck(IIC_PARA_t *p){
 645                     	switch	.text
 646  0157               L112_IIC_Nck:
 648  0157 89            	pushw	x
 649       00000000      OFST:	set	0
 652                     ; 72 	IIC_Port_Write(p->ID, IIC_SDA, 1);
 654  0158 ae0001        	ldw	x,#1
 655  015b 89            	pushw	x
 656  015c 5f            	clrw	x
 657  015d 89            	pushw	x
 658  015e 1e05          	ldw	x,(OFST+5,sp)
 659  0160 fe            	ldw	x,(x)
 660  0161 cd0000        	call	_IIC_Port_Write
 662  0164 5b04          	addw	sp,#4
 663                     ; 73 	IIC_Delay_us(IIC_DelayTime);
 665  0166 5f            	clrw	x
 666  0167 cd0000        	call	L3_IIC_Delay_us
 668                     ; 74 	IIC_Port_Write(p->ID, IIC_SCL, 1);
 670  016a ae0001        	ldw	x,#1
 671  016d 89            	pushw	x
 672  016e ae0001        	ldw	x,#1
 673  0171 89            	pushw	x
 674  0172 1e05          	ldw	x,(OFST+5,sp)
 675  0174 fe            	ldw	x,(x)
 676  0175 cd0000        	call	_IIC_Port_Write
 678  0178 5b04          	addw	sp,#4
 679                     ; 75 	IIC_Delay_us(IIC_DelayTime);
 681  017a 5f            	clrw	x
 682  017b cd0000        	call	L3_IIC_Delay_us
 684                     ; 76 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 686  017e 5f            	clrw	x
 687  017f 89            	pushw	x
 688  0180 ae0001        	ldw	x,#1
 689  0183 89            	pushw	x
 690  0184 1e05          	ldw	x,(OFST+5,sp)
 691  0186 fe            	ldw	x,(x)
 692  0187 cd0000        	call	_IIC_Port_Write
 694  018a 5b04          	addw	sp,#4
 695                     ; 77 	IIC_Delay_us(IIC_DelayTime);
 697  018c 5f            	clrw	x
 698  018d cd0000        	call	L3_IIC_Delay_us
 700                     ; 78 	IIC_Port_Write(p->ID, IIC_SDA, 0);
 702  0190 5f            	clrw	x
 703  0191 89            	pushw	x
 704  0192 5f            	clrw	x
 705  0193 89            	pushw	x
 706  0194 1e05          	ldw	x,(OFST+5,sp)
 707  0196 fe            	ldw	x,(x)
 708  0197 cd0000        	call	_IIC_Port_Write
 710  019a 5b04          	addw	sp,#4
 711                     ; 79 	IIC_Delay_us(IIC_DelayTime);
 713  019c 5f            	clrw	x
 714  019d cd0000        	call	L3_IIC_Delay_us
 716                     ; 80 }
 719  01a0 85            	popw	x
 720  01a1 81            	ret
 759                     ; 82 static void I2C_Ack(IIC_PARA_t *p){
 760                     	switch	.text
 761  01a2               L332_I2C_Ack:
 763  01a2 89            	pushw	x
 764       00000000      OFST:	set	0
 767                     ; 83 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 769  01a3 5f            	clrw	x
 770  01a4 89            	pushw	x
 771  01a5 ae0001        	ldw	x,#1
 772  01a8 89            	pushw	x
 773  01a9 1e05          	ldw	x,(OFST+5,sp)
 774  01ab fe            	ldw	x,(x)
 775  01ac cd0000        	call	_IIC_Port_Write
 777  01af 5b04          	addw	sp,#4
 778                     ; 84 	IIC_Delay_us(IIC_DelayTime);
 780  01b1 5f            	clrw	x
 781  01b2 cd0000        	call	L3_IIC_Delay_us
 783                     ; 85 	IIC_Port_Write(p->ID, IIC_SDA, 0);
 785  01b5 5f            	clrw	x
 786  01b6 89            	pushw	x
 787  01b7 5f            	clrw	x
 788  01b8 89            	pushw	x
 789  01b9 1e05          	ldw	x,(OFST+5,sp)
 790  01bb fe            	ldw	x,(x)
 791  01bc cd0000        	call	_IIC_Port_Write
 793  01bf 5b04          	addw	sp,#4
 794                     ; 86 	IIC_Delay_us(IIC_DelayTime);
 796  01c1 5f            	clrw	x
 797  01c2 cd0000        	call	L3_IIC_Delay_us
 799                     ; 87 	IIC_Port_Write(p->ID, IIC_SCL, 1);
 801  01c5 ae0001        	ldw	x,#1
 802  01c8 89            	pushw	x
 803  01c9 ae0001        	ldw	x,#1
 804  01cc 89            	pushw	x
 805  01cd 1e05          	ldw	x,(OFST+5,sp)
 806  01cf fe            	ldw	x,(x)
 807  01d0 cd0000        	call	_IIC_Port_Write
 809  01d3 5b04          	addw	sp,#4
 810                     ; 88 	IIC_Delay_us(IIC_DelayTime);
 812  01d5 5f            	clrw	x
 813  01d6 cd0000        	call	L3_IIC_Delay_us
 815                     ; 89 	IIC_Port_Write(p->ID, IIC_SCL, 0);
 817  01d9 5f            	clrw	x
 818  01da 89            	pushw	x
 819  01db ae0001        	ldw	x,#1
 820  01de 89            	pushw	x
 821  01df 1e05          	ldw	x,(OFST+5,sp)
 822  01e1 fe            	ldw	x,(x)
 823  01e2 cd0000        	call	_IIC_Port_Write
 825  01e5 5b04          	addw	sp,#4
 826                     ; 90 	IIC_Delay_us(IIC_DelayTime);
 828  01e7 5f            	clrw	x
 829  01e8 cd0000        	call	L3_IIC_Delay_us
 831                     ; 91 }
 834  01eb 85            	popw	x
 835  01ec 81            	ret
 894                     ; 93 static unsigned char IIC_ReadData(IIC_PARA_t *p){
 895                     	switch	.text
 896  01ed               L552_IIC_ReadData:
 898  01ed 89            	pushw	x
 899  01ee 89            	pushw	x
 900       00000002      OFST:	set	2
 903                     ; 94 	unsigned char Read = 0,j;
 905  01ef 0f01          	clr	(OFST-1,sp)
 906                     ; 95 	IIC_Port_SDA_Set(p->ID, IN);
 908  01f1 5f            	clrw	x
 909  01f2 89            	pushw	x
 910  01f3 1e05          	ldw	x,(OFST+3,sp)
 911  01f5 fe            	ldw	x,(x)
 912  01f6 cd0000        	call	_IIC_Port_SDA_Set
 914  01f9 85            	popw	x
 915                     ; 96 	IIC_Delay_us(IIC_DelayTime);
 917  01fa 5f            	clrw	x
 918  01fb cd0000        	call	L3_IIC_Delay_us
 920                     ; 97 	for(j = 0;j < 8;j ++){
 922  01fe 0f02          	clr	(OFST+0,sp)
 923  0200               L703:
 924                     ; 98 		IIC_Port_Write(p->ID, IIC_SCL, 1);
 926  0200 ae0001        	ldw	x,#1
 927  0203 89            	pushw	x
 928  0204 ae0001        	ldw	x,#1
 929  0207 89            	pushw	x
 930  0208 1e07          	ldw	x,(OFST+5,sp)
 931  020a fe            	ldw	x,(x)
 932  020b cd0000        	call	_IIC_Port_Write
 934  020e 5b04          	addw	sp,#4
 935                     ; 99 		IIC_Delay_us(IIC_DelayTime);
 937  0210 5f            	clrw	x
 938  0211 cd0000        	call	L3_IIC_Delay_us
 940                     ; 100 		if(IIC_Port_Read(p->ID,IIC_SDA)){
 942  0214 5f            	clrw	x
 943  0215 89            	pushw	x
 944  0216 1e05          	ldw	x,(OFST+3,sp)
 945  0218 fe            	ldw	x,(x)
 946  0219 cd0000        	call	_IIC_Port_Read
 948  021c 5b02          	addw	sp,#2
 949  021e a30000        	cpw	x,#0
 950  0221 2711          	jreq	L513
 951                     ; 101 			 Read = Read |(0x80 >> j);
 953  0223 7b02          	ld	a,(OFST+0,sp)
 954  0225 5f            	clrw	x
 955  0226 97            	ld	xl,a
 956  0227 a680          	ld	a,#128
 957  0229 5d            	tnzw	x
 958  022a 2704          	jreq	L42
 959  022c               L62:
 960  022c 44            	srl	a
 961  022d 5a            	decw	x
 962  022e 26fc          	jrne	L62
 963  0230               L42:
 964  0230 1a01          	or	a,(OFST-1,sp)
 965  0232 6b01          	ld	(OFST-1,sp),a
 966  0234               L513:
 967                     ; 103 		IIC_Port_Write(p->ID, IIC_SCL, 0);
 969  0234 5f            	clrw	x
 970  0235 89            	pushw	x
 971  0236 ae0001        	ldw	x,#1
 972  0239 89            	pushw	x
 973  023a 1e07          	ldw	x,(OFST+5,sp)
 974  023c fe            	ldw	x,(x)
 975  023d cd0000        	call	_IIC_Port_Write
 977  0240 5b04          	addw	sp,#4
 978                     ; 104 		IIC_Delay_us(IIC_DelayTime);
 980  0242 5f            	clrw	x
 981  0243 cd0000        	call	L3_IIC_Delay_us
 983                     ; 97 	for(j = 0;j < 8;j ++){
 985  0246 0c02          	inc	(OFST+0,sp)
 988  0248 7b02          	ld	a,(OFST+0,sp)
 989  024a a108          	cp	a,#8
 990  024c 25b2          	jrult	L703
 991                     ; 106 	IIC_Port_SDA_Set(p->ID, OUT);
 993  024e ae0001        	ldw	x,#1
 994  0251 89            	pushw	x
 995  0252 1e05          	ldw	x,(OFST+3,sp)
 996  0254 fe            	ldw	x,(x)
 997  0255 cd0000        	call	_IIC_Port_SDA_Set
 999  0258 85            	popw	x
1000                     ; 107 	return Read;
1002  0259 7b01          	ld	a,(OFST-1,sp)
1005  025b 5b04          	addw	sp,#4
1006  025d 81            	ret
1067                     ; 110 int  IIC_Read_Data(IIC_PARA_t *p,unsigned char Add,unsigned char *Read_Data){
1068                     	switch	.text
1069  025e               _IIC_Read_Data:
1071  025e 89            	pushw	x
1072       00000000      OFST:	set	0
1075                     ; 111 	IIC_Start(p);
1077  025f cd001d        	call	L17_IIC_Start
1079                     ; 112 	if(IIC_WriteData(p, Add) == 0){
1081  0262 7b05          	ld	a,(OFST+5,sp)
1082  0264 88            	push	a
1083  0265 1e02          	ldw	x,(OFST+2,sp)
1084  0267 cd0064        	call	L311_IIC_WriteData
1086  026a 84            	pop	a
1087  026b a30000        	cpw	x,#0
1088  026e 2608          	jrne	L743
1089                     ; 113 		IIC_Stop(p);
1091  0270 1e01          	ldw	x,(OFST+1,sp)
1092  0272 cd0116        	call	L761_IIC_Stop
1094                     ; 114 		return 0;
1096  0275 5f            	clrw	x
1098  0276 2015          	jra	L23
1099  0278               L743:
1100                     ; 116 	*Read_Data = IIC_ReadData(p);
1102  0278 1e01          	ldw	x,(OFST+1,sp)
1103  027a cd01ed        	call	L552_IIC_ReadData
1105  027d 1e06          	ldw	x,(OFST+6,sp)
1106  027f f7            	ld	(x),a
1107                     ; 117 	IIC_Nck(p);
1109  0280 1e01          	ldw	x,(OFST+1,sp)
1110  0282 cd0157        	call	L112_IIC_Nck
1112                     ; 118 	IIC_Stop(p);
1114  0285 1e01          	ldw	x,(OFST+1,sp)
1115  0287 cd0116        	call	L761_IIC_Stop
1117                     ; 119 	return 1;
1119  028a ae0001        	ldw	x,#1
1121  028d               L23:
1123  028d 5b02          	addw	sp,#2
1124  028f 81            	ret
1183                     ; 122 int  IIC_Write_Data(IIC_PARA_t *p,unsigned char Add,unsigned char Write_Data){
1184                     	switch	.text
1185  0290               _IIC_Write_Data:
1187  0290 89            	pushw	x
1188       00000000      OFST:	set	0
1191                     ; 123 	IIC_Start(p);
1193  0291 cd001d        	call	L17_IIC_Start
1195                     ; 124 	if(!IIC_WriteData(p, Add)){
1197  0294 7b05          	ld	a,(OFST+5,sp)
1198  0296 88            	push	a
1199  0297 1e02          	ldw	x,(OFST+2,sp)
1200  0299 cd0064        	call	L311_IIC_WriteData
1202  029c 84            	pop	a
1203  029d a30000        	cpw	x,#0
1204  02a0 2608          	jrne	L104
1205                     ; 125 		IIC_Stop(p);
1207  02a2 1e01          	ldw	x,(OFST+1,sp)
1208  02a4 cd0116        	call	L761_IIC_Stop
1210                     ; 126 		return 0;
1212  02a7 5f            	clrw	x
1214  02a8 2014          	jra	L63
1215  02aa               L104:
1216                     ; 128 	if(!IIC_WriteData(p, Write_Data)){
1218  02aa 7b06          	ld	a,(OFST+6,sp)
1219  02ac 88            	push	a
1220  02ad 1e02          	ldw	x,(OFST+2,sp)
1221  02af cd0064        	call	L311_IIC_WriteData
1223  02b2 84            	pop	a
1224  02b3 a30000        	cpw	x,#0
1225  02b6 2609          	jrne	L304
1226                     ; 129 		IIC_Stop(p);
1228  02b8 1e01          	ldw	x,(OFST+1,sp)
1229  02ba cd0116        	call	L761_IIC_Stop
1231                     ; 130 		return 0;
1233  02bd 5f            	clrw	x
1235  02be               L63:
1237  02be 5b02          	addw	sp,#2
1238  02c0 81            	ret
1239  02c1               L304:
1240                     ; 132 	IIC_Nck(p);
1242  02c1 1e01          	ldw	x,(OFST+1,sp)
1243  02c3 cd0157        	call	L112_IIC_Nck
1245                     ; 133 	IIC_Stop(p);
1247  02c6 1e01          	ldw	x,(OFST+1,sp)
1248  02c8 cd0116        	call	L761_IIC_Stop
1250                     ; 134 	return 1;
1252  02cb ae0001        	ldw	x,#1
1254  02ce 20ee          	jra	L63
1267                     	xref	_IIC_Port_SDA_Set
1268                     	xref	_IIC_Port_Read
1269                     	xref	_IIC_Port_Write
1270                     	xdef	_IIC_Write_Data
1271                     	xdef	_IIC_Read_Data
1272                     	xdef	_IIC_Init
1291                     	end
