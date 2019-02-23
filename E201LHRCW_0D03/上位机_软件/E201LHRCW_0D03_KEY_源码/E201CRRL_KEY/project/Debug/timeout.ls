   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
   4                     	bsct
   5  0000               _InsBaseNum:
   6  0000 0000          	dc.w	0
  36                     ; 6 void TimeOutDet_Init(void)
  36                     ; 7 {
  38                     	switch	.text
  39  0000               _TimeOutDet_Init:
  43                     ; 8 	InsBaseNum=0;
  45  0000 5f            	clrw	x
  46  0001 bf00          	ldw	_InsBaseNum,x
  47                     ; 9 }
  50  0003 81            	ret
  75                     ; 12 void TimeOutDet_DecHandle(void)
  75                     ; 13 {
  76                     	switch	.text
  77  0004               _TimeOutDet_DecHandle:
  81                     ; 14 	InsBaseNum++;
  83  0004 be00          	ldw	x,_InsBaseNum
  84  0006 1c0001        	addw	x,#1
  85  0009 bf00          	ldw	_InsBaseNum,x
  86                     ; 15 }
  89  000b 81            	ret
 113                     ; 17 clock_time_t TimeOut_BaseValue(void)
 113                     ; 18 {
 114                     	switch	.text
 115  000c               _TimeOut_BaseValue:
 119                     ; 19 	return InsBaseNum;
 121  000c be00          	ldw	x,_InsBaseNum
 124  000e 81            	ret
 192                     ; 24 void TimeOut_Record(TIMEOUT_PARA * TimeOutPara,clock_time_t timeoutvalue)
 192                     ; 25 
 192                     ; 26 {
 193                     	switch	.text
 194  000f               _TimeOut_Record:
 196  000f 89            	pushw	x
 197       00000000      OFST:	set	0
 200                     ; 27 	TimeOutPara->RecordValue=TimeOut_BaseValue();
 202  0010 adfa          	call	_TimeOut_BaseValue
 204  0012 1601          	ldw	y,(OFST+1,sp)
 205  0014 90ff          	ldw	(y),x
 206                     ; 28 	TimeOutPara->timeoutcnt=timeoutvalue;
 208  0016 1e01          	ldw	x,(OFST+1,sp)
 209  0018 1605          	ldw	y,(OFST+5,sp)
 210  001a ef02          	ldw	(2,x),y
 211                     ; 29 }
 214  001c 85            	popw	x
 215  001d 81            	ret
 253                     ; 32 void TimeOut_restart(TIMEOUT_PARA *TimeOutPara)
 253                     ; 33 {	
 254                     	switch	.text
 255  001e               _TimeOut_restart:
 257  001e 89            	pushw	x
 258       00000000      OFST:	set	0
 261                     ; 34 	TimeOutPara->RecordValue = TimeOut_BaseValue();
 263  001f adeb          	call	_TimeOut_BaseValue
 265  0021 1601          	ldw	y,(OFST+1,sp)
 266  0023 90ff          	ldw	(y),x
 267                     ; 35 }
 270  0025 85            	popw	x
 271  0026 81            	ret
 309                     ; 37 clock_time_t TimeOutDet_Check(TIMEOUT_PARA * TimeOutPara)
 309                     ; 38 {
 310                     	switch	.text
 311  0027               _TimeOutDet_Check:
 313  0027 89            	pushw	x
 314       00000000      OFST:	set	0
 317                     ; 39 	return (((clock_time_t)(InsBaseNum-TimeOutPara->RecordValue)>=TimeOutPara->timeoutcnt)?1:0);
 319  0028 be00          	ldw	x,_InsBaseNum
 320  002a 1601          	ldw	y,(OFST+1,sp)
 321  002c 90fe          	ldw	y,(y)
 322  002e 90bf00        	ldw	c_x,y
 323  0031 72b00000      	subw	x,c_x
 324  0035 1601          	ldw	y,(OFST+1,sp)
 325  0037 90e302        	cpw	x,(2,y)
 326  003a 2505          	jrult	L02
 327  003c ae0001        	ldw	x,#1
 328  003f 2001          	jra	L22
 329  0041               L02:
 330  0041 5f            	clrw	x
 331  0042               L22:
 334  0042 5b02          	addw	sp,#2
 335  0044 81            	ret
 359                     	xdef	_InsBaseNum
 360                     	xdef	_TimeOutDet_Check
 361                     	xdef	_TimeOut_restart
 362                     	xdef	_TimeOut_Record
 363                     	xdef	_TimeOut_BaseValue
 364                     	xdef	_TimeOutDet_DecHandle
 365                     	xdef	_TimeOutDet_Init
 366                     	xref.b	c_x
 385                     	end
