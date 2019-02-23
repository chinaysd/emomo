   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
   4                     .const:	section	.text
   5  0000               L31_KeyEvent:
   6  0000 0000          	dc.w	0
   7  0002 0000          	dc.w	0
   8  0004 0000          	dc.w	0
   9  0006 0000          	dc.w	0
  10  0008 0000          	dc.w	0
  11  000a 0001          	dc.w	1
  12  000c 0002          	dc.w	2
  13  000e 0003          	dc.w	3
  14  0010 0000          	dc.w	0
  15  0012 0004          	dc.w	4
  16  0014 0005          	dc.w	5
  17  0016 0006          	dc.w	6
  18  0018 0007          	dc.w	7
  19  001a 0000          	dc.w	0
  20  001c 0008          	dc.w	8
  21  001e 0009          	dc.w	9
  22  0020 000a          	dc.w	10
  23  0022 000b          	dc.w	11
  24  0024 0000          	dc.w	0
  25  0026 000c          	dc.w	12
  26                     	xref	_Key_Port_Read
  76                     ; 38 static u8 GetKeyIndex(void)
  76                     ; 39 {
  78                     	switch	.text
  79  0000               L51_GetKeyIndex:
  81  0000 89            	pushw	x
  82       00000002      OFST:	set	2
  85                     ; 41 	u8 value = 0,cnt = 0;
  87  0001 0f01          	clr	(OFST-1,sp)
  90  0003 0f02          	clr	(OFST+0,sp)
  91                     ; 42 	if(!Key_Port_Read(1))
  93  0005 a601          	ld	a,#1
  94  0007 cd0000        	call	_Key_Port_Read
  96  000a 4d            	tnz	a
  97  000b 2606          	jrne	L74
  98                     ; 43 		cnt ++,value = 1;
 100  000d 0c02          	inc	(OFST+0,sp)
 101  000f a601          	ld	a,#1
 102  0011 6b01          	ld	(OFST-1,sp),a
 103  0013               L74:
 104                     ; 44 	if(!Key_Port_Read(2))
 106  0013 a602          	ld	a,#2
 107  0015 cd0000        	call	_Key_Port_Read
 109  0018 4d            	tnz	a
 110  0019 2606          	jrne	L15
 111                     ; 45 		cnt ++,value = 2;
 113  001b 0c02          	inc	(OFST+0,sp)
 114  001d a602          	ld	a,#2
 115  001f 6b01          	ld	(OFST-1,sp),a
 116  0021               L15:
 117                     ; 46 	if(cnt > 1){
 119  0021 7b02          	ld	a,(OFST+0,sp)
 120  0023 a102          	cp	a,#2
 121  0025 2503          	jrult	L35
 122                     ; 47 		return 0;
 124  0027 4f            	clr	a
 126  0028 2002          	jra	L6
 127  002a               L35:
 128                     ; 49 	return value;	
 130  002a 7b01          	ld	a,(OFST-1,sp)
 132  002c               L6:
 134  002c 85            	popw	x
 135  002d 81            	ret
 138                     	xref	_Key_Port_Init
 163                     ; 55 void KEY_Init(void){
 164                     	switch	.text
 165  002e               _KEY_Init:
 169                     ; 58 	Key_Port_Init();
 171  002e cd0000        	call	_Key_Port_Init
 173                     ; 59 	KeyState=KEY_STATE_IDLE;
 175  0031 3f00          	clr	L11_KeyState
 176                     ; 60 	TimeOut_Record(&Key_Scan_Timer,0);
 178  0033 5f            	clrw	x
 179  0034 89            	pushw	x
 180  0035 ae0005        	ldw	x,#L5_Key_Scan_Timer
 181  0038 cd0000        	call	_TimeOut_Record
 183  003b 85            	popw	x
 184                     ; 61 }
 187  003c 81            	ret
 190                     	bsct
 191  0000               L56_PreKeyIndex:
 192  0000 ff            	dc.b	255
 351                     ; 67 t_KEY_MSG KEY_Scan(void){
 352                     	switch	.text
 353  003d               _KEY_Scan:
 355  003d 88            	push	a
 356       00000001      OFST:	set	1
 359                     ; 71 	if(!(TimeOutDet_Check(&Key_Scan_Timer))){
 361  003e ae0005        	ldw	x,#L5_Key_Scan_Timer
 362  0041 cd0000        	call	_TimeOutDet_Check
 364  0044 a30000        	cpw	x,#0
 365  0047 2604          	jrne	L361
 366                     ; 72 		return MSG_KEY_NONE;
 368  0049 4f            	clr	a
 371  004a 5b01          	addw	sp,#1
 372  004c 81            	ret
 373  004d               L361:
 374                     ; 75 	TimeOut_Record(&Key_Scan_Timer,KEY_SCAN_TIME);
 376  004d ae0014        	ldw	x,#20
 377  0050 89            	pushw	x
 378  0051 ae0005        	ldw	x,#L5_Key_Scan_Timer
 379  0054 cd0000        	call	_TimeOut_Record
 381  0057 85            	popw	x
 382                     ; 77 	KeyIndex=GetKeyIndex();
 384  0058 ada6          	call	L51_GetKeyIndex
 386  005a 6b01          	ld	(OFST+0,sp),a
 387                     ; 79 	switch(KeyState){
 389  005c b600          	ld	a,L11_KeyState
 391                     ; 127 			break;
 392  005e 4d            	tnz	a
 393  005f 2712          	jreq	L76
 394  0061 4a            	dec	a
 395  0062 272e          	jreq	L17
 396  0064 4a            	dec	a
 397  0065 2760          	jreq	L37
 398  0067 4a            	dec	a
 399  0068 2603cc0101    	jreq	L57
 400  006d               L77:
 401                     ; 126 			KeyState = KEY_STATE_IDLE;
 403  006d 3f00          	clr	L11_KeyState
 404                     ; 127 			break;
 406  006f ac370137      	jpf	L761
 407  0073               L76:
 408                     ; 81 			if(!KeyIndex){
 410  0073 0d01          	tnz	(OFST+0,sp)
 411  0075 2604          	jrne	L171
 412                     ; 82 				return MSG_KEY_NONE;
 414  0077 4f            	clr	a
 417  0078 5b01          	addw	sp,#1
 418  007a 81            	ret
 419  007b               L171:
 420                     ; 85 			PreKeyIndex = KeyIndex;
 422  007b 7b01          	ld	a,(OFST+0,sp)
 423  007d b700          	ld	L56_PreKeyIndex,a
 424                     ; 86 			TimeOut_Record(&Key_Wait_Timer,KEY_JITTER_TIME);
 426  007f ae001e        	ldw	x,#30
 427  0082 89            	pushw	x
 428  0083 ae0001        	ldw	x,#L7_Key_Wait_Timer
 429  0086 cd0000        	call	_TimeOut_Record
 431  0089 85            	popw	x
 432                     ; 87 			KeyState = KEY_STATE_JITTER;
 434  008a 35010000      	mov	L11_KeyState,#1
 435                     ; 88 			break;
 437  008e ac370137      	jpf	L761
 438  0092               L17:
 439                     ; 92 			if(PreKeyIndex != KeyIndex){
 441  0092 b600          	ld	a,L56_PreKeyIndex
 442  0094 1101          	cp	a,(OFST+0,sp)
 443  0096 2706          	jreq	L371
 444                     ; 93 				KeyState = KEY_STATE_IDLE;
 446  0098 3f00          	clr	L11_KeyState
 448  009a ac370137      	jpf	L761
 449  009e               L371:
 450                     ; 94 			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
 452  009e ae0001        	ldw	x,#L7_Key_Wait_Timer
 453  00a1 cd0000        	call	_TimeOutDet_Check
 455  00a4 a30000        	cpw	x,#0
 456  00a7 2603cc0137    	jreq	L761
 457                     ; 95 				TimeOut_Record(&Key_Wait_Timer,KEY_CP_TIME);
 459  00ac ae05dc        	ldw	x,#1500
 460  00af 89            	pushw	x
 461  00b0 ae0001        	ldw	x,#L7_Key_Wait_Timer
 462  00b3 cd0000        	call	_TimeOut_Record
 464  00b6 85            	popw	x
 465                     ; 96 				KeyState = KEY_STATE_PRESS_DOWN;
 467  00b7 35020000      	mov	L11_KeyState,#2
 468                     ; 97 				return KeyEvent[PreKeyIndex][0];
 470  00bb b600          	ld	a,L56_PreKeyIndex
 471  00bd 97            	ld	xl,a
 472  00be a60a          	ld	a,#10
 473  00c0 42            	mul	x,a
 474  00c1 d60001        	ld	a,(L31_KeyEvent+1,x)
 477  00c4 5b01          	addw	sp,#1
 478  00c6 81            	ret
 479  00c7               L37:
 480                     ; 103 			if(PreKeyIndex != KeyIndex){
 482  00c7 b600          	ld	a,L56_PreKeyIndex
 483  00c9 1101          	cp	a,(OFST+0,sp)
 484  00cb 270e          	jreq	L102
 485                     ; 104 				KeyState = KEY_STATE_IDLE;
 487  00cd 3f00          	clr	L11_KeyState
 488                     ; 105 				return KeyEvent[PreKeyIndex][1];
 490  00cf b600          	ld	a,L56_PreKeyIndex
 491  00d1 97            	ld	xl,a
 492  00d2 a60a          	ld	a,#10
 493  00d4 42            	mul	x,a
 494  00d5 d60003        	ld	a,(L31_KeyEvent+3,x)
 497  00d8 5b01          	addw	sp,#1
 498  00da 81            	ret
 499  00db               L102:
 500                     ; 106 			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
 502  00db ae0001        	ldw	x,#L7_Key_Wait_Timer
 503  00de cd0000        	call	_TimeOutDet_Check
 505  00e1 a30000        	cpw	x,#0
 506  00e4 2751          	jreq	L761
 507                     ; 107 				TimeOut_Record(&Key_Wait_Timer,KEY_CPH_TIME);
 509  00e6 ae0032        	ldw	x,#50
 510  00e9 89            	pushw	x
 511  00ea ae0001        	ldw	x,#L7_Key_Wait_Timer
 512  00ed cd0000        	call	_TimeOut_Record
 514  00f0 85            	popw	x
 515                     ; 108 				KeyState = KEY_STATE_CP;
 517  00f1 35030000      	mov	L11_KeyState,#3
 518                     ; 109 				return KeyEvent[PreKeyIndex][2];
 520  00f5 b600          	ld	a,L56_PreKeyIndex
 521  00f7 97            	ld	xl,a
 522  00f8 a60a          	ld	a,#10
 523  00fa 42            	mul	x,a
 524  00fb d60005        	ld	a,(L31_KeyEvent+5,x)
 527  00fe 5b01          	addw	sp,#1
 528  0100 81            	ret
 529  0101               L57:
 530                     ; 115 			if(PreKeyIndex != KeyIndex){
 532  0101 b600          	ld	a,L56_PreKeyIndex
 533  0103 1101          	cp	a,(OFST+0,sp)
 534  0105 270e          	jreq	L702
 535                     ; 116 				KeyState = KEY_STATE_IDLE;
 537  0107 3f00          	clr	L11_KeyState
 538                     ; 117 				return KeyEvent[PreKeyIndex][4];
 540  0109 b600          	ld	a,L56_PreKeyIndex
 541  010b 97            	ld	xl,a
 542  010c a60a          	ld	a,#10
 543  010e 42            	mul	x,a
 544  010f d60009        	ld	a,(L31_KeyEvent+9,x)
 547  0112 5b01          	addw	sp,#1
 548  0114 81            	ret
 549  0115               L702:
 550                     ; 118 			}else if(TimeOutDet_Check(&Key_Wait_Timer)){
 552  0115 ae0001        	ldw	x,#L7_Key_Wait_Timer
 553  0118 cd0000        	call	_TimeOutDet_Check
 555  011b a30000        	cpw	x,#0
 556  011e 2717          	jreq	L761
 557                     ; 119 				TimeOut_Record(&Key_Wait_Timer,KEY_CPH_TIME);
 559  0120 ae0032        	ldw	x,#50
 560  0123 89            	pushw	x
 561  0124 ae0001        	ldw	x,#L7_Key_Wait_Timer
 562  0127 cd0000        	call	_TimeOut_Record
 564  012a 85            	popw	x
 565                     ; 120 				return KeyEvent[PreKeyIndex][3];
 567  012b b600          	ld	a,L56_PreKeyIndex
 568  012d 97            	ld	xl,a
 569  012e a60a          	ld	a,#10
 570  0130 42            	mul	x,a
 571  0131 d60007        	ld	a,(L31_KeyEvent+7,x)
 574  0134 5b01          	addw	sp,#1
 575  0136 81            	ret
 576  0137               L761:
 577                     ; 130 	return MSG_KEY_NONE;
 579  0137 4f            	clr	a
 582  0138 5b01          	addw	sp,#1
 583  013a 81            	ret
 705                     	switch	.ubsct
 706  0000               L11_KeyState:
 707  0000 00            	ds.b	1
 708  0001               L7_Key_Wait_Timer:
 709  0001 00000000      	ds.b	4
 710  0005               L5_Key_Scan_Timer:
 711  0005 00000000      	ds.b	4
 712  0009               L3_Read_Key_Timer:
 713  0009 00000000      	ds.b	4
 714                     	xref	_TimeOutDet_Check
 715                     	xref	_TimeOut_Record
 716                     	xdef	_KEY_Scan
 717                     	xdef	_KEY_Init
 737                     	end
