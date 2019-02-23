   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
   4                     	bsct
   5  0000               L13_key_msg:
   6  0000 00            	dc.b	0
  43                     ; 28 static void Tim4_Init(void)
  43                     ; 29 {
  45                     	switch	.text
  46  0000               L33_Tim4_Init:
  50                     ; 30 	TIM4_DeInit();
  52  0000 cd0000        	call	_TIM4_DeInit
  54                     ; 31 	TIM4_TimeBaseInit( TIM4_PRESCALER_128,Delay-1);
  56  0003 ae007c        	ldw	x,#124
  57  0006 a607          	ld	a,#7
  58  0008 95            	ld	xh,a
  59  0009 cd0000        	call	_TIM4_TimeBaseInit
  61                     ; 32 	TIM4_PrescalerConfig(TIM4_PRESCALER_128,TIM4_PSCRELOADMODE_IMMEDIATE);
  63  000c ae0001        	ldw	x,#1
  64  000f a607          	ld	a,#7
  65  0011 95            	ld	xh,a
  66  0012 cd0000        	call	_TIM4_PrescalerConfig
  68                     ; 33 	TIM4_ARRPreloadConfig(ENABLE);
  70  0015 a601          	ld	a,#1
  71  0017 cd0000        	call	_TIM4_ARRPreloadConfig
  73                     ; 34 	TIM4_ITConfig( TIM4_IT_UPDATE , ENABLE);
  75  001a ae0001        	ldw	x,#1
  76  001d a601          	ld	a,#1
  77  001f 95            	ld	xh,a
  78  0020 cd0000        	call	_TIM4_ITConfig
  80                     ; 35 	TIM4_UpdateDisableConfig(DISABLE);
  82  0023 4f            	clr	a
  83  0024 cd0000        	call	_TIM4_UpdateDisableConfig
  85                     ; 36 	TIM4_UpdateRequestConfig( TIM4_UPDATESOURCE_GLOBAL);
  87  0027 4f            	clr	a
  88  0028 cd0000        	call	_TIM4_UpdateRequestConfig
  90                     ; 37 	TIM4_Cmd(ENABLE );
  92  002b a601          	ld	a,#1
  93  002d cd0000        	call	_TIM4_Cmd
  95                     ; 38 }
  98  0030 81            	ret
 126                     ; 44 static void Iwdg_Init(void)
 126                     ; 45 {	
 127                     	switch	.text
 128  0031               L35_Iwdg_Init:
 132                     ; 46 	IWDG_Enable();
 134  0031 cd0000        	call	_IWDG_Enable
 136                     ; 47 	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
 138  0034 a655          	ld	a,#85
 139  0036 cd0000        	call	_IWDG_WriteAccessCmd
 141                     ; 48 	IWDG_SetPrescaler(IWDG_Prescaler_256);
 143  0039 a606          	ld	a,#6
 144  003b cd0000        	call	_IWDG_SetPrescaler
 146                     ; 49 	IWDG_SetReload(0XFF);
 148  003e a6ff          	ld	a,#255
 149  0040 cd0000        	call	_IWDG_SetReload
 151                     ; 50 	IWDG_ReloadCounter();
 153  0043 cd0000        	call	_IWDG_ReloadCounter
 155                     ; 51 }
 158  0046 81            	ret
 184                     ; 53 static System_Sundry_Init(void){
 185                     	switch	.text
 186  0047               L56_System_Sundry_Init:
 190                     ; 54 	GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);		//pwm
 192  0047 4bf0          	push	#240
 193  0049 4b10          	push	#16
 194  004b ae500a        	ldw	x,#20490
 195  004e cd0000        	call	_GPIO_Init
 197  0051 85            	popw	x
 198                     ; 55 	GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
 200  0052 4bf0          	push	#240
 201  0054 4b20          	push	#32
 202  0056 ae500a        	ldw	x,#20490
 203  0059 cd0000        	call	_GPIO_Init
 205  005c 85            	popw	x
 206                     ; 56 	Led1_Set(0);
 208  005d 4b10          	push	#16
 209  005f ae500a        	ldw	x,#20490
 210  0062 cd0000        	call	_GPIO_WriteLow
 212  0065 84            	pop	a
 213                     ; 57 	Led2_Set(0);
 215  0066 4b20          	push	#32
 216  0068 ae500a        	ldw	x,#20490
 217  006b cd0000        	call	_GPIO_WriteLow
 219  006e 84            	pop	a
 220                     ; 58 	GPIO_Init(INT_PORT, INT_PIN, GPIO_MODE_IN_PU_NO_IT);
 222  006f 4b40          	push	#64
 223  0071 4b40          	push	#64
 224  0073 ae500f        	ldw	x,#20495
 225  0076 cd0000        	call	_GPIO_Init
 227  0079 85            	popw	x
 228                     ; 59 	GPIO_Init(INT1_PORT, INT1_PIN, GPIO_MODE_IN_PU_NO_IT);
 230  007a 4b40          	push	#64
 231  007c 4b10          	push	#16
 232  007e ae500f        	ldw	x,#20495
 233  0081 cd0000        	call	_GPIO_Init
 235  0084 85            	popw	x
 236                     ; 60 }
 239  0085 81            	ret
 300                     ; 61 void delay(u16 delay){
 301                     	switch	.text
 302  0086               _delay:
 304  0086 89            	pushw	x
 305  0087 5206          	subw	sp,#6
 306       00000006      OFST:	set	6
 309                     ; 63 	for(i = 0; i < 20;i ++){
 311  0089 5f            	clrw	x
 312  008a 1f01          	ldw	(OFST-5,sp),x
 313  008c               L131:
 314                     ; 64 		for(j = 0;j < 50 ;j ++){
 316  008c 5f            	clrw	x
 317  008d 1f03          	ldw	(OFST-3,sp),x
 318  008f               L731:
 319                     ; 65 			for(l = 0; l< delay;l ++);
 321  008f 5f            	clrw	x
 322  0090 1f05          	ldw	(OFST-1,sp),x
 324  0092 2007          	jra	L151
 325  0094               L541:
 329  0094 1e05          	ldw	x,(OFST-1,sp)
 330  0096 1c0001        	addw	x,#1
 331  0099 1f05          	ldw	(OFST-1,sp),x
 332  009b               L151:
 335  009b 1e05          	ldw	x,(OFST-1,sp)
 336  009d 1307          	cpw	x,(OFST+1,sp)
 337  009f 25f3          	jrult	L541
 338                     ; 64 		for(j = 0;j < 50 ;j ++){
 340  00a1 1e03          	ldw	x,(OFST-3,sp)
 341  00a3 1c0001        	addw	x,#1
 342  00a6 1f03          	ldw	(OFST-3,sp),x
 345  00a8 9c            	rvf
 346  00a9 1e03          	ldw	x,(OFST-3,sp)
 347  00ab a30032        	cpw	x,#50
 348  00ae 2fdf          	jrslt	L731
 349                     ; 63 	for(i = 0; i < 20;i ++){
 351  00b0 1e01          	ldw	x,(OFST-5,sp)
 352  00b2 1c0001        	addw	x,#1
 353  00b5 1f01          	ldw	(OFST-5,sp),x
 356  00b7 9c            	rvf
 357  00b8 1e01          	ldw	x,(OFST-5,sp)
 358  00ba a30014        	cpw	x,#20
 359  00bd 2fcd          	jrslt	L131
 360                     ; 68 }
 363  00bf 5b08          	addw	sp,#8
 364  00c1 81            	ret
 413                     ; 69 void System_Init(void){
 414                     	switch	.text
 415  00c2               _System_Init:
 417  00c2 89            	pushw	x
 418       00000002      OFST:	set	2
 421                     ; 70 	int i = 0;
 423  00c3 5f            	clrw	x
 424  00c4 1f01          	ldw	(OFST-1,sp),x
 425                     ; 71 	CLK_DeInit();
 427  00c6 cd0000        	call	_CLK_DeInit
 429                     ; 73   	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
 431  00c9 4f            	clr	a
 432  00ca cd0000        	call	_CLK_HSIPrescalerConfig
 434                     ; 74 	System_Sundry_Init();
 436  00cd cd0047        	call	L56_System_Sundry_Init
 438                     ; 75 	Tim4_Init();
 440  00d0 cd0000        	call	L33_Tim4_Init
 442                     ; 76 	Commu_Init();
 444  00d3 cd0000        	call	_Commu_Init
 446                     ; 77 	Led_Pwm_Init();	
 448  00d6 ad47          	call	L72_Led_Pwm_Init
 450                     ; 78 	delay(500);
 452  00d8 ae01f4        	ldw	x,#500
 453  00db ada9          	call	_delay
 455                     ; 79 	for(i = 0;i < IIC_NUM;i ++){
 457  00dd 5f            	clrw	x
 458  00de 1f01          	ldw	(OFST-1,sp),x
 459  00e0               L371:
 460                     ; 80 		IIC_Para[i].ID = i;
 462  00e0 1e01          	ldw	x,(OFST-1,sp)
 463  00e2 58            	sllw	x
 464  00e3 1601          	ldw	y,(OFST-1,sp)
 465  00e5 ef3f          	ldw	(L3_IIC_Para,x),y
 466                     ; 81 		IIC_Init(&IIC_Para[i]);
 468  00e7 1e01          	ldw	x,(OFST-1,sp)
 469  00e9 58            	sllw	x
 470  00ea 01            	rrwa	x,a
 471  00eb ab3f          	add	a,#L3_IIC_Para
 472  00ed 2401          	jrnc	L61
 473  00ef 5c            	incw	x
 474  00f0               L61:
 475  00f0 5f            	clrw	x
 476  00f1 97            	ld	xl,a
 477  00f2 cd0000        	call	_IIC_Init
 479                     ; 79 	for(i = 0;i < IIC_NUM;i ++){
 481  00f5 1e01          	ldw	x,(OFST-1,sp)
 482  00f7 1c0001        	addw	x,#1
 483  00fa 1f01          	ldw	(OFST-1,sp),x
 486  00fc 9c            	rvf
 487  00fd 1e01          	ldw	x,(OFST-1,sp)
 488  00ff a30002        	cpw	x,#2
 489  0102 2fdc          	jrslt	L371
 490                     ; 83 	TimeOutDet_Init();
 492  0104 cd0000        	call	_TimeOutDet_Init
 494                     ; 84 	TimeOut_Record(&ONLine_Time, ON_LINE_TIME);
 496  0107 ae012c        	ldw	x,#300
 497  010a 89            	pushw	x
 498  010b ae002a        	ldw	x,#L7_ONLine_Time
 499  010e cd0000        	call	_TimeOut_Record
 501  0111 85            	popw	x
 502                     ; 86 	System_Para.ShutDown_Flag = TRUE;
 504  0112 35010036      	mov	L5_System_Para+8,#1
 505                     ; 87 	System_Para.ShutDown_Cnt = 0;
 507  0116 5f            	clrw	x
 508  0117 bf3b          	ldw	L5_System_Para+13,x
 509                     ; 89 	Iwdg_Init();
 511  0119 cd0031        	call	L35_Iwdg_Init
 513                     ; 90 	enableInterrupts();
 516  011c 9a            rim
 518                     ; 91 }
 522  011d 85            	popw	x
 523  011e 81            	ret
 551                     ; 96 static void Led_Pwm_Init(void) {
 552                     	switch	.text
 553  011f               L72_Led_Pwm_Init:
 557                     ; 97 	TIM1_DeInit(); 
 559  011f cd0000        	call	_TIM1_DeInit
 561                     ; 98   	TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, 600, 0);
 563  0122 4b00          	push	#0
 564  0124 ae0258        	ldw	x,#600
 565  0127 89            	pushw	x
 566  0128 4b00          	push	#0
 567  012a 5f            	clrw	x
 568  012b cd0000        	call	_TIM1_TimeBaseInit
 570  012e 5b04          	addw	sp,#4
 571                     ; 100 	TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 1000, TIM1_OCPOLARITY_LOW,
 571                     ; 101 		TIM1_OCIDLESTATE_SET);
 573  0130 4b55          	push	#85
 574  0132 4b22          	push	#34
 575  0134 ae03e8        	ldw	x,#1000
 576  0137 89            	pushw	x
 577  0138 ae0011        	ldw	x,#17
 578  013b a660          	ld	a,#96
 579  013d 95            	ld	xh,a
 580  013e cd0000        	call	_TIM1_OC4Init
 582  0141 5b04          	addw	sp,#4
 583                     ; 103 	TIM1_Cmd(DISABLE);
 585  0143 4f            	clr	a
 586  0144 cd0000        	call	_TIM1_Cmd
 588                     ; 105 	TIM1_CtrlPWMOutputs(DISABLE);
 590  0147 4f            	clr	a
 591  0148 cd0000        	call	_TIM1_CtrlPWMOutputs
 593                     ; 106 }
 596  014b 81            	ret
 599                     	bsct
 600  0001               L312_value:
 601  0001 0000          	dc.w	0
 602  0003               L512_num:
 603  0003 0000          	dc.w	0
 647                     ; 108 static void Led_Pwm_Handle(void){
 648                     	switch	.text
 649  014c               L112_Led_Pwm_Handle:
 653                     ; 112 	switch(num){
 655  014c be03          	ldw	x,L512_num
 657                     ; 131 			break;
 658  014e 5d            	tnzw	x
 659  014f 2708          	jreq	L712
 660  0151 5a            	decw	x
 661  0152 272b          	jreq	L122
 662  0154               L322:
 663                     ; 130 			num = 0;
 665  0154 5f            	clrw	x
 666  0155 bf03          	ldw	L512_num,x
 667                     ; 131 			break;
 669  0157 2046          	jra	L152
 670  0159               L712:
 671                     ; 114 			TimeOut_Record(&Pwm_Time, 3);
 673  0159 ae0003        	ldw	x,#3
 674  015c 89            	pushw	x
 675  015d ae001a        	ldw	x,#L71_Pwm_Time
 676  0160 cd0000        	call	_TimeOut_Record
 678  0163 85            	popw	x
 679                     ; 115 			if(value ++ > MAX_VALUE){
 681  0164 be01          	ldw	x,L312_value
 682  0166 1c0001        	addw	x,#1
 683  0169 bf01          	ldw	L312_value,x
 684  016b 1d0001        	subw	x,#1
 685  016e a30259        	cpw	x,#601
 686  0171 252c          	jrult	L152
 687                     ; 116 				value = MAX_VALUE;
 689  0173 ae0258        	ldw	x,#600
 690  0176 bf01          	ldw	L312_value,x
 691                     ; 117 				num = 1;
 693  0178 ae0001        	ldw	x,#1
 694  017b bf03          	ldw	L512_num,x
 695  017d 2020          	jra	L152
 696  017f               L122:
 697                     ; 122 			TimeOut_Record(&Pwm_Time, 2);
 699  017f ae0002        	ldw	x,#2
 700  0182 89            	pushw	x
 701  0183 ae001a        	ldw	x,#L71_Pwm_Time
 702  0186 cd0000        	call	_TimeOut_Record
 704  0189 85            	popw	x
 705                     ; 123 			if(value -- == MIN_VALUE){
 707  018a be01          	ldw	x,L312_value
 708  018c 1d0001        	subw	x,#1
 709  018f bf01          	ldw	L312_value,x
 710  0191 1c0001        	addw	x,#1
 711  0194 a30000        	cpw	x,#0
 712  0197 2606          	jrne	L152
 713                     ; 124 				value = MIN_VALUE;
 715  0199 5f            	clrw	x
 716  019a bf01          	ldw	L312_value,x
 717                     ; 125 				num = 0;
 719  019c 5f            	clrw	x
 720  019d bf03          	ldw	L512_num,x
 721  019f               L152:
 722                     ; 134 	TIM1_SetCompare4(value);
 724  019f be01          	ldw	x,L312_value
 725  01a1 cd0000        	call	_TIM1_SetCompare4
 727                     ; 135 }
 730  01a4 81            	ret
 766                     ; 137 static unsigned int System_Get_LedStatus(void){
 767                     	switch	.text
 768  01a5               L752_System_Get_LedStatus:
 770  01a5 88            	push	a
 771       00000001      OFST:	set	1
 774                     ; 138 	unsigned char LedStatus = 0XFF;
 776  01a6 a6ff          	ld	a,#255
 777  01a8 6b01          	ld	(OFST+0,sp),a
 778                     ; 139 	if(System_Para.Foot_Led_Status == FOOT_LED_OFF){
 780  01aa 3d2e          	tnz	L5_System_Para
 781  01ac 2608          	jrne	L772
 782                     ; 140 		LedStatus |= ~KEY1_LED;		// open key1 led
 784  01ae 7b01          	ld	a,(OFST+0,sp)
 785  01b0 aa01          	or	a,#1
 786  01b2 6b01          	ld	(OFST+0,sp),a
 788  01b4 200c          	jra	L103
 789  01b6               L772:
 790                     ; 141 	}else if(System_Para.Foot_Led_Status == FOOT_LED_ON){
 792  01b6 b62e          	ld	a,L5_System_Para
 793  01b8 a101          	cp	a,#1
 794  01ba 2606          	jrne	L103
 795                     ; 142 		LedStatus &= KEY1_LED;
 797  01bc 7b01          	ld	a,(OFST+0,sp)
 798  01be a4fe          	and	a,#254
 799  01c0 6b01          	ld	(OFST+0,sp),a
 800  01c2               L103:
 801                     ; 144 	if(System_Para.CH_Status == CH_A_OFF){
 803  01c2 3d2f          	tnz	L5_System_Para+1
 804  01c4 260e          	jrne	L503
 805                     ; 145 		LedStatus |= ~KEY2_LED;
 807  01c6 7b01          	ld	a,(OFST+0,sp)
 808  01c8 aa02          	or	a,#2
 809  01ca 6b01          	ld	(OFST+0,sp),a
 810                     ; 146 		LedStatus |= ~KEY5_LED;
 812  01cc 7b01          	ld	a,(OFST+0,sp)
 813  01ce aa10          	or	a,#16
 814  01d0 6b01          	ld	(OFST+0,sp),a
 816  01d2 2026          	jra	L703
 817  01d4               L503:
 818                     ; 147 	}else if(System_Para.CH_Status == CH_A_COOL){
 820  01d4 b62f          	ld	a,L5_System_Para+1
 821  01d6 a101          	cp	a,#1
 822  01d8 260e          	jrne	L113
 823                     ; 148 		LedStatus &= KEY5_LED;
 825  01da 7b01          	ld	a,(OFST+0,sp)
 826  01dc a4ef          	and	a,#239
 827  01de 6b01          	ld	(OFST+0,sp),a
 828                     ; 149 		LedStatus |= ~KEY2_LED;
 830  01e0 7b01          	ld	a,(OFST+0,sp)
 831  01e2 aa02          	or	a,#2
 832  01e4 6b01          	ld	(OFST+0,sp),a
 834  01e6 2012          	jra	L703
 835  01e8               L113:
 836                     ; 150 	}else if(System_Para.CH_Status == CH_A_HEAT){
 838  01e8 b62f          	ld	a,L5_System_Para+1
 839  01ea a102          	cp	a,#2
 840  01ec 260c          	jrne	L703
 841                     ; 151 		LedStatus &= KEY2_LED;
 843  01ee 7b01          	ld	a,(OFST+0,sp)
 844  01f0 a4fd          	and	a,#253
 845  01f2 6b01          	ld	(OFST+0,sp),a
 846                     ; 152 		LedStatus |= ~KEY5_LED;
 848  01f4 7b01          	ld	a,(OFST+0,sp)
 849  01f6 aa10          	or	a,#16
 850  01f8 6b01          	ld	(OFST+0,sp),a
 851  01fa               L703:
 852                     ; 154 	if(System_Para.LockFlag){
 854  01fa 3d32          	tnz	L5_System_Para+4
 855  01fc 270e          	jreq	L713
 856                     ; 155 		LedStatus |= ~BACKLIGHT_LED;
 858  01fe 7b01          	ld	a,(OFST+0,sp)
 859  0200 aa40          	or	a,#64
 860  0202 6b01          	ld	(OFST+0,sp),a
 861                     ; 156 		LedStatus &= KEY6_LED;
 863  0204 7b01          	ld	a,(OFST+0,sp)
 864  0206 a4df          	and	a,#223
 865  0208 6b01          	ld	(OFST+0,sp),a
 867  020a 200c          	jra	L123
 868  020c               L713:
 869                     ; 158 		LedStatus &= BACKLIGHT_LED;
 871  020c 7b01          	ld	a,(OFST+0,sp)
 872  020e a4bf          	and	a,#191
 873  0210 6b01          	ld	(OFST+0,sp),a
 874                     ; 159 		LedStatus |= ~KEY6_LED;
 876  0212 7b01          	ld	a,(OFST+0,sp)
 877  0214 aa20          	or	a,#32
 878  0216 6b01          	ld	(OFST+0,sp),a
 879  0218               L123:
 880                     ; 161 	return LedStatus;
 882  0218 7b01          	ld	a,(OFST+0,sp)
 883  021a 5f            	clrw	x
 884  021b 97            	ld	xl,a
 887  021c 84            	pop	a
 888  021d 81            	ret
 937                     ; 164 static void Led_Display(void){
 938                     	switch	.text
 939  021e               L323_Led_Display:
 941  021e 89            	pushw	x
 942       00000002      OFST:	set	2
 945                     ; 165 	unsigned char LedSta = 0,i = 0;
 947  021f 7b01          	ld	a,(OFST-1,sp)
 948  0221 97            	ld	xl,a
 951  0222 7b02          	ld	a,(OFST+0,sp)
 952  0224 97            	ld	xl,a
 953                     ; 167 	LedSta = System_Get_LedStatus();
 955  0225 cd01a5        	call	L752_System_Get_LedStatus
 957  0228 01            	rrwa	x,a
 958  0229 6b01          	ld	(OFST-1,sp),a
 959  022b 02            	rlwa	x,a
 960                     ; 168 	for(i = 0; i < IIC_NUM;i++){
 962  022c 0f02          	clr	(OFST+0,sp)
 963  022e               L743:
 964                     ; 169 		IWDG_ReloadCounter();		
 966  022e cd0000        	call	_IWDG_ReloadCounter
 968                     ; 170 		disableInterrupts();
 971  0231 9b            sim
 973                     ; 171 		IIC_Write_Data(&IIC_Para[i], WRITE_DATA_ADD, LedSta);
 976  0232 7b01          	ld	a,(OFST-1,sp)
 977  0234 88            	push	a
 978  0235 4b5a          	push	#90
 979  0237 7b04          	ld	a,(OFST+2,sp)
 980  0239 5f            	clrw	x
 981  023a 97            	ld	xl,a
 982  023b 58            	sllw	x
 983  023c 01            	rrwa	x,a
 984  023d ab3f          	add	a,#L3_IIC_Para
 985  023f 2401          	jrnc	L03
 986  0241 5c            	incw	x
 987  0242               L03:
 988  0242 5f            	clrw	x
 989  0243 97            	ld	xl,a
 990  0244 cd0000        	call	_IIC_Write_Data
 992  0247 85            	popw	x
 993                     ; 172 		enableInterrupts();
 996  0248 9a            rim
 998                     ; 168 	for(i = 0; i < IIC_NUM;i++){
1001  0249 0c02          	inc	(OFST+0,sp)
1004  024b 7b02          	ld	a,(OFST+0,sp)
1005  024d a102          	cp	a,#2
1006  024f 25dd          	jrult	L743
1007                     ; 174 }
1010  0251 85            	popw	x
1011  0252 81            	ret
1142                     ; 176 static int System_Send_Message(unsigned int cont){
1143                     	switch	.text
1144  0253               L553_System_Send_Message:
1146  0253 89            	pushw	x
1147  0254 5207          	subw	sp,#7
1148       00000007      OFST:	set	7
1151                     ; 178 	TX_Buf.Data_Format.Start = START_FIELD;
1153  0256 a655          	ld	a,#85
1154  0258 6b01          	ld	(OFST-6,sp),a
1155                     ; 179 	TX_Buf.Data_Format.MessageID = NUM1;
1157  025a a601          	ld	a,#1
1158  025c 6b02          	ld	(OFST-5,sp),a
1159                     ; 180 	TX_Buf.Data_Format.Cont1 = Get_High(cont);
1161  025e 9e            	ld	a,xh
1162  025f a4ff          	and	a,#255
1163  0261 6b03          	ld	(OFST-4,sp),a
1164                     ; 181 	TX_Buf.Data_Format.Cont2 = Get_Low(cont);
1166  0263 7b09          	ld	a,(OFST+2,sp)
1167  0265 a4ff          	and	a,#255
1168  0267 6b04          	ld	(OFST-3,sp),a
1169                     ; 182 	TX_Buf.Data_Format.Checksum = (unsigned char)(TX_Buf.Data_Format.Start + TX_Buf.Data_Format.MessageID+
1169                     ; 183 		  TX_Buf.Data_Format.Cont1 +  TX_Buf.Data_Format.Cont2);
1171  0269 7b01          	ld	a,(OFST-6,sp)
1172  026b 1b02          	add	a,(OFST-5,sp)
1173  026d 1b03          	add	a,(OFST-4,sp)
1174  026f 1b04          	add	a,(OFST-3,sp)
1175  0271 6b05          	ld	(OFST-2,sp),a
1176                     ; 184 	TX_Buf.Data_Format.Stop1 = Get_High(STOP_MESSAGE);
1178  0273 a60d          	ld	a,#13
1179  0275 6b06          	ld	(OFST-1,sp),a
1180                     ; 185 	TX_Buf.Data_Format.Stop2 = Get_Low(STOP_MESSAGE);
1182  0277 a60a          	ld	a,#10
1183  0279 6b07          	ld	(OFST+0,sp),a
1184                     ; 186 	disableInterrupts();
1187  027b 9b            sim
1189                     ; 187 	Commu_Sent(&TX_Buf);
1192  027c 96            	ldw	x,sp
1193  027d 1c0001        	addw	x,#OFST-6
1194  0280 cd0000        	call	_Commu_Sent
1196                     ; 188 	enableInterrupts();
1199  0283 9a            rim
1201                     ; 189 }
1205  0284 5b09          	addw	sp,#9
1206  0286 81            	ret
1209                     	bsct
1210  0005               L144_Flag:
1211  0005 00            	dc.b	0
1252                     ; 191 static int System_Backlight_Handle(void){
1253                     	switch	.text
1254  0287               L734_System_Backlight_Handle:
1258                     ; 193 	if(System_Para.CH_Status == CH_A_COOL){
1260  0287 b62f          	ld	a,L5_System_Para+1
1261  0289 a101          	cp	a,#1
1262  028b 2622          	jrne	L164
1263                     ; 194 		PWM_Set(0);
1265  028d 4f            	clr	a
1266  028e cd0000        	call	_TIM1_Cmd
1268  0291 4f            	clr	a
1269  0292 cd0000        	call	_TIM1_CtrlPWMOutputs
1271                     ; 195 		TIM1_SetCompare4(1000);
1273  0295 ae03e8        	ldw	x,#1000
1274  0298 cd0000        	call	_TIM1_SetCompare4
1276                     ; 196 		Led1_Set(1);
1278  029b 4b10          	push	#16
1279  029d ae500a        	ldw	x,#20490
1280  02a0 cd0000        	call	_GPIO_WriteHigh
1282  02a3 84            	pop	a
1283                     ; 197 		Led2_Set(0);
1285  02a4 4b20          	push	#32
1286  02a6 ae500a        	ldw	x,#20490
1287  02a9 cd0000        	call	_GPIO_WriteLow
1289  02ac 84            	pop	a
1290                     ; 198 		Flag = 0;
1292  02ad 3f05          	clr	L144_Flag
1293  02af               L164:
1294                     ; 200 	if(System_Para.CH_Status == CH_A_HEAT){
1296  02af b62f          	ld	a,L5_System_Para+1
1297  02b1 a102          	cp	a,#2
1298  02b3 2622          	jrne	L364
1299                     ; 201 		PWM_Set(0);
1301  02b5 4f            	clr	a
1302  02b6 cd0000        	call	_TIM1_Cmd
1304  02b9 4f            	clr	a
1305  02ba cd0000        	call	_TIM1_CtrlPWMOutputs
1307                     ; 202 		TIM1_SetCompare4(1000);
1309  02bd ae03e8        	ldw	x,#1000
1310  02c0 cd0000        	call	_TIM1_SetCompare4
1312                     ; 203 		Led1_Set(0);
1314  02c3 4b10          	push	#16
1315  02c5 ae500a        	ldw	x,#20490
1316  02c8 cd0000        	call	_GPIO_WriteLow
1318  02cb 84            	pop	a
1319                     ; 204 		Led2_Set(1);
1321  02cc 4b20          	push	#32
1322  02ce ae500a        	ldw	x,#20490
1323  02d1 cd0000        	call	_GPIO_WriteHigh
1325  02d4 84            	pop	a
1326                     ; 205 		Flag = 0;
1328  02d5 3f05          	clr	L144_Flag
1329  02d7               L364:
1330                     ; 207 	if(System_Para.CH_Status == CH_A_OFF && System_Para.Foot_Led_Status == FOOT_LED_ON){
1332  02d7 3d2f          	tnz	L5_System_Para+1
1333  02d9 262a          	jrne	L564
1335  02db b62e          	ld	a,L5_System_Para
1336  02dd a101          	cp	a,#1
1337  02df 2624          	jrne	L564
1338                     ; 208 		Led2_Set(0);
1340  02e1 4b20          	push	#32
1341  02e3 ae500a        	ldw	x,#20490
1342  02e6 cd0000        	call	_GPIO_WriteLow
1344  02e9 84            	pop	a
1345                     ; 209 		PWM_Set(1);
1347  02ea a601          	ld	a,#1
1348  02ec cd0000        	call	_TIM1_Cmd
1350  02ef a601          	ld	a,#1
1351  02f1 cd0000        	call	_TIM1_CtrlPWMOutputs
1353                     ; 210 		if(!Flag){
1355  02f4 3d05          	tnz	L144_Flag
1356  02f6 260d          	jrne	L564
1357                     ; 211 			Flag = 1;
1359  02f8 35010005      	mov	L144_Flag,#1
1360                     ; 212 			TimeOut_Record(&Pwm_Time, 0);
1362  02fc 5f            	clrw	x
1363  02fd 89            	pushw	x
1364  02fe ae001a        	ldw	x,#L71_Pwm_Time
1365  0301 cd0000        	call	_TimeOut_Record
1367  0304 85            	popw	x
1368  0305               L564:
1369                     ; 215 	if(System_Para.CH_Status == CH_A_OFF && System_Para.Foot_Led_Status == FOOT_LED_OFF){
1371  0305 3d2f          	tnz	L5_System_Para+1
1372  0307 2624          	jrne	L174
1374  0309 3d2e          	tnz	L5_System_Para
1375  030b 2620          	jrne	L174
1376                     ; 216 		Led1_Set(0);
1378  030d 4b10          	push	#16
1379  030f ae500a        	ldw	x,#20490
1380  0312 cd0000        	call	_GPIO_WriteLow
1382  0315 84            	pop	a
1383                     ; 217 		Led2_Set(0);
1385  0316 4b20          	push	#32
1386  0318 ae500a        	ldw	x,#20490
1387  031b cd0000        	call	_GPIO_WriteLow
1389  031e 84            	pop	a
1390                     ; 218 		PWM_Set(0);
1392  031f 4f            	clr	a
1393  0320 cd0000        	call	_TIM1_Cmd
1395  0323 4f            	clr	a
1396  0324 cd0000        	call	_TIM1_CtrlPWMOutputs
1398                     ; 219 		TIM1_SetCompare4(0);
1400  0327 5f            	clrw	x
1401  0328 cd0000        	call	_TIM1_SetCompare4
1403                     ; 220 		Flag = 0;
1405  032b 3f05          	clr	L144_Flag
1406  032d               L174:
1407                     ; 222 	return 1;
1409  032d ae0001        	ldw	x,#1
1412  0330 81            	ret
1415                     	bsct
1416  0006               L125_SentFlag:
1417  0006 00            	dc.b	0
1418  0007               L335_SentFlag:
1419  0007 00            	dc.b	0
1420  0008               L545_SentFlag:
1421  0008 00            	dc.b	0
1422                     	switch	.ubsct
1423  0000               L774_RunFlag:
1424  0000 0000          	ds.b	2
1425  0002               L574_RelaseFlag:
1426  0002 0000          	ds.b	2
1510                     ; 225 static void System_Touch_DataHandle(void){
1511                     	switch	.text
1512  0331               L374_System_Touch_DataHandle:
1516                     ; 229 	if(!INT1_Read()){
1518  0331 4b10          	push	#16
1519  0333 ae500f        	ldw	x,#20495
1520  0336 cd0000        	call	_GPIO_ReadInputPin
1522  0339 5b01          	addw	sp,#1
1523  033b 4d            	tnz	a
1524  033c 2622          	jrne	L706
1525                     ; 230 		disableInterrupts();
1528  033e 9b            sim
1530                     ; 232 		memset(ReadBuf,0,sizeof(ReadBuf));
1533  033f ae0002        	ldw	x,#2
1534  0342               L04:
1535  0342 6f0b          	clr	(L52_ReadBuf-1,x)
1536  0344 5a            	decw	x
1537  0345 26fb          	jrne	L04
1538                     ; 233 		IIC_Read_Data(&IIC_Para[TP_ID], READ_DATA_ADD, &ReadBuf[TP_ID]);
1540  0347 ae000d        	ldw	x,#L52_ReadBuf+1
1541  034a 89            	pushw	x
1542  034b 4b5b          	push	#91
1543  034d ae0041        	ldw	x,#L3_IIC_Para+2
1544  0350 cd0000        	call	_IIC_Read_Data
1546  0353 5b03          	addw	sp,#3
1547                     ; 234 		enableInterrupts();
1550  0355 9a            rim
1552                     ; 235 		if(System_Para.Pushrod_Status != PUSHROD_STOP){
1555  0356 3d30          	tnz	L5_System_Para+2
1556  0358 2706          	jreq	L706
1557                     ; 236 			System_Para.Pushrod_Status = PUSHROD_STOP;
1559  035a 3f30          	clr	L5_System_Para+2
1560                     ; 237 			System_Para.Updata_Flag = TRUE;
1562  035c 35010033      	mov	L5_System_Para+5,#1
1563  0360               L706:
1564                     ; 241 	if(!INT_Read()){
1566  0360 4b40          	push	#64
1567  0362 ae500f        	ldw	x,#20495
1568  0365 cd0000        	call	_GPIO_ReadInputPin
1570  0368 5b01          	addw	sp,#1
1571  036a 4d            	tnz	a
1572  036b 2622          	jrne	L316
1573                     ; 242 		disableInterrupts();
1576  036d 9b            sim
1578                     ; 244 		memset(ReadBuf,0,sizeof(ReadBuf));
1581  036e ae0002        	ldw	x,#2
1582  0371               L24:
1583  0371 6f0b          	clr	(L52_ReadBuf-1,x)
1584  0373 5a            	decw	x
1585  0374 26fb          	jrne	L24
1586                     ; 245 		IIC_Read_Data(&IIC_Para[CHG_ID], READ_DATA_ADD, &ReadBuf[CHG_ID]);
1588  0376 ae000c        	ldw	x,#L52_ReadBuf
1589  0379 89            	pushw	x
1590  037a 4b5b          	push	#91
1591  037c ae003f        	ldw	x,#L3_IIC_Para
1592  037f cd0000        	call	_IIC_Read_Data
1594  0382 5b03          	addw	sp,#3
1595                     ; 246 		enableInterrupts();
1598  0384 9a            rim
1600                     ; 247 		if(System_Para.Pushrod_Status != PUSHROD_STOP){
1603  0385 3d30          	tnz	L5_System_Para+2
1604  0387 2706          	jreq	L316
1605                     ; 248 			System_Para.Pushrod_Status = PUSHROD_STOP;
1607  0389 3f30          	clr	L5_System_Para+2
1608                     ; 249 			System_Para.Updata_Flag = TRUE;
1610  038b 35010033      	mov	L5_System_Para+5,#1
1611  038f               L316:
1612                     ; 255 	switch(ReadBuf[TP_ID]){
1614  038f b60d          	ld	a,L52_ReadBuf+1
1616                     ; 400 			break;
1617  0391 4d            	tnz	a
1618  0392 2735          	jreq	L305
1619  0394 4a            	dec	a
1620  0395 2603          	jrne	L47
1621  0397 cc0525        	jp	L515
1622  039a               L47:
1623  039a 4a            	dec	a
1624  039b 273b          	jreq	L505
1625  039d a002          	sub	a,#2
1626  039f 2603cc042c    	jreq	L705
1627  03a4 a004          	sub	a,#4
1628  03a6 2603          	jrne	L67
1629  03a8 cc056d        	jp	L715
1630  03ab               L67:
1631  03ab a008          	sub	a,#8
1632  03ad 2603          	jrne	L001
1633  03af cc0480        	jp	L115
1634  03b2               L001:
1635  03b2 a010          	sub	a,#16
1636  03b4 2603          	jrne	L201
1637  03b6 cc04d4        	jp	L315
1638  03b9               L201:
1639  03b9               L325:
1640                     ; 397 			RelaseFlag[TP_ID] = 0;
1642  03b9 3f03          	clr	L574_RelaseFlag+1
1643                     ; 398 			RunFlag[TP_ID] = 0;			
1645  03bb 3f01          	clr	L774_RunFlag+1
1646                     ; 399 			memset(ReadBuf,0,sizeof(ReadBuf));
1648  03bd ae0002        	ldw	x,#2
1649  03c0               L65:
1650  03c0 6f0b          	clr	(L52_ReadBuf-1,x)
1651  03c2 5a            	decw	x
1652  03c3 26fb          	jrne	L65
1653                     ; 400 			break;
1655  03c5 acad05ad      	jpf	L126
1656  03c9               L305:
1657                     ; 257 			if(ReadBuf[TP_ID] == 0x00){	
1659  03c9 3d0d          	tnz	L52_ReadBuf+1
1660  03cb 2703          	jreq	L401
1661  03cd cc05ad        	jp	L126
1662  03d0               L401:
1663                     ; 258 				RelaseFlag[TP_ID] = 0;
1665  03d0 3f03          	clr	L574_RelaseFlag+1
1666                     ; 259 				RunFlag[TP_ID] = 0;
1668  03d2 3f01          	clr	L774_RunFlag+1
1669  03d4 acad05ad      	jpf	L126
1670  03d8               L505:
1671                     ; 264 			if(!System_Para.LockFlag){
1673  03d8 3d32          	tnz	L5_System_Para+4
1674  03da 2644          	jrne	L526
1675                     ; 265 				if(!RelaseFlag[TP_ID]){
1677  03dc 3d03          	tnz	L574_RelaseFlag+1
1678  03de 260f          	jrne	L726
1679                     ; 266 					RelaseFlag[TP_ID] = 1;
1681  03e0 35010003      	mov	L574_RelaseFlag+1,#1
1682                     ; 267 					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
1684  03e4 ae0050        	ldw	x,#80
1685  03e7 89            	pushw	x
1686  03e8 ae0012        	ldw	x,#L32_Scan_Time+4
1687  03eb cd0000        	call	_TimeOut_Record
1689  03ee 85            	popw	x
1690  03ef               L726:
1691                     ; 269 				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
1693  03ef ae0012        	ldw	x,#L32_Scan_Time+4
1694  03f2 cd0000        	call	_TimeOutDet_Check
1696  03f5 a30000        	cpw	x,#0
1697  03f8 2603          	jrne	L601
1698  03fa cc05ad        	jp	L126
1699  03fd               L601:
1700                     ; 270 					if(!RunFlag[TP_ID]){
1702  03fd 3d01          	tnz	L774_RunFlag+1
1703  03ff 2703          	jreq	L011
1704  0401 cc05ad        	jp	L126
1705  0404               L011:
1706                     ; 271 						System_Para.Updata_Flag = TRUE;
1708  0404 35010033      	mov	L5_System_Para+5,#1
1709                     ; 272 						RunFlag[TP_ID] = TRUE;
1711  0408 35010001      	mov	L774_RunFlag+1,#1
1712                     ; 273 						if(System_Para.CH_Status != CH_A_HEAT){
1714  040c b62f          	ld	a,L5_System_Para+1
1715  040e a102          	cp	a,#2
1716  0410 2708          	jreq	L536
1717                     ; 274 							System_Para.CH_Status = CH_A_HEAT;
1719  0412 3502002f      	mov	L5_System_Para+1,#2
1721  0416 acad05ad      	jpf	L126
1722  041a               L536:
1723                     ; 276 							System_Para.CH_Status = CH_A_OFF;
1725  041a 3f2f          	clr	L5_System_Para+1
1726  041c acad05ad      	jpf	L126
1727  0420               L526:
1728                     ; 281 				memset(ReadBuf,0,sizeof(ReadBuf));
1730  0420 ae0002        	ldw	x,#2
1731  0423               L44:
1732  0423 6f0b          	clr	(L52_ReadBuf-1,x)
1733  0425 5a            	decw	x
1734  0426 26fb          	jrne	L44
1735  0428 acad05ad      	jpf	L126
1736  042c               L705:
1737                     ; 285 			if(!System_Para.LockFlag){
1739  042c 3d32          	tnz	L5_System_Para+4
1740  042e 2644          	jrne	L346
1741                     ; 286 				if(!RelaseFlag[TP_ID]){
1743  0430 3d03          	tnz	L574_RelaseFlag+1
1744  0432 260f          	jrne	L546
1745                     ; 287 					RelaseFlag[TP_ID] = TRUE;
1747  0434 35010003      	mov	L574_RelaseFlag+1,#1
1748                     ; 288 					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
1750  0438 ae0050        	ldw	x,#80
1751  043b 89            	pushw	x
1752  043c ae0012        	ldw	x,#L32_Scan_Time+4
1753  043f cd0000        	call	_TimeOut_Record
1755  0442 85            	popw	x
1756  0443               L546:
1757                     ; 290 				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
1759  0443 ae0012        	ldw	x,#L32_Scan_Time+4
1760  0446 cd0000        	call	_TimeOutDet_Check
1762  0449 a30000        	cpw	x,#0
1763  044c 2603          	jrne	L211
1764  044e cc05ad        	jp	L126
1765  0451               L211:
1766                     ; 291 					if(!RunFlag[TP_ID]){
1768  0451 3d01          	tnz	L774_RunFlag+1
1769  0453 2703          	jreq	L411
1770  0455 cc05ad        	jp	L126
1771  0458               L411:
1772                     ; 292 						RunFlag[TP_ID] = 1;
1774  0458 35010001      	mov	L774_RunFlag+1,#1
1775                     ; 293 						System_Para.Updata_Flag = TRUE;	
1777  045c 35010033      	mov	L5_System_Para+5,#1
1778                     ; 294 						if(System_Para.Foot_Led_Status != FOOT_LED_ON){
1780  0460 b62e          	ld	a,L5_System_Para
1781  0462 a101          	cp	a,#1
1782  0464 2708          	jreq	L356
1783                     ; 295 							System_Para.Foot_Led_Status = FOOT_LED_ON;
1785  0466 3501002e      	mov	L5_System_Para,#1
1787  046a acad05ad      	jpf	L126
1788  046e               L356:
1789                     ; 297 							System_Para.Foot_Led_Status = FOOT_LED_OFF;
1791  046e 3f2e          	clr	L5_System_Para
1792  0470 acad05ad      	jpf	L126
1793  0474               L346:
1794                     ; 302 				memset(ReadBuf,0,sizeof(ReadBuf));
1796  0474 ae0002        	ldw	x,#2
1797  0477               L64:
1798  0477 6f0b          	clr	(L52_ReadBuf-1,x)
1799  0479 5a            	decw	x
1800  047a 26fb          	jrne	L64
1801  047c acad05ad      	jpf	L126
1802  0480               L115:
1803                     ; 306 			if(!System_Para.LockFlag){
1805  0480 3d32          	tnz	L5_System_Para+4
1806  0482 2644          	jrne	L166
1807                     ; 307 				if(!RelaseFlag[TP_ID]){
1809  0484 3d03          	tnz	L574_RelaseFlag+1
1810  0486 260f          	jrne	L366
1811                     ; 308 					RelaseFlag[TP_ID] = TRUE;
1813  0488 35010003      	mov	L574_RelaseFlag+1,#1
1814                     ; 309 					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
1816  048c ae0050        	ldw	x,#80
1817  048f 89            	pushw	x
1818  0490 ae0012        	ldw	x,#L32_Scan_Time+4
1819  0493 cd0000        	call	_TimeOut_Record
1821  0496 85            	popw	x
1822  0497               L366:
1823                     ; 311 				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
1825  0497 ae0012        	ldw	x,#L32_Scan_Time+4
1826  049a cd0000        	call	_TimeOutDet_Check
1828  049d a30000        	cpw	x,#0
1829  04a0 2603          	jrne	L611
1830  04a2 cc05ad        	jp	L126
1831  04a5               L611:
1832                     ; 312 					if(!RunFlag[TP_ID]){
1834  04a5 3d01          	tnz	L774_RunFlag+1
1835  04a7 2703          	jreq	L021
1836  04a9 cc05ad        	jp	L126
1837  04ac               L021:
1838                     ; 313 						System_Para.Updata_Flag = TRUE;
1840  04ac 35010033      	mov	L5_System_Para+5,#1
1841                     ; 314 						RunFlag[TP_ID] = TRUE;
1843  04b0 35010001      	mov	L774_RunFlag+1,#1
1844                     ; 315 						if(System_Para.CH_Status != CH_A_COOL){
1846  04b4 b62f          	ld	a,L5_System_Para+1
1847  04b6 a101          	cp	a,#1
1848  04b8 2708          	jreq	L176
1849                     ; 316 							System_Para.CH_Status = CH_A_COOL;
1851  04ba 3501002f      	mov	L5_System_Para+1,#1
1853  04be acad05ad      	jpf	L126
1854  04c2               L176:
1855                     ; 318 							System_Para.CH_Status = CH_A_OFF;
1857  04c2 3f2f          	clr	L5_System_Para+1
1858  04c4 acad05ad      	jpf	L126
1859  04c8               L166:
1860                     ; 323 				memset(ReadBuf,0,sizeof(ReadBuf));
1862  04c8 ae0002        	ldw	x,#2
1863  04cb               L05:
1864  04cb 6f0b          	clr	(L52_ReadBuf-1,x)
1865  04cd 5a            	decw	x
1866  04ce 26fb          	jrne	L05
1867  04d0 acad05ad      	jpf	L126
1868  04d4               L315:
1869                     ; 328 			if(!System_Para.LockFlag){
1871  04d4 3d32          	tnz	L5_System_Para+4
1872  04d6 2642          	jrne	L776
1873                     ; 329 				if(!RelaseFlag[TP_ID]){
1875  04d8 3d03          	tnz	L574_RelaseFlag+1
1876  04da 2619          	jrne	L107
1877                     ; 330 					RelaseFlag[TP_ID] = 1;
1879  04dc 35010003      	mov	L574_RelaseFlag+1,#1
1880                     ; 331 					TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME);
1882  04e0 ae00c8        	ldw	x,#200
1883  04e3 89            	pushw	x
1884  04e4 ae0012        	ldw	x,#L32_Scan_Time+4
1885  04e7 cd0000        	call	_TimeOut_Record
1887  04ea 85            	popw	x
1888                     ; 332 					if(System_Para.Pushrod_Status != PUSHROD_STOP){
1890  04eb 3d30          	tnz	L5_System_Para+2
1891  04ed 2706          	jreq	L107
1892                     ; 333 						System_Para.Updata_Flag = TRUE;
1894  04ef 35010033      	mov	L5_System_Para+5,#1
1895                     ; 334 						System_Para.Pushrod_Status = PUSHROD_STOP;
1897  04f3 3f30          	clr	L5_System_Para+2
1898  04f5               L107:
1899                     ; 337 				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
1901  04f5 ae0012        	ldw	x,#L32_Scan_Time+4
1902  04f8 cd0000        	call	_TimeOutDet_Check
1904  04fb a30000        	cpw	x,#0
1905  04fe 2603          	jrne	L221
1906  0500 cc05ad        	jp	L126
1907  0503               L221:
1908                     ; 338 					if(!RunFlag[TP_ID]){
1910  0503 3d01          	tnz	L774_RunFlag+1
1911  0505 2703          	jreq	L421
1912  0507 cc05ad        	jp	L126
1913  050a               L421:
1914                     ; 339 						RunFlag[TP_ID] = 1;
1916  050a 35010001      	mov	L774_RunFlag+1,#1
1917                     ; 340 						System_Para.Updata_Flag = TRUE;	
1919  050e 35010033      	mov	L5_System_Para+5,#1
1920                     ; 341 						System_Para.Pushrod_Status = PUSHROD_A_CLOSE;
1922  0512 35020030      	mov	L5_System_Para+2,#2
1923  0516 acad05ad      	jpf	L126
1924  051a               L776:
1925                     ; 345 				memset(ReadBuf,0,sizeof(ReadBuf));
1927  051a ae0002        	ldw	x,#2
1928  051d               L25:
1929  051d 6f0b          	clr	(L52_ReadBuf-1,x)
1930  051f 5a            	decw	x
1931  0520 26fb          	jrne	L25
1932  0522 cc05ad        	jra	L126
1933  0525               L515:
1934                     ; 352 			if(!System_Para.LockFlag){
1936  0525 3d32          	tnz	L5_System_Para+4
1937  0527 263a          	jrne	L317
1938                     ; 353 				if(!RelaseFlag[TP_ID]){
1940  0529 3d03          	tnz	L574_RelaseFlag+1
1941  052b 2619          	jrne	L517
1942                     ; 354 					RelaseFlag[TP_ID] = 1;
1944  052d 35010003      	mov	L574_RelaseFlag+1,#1
1945                     ; 355 					TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME);
1947  0531 ae00c8        	ldw	x,#200
1948  0534 89            	pushw	x
1949  0535 ae0012        	ldw	x,#L32_Scan_Time+4
1950  0538 cd0000        	call	_TimeOut_Record
1952  053b 85            	popw	x
1953                     ; 356 					if(System_Para.Pushrod_Status != PUSHROD_STOP){
1955  053c 3d30          	tnz	L5_System_Para+2
1956  053e 2706          	jreq	L517
1957                     ; 357 						System_Para.Updata_Flag = TRUE;
1959  0540 35010033      	mov	L5_System_Para+5,#1
1960                     ; 358 						System_Para.Pushrod_Status = PUSHROD_STOP;
1962  0544 3f30          	clr	L5_System_Para+2
1963  0546               L517:
1964                     ; 361 				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
1966  0546 ae0012        	ldw	x,#L32_Scan_Time+4
1967  0549 cd0000        	call	_TimeOutDet_Check
1969  054c a30000        	cpw	x,#0
1970  054f 275c          	jreq	L126
1971                     ; 362 					if(!RunFlag[TP_ID]){
1973  0551 3d01          	tnz	L774_RunFlag+1
1974  0553 2658          	jrne	L126
1975                     ; 363 						RunFlag[TP_ID] = 1;
1977  0555 35010001      	mov	L774_RunFlag+1,#1
1978                     ; 364 						System_Para.Updata_Flag = TRUE;	
1980  0559 35010033      	mov	L5_System_Para+5,#1
1981                     ; 365 						System_Para.Pushrod_Status = PUSHROD_A_OPEN;
1983  055d 35010030      	mov	L5_System_Para+2,#1
1984  0561 204a          	jra	L126
1985  0563               L317:
1986                     ; 369 				memset(ReadBuf,0,sizeof(ReadBuf));
1988  0563 ae0002        	ldw	x,#2
1989  0566               L45:
1990  0566 6f0b          	clr	(L52_ReadBuf-1,x)
1991  0568 5a            	decw	x
1992  0569 26fb          	jrne	L45
1993  056b 2040          	jra	L126
1994  056d               L715:
1995                     ; 375 			if(!RelaseFlag[TP_ID]){
1997  056d 3d03          	tnz	L574_RelaseFlag+1
1998  056f 260f          	jrne	L727
1999                     ; 376 				RelaseFlag[TP_ID] = 1;
2001  0571 35010003      	mov	L574_RelaseFlag+1,#1
2002                     ; 377 				TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME + 200);
2004  0575 ae0190        	ldw	x,#400
2005  0578 89            	pushw	x
2006  0579 ae0012        	ldw	x,#L32_Scan_Time+4
2007  057c cd0000        	call	_TimeOut_Record
2009  057f 85            	popw	x
2010  0580               L727:
2011                     ; 379 			if(TimeOutDet_Check(&Scan_Time[TP_ID])){
2013  0580 ae0012        	ldw	x,#L32_Scan_Time+4
2014  0583 cd0000        	call	_TimeOutDet_Check
2016  0586 a30000        	cpw	x,#0
2017  0589 2722          	jreq	L126
2018                     ; 381 				if(!RunFlag[TP_ID]){
2020  058b 3d01          	tnz	L774_RunFlag+1
2021  058d 261e          	jrne	L126
2022                     ; 382 					RunFlag[TP_ID] = 1;
2024  058f 35010001      	mov	L774_RunFlag+1,#1
2025                     ; 383 					System_Para.Updata_Flag = TRUE;
2027  0593 35010033      	mov	L5_System_Para+5,#1
2028                     ; 384 					if(!System_Para.LockFlag){
2030  0597 3d32          	tnz	L5_System_Para+4
2031  0599 2609          	jrne	L537
2032                     ; 385 						System_Para.LockFlag = TRUE;
2034  059b 35010032      	mov	L5_System_Para+4,#1
2035                     ; 386 						System_Para.SentCnt = 0;
2037  059f 5f            	clrw	x
2038  05a0 bf3d          	ldw	L5_System_Para+15,x
2040  05a2 2009          	jra	L126
2041  05a4               L537:
2042                     ; 388 						System_Para.LockFlag = FALSE;
2044  05a4 3f32          	clr	L5_System_Para+4
2045                     ; 389 						System_Para.ShutDown_Flag = TRUE;
2047  05a6 35010036      	mov	L5_System_Para+8,#1
2048                     ; 390 						System_Para.ShutDown_Cnt = 0;
2050  05aa 5f            	clrw	x
2051  05ab bf3b          	ldw	L5_System_Para+13,x
2052  05ad               L126:
2053                     ; 406 	switch(ReadBuf[CHG_ID]){
2055  05ad b60c          	ld	a,L52_ReadBuf
2057                     ; 555 			break;
2058  05af 4d            	tnz	a
2059  05b0 2735          	jreq	L525
2060  05b2 4a            	dec	a
2061  05b3 2603          	jrne	L621
2062  05b5 cc0747        	jp	L145
2063  05b8               L621:
2064  05b8 4a            	dec	a
2065  05b9 273b          	jreq	L725
2066  05bb a002          	sub	a,#2
2067  05bd 2603cc064a    	jreq	L135
2068  05c2 a004          	sub	a,#4
2069  05c4 2603          	jrne	L031
2070  05c6 cc078f        	jp	L345
2071  05c9               L031:
2072  05c9 a008          	sub	a,#8
2073  05cb 2603          	jrne	L231
2074  05cd cc06a2        	jp	L535
2075  05d0               L231:
2076  05d0 a010          	sub	a,#16
2077  05d2 2603          	jrne	L431
2078  05d4 cc06f6        	jp	L735
2079  05d7               L431:
2080  05d7               L745:
2081                     ; 552 			RelaseFlag[CHG_ID] = 0;
2083  05d7 3f02          	clr	L574_RelaseFlag
2084                     ; 553 			RunFlag[CHG_ID] = 0;
2086  05d9 3f00          	clr	L774_RunFlag
2087                     ; 554 			memset(ReadBuf,0,sizeof(ReadBuf));
2089  05db ae0002        	ldw	x,#2
2090  05de               L27:
2091  05de 6f0b          	clr	(L52_ReadBuf-1,x)
2092  05e0 5a            	decw	x
2093  05e1 26fb          	jrne	L27
2094                     ; 555 			break;
2096  05e3 accf07cf      	jpf	L347
2097  05e7               L525:
2098                     ; 408 			if(ReadBuf[CHG_ID] == 0x00){	// need to close pushrod
2100  05e7 3d0c          	tnz	L52_ReadBuf
2101  05e9 2703          	jreq	L631
2102  05eb cc07cf        	jp	L347
2103  05ee               L631:
2104                     ; 409 				RelaseFlag[CHG_ID] = 0;
2106  05ee 3f02          	clr	L574_RelaseFlag
2107                     ; 410 				RunFlag[CHG_ID] = 0;
2109  05f0 3f00          	clr	L774_RunFlag
2110  05f2 accf07cf      	jpf	L347
2111  05f6               L725:
2112                     ; 415 			if(!System_Para.LockFlag){
2114  05f6 3d32          	tnz	L5_System_Para+4
2115  05f8 2644          	jrne	L747
2116                     ; 416 				if(!RelaseFlag[CHG_ID]){
2118  05fa 3d02          	tnz	L574_RelaseFlag
2119  05fc 260f          	jrne	L157
2120                     ; 417 					RelaseFlag[CHG_ID] = 1;
2122  05fe 35010002      	mov	L574_RelaseFlag,#1
2123                     ; 418 					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
2125  0602 ae0050        	ldw	x,#80
2126  0605 89            	pushw	x
2127  0606 ae000e        	ldw	x,#L32_Scan_Time
2128  0609 cd0000        	call	_TimeOut_Record
2130  060c 85            	popw	x
2131  060d               L157:
2132                     ; 420 				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2134  060d ae000e        	ldw	x,#L32_Scan_Time
2135  0610 cd0000        	call	_TimeOutDet_Check
2137  0613 a30000        	cpw	x,#0
2138  0616 2603          	jrne	L041
2139  0618 cc07cf        	jp	L347
2140  061b               L041:
2141                     ; 421 					if(!RunFlag[CHG_ID]){
2143  061b 3d00          	tnz	L774_RunFlag
2144  061d 2703          	jreq	L241
2145  061f cc07cf        	jp	L347
2146  0622               L241:
2147                     ; 422 						System_Para.Updata_Flag = TRUE;
2149  0622 35010033      	mov	L5_System_Para+5,#1
2150                     ; 423 						RunFlag[CHG_ID] = TRUE;
2152  0626 35010000      	mov	L774_RunFlag,#1
2153                     ; 424 						if(System_Para.CH_Status != CH_A_HEAT){
2155  062a b62f          	ld	a,L5_System_Para+1
2156  062c a102          	cp	a,#2
2157  062e 2708          	jreq	L757
2158                     ; 425 							System_Para.CH_Status = CH_A_HEAT;
2160  0630 3502002f      	mov	L5_System_Para+1,#2
2162  0634 accf07cf      	jpf	L347
2163  0638               L757:
2164                     ; 427 							System_Para.CH_Status = CH_A_OFF;
2166  0638 3f2f          	clr	L5_System_Para+1
2167  063a accf07cf      	jpf	L347
2168  063e               L747:
2169                     ; 432 				memset(ReadBuf,0,sizeof(ReadBuf));
2171  063e ae0002        	ldw	x,#2
2172  0641               L06:
2173  0641 6f0b          	clr	(L52_ReadBuf-1,x)
2174  0643 5a            	decw	x
2175  0644 26fb          	jrne	L06
2176  0646 accf07cf      	jpf	L347
2177  064a               L135:
2178                     ; 436 			if(!System_Para.LockFlag){
2180  064a 3d32          	tnz	L5_System_Para+4
2181  064c 2648          	jrne	L567
2182                     ; 437 				if(!RelaseFlag[CHG_ID]){
2184  064e 3d02          	tnz	L574_RelaseFlag
2185  0650 260f          	jrne	L767
2186                     ; 438 					RelaseFlag[CHG_ID] = TRUE;
2188  0652 35010002      	mov	L574_RelaseFlag,#1
2189                     ; 439 					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
2191  0656 ae0050        	ldw	x,#80
2192  0659 89            	pushw	x
2193  065a ae000e        	ldw	x,#L32_Scan_Time
2194  065d cd0000        	call	_TimeOut_Record
2196  0660 85            	popw	x
2197  0661               L767:
2198                     ; 441 				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2200  0661 ae000e        	ldw	x,#L32_Scan_Time
2201  0664 cd0000        	call	_TimeOutDet_Check
2203  0667 a30000        	cpw	x,#0
2204  066a 2603          	jrne	L441
2205  066c cc07cf        	jp	L347
2206  066f               L441:
2207                     ; 443 					if(!RunFlag[CHG_ID]){
2209  066f 3d00          	tnz	L774_RunFlag
2210  0671 2703          	jreq	L641
2211  0673 cc07cf        	jp	L347
2212  0676               L641:
2213                     ; 444 						RunFlag[CHG_ID] = 1;
2215  0676 35010000      	mov	L774_RunFlag,#1
2216                     ; 445 						System_Para.Updata_Flag = TRUE;	
2218  067a 35010033      	mov	L5_System_Para+5,#1
2219                     ; 446 						if(!SentFlag){
2221  067e 3d07          	tnz	L335_SentFlag
2222  0680 260c          	jrne	L577
2223                     ; 447 							SentFlag = 1;
2225  0682 35010007      	mov	L335_SentFlag,#1
2226                     ; 448 							System_Para.Foot_Led_Status= FOOT_LED_ON;
2228  0686 3501002e      	mov	L5_System_Para,#1
2230  068a accf07cf      	jpf	L347
2231  068e               L577:
2232                     ; 450 							SentFlag = 0;
2234  068e 3f07          	clr	L335_SentFlag
2235                     ; 451 							System_Para.Foot_Led_Status= FOOT_LED_OFF;
2237  0690 3f2e          	clr	L5_System_Para
2238  0692 accf07cf      	jpf	L347
2239  0696               L567:
2240                     ; 456 				memset(ReadBuf,0,sizeof(ReadBuf));
2242  0696 ae0002        	ldw	x,#2
2243  0699               L26:
2244  0699 6f0b          	clr	(L52_ReadBuf-1,x)
2245  069b 5a            	decw	x
2246  069c 26fb          	jrne	L26
2247  069e accf07cf      	jpf	L347
2248  06a2               L535:
2249                     ; 460 			if(!System_Para.LockFlag){
2251  06a2 3d32          	tnz	L5_System_Para+4
2252  06a4 2644          	jrne	L3001
2253                     ; 461 				if(!RelaseFlag[CHG_ID]){
2255  06a6 3d02          	tnz	L574_RelaseFlag
2256  06a8 260f          	jrne	L5001
2257                     ; 462 					RelaseFlag[CHG_ID] = TRUE;
2259  06aa 35010002      	mov	L574_RelaseFlag,#1
2260                     ; 463 					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
2262  06ae ae0050        	ldw	x,#80
2263  06b1 89            	pushw	x
2264  06b2 ae000e        	ldw	x,#L32_Scan_Time
2265  06b5 cd0000        	call	_TimeOut_Record
2267  06b8 85            	popw	x
2268  06b9               L5001:
2269                     ; 465 				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2271  06b9 ae000e        	ldw	x,#L32_Scan_Time
2272  06bc cd0000        	call	_TimeOutDet_Check
2274  06bf a30000        	cpw	x,#0
2275  06c2 2603          	jrne	L051
2276  06c4 cc07cf        	jp	L347
2277  06c7               L051:
2278                     ; 466 					if(!RunFlag[CHG_ID]){
2280  06c7 3d00          	tnz	L774_RunFlag
2281  06c9 2703          	jreq	L251
2282  06cb cc07cf        	jp	L347
2283  06ce               L251:
2284                     ; 467 						System_Para.Updata_Flag = TRUE;
2286  06ce 35010033      	mov	L5_System_Para+5,#1
2287                     ; 468 						RunFlag[CHG_ID] = TRUE;
2289  06d2 35010000      	mov	L774_RunFlag,#1
2290                     ; 469 						if(System_Para.CH_Status != CH_A_COOL){
2292  06d6 b62f          	ld	a,L5_System_Para+1
2293  06d8 a101          	cp	a,#1
2294  06da 2708          	jreq	L3101
2295                     ; 470 							System_Para.CH_Status = CH_A_COOL;
2297  06dc 3501002f      	mov	L5_System_Para+1,#1
2299  06e0 accf07cf      	jpf	L347
2300  06e4               L3101:
2301                     ; 472 							System_Para.CH_Status = CH_A_OFF;
2303  06e4 3f2f          	clr	L5_System_Para+1
2304  06e6 accf07cf      	jpf	L347
2305  06ea               L3001:
2306                     ; 477 				memset(ReadBuf,0,sizeof(ReadBuf));
2308  06ea ae0002        	ldw	x,#2
2309  06ed               L46:
2310  06ed 6f0b          	clr	(L52_ReadBuf-1,x)
2311  06ef 5a            	decw	x
2312  06f0 26fb          	jrne	L46
2313  06f2 accf07cf      	jpf	L347
2314  06f6               L735:
2315                     ; 482 			if(!System_Para.LockFlag){
2317  06f6 3d32          	tnz	L5_System_Para+4
2318  06f8 2642          	jrne	L1201
2319                     ; 483 				if(!RelaseFlag[CHG_ID]){
2321  06fa 3d02          	tnz	L574_RelaseFlag
2322  06fc 2619          	jrne	L3201
2323                     ; 484 					RelaseFlag[CHG_ID] = 1;
2325  06fe 35010002      	mov	L574_RelaseFlag,#1
2326                     ; 485 					TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME);
2328  0702 ae00c8        	ldw	x,#200
2329  0705 89            	pushw	x
2330  0706 ae000e        	ldw	x,#L32_Scan_Time
2331  0709 cd0000        	call	_TimeOut_Record
2333  070c 85            	popw	x
2334                     ; 486 					if(System_Para.Pushrod_Status != PUSHROD_STOP){
2336  070d 3d30          	tnz	L5_System_Para+2
2337  070f 2706          	jreq	L3201
2338                     ; 487 						System_Para.Updata_Flag = TRUE;
2340  0711 35010033      	mov	L5_System_Para+5,#1
2341                     ; 488 						System_Para.Pushrod_Status = PUSHROD_STOP;
2343  0715 3f30          	clr	L5_System_Para+2
2344  0717               L3201:
2345                     ; 491 				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2347  0717 ae000e        	ldw	x,#L32_Scan_Time
2348  071a cd0000        	call	_TimeOutDet_Check
2350  071d a30000        	cpw	x,#0
2351  0720 2603          	jrne	L451
2352  0722 cc07cf        	jp	L347
2353  0725               L451:
2354                     ; 492 					if(!RunFlag[CHG_ID]){
2356  0725 3d00          	tnz	L774_RunFlag
2357  0727 2703          	jreq	L651
2358  0729 cc07cf        	jp	L347
2359  072c               L651:
2360                     ; 493 						RunFlag[CHG_ID] = 1;
2362  072c 35010000      	mov	L774_RunFlag,#1
2363                     ; 494 						System_Para.Updata_Flag = TRUE;	
2365  0730 35010033      	mov	L5_System_Para+5,#1
2366                     ; 495 						System_Para.Pushrod_Status = PUSHROD_A_CLOSE;
2368  0734 35020030      	mov	L5_System_Para+2,#2
2369  0738 accf07cf      	jpf	L347
2370  073c               L1201:
2371                     ; 499 				memset(ReadBuf,0,sizeof(ReadBuf));
2373  073c ae0002        	ldw	x,#2
2374  073f               L66:
2375  073f 6f0b          	clr	(L52_ReadBuf-1,x)
2376  0741 5a            	decw	x
2377  0742 26fb          	jrne	L66
2378  0744 cc07cf        	jra	L347
2379  0747               L145:
2380                     ; 506 			if(!System_Para.LockFlag){
2382  0747 3d32          	tnz	L5_System_Para+4
2383  0749 263a          	jrne	L5301
2384                     ; 507 				if(!RelaseFlag[CHG_ID]){
2386  074b 3d02          	tnz	L574_RelaseFlag
2387  074d 2619          	jrne	L7301
2388                     ; 508 					RelaseFlag[CHG_ID] = 1;
2390  074f 35010002      	mov	L574_RelaseFlag,#1
2391                     ; 509 					TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME);
2393  0753 ae00c8        	ldw	x,#200
2394  0756 89            	pushw	x
2395  0757 ae000e        	ldw	x,#L32_Scan_Time
2396  075a cd0000        	call	_TimeOut_Record
2398  075d 85            	popw	x
2399                     ; 510 					if(System_Para.Pushrod_Status != PUSHROD_STOP){
2401  075e 3d30          	tnz	L5_System_Para+2
2402  0760 2706          	jreq	L7301
2403                     ; 511 						System_Para.Updata_Flag = TRUE;
2405  0762 35010033      	mov	L5_System_Para+5,#1
2406                     ; 512 						System_Para.Pushrod_Status = PUSHROD_STOP;
2408  0766 3f30          	clr	L5_System_Para+2
2409  0768               L7301:
2410                     ; 515 				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2412  0768 ae000e        	ldw	x,#L32_Scan_Time
2413  076b cd0000        	call	_TimeOutDet_Check
2415  076e a30000        	cpw	x,#0
2416  0771 275c          	jreq	L347
2417                     ; 516 					if(!RunFlag[CHG_ID]){
2419  0773 3d00          	tnz	L774_RunFlag
2420  0775 2658          	jrne	L347
2421                     ; 517 						RunFlag[CHG_ID] = 1;
2423  0777 35010000      	mov	L774_RunFlag,#1
2424                     ; 518 						System_Para.Updata_Flag = TRUE;	
2426  077b 35010033      	mov	L5_System_Para+5,#1
2427                     ; 519 						System_Para.Pushrod_Status = PUSHROD_A_OPEN;
2429  077f 35010030      	mov	L5_System_Para+2,#1
2430  0783 204a          	jra	L347
2431  0785               L5301:
2432                     ; 523 				memset(ReadBuf,0,sizeof(ReadBuf));
2434  0785 ae0002        	ldw	x,#2
2435  0788               L07:
2436  0788 6f0b          	clr	(L52_ReadBuf-1,x)
2437  078a 5a            	decw	x
2438  078b 26fb          	jrne	L07
2439  078d 2040          	jra	L347
2440  078f               L345:
2441                     ; 530 			if(!RelaseFlag[CHG_ID]){
2443  078f 3d02          	tnz	L574_RelaseFlag
2444  0791 260f          	jrne	L1501
2445                     ; 531 				RelaseFlag[CHG_ID] = 1;
2447  0793 35010002      	mov	L574_RelaseFlag,#1
2448                     ; 532 				TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME + 200);
2450  0797 ae0190        	ldw	x,#400
2451  079a 89            	pushw	x
2452  079b ae000e        	ldw	x,#L32_Scan_Time
2453  079e cd0000        	call	_TimeOut_Record
2455  07a1 85            	popw	x
2456  07a2               L1501:
2457                     ; 534 			if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
2459  07a2 ae000e        	ldw	x,#L32_Scan_Time
2460  07a5 cd0000        	call	_TimeOutDet_Check
2462  07a8 a30000        	cpw	x,#0
2463  07ab 2722          	jreq	L347
2464                     ; 536 				if(!RunFlag[CHG_ID]){
2466  07ad 3d00          	tnz	L774_RunFlag
2467  07af 261e          	jrne	L347
2468                     ; 537 					RunFlag[CHG_ID] = 1;
2470  07b1 35010000      	mov	L774_RunFlag,#1
2471                     ; 538 					System_Para.Updata_Flag = TRUE;
2473  07b5 35010033      	mov	L5_System_Para+5,#1
2474                     ; 539 					if(!System_Para.LockFlag){
2476  07b9 3d32          	tnz	L5_System_Para+4
2477  07bb 2609          	jrne	L7501
2478                     ; 540 						System_Para.LockFlag = TRUE;
2480  07bd 35010032      	mov	L5_System_Para+4,#1
2481                     ; 541 						System_Para.SentCnt = 0;
2483  07c1 5f            	clrw	x
2484  07c2 bf3d          	ldw	L5_System_Para+15,x
2486  07c4 2009          	jra	L347
2487  07c6               L7501:
2488                     ; 543 						System_Para.LockFlag = FALSE;
2490  07c6 3f32          	clr	L5_System_Para+4
2491                     ; 544 						System_Para.ShutDown_Flag = TRUE;
2493  07c8 35010036      	mov	L5_System_Para+8,#1
2494                     ; 545 						System_Para.ShutDown_Cnt = 0;
2496  07cc 5f            	clrw	x
2497  07cd bf3b          	ldw	L5_System_Para+13,x
2498  07cf               L347:
2499                     ; 559 }
2502  07cf 81            	ret
2505                     	switch	.ubsct
2506  0004               L3601_OnLine_Data:
2507  0004 0000          	ds.b	2
2560                     ; 562 void System_Handle(void){	
2561                     	switch	.text
2562  07d0               _System_Handle:
2564  07d0 89            	pushw	x
2565       00000002      OFST:	set	2
2568                     ; 565 	IWDG_ReloadCounter();
2570  07d1 cd0000        	call	_IWDG_ReloadCounter
2572                     ; 570 	if(TimeOutDet_Check(&LedRefresh_Time)){
2574  07d4 ae0016        	ldw	x,#L12_LedRefresh_Time
2575  07d7 cd0000        	call	_TimeOutDet_Check
2577  07da a30000        	cpw	x,#0
2578  07dd 270e          	jreq	L7011
2579                     ; 571 		TimeOut_Record(&LedRefresh_Time, LED_REFRESH_TIME);
2581  07df ae0bb8        	ldw	x,#3000
2582  07e2 89            	pushw	x
2583  07e3 ae0016        	ldw	x,#L12_LedRefresh_Time
2584  07e6 cd0000        	call	_TimeOut_Record
2586  07e9 85            	popw	x
2587                     ; 572 		Led_Display();
2589  07ea cd021e        	call	L323_Led_Display
2591  07ed               L7011:
2592                     ; 577 	System_Touch_DataHandle();
2594  07ed cd0331        	call	L374_System_Touch_DataHandle
2596                     ; 583 	if(System_Para.Updata_Flag){		/*if the key is updata,send new data*/
2598  07f0 3d33          	tnz	L5_System_Para+5
2599  07f2 2603          	jrne	L261
2600  07f4 cc08f5        	jp	L1111
2601  07f7               L261:
2602                     ; 584 		unsigned int SentData = 0;
2604  07f7 5f            	clrw	x
2605  07f8 1f01          	ldw	(OFST-1,sp),x
2606                     ; 585 		System_Para.Updata_Flag = FALSE;
2608  07fa 3f33          	clr	L5_System_Para+5
2609                     ; 588 		TimeOut_Record(&LedRefresh_Time, LED_REFRESH_TIME);
2611  07fc ae0bb8        	ldw	x,#3000
2612  07ff 89            	pushw	x
2613  0800 ae0016        	ldw	x,#L12_LedRefresh_Time
2614  0803 cd0000        	call	_TimeOut_Record
2616  0806 85            	popw	x
2617                     ; 589 		System_Para.ShutDown_Cnt = 0;
2619  0807 5f            	clrw	x
2620  0808 bf3b          	ldw	L5_System_Para+13,x
2621                     ; 591 		if(System_Para.CH_Status == CH_A_OFF){
2623  080a 3d2f          	tnz	L5_System_Para+1
2624  080c 261e          	jrne	L3111
2625                     ; 592 			System_Para.Cool_CloseFlag = FALSE;
2627  080e 3f35          	clr	L5_System_Para+7
2628                     ; 593 			System_Para.Heat_CloseFlag = FALSE;
2630  0810 3f34          	clr	L5_System_Para+6
2631                     ; 594 			System_Para.Cool_CloseCnt = 0;
2633  0812 5f            	clrw	x
2634  0813 bf39          	ldw	L5_System_Para+11,x
2635                     ; 595 			System_Para.Heat_CloseCnt = 0;
2637  0815 5f            	clrw	x
2638  0816 bf37          	ldw	L5_System_Para+9,x
2639                     ; 596 			SentData &= ~CONT_CH_A_COOL;
2641  0818 7b02          	ld	a,(OFST+0,sp)
2642  081a a4f7          	and	a,#247
2643  081c 6b02          	ld	(OFST+0,sp),a
2644                     ; 597 			SentData &= ~CONT_CH_A_HEAT;
2646  081e 7b02          	ld	a,(OFST+0,sp)
2647  0820 a4ef          	and	a,#239
2648  0822 6b02          	ld	(OFST+0,sp),a
2649                     ; 598 			SentData |= CONT_CH_A_OFF;
2651  0824 7b02          	ld	a,(OFST+0,sp)
2652  0826 aa04          	or	a,#4
2653  0828 6b02          	ld	(OFST+0,sp),a
2655  082a 2044          	jra	L5111
2656  082c               L3111:
2657                     ; 599 		}else if(System_Para.CH_Status == CH_A_COOL){		
2659  082c b62f          	ld	a,L5_System_Para+1
2660  082e a101          	cp	a,#1
2661  0830 261d          	jrne	L7111
2662                     ; 600 			System_Para.Cool_CloseFlag = TRUE;// start the auto close function
2664  0832 35010035      	mov	L5_System_Para+7,#1
2665                     ; 601 			System_Para.Heat_CloseFlag = FALSE;
2667  0836 3f34          	clr	L5_System_Para+6
2668                     ; 602 			System_Para.Heat_CloseCnt = 0;
2670  0838 5f            	clrw	x
2671  0839 bf37          	ldw	L5_System_Para+9,x
2672                     ; 603 			SentData &= ~CONT_CH_A_HEAT;
2674  083b 7b02          	ld	a,(OFST+0,sp)
2675  083d a4ef          	and	a,#239
2676  083f 6b02          	ld	(OFST+0,sp),a
2677                     ; 604 			SentData &= ~CONT_CH_A_OFF;
2679  0841 7b02          	ld	a,(OFST+0,sp)
2680  0843 a4fb          	and	a,#251
2681  0845 6b02          	ld	(OFST+0,sp),a
2682                     ; 605 			SentData  |= CONT_CH_A_COOL;
2684  0847 7b02          	ld	a,(OFST+0,sp)
2685  0849 aa08          	or	a,#8
2686  084b 6b02          	ld	(OFST+0,sp),a
2688  084d 2021          	jra	L5111
2689  084f               L7111:
2690                     ; 606 		}else if(System_Para.CH_Status == CH_A_HEAT){
2692  084f b62f          	ld	a,L5_System_Para+1
2693  0851 a102          	cp	a,#2
2694  0853 261b          	jrne	L5111
2695                     ; 607 			System_Para.Heat_CloseFlag = TRUE;		// start the auto close function
2697  0855 35010034      	mov	L5_System_Para+6,#1
2698                     ; 608 			System_Para.Cool_CloseFlag = FALSE;
2700  0859 3f35          	clr	L5_System_Para+7
2701                     ; 609 			System_Para.Cool_CloseCnt = 0;
2703  085b 5f            	clrw	x
2704  085c bf39          	ldw	L5_System_Para+11,x
2705                     ; 610 			SentData &= ~CONT_CH_A_OFF;
2707  085e 7b02          	ld	a,(OFST+0,sp)
2708  0860 a4fb          	and	a,#251
2709  0862 6b02          	ld	(OFST+0,sp),a
2710                     ; 611 			SentData  &= ~ CONT_CH_A_COOL;
2712  0864 7b02          	ld	a,(OFST+0,sp)
2713  0866 a4f7          	and	a,#247
2714  0868 6b02          	ld	(OFST+0,sp),a
2715                     ; 612 			SentData |= CONT_CH_A_HEAT;
2717  086a 7b02          	ld	a,(OFST+0,sp)
2718  086c aa10          	or	a,#16
2719  086e 6b02          	ld	(OFST+0,sp),a
2721  0870               L5111:
2722                     ; 618 		if(System_Para.Foot_Led_Status == FOOT_LED_ON){
2724  0870 b62e          	ld	a,L5_System_Para
2725  0872 a101          	cp	a,#1
2726  0874 260e          	jrne	L7211
2727                     ; 619 			SentData &= ~CONT_LED_OFF;
2729  0876 7b02          	ld	a,(OFST+0,sp)
2730  0878 a4fd          	and	a,#253
2731  087a 6b02          	ld	(OFST+0,sp),a
2732                     ; 620 			SentData |= CONT_LED_ON;
2734  087c 7b02          	ld	a,(OFST+0,sp)
2735  087e aa01          	or	a,#1
2736  0880 6b02          	ld	(OFST+0,sp),a
2738  0882 2010          	jra	L1311
2739  0884               L7211:
2740                     ; 621 		}else if(System_Para.Foot_Led_Status == FOOT_LED_OFF){
2742  0884 3d2e          	tnz	L5_System_Para
2743  0886 260c          	jrne	L1311
2744                     ; 622 			SentData &= ~CONT_LED_ON;
2746  0888 7b02          	ld	a,(OFST+0,sp)
2747  088a a4fe          	and	a,#254
2748  088c 6b02          	ld	(OFST+0,sp),a
2749                     ; 623 			SentData |= CONT_LED_OFF;
2751  088e 7b02          	ld	a,(OFST+0,sp)
2752  0890 aa02          	or	a,#2
2753  0892 6b02          	ld	(OFST+0,sp),a
2754  0894               L1311:
2755                     ; 627 		if(System_Para.Pushrod_Status == PUSHROD_STOP ||System_Para.Pushrod_Status == PUSHROD_A_STOP){
2757  0894 3d30          	tnz	L5_System_Para+2
2758  0896 2706          	jreq	L7311
2760  0898 b630          	ld	a,L5_System_Para+2
2761  089a a103          	cp	a,#3
2762  089c 2623          	jrne	L5311
2763  089e               L7311:
2764                     ; 628 			SentData &= ~ CONT_PUSHROD_A_OPEN;
2766  089e 7b02          	ld	a,(OFST+0,sp)
2767  08a0 a4bf          	and	a,#191
2768  08a2 6b02          	ld	(OFST+0,sp),a
2769                     ; 629 			SentData &= ~ CONT_PUSHROD_A_CLOSE;
2771  08a4 7b02          	ld	a,(OFST+0,sp)
2772  08a6 a47f          	and	a,#127
2773  08a8 6b02          	ld	(OFST+0,sp),a
2774                     ; 630 			SentData |= CONT_PUSHROD_STOP;
2776  08aa 7b02          	ld	a,(OFST+0,sp)
2777  08ac aa20          	or	a,#32
2778  08ae 6b02          	ld	(OFST+0,sp),a
2780  08b0               L1411:
2781                     ; 641 		Led_Display();
2783  08b0 cd021e        	call	L323_Led_Display
2785                     ; 644 		System_Backlight_Handle();
2787  08b3 cd0287        	call	L734_System_Backlight_Handle
2789                     ; 647 		System_Send_Message(SentData);
2791  08b6 1e01          	ldw	x,(OFST-1,sp)
2792  08b8 cd0253        	call	L553_System_Send_Message
2794                     ; 648 		OnLine_Data = SentData;
2796  08bb 1e01          	ldw	x,(OFST-1,sp)
2797  08bd bf04          	ldw	L3601_OnLine_Data,x
2798  08bf 2034          	jra	L1111
2799  08c1               L5311:
2800                     ; 631 		}else if(System_Para.Pushrod_Status == PUSHROD_A_OPEN){
2802  08c1 b630          	ld	a,L5_System_Para+2
2803  08c3 a101          	cp	a,#1
2804  08c5 2614          	jrne	L3411
2805                     ; 632 			SentData &= ~ CONT_PUSHROD_A_STOP;
2807  08c7 7b01          	ld	a,(OFST-1,sp)
2808  08c9 a4fe          	and	a,#254
2809  08cb 6b01          	ld	(OFST-1,sp),a
2810                     ; 633 			SentData &= ~ CONT_PUSHROD_A_CLOSE;
2812  08cd 7b02          	ld	a,(OFST+0,sp)
2813  08cf a47f          	and	a,#127
2814  08d1 6b02          	ld	(OFST+0,sp),a
2815                     ; 634 			SentData |= CONT_PUSHROD_A_OPEN;
2817  08d3 7b02          	ld	a,(OFST+0,sp)
2818  08d5 aa40          	or	a,#64
2819  08d7 6b02          	ld	(OFST+0,sp),a
2821  08d9 20d5          	jra	L1411
2822  08db               L3411:
2823                     ; 635 		}else if(System_Para.Pushrod_Status == PUSHROD_A_CLOSE){
2825  08db b630          	ld	a,L5_System_Para+2
2826  08dd a102          	cp	a,#2
2827  08df 26cf          	jrne	L1411
2828                     ; 636 			SentData &= ~ CONT_PUSHROD_A_OPEN;
2830  08e1 7b02          	ld	a,(OFST+0,sp)
2831  08e3 a4bf          	and	a,#191
2832  08e5 6b02          	ld	(OFST+0,sp),a
2833                     ; 637 			SentData &= ~ CONT_PUSHROD_A_STOP;
2835  08e7 7b01          	ld	a,(OFST-1,sp)
2836  08e9 a4fe          	and	a,#254
2837  08eb 6b01          	ld	(OFST-1,sp),a
2838                     ; 638 			SentData |= CONT_PUSHROD_A_CLOSE;
2840  08ed 7b02          	ld	a,(OFST+0,sp)
2841  08ef aa80          	or	a,#128
2842  08f1 6b02          	ld	(OFST+0,sp),a
2843  08f3 20bb          	jra	L1411
2844  08f5               L1111:
2845                     ; 652 	if(TimeOutDet_Check(&ONLine_Time)){
2847  08f5 ae002a        	ldw	x,#L7_ONLine_Time
2848  08f8 cd0000        	call	_TimeOutDet_Check
2850  08fb a30000        	cpw	x,#0
2851  08fe 2710          	jreq	L1511
2852                     ; 653 		TimeOut_Record(&ONLine_Time, ON_LINE_TIME);
2854  0900 ae012c        	ldw	x,#300
2855  0903 89            	pushw	x
2856  0904 ae002a        	ldw	x,#L7_ONLine_Time
2857  0907 cd0000        	call	_TimeOut_Record
2859  090a 85            	popw	x
2860                     ; 654 		System_Send_Message(OnLine_Data);
2862  090b be04          	ldw	x,L3601_OnLine_Data
2863  090d cd0253        	call	L553_System_Send_Message
2865  0910               L1511:
2866                     ; 658 	if((System_Para.Heat_CloseCnt > HEAT_AUTO_CLOSE_TIME) && System_Para.CH_Status == CH_A_HEAT){
2868  0910 be37          	ldw	x,L5_System_Para+9
2869  0912 a30e11        	cpw	x,#3601
2870  0915 250c          	jrult	L3511
2872  0917 b62f          	ld	a,L5_System_Para+1
2873  0919 a102          	cp	a,#2
2874  091b 2606          	jrne	L3511
2875                     ; 659 		System_Para.CH_Status = CH_A_OFF;
2877  091d 3f2f          	clr	L5_System_Para+1
2878                     ; 660 		System_Para.Updata_Flag = TRUE;
2880  091f 35010033      	mov	L5_System_Para+5,#1
2881  0923               L3511:
2882                     ; 664 	if((System_Para.Cool_CloseCnt > COOL_AUTO_CLOSE_TIME) && System_Para.CH_Status == CH_A_COOL){
2884  0923 be39          	ldw	x,L5_System_Para+11
2885  0925 a31c21        	cpw	x,#7201
2886  0928 250c          	jrult	L5511
2888  092a b62f          	ld	a,L5_System_Para+1
2889  092c a101          	cp	a,#1
2890  092e 2606          	jrne	L5511
2891                     ; 665 		System_Para.CH_Status = CH_A_OFF;
2893  0930 3f2f          	clr	L5_System_Para+1
2894                     ; 666 		System_Para.Updata_Flag = TRUE;
2896  0932 35010033      	mov	L5_System_Para+5,#1
2897  0936               L5511:
2898                     ; 670 	if(System_Para.ShutDown_Cnt > SHUTDOWN_TIME && System_Para.ShutDown_Flag){
2900  0936 be3b          	ldw	x,L5_System_Para+13
2901  0938 a33841        	cpw	x,#14401
2902  093b 2530          	jrult	L7511
2904  093d 3d36          	tnz	L5_System_Para+8
2905  093f 272c          	jreq	L7511
2906                     ; 672 		System_Para.Updata_Flag = TRUE;
2908  0941 35010033      	mov	L5_System_Para+5,#1
2909                     ; 673 		System_Para.Foot_Led_Status = FOOT_LED_OFF;
2911  0945 3f2e          	clr	L5_System_Para
2912                     ; 674 		System_Para.CH_Status = CH_A_OFF;
2914  0947 3f2f          	clr	L5_System_Para+1
2915                     ; 675 		System_Para.Pushrod_Status = PUSHROD_STOP;
2917  0949 3f30          	clr	L5_System_Para+2
2918                     ; 682 		System_Para.LockFlag = TRUE;
2920  094b 35010032      	mov	L5_System_Para+4,#1
2921                     ; 683 		System_Send_Message(CONT_LED_OFF|CONT_CH_A_OFF|CONT_PUSHROD_STOP);
2923  094f ae0026        	ldw	x,#38
2924  0952 cd0253        	call	L553_System_Send_Message
2926                     ; 684 		if(System_Para.SentCnt ++ > 10){
2928  0955 9c            	rvf
2929  0956 be3d          	ldw	x,L5_System_Para+15
2930  0958 1c0001        	addw	x,#1
2931  095b bf3d          	ldw	L5_System_Para+15,x
2932  095d 1d0001        	subw	x,#1
2933  0960 a3000b        	cpw	x,#11
2934  0963 2f08          	jrslt	L7511
2935                     ; 685 			System_Para.SentCnt = 0;
2937  0965 5f            	clrw	x
2938  0966 bf3d          	ldw	L5_System_Para+15,x
2939                     ; 686 			System_Para.ShutDown_Flag = FALSE;
2941  0968 3f36          	clr	L5_System_Para+8
2942                     ; 687 			System_Para.ShutDown_Cnt = 0;
2944  096a 5f            	clrw	x
2945  096b bf3b          	ldw	L5_System_Para+13,x
2946  096d               L7511:
2947                     ; 692 	if(TimeOutDet_Check(&Pwm_Time)){
2949  096d ae001a        	ldw	x,#L71_Pwm_Time
2950  0970 cd0000        	call	_TimeOutDet_Check
2952  0973 a30000        	cpw	x,#0
2953  0976 2703          	jreq	L3611
2954                     ; 693 		Led_Pwm_Handle();
2956  0978 cd014c        	call	L112_Led_Pwm_Handle
2958  097b               L3611:
2959                     ; 695 }
2962  097b 85            	popw	x
2963  097c 81            	ret
2966                     	switch	.ubsct
2967  0006               L1711_ShutDownBase:
2968  0006 0000          	ds.b	2
2969  0008               L7611_HeatCntBase:
2970  0008 0000          	ds.b	2
2971  000a               L5611_CoolCntBase:
2972  000a 0000          	ds.b	2
3023                     ; 697 void System_TimeHandle(void){
3024                     	switch	.text
3025  097d               _System_TimeHandle:
3029                     ; 699 	if(System_Para.Cool_CloseFlag){
3031  097d 3d35          	tnz	L5_System_Para+7
3032  097f 2726          	jreq	L1221
3033                     ; 700 		if(CoolCntBase ++ > 999){
3035  0981 be0a          	ldw	x,L5611_CoolCntBase
3036  0983 1c0001        	addw	x,#1
3037  0986 bf0a          	ldw	L5611_CoolCntBase,x
3038  0988 1d0001        	subw	x,#1
3039  098b a303e8        	cpw	x,#1000
3040  098e 2517          	jrult	L1221
3041                     ; 701 			CoolCntBase = 0;
3043  0990 5f            	clrw	x
3044  0991 bf0a          	ldw	L5611_CoolCntBase,x
3045                     ; 702 			if(System_Para.Cool_CloseCnt ++ > COOL_AUTO_CLOSE_TIME){
3047  0993 be39          	ldw	x,L5_System_Para+11
3048  0995 1c0001        	addw	x,#1
3049  0998 bf39          	ldw	L5_System_Para+11,x
3050  099a 1d0001        	subw	x,#1
3051  099d a31c21        	cpw	x,#7201
3052  09a0 2505          	jrult	L1221
3053                     ; 703 				System_Para.Cool_CloseCnt = COOL_AUTO_CLOSE_TIME + 10;
3055  09a2 ae1c2a        	ldw	x,#7210
3056  09a5 bf39          	ldw	L5_System_Para+11,x
3057  09a7               L1221:
3058                     ; 707 	if(System_Para.Heat_CloseFlag){
3060  09a7 3d34          	tnz	L5_System_Para+6
3061  09a9 2726          	jreq	L7221
3062                     ; 708 		if(HeatCntBase ++ > 999){
3064  09ab be08          	ldw	x,L7611_HeatCntBase
3065  09ad 1c0001        	addw	x,#1
3066  09b0 bf08          	ldw	L7611_HeatCntBase,x
3067  09b2 1d0001        	subw	x,#1
3068  09b5 a303e8        	cpw	x,#1000
3069  09b8 2517          	jrult	L7221
3070                     ; 709 			HeatCntBase = 0;
3072  09ba 5f            	clrw	x
3073  09bb bf08          	ldw	L7611_HeatCntBase,x
3074                     ; 710 			if(System_Para.Heat_CloseCnt ++ > HEAT_AUTO_CLOSE_TIME){
3076  09bd be37          	ldw	x,L5_System_Para+9
3077  09bf 1c0001        	addw	x,#1
3078  09c2 bf37          	ldw	L5_System_Para+9,x
3079  09c4 1d0001        	subw	x,#1
3080  09c7 a30e11        	cpw	x,#3601
3081  09ca 2505          	jrult	L7221
3082                     ; 711 				System_Para.Heat_CloseCnt = HEAT_AUTO_CLOSE_TIME + 10;
3084  09cc ae0e1a        	ldw	x,#3610
3085  09cf bf37          	ldw	L5_System_Para+9,x
3086  09d1               L7221:
3087                     ; 715 	if(System_Para.ShutDown_Flag){
3089  09d1 3d36          	tnz	L5_System_Para+8
3090  09d3 2726          	jreq	L5321
3091                     ; 716 		if(ShutDownBase ++ > 999){
3093  09d5 be06          	ldw	x,L1711_ShutDownBase
3094  09d7 1c0001        	addw	x,#1
3095  09da bf06          	ldw	L1711_ShutDownBase,x
3096  09dc 1d0001        	subw	x,#1
3097  09df a303e8        	cpw	x,#1000
3098  09e2 2517          	jrult	L5321
3099                     ; 717 			ShutDownBase = 0;
3101  09e4 5f            	clrw	x
3102  09e5 bf06          	ldw	L1711_ShutDownBase,x
3103                     ; 718 			if(System_Para.ShutDown_Cnt++ > SHUTDOWN_TIME){
3105  09e7 be3b          	ldw	x,L5_System_Para+13
3106  09e9 1c0001        	addw	x,#1
3107  09ec bf3b          	ldw	L5_System_Para+13,x
3108  09ee 1d0001        	subw	x,#1
3109  09f1 a33841        	cpw	x,#14401
3110  09f4 2505          	jrult	L5321
3111                     ; 719 				System_Para.ShutDown_Cnt = SHUTDOWN_TIME + 10;
3113  09f6 ae384a        	ldw	x,#14410
3114  09f9 bf3b          	ldw	L5_System_Para+13,x
3115  09fb               L5321:
3116                     ; 724 }
3119  09fb 81            	ret
3639                     	xdef	_delay
3640                     	switch	.ubsct
3641  000c               L52_ReadBuf:
3642  000c 0000          	ds.b	2
3643  000e               L32_Scan_Time:
3644  000e 000000000000  	ds.b	8
3645  0016               L12_LedRefresh_Time:
3646  0016 00000000      	ds.b	4
3647  001a               L71_Pwm_Time:
3648  001a 00000000      	ds.b	4
3649  001e               L51_Cool_Close_Time:
3650  001e 00000000      	ds.b	4
3651  0022               L31_Heat_Close_Time:
3652  0022 00000000      	ds.b	4
3653  0026               L11_Shutdown_Time:
3654  0026 00000000      	ds.b	4
3655  002a               L7_ONLine_Time:
3656  002a 00000000      	ds.b	4
3657  002e               L5_System_Para:
3658  002e 000000000000  	ds.b	17
3659  003f               L3_IIC_Para:
3660  003f 00000000      	ds.b	4
3661                     	xref	_memset
3662                     	xref	_IIC_Write_Data
3663                     	xref	_IIC_Read_Data
3664                     	xref	_IIC_Init
3665                     	xref	_TimeOutDet_Check
3666                     	xref	_TimeOut_Record
3667                     	xref	_TimeOutDet_Init
3668                     	xdef	_System_TimeHandle
3669                     	xdef	_System_Handle
3670                     	xdef	_System_Init
3671                     	xref	_Commu_Sent
3672                     	xref	_Commu_Init
3673                     	xref	_TIM4_ARRPreloadConfig
3674                     	xref	_TIM4_PrescalerConfig
3675                     	xref	_TIM4_UpdateRequestConfig
3676                     	xref	_TIM4_UpdateDisableConfig
3677                     	xref	_TIM4_ITConfig
3678                     	xref	_TIM4_Cmd
3679                     	xref	_TIM4_TimeBaseInit
3680                     	xref	_TIM4_DeInit
3681                     	xref	_TIM1_SetCompare4
3682                     	xref	_TIM1_CtrlPWMOutputs
3683                     	xref	_TIM1_Cmd
3684                     	xref	_TIM1_OC4Init
3685                     	xref	_TIM1_TimeBaseInit
3686                     	xref	_TIM1_DeInit
3687                     	xref	_IWDG_Enable
3688                     	xref	_IWDG_ReloadCounter
3689                     	xref	_IWDG_SetReload
3690                     	xref	_IWDG_SetPrescaler
3691                     	xref	_IWDG_WriteAccessCmd
3692                     	xref	_GPIO_ReadInputPin
3693                     	xref	_GPIO_WriteLow
3694                     	xref	_GPIO_WriteHigh
3695                     	xref	_GPIO_Init
3696                     	xref	_CLK_HSIPrescalerConfig
3697                     	xref	_CLK_DeInit
3717                     	end
