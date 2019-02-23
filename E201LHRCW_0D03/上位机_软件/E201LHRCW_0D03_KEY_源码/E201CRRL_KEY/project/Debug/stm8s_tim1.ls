   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  32                     ; 52 void TIM1_DeInit(void)
  32                     ; 53 {
  34                     	switch	.text
  35  0000               _TIM1_DeInit:
  39                     ; 54     TIM1->CR1  = TIM1_CR1_RESET_VALUE;
  41  0000 725f5250      	clr	21072
  42                     ; 55     TIM1->CR2  = TIM1_CR2_RESET_VALUE;
  44  0004 725f5251      	clr	21073
  45                     ; 56     TIM1->SMCR = TIM1_SMCR_RESET_VALUE;
  47  0008 725f5252      	clr	21074
  48                     ; 57     TIM1->ETR  = TIM1_ETR_RESET_VALUE;
  50  000c 725f5253      	clr	21075
  51                     ; 58     TIM1->IER  = TIM1_IER_RESET_VALUE;
  53  0010 725f5254      	clr	21076
  54                     ; 59     TIM1->SR2  = TIM1_SR2_RESET_VALUE;
  56  0014 725f5256      	clr	21078
  57                     ; 61     TIM1->CCER1 = TIM1_CCER1_RESET_VALUE;
  59  0018 725f525c      	clr	21084
  60                     ; 62     TIM1->CCER2 = TIM1_CCER2_RESET_VALUE;
  62  001c 725f525d      	clr	21085
  63                     ; 64     TIM1->CCMR1 = 0x01;
  65  0020 35015258      	mov	21080,#1
  66                     ; 65     TIM1->CCMR2 = 0x01;
  68  0024 35015259      	mov	21081,#1
  69                     ; 66     TIM1->CCMR3 = 0x01;
  71  0028 3501525a      	mov	21082,#1
  72                     ; 67     TIM1->CCMR4 = 0x01;
  74  002c 3501525b      	mov	21083,#1
  75                     ; 69     TIM1->CCER1 = TIM1_CCER1_RESET_VALUE;
  77  0030 725f525c      	clr	21084
  78                     ; 70     TIM1->CCER2 = TIM1_CCER2_RESET_VALUE;
  80  0034 725f525d      	clr	21085
  81                     ; 71     TIM1->CCMR1 = TIM1_CCMR1_RESET_VALUE;
  83  0038 725f5258      	clr	21080
  84                     ; 72     TIM1->CCMR2 = TIM1_CCMR2_RESET_VALUE;
  86  003c 725f5259      	clr	21081
  87                     ; 73     TIM1->CCMR3 = TIM1_CCMR3_RESET_VALUE;
  89  0040 725f525a      	clr	21082
  90                     ; 74     TIM1->CCMR4 = TIM1_CCMR4_RESET_VALUE;
  92  0044 725f525b      	clr	21083
  93                     ; 75     TIM1->CNTRH = TIM1_CNTRH_RESET_VALUE;
  95  0048 725f525e      	clr	21086
  96                     ; 76     TIM1->CNTRL = TIM1_CNTRL_RESET_VALUE;
  98  004c 725f525f      	clr	21087
  99                     ; 77     TIM1->PSCRH = TIM1_PSCRH_RESET_VALUE;
 101  0050 725f5260      	clr	21088
 102                     ; 78     TIM1->PSCRL = TIM1_PSCRL_RESET_VALUE;
 104  0054 725f5261      	clr	21089
 105                     ; 79     TIM1->ARRH  = TIM1_ARRH_RESET_VALUE;
 107  0058 35ff5262      	mov	21090,#255
 108                     ; 80     TIM1->ARRL  = TIM1_ARRL_RESET_VALUE;
 110  005c 35ff5263      	mov	21091,#255
 111                     ; 81     TIM1->CCR1H = TIM1_CCR1H_RESET_VALUE;
 113  0060 725f5265      	clr	21093
 114                     ; 82     TIM1->CCR1L = TIM1_CCR1L_RESET_VALUE;
 116  0064 725f5266      	clr	21094
 117                     ; 83     TIM1->CCR2H = TIM1_CCR2H_RESET_VALUE;
 119  0068 725f5267      	clr	21095
 120                     ; 84     TIM1->CCR2L = TIM1_CCR2L_RESET_VALUE;
 122  006c 725f5268      	clr	21096
 123                     ; 85     TIM1->CCR3H = TIM1_CCR3H_RESET_VALUE;
 125  0070 725f5269      	clr	21097
 126                     ; 86     TIM1->CCR3L = TIM1_CCR3L_RESET_VALUE;
 128  0074 725f526a      	clr	21098
 129                     ; 87     TIM1->CCR4H = TIM1_CCR4H_RESET_VALUE;
 131  0078 725f526b      	clr	21099
 132                     ; 88     TIM1->CCR4L = TIM1_CCR4L_RESET_VALUE;
 134  007c 725f526c      	clr	21100
 135                     ; 89     TIM1->OISR  = TIM1_OISR_RESET_VALUE;
 137  0080 725f526f      	clr	21103
 138                     ; 90     TIM1->EGR   = 0x01; /* TIM1_EGR_UG */
 140  0084 35015257      	mov	21079,#1
 141                     ; 91     TIM1->DTR   = TIM1_DTR_RESET_VALUE;
 143  0088 725f526e      	clr	21102
 144                     ; 92     TIM1->BKR   = TIM1_BKR_RESET_VALUE;
 146  008c 725f526d      	clr	21101
 147                     ; 93     TIM1->RCR   = TIM1_RCR_RESET_VALUE;
 149  0090 725f5264      	clr	21092
 150                     ; 94     TIM1->SR1   = TIM1_SR1_RESET_VALUE;
 152  0094 725f5255      	clr	21077
 153                     ; 95 }
 156  0098 81            	ret
 265                     ; 105 void TIM1_TimeBaseInit(uint16_t TIM1_Prescaler,
 265                     ; 106                        TIM1_CounterMode_TypeDef TIM1_CounterMode,
 265                     ; 107                        uint16_t TIM1_Period,
 265                     ; 108                        uint8_t TIM1_RepetitionCounter)
 265                     ; 109 {
 266                     	switch	.text
 267  0099               _TIM1_TimeBaseInit:
 269  0099 89            	pushw	x
 270       00000000      OFST:	set	0
 273                     ; 112     assert_param(IS_TIM1_COUNTER_MODE_OK(TIM1_CounterMode));
 275                     ; 115     TIM1->ARRH = (uint8_t)(TIM1_Period >> 8);
 277  009a 7b06          	ld	a,(OFST+6,sp)
 278  009c c75262        	ld	21090,a
 279                     ; 116     TIM1->ARRL = (uint8_t)(TIM1_Period);
 281  009f 7b07          	ld	a,(OFST+7,sp)
 282  00a1 c75263        	ld	21091,a
 283                     ; 119     TIM1->PSCRH = (uint8_t)(TIM1_Prescaler >> 8);
 285  00a4 9e            	ld	a,xh
 286  00a5 c75260        	ld	21088,a
 287                     ; 120     TIM1->PSCRL = (uint8_t)(TIM1_Prescaler);
 289  00a8 9f            	ld	a,xl
 290  00a9 c75261        	ld	21089,a
 291                     ; 123     TIM1->CR1 = (uint8_t)((uint8_t)(TIM1->CR1 & (uint8_t)(~(TIM1_CR1_CMS | TIM1_CR1_DIR)))
 291                     ; 124                            | (uint8_t)(TIM1_CounterMode));
 293  00ac c65250        	ld	a,21072
 294  00af a48f          	and	a,#143
 295  00b1 1a05          	or	a,(OFST+5,sp)
 296  00b3 c75250        	ld	21072,a
 297                     ; 127     TIM1->RCR = TIM1_RepetitionCounter;
 299  00b6 7b08          	ld	a,(OFST+8,sp)
 300  00b8 c75264        	ld	21092,a
 301                     ; 129 }
 304  00bb 85            	popw	x
 305  00bc 81            	ret
 494                     ; 341 void TIM1_OC4Init(TIM1_OCMode_TypeDef TIM1_OCMode,
 494                     ; 342                   TIM1_OutputState_TypeDef TIM1_OutputState,
 494                     ; 343                   uint16_t TIM1_Pulse,
 494                     ; 344                   TIM1_OCPolarity_TypeDef TIM1_OCPolarity,
 494                     ; 345                   TIM1_OCIdleState_TypeDef TIM1_OCIdleState)
 494                     ; 346 {
 495                     	switch	.text
 496  00bd               _TIM1_OC4Init:
 498  00bd 89            	pushw	x
 499  00be 88            	push	a
 500       00000001      OFST:	set	1
 503                     ; 348     assert_param(IS_TIM1_OC_MODE_OK(TIM1_OCMode));
 505                     ; 349     assert_param(IS_TIM1_OUTPUT_STATE_OK(TIM1_OutputState));
 507                     ; 350     assert_param(IS_TIM1_OC_POLARITY_OK(TIM1_OCPolarity));
 509                     ; 351     assert_param(IS_TIM1_OCIDLE_STATE_OK(TIM1_OCIdleState));
 511                     ; 354     TIM1->CCER2 &= (uint8_t)(~(TIM1_CCER2_CC4E | TIM1_CCER2_CC4P));
 513  00bf c6525d        	ld	a,21085
 514  00c2 a4cf          	and	a,#207
 515  00c4 c7525d        	ld	21085,a
 516                     ; 356     TIM1->CCER2 |= (uint8_t)((uint8_t)(TIM1_OutputState & TIM1_CCER2_CC4E ) |  
 516                     ; 357                              (uint8_t)(TIM1_OCPolarity  & TIM1_CCER2_CC4P ));
 518  00c7 7b08          	ld	a,(OFST+7,sp)
 519  00c9 a420          	and	a,#32
 520  00cb 6b01          	ld	(OFST+0,sp),a
 521  00cd 9f            	ld	a,xl
 522  00ce a410          	and	a,#16
 523  00d0 1a01          	or	a,(OFST+0,sp)
 524  00d2 ca525d        	or	a,21085
 525  00d5 c7525d        	ld	21085,a
 526                     ; 360     TIM1->CCMR4 = (uint8_t)((uint8_t)(TIM1->CCMR4 & (uint8_t)(~TIM1_CCMR_OCM)) | 
 526                     ; 361                             TIM1_OCMode);
 528  00d8 c6525b        	ld	a,21083
 529  00db a48f          	and	a,#143
 530  00dd 1a02          	or	a,(OFST+1,sp)
 531  00df c7525b        	ld	21083,a
 532                     ; 364     if (TIM1_OCIdleState != TIM1_OCIDLESTATE_RESET)
 534  00e2 0d09          	tnz	(OFST+8,sp)
 535  00e4 270a          	jreq	L702
 536                     ; 366         TIM1->OISR |= (uint8_t)(~TIM1_CCER2_CC4P);
 538  00e6 c6526f        	ld	a,21103
 539  00e9 aadf          	or	a,#223
 540  00eb c7526f        	ld	21103,a
 542  00ee 2004          	jra	L112
 543  00f0               L702:
 544                     ; 370         TIM1->OISR &= (uint8_t)(~TIM1_OISR_OIS4);
 546  00f0 721d526f      	bres	21103,#6
 547  00f4               L112:
 548                     ; 374     TIM1->CCR4H = (uint8_t)(TIM1_Pulse >> 8);
 550  00f4 7b06          	ld	a,(OFST+5,sp)
 551  00f6 c7526b        	ld	21099,a
 552                     ; 375     TIM1->CCR4L = (uint8_t)(TIM1_Pulse);
 554  00f9 7b07          	ld	a,(OFST+6,sp)
 555  00fb c7526c        	ld	21100,a
 556                     ; 377 }
 559  00fe 5b03          	addw	sp,#3
 560  0100 81            	ret
 615                     ; 572 void TIM1_Cmd(FunctionalState NewState)
 615                     ; 573 {
 616                     	switch	.text
 617  0101               _TIM1_Cmd:
 621                     ; 575     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 623                     ; 578     if (NewState != DISABLE)
 625  0101 4d            	tnz	a
 626  0102 2706          	jreq	L142
 627                     ; 580         TIM1->CR1 |= TIM1_CR1_CEN;
 629  0104 72105250      	bset	21072,#0
 631  0108 2004          	jra	L342
 632  010a               L142:
 633                     ; 584         TIM1->CR1 &= (uint8_t)(~TIM1_CR1_CEN);
 635  010a 72115250      	bres	21072,#0
 636  010e               L342:
 637                     ; 586 }
 640  010e 81            	ret
 676                     ; 594 void TIM1_CtrlPWMOutputs(FunctionalState NewState)
 676                     ; 595 {
 677                     	switch	.text
 678  010f               _TIM1_CtrlPWMOutputs:
 682                     ; 597     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 684                     ; 601     if (NewState != DISABLE)
 686  010f 4d            	tnz	a
 687  0110 2706          	jreq	L362
 688                     ; 603         TIM1->BKR |= TIM1_BKR_MOE;
 690  0112 721e526d      	bset	21101,#7
 692  0116 2004          	jra	L562
 693  0118               L362:
 694                     ; 607         TIM1->BKR &= (uint8_t)(~TIM1_BKR_MOE);
 696  0118 721f526d      	bres	21101,#7
 697  011c               L562:
 698                     ; 609 }
 701  011c 81            	ret
 768                     ; 1059 void TIM1_PrescalerConfig(uint16_t Prescaler,
 768                     ; 1060                           TIM1_PSCReloadMode_TypeDef TIM1_PSCReloadMode)
 768                     ; 1061 {
 769                     	switch	.text
 770  011d               _TIM1_PrescalerConfig:
 772  011d 89            	pushw	x
 773       00000000      OFST:	set	0
 776                     ; 1063     assert_param(IS_TIM1_PRESCALER_RELOAD_OK(TIM1_PSCReloadMode));
 778                     ; 1066     TIM1->PSCRH = (uint8_t)(Prescaler >> 8);
 780  011e 9e            	ld	a,xh
 781  011f c75260        	ld	21088,a
 782                     ; 1067     TIM1->PSCRL = (uint8_t)(Prescaler);
 784  0122 9f            	ld	a,xl
 785  0123 c75261        	ld	21089,a
 786                     ; 1070     TIM1->EGR = (uint8_t)TIM1_PSCReloadMode;
 788  0126 7b05          	ld	a,(OFST+5,sp)
 789  0128 c75257        	ld	21079,a
 790                     ; 1072 }
 793  012b 85            	popw	x
 794  012c 81            	ret
 830                     ; 1186 void TIM1_ARRPreloadConfig(FunctionalState NewState)
 830                     ; 1187 {
 831                     	switch	.text
 832  012d               _TIM1_ARRPreloadConfig:
 836                     ; 1189     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 838                     ; 1192     if (NewState != DISABLE)
 840  012d 4d            	tnz	a
 841  012e 2706          	jreq	L733
 842                     ; 1194         TIM1->CR1 |= TIM1_CR1_ARPE;
 844  0130 721e5250      	bset	21072,#7
 846  0134 2004          	jra	L143
 847  0136               L733:
 848                     ; 1198         TIM1->CR1 &= (uint8_t)(~TIM1_CR1_ARPE);
 850  0136 721f5250      	bres	21072,#7
 851  013a               L143:
 852                     ; 1200 }
 855  013a 81            	ret
 891                     ; 1329 void TIM1_OC4PreloadConfig(FunctionalState NewState)
 891                     ; 1330 {
 892                     	switch	.text
 893  013b               _TIM1_OC4PreloadConfig:
 897                     ; 1332     assert_param(IS_FUNCTIONALSTATE_OK(NewState));
 899                     ; 1335     if (NewState != DISABLE)
 901  013b 4d            	tnz	a
 902  013c 2706          	jreq	L163
 903                     ; 1337         TIM1->CCMR4 |= TIM1_CCMR_OCxPE;
 905  013e 7216525b      	bset	21083,#3
 907  0142 2004          	jra	L363
 908  0144               L163:
 909                     ; 1341         TIM1->CCMR4 &= (uint8_t)(~TIM1_CCMR_OCxPE);
 911  0144 7217525b      	bres	21083,#3
 912  0148               L363:
 913                     ; 1343 }
 916  0148 81            	ret
 950                     ; 1834 void TIM1_SetCounter(uint16_t Counter)
 950                     ; 1835 {
 951                     	switch	.text
 952  0149               _TIM1_SetCounter:
 956                     ; 1837     TIM1->CNTRH = (uint8_t)(Counter >> 8);
 958  0149 9e            	ld	a,xh
 959  014a c7525e        	ld	21086,a
 960                     ; 1838     TIM1->CNTRL = (uint8_t)(Counter);
 962  014d 9f            	ld	a,xl
 963  014e c7525f        	ld	21087,a
 964                     ; 1840 }
 967  0151 81            	ret
1001                     ; 1912 void TIM1_SetCompare4(uint16_t Compare4)
1001                     ; 1913 {
1002                     	switch	.text
1003  0152               _TIM1_SetCompare4:
1007                     ; 1915     TIM1->CCR4H = (uint8_t)(Compare4 >> 8);
1009  0152 9e            	ld	a,xh
1010  0153 c7526b        	ld	21099,a
1011                     ; 1916     TIM1->CCR4L = (uint8_t)(Compare4);
1013  0156 9f            	ld	a,xl
1014  0157 c7526c        	ld	21100,a
1015                     ; 1917 }
1018  015a 81            	ret
1143                     ; 2176 void TIM1_ClearFlag(TIM1_FLAG_TypeDef TIM1_FLAG)
1143                     ; 2177 {
1144                     	switch	.text
1145  015b               _TIM1_ClearFlag:
1147  015b 89            	pushw	x
1148       00000000      OFST:	set	0
1151                     ; 2179     assert_param(IS_TIM1_CLEAR_FLAG_OK(TIM1_FLAG));
1153                     ; 2182     TIM1->SR1 = (uint8_t)(~(uint8_t)(TIM1_FLAG));
1155  015c 9f            	ld	a,xl
1156  015d 43            	cpl	a
1157  015e c75255        	ld	21077,a
1158                     ; 2183     TIM1->SR2 = (uint8_t)((uint8_t)(~((uint8_t)((uint16_t)TIM1_FLAG >> 8))) & 
1158                     ; 2184                           (uint8_t)0x1E);
1160  0161 7b01          	ld	a,(OFST+1,sp)
1161  0163 43            	cpl	a
1162  0164 a41e          	and	a,#30
1163  0166 c75256        	ld	21078,a
1164                     ; 2185 }
1167  0169 85            	popw	x
1168  016a 81            	ret
1314                     ; 2201 ITStatus TIM1_GetITStatus(TIM1_IT_TypeDef TIM1_IT)
1314                     ; 2202 {
1315                     	switch	.text
1316  016b               _TIM1_GetITStatus:
1318  016b 88            	push	a
1319  016c 89            	pushw	x
1320       00000002      OFST:	set	2
1323                     ; 2203     ITStatus bitstatus = RESET;
1325  016d 7b02          	ld	a,(OFST+0,sp)
1326  016f 97            	ld	xl,a
1327                     ; 2204     uint8_t TIM1_itStatus = 0, TIM1_itEnable = 0;
1329  0170 7b01          	ld	a,(OFST-1,sp)
1330  0172 97            	ld	xl,a
1333  0173 7b02          	ld	a,(OFST+0,sp)
1334  0175 97            	ld	xl,a
1335                     ; 2207     assert_param(IS_TIM1_GET_IT_OK(TIM1_IT));
1337                     ; 2209     TIM1_itStatus = (uint8_t)(TIM1->SR1 & (uint8_t)TIM1_IT);
1339  0176 c65255        	ld	a,21077
1340  0179 1403          	and	a,(OFST+1,sp)
1341  017b 6b01          	ld	(OFST-1,sp),a
1342                     ; 2211     TIM1_itEnable = (uint8_t)(TIM1->IER & (uint8_t)TIM1_IT);
1344  017d c65254        	ld	a,21076
1345  0180 1403          	and	a,(OFST+1,sp)
1346  0182 6b02          	ld	(OFST+0,sp),a
1347                     ; 2213     if ((TIM1_itStatus != (uint8_t)RESET ) && (TIM1_itEnable != (uint8_t)RESET ))
1349  0184 0d01          	tnz	(OFST-1,sp)
1350  0186 270a          	jreq	L165
1352  0188 0d02          	tnz	(OFST+0,sp)
1353  018a 2706          	jreq	L165
1354                     ; 2215         bitstatus = SET;
1356  018c a601          	ld	a,#1
1357  018e 6b02          	ld	(OFST+0,sp),a
1359  0190 2002          	jra	L365
1360  0192               L165:
1361                     ; 2219         bitstatus = RESET;
1363  0192 0f02          	clr	(OFST+0,sp)
1364  0194               L365:
1365                     ; 2221     return (ITStatus)(bitstatus);
1367  0194 7b02          	ld	a,(OFST+0,sp)
1370  0196 5b03          	addw	sp,#3
1371  0198 81            	ret
1407                     ; 2238 void TIM1_ClearITPendingBit(TIM1_IT_TypeDef TIM1_IT)
1407                     ; 2239 {
1408                     	switch	.text
1409  0199               _TIM1_ClearITPendingBit:
1413                     ; 2241     assert_param(IS_TIM1_IT_OK(TIM1_IT));
1415                     ; 2244     TIM1->SR1 = (uint8_t)(~(uint8_t)TIM1_IT);
1417  0199 43            	cpl	a
1418  019a c75255        	ld	21077,a
1419                     ; 2245 }
1422  019d 81            	ret
1435                     	xdef	_TIM1_ClearITPendingBit
1436                     	xdef	_TIM1_GetITStatus
1437                     	xdef	_TIM1_ClearFlag
1438                     	xdef	_TIM1_SetCompare4
1439                     	xdef	_TIM1_SetCounter
1440                     	xdef	_TIM1_OC4PreloadConfig
1441                     	xdef	_TIM1_ARRPreloadConfig
1442                     	xdef	_TIM1_PrescalerConfig
1443                     	xdef	_TIM1_CtrlPWMOutputs
1444                     	xdef	_TIM1_Cmd
1445                     	xdef	_TIM1_OC4Init
1446                     	xdef	_TIM1_TimeBaseInit
1447                     	xdef	_TIM1_DeInit
1466                     	end
