   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Generator V4.2.8 - 03 Dec 2008
  98                     ; 47 void GPIO_DeInit(GPIO_TypeDef* GPIOx)
  98                     ; 48 {
 100                     	switch	.text
 101  0000               _GPIO_DeInit:
 105                     ; 49     GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
 107  0000 7f            	clr	(x)
 108                     ; 50     GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
 110  0001 6f02          	clr	(2,x)
 111                     ; 51     GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
 113  0003 6f03          	clr	(3,x)
 114                     ; 52     GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
 116  0005 6f04          	clr	(4,x)
 117                     ; 53 }
 120  0007 81            	ret
 360                     ; 65 void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, GPIO_Mode_TypeDef GPIO_Mode)
 360                     ; 66 {
 361                     	switch	.text
 362  0008               _GPIO_Init:
 364  0008 89            	pushw	x
 365       00000000      OFST:	set	0
 368                     ; 75   GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
 370  0009 7b05          	ld	a,(OFST+5,sp)
 371  000b 43            	cpl	a
 372  000c e404          	and	a,(4,x)
 373  000e e704          	ld	(4,x),a
 374                     ; 81     if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x80) != (uint8_t)0x00) /* Output mode */
 376  0010 7b06          	ld	a,(OFST+6,sp)
 377  0012 a580          	bcp	a,#128
 378  0014 271d          	jreq	L771
 379                     ; 83         if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x10) != (uint8_t)0x00) /* High level */
 381  0016 7b06          	ld	a,(OFST+6,sp)
 382  0018 a510          	bcp	a,#16
 383  001a 2706          	jreq	L102
 384                     ; 85             GPIOx->ODR |= (uint8_t)GPIO_Pin;
 386  001c f6            	ld	a,(x)
 387  001d 1a05          	or	a,(OFST+5,sp)
 388  001f f7            	ld	(x),a
 390  0020 2007          	jra	L302
 391  0022               L102:
 392                     ; 89             GPIOx->ODR &= (uint8_t)(~(GPIO_Pin));
 394  0022 1e01          	ldw	x,(OFST+1,sp)
 395  0024 7b05          	ld	a,(OFST+5,sp)
 396  0026 43            	cpl	a
 397  0027 f4            	and	a,(x)
 398  0028 f7            	ld	(x),a
 399  0029               L302:
 400                     ; 92         GPIOx->DDR |= (uint8_t)GPIO_Pin;
 402  0029 1e01          	ldw	x,(OFST+1,sp)
 403  002b e602          	ld	a,(2,x)
 404  002d 1a05          	or	a,(OFST+5,sp)
 405  002f e702          	ld	(2,x),a
 407  0031 2009          	jra	L502
 408  0033               L771:
 409                     ; 97         GPIOx->DDR &= (uint8_t)(~(GPIO_Pin));
 411  0033 1e01          	ldw	x,(OFST+1,sp)
 412  0035 7b05          	ld	a,(OFST+5,sp)
 413  0037 43            	cpl	a
 414  0038 e402          	and	a,(2,x)
 415  003a e702          	ld	(2,x),a
 416  003c               L502:
 417                     ; 104     if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x40) != (uint8_t)0x00) /* Pull-Up or Push-Pull */
 419  003c 7b06          	ld	a,(OFST+6,sp)
 420  003e a540          	bcp	a,#64
 421  0040 270a          	jreq	L702
 422                     ; 106         GPIOx->CR1 |= (uint8_t)GPIO_Pin;
 424  0042 1e01          	ldw	x,(OFST+1,sp)
 425  0044 e603          	ld	a,(3,x)
 426  0046 1a05          	or	a,(OFST+5,sp)
 427  0048 e703          	ld	(3,x),a
 429  004a 2009          	jra	L112
 430  004c               L702:
 431                     ; 110         GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
 433  004c 1e01          	ldw	x,(OFST+1,sp)
 434  004e 7b05          	ld	a,(OFST+5,sp)
 435  0050 43            	cpl	a
 436  0051 e403          	and	a,(3,x)
 437  0053 e703          	ld	(3,x),a
 438  0055               L112:
 439                     ; 117     if ((((uint8_t)(GPIO_Mode)) & (uint8_t)0x20) != (uint8_t)0x00) /* Interrupt or Slow slope */
 441  0055 7b06          	ld	a,(OFST+6,sp)
 442  0057 a520          	bcp	a,#32
 443  0059 270a          	jreq	L312
 444                     ; 119         GPIOx->CR2 |= (uint8_t)GPIO_Pin;
 446  005b 1e01          	ldw	x,(OFST+1,sp)
 447  005d e604          	ld	a,(4,x)
 448  005f 1a05          	or	a,(OFST+5,sp)
 449  0061 e704          	ld	(4,x),a
 451  0063 2009          	jra	L512
 452  0065               L312:
 453                     ; 123         GPIOx->CR2 &= (uint8_t)(~(GPIO_Pin));
 455  0065 1e01          	ldw	x,(OFST+1,sp)
 456  0067 7b05          	ld	a,(OFST+5,sp)
 457  0069 43            	cpl	a
 458  006a e404          	and	a,(4,x)
 459  006c e704          	ld	(4,x),a
 460  006e               L512:
 461                     ; 125 }
 464  006e 85            	popw	x
 465  006f 81            	ret
 511                     ; 135 void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
 511                     ; 136 {
 512                     	switch	.text
 513  0070               _GPIO_Write:
 515  0070 89            	pushw	x
 516       00000000      OFST:	set	0
 519                     ; 137     GPIOx->ODR = PortVal;
 521  0071 7b05          	ld	a,(OFST+5,sp)
 522  0073 1e01          	ldw	x,(OFST+1,sp)
 523  0075 f7            	ld	(x),a
 524                     ; 138 }
 527  0076 85            	popw	x
 528  0077 81            	ret
 575                     ; 148 void GPIO_WriteHigh(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
 575                     ; 149 {
 576                     	switch	.text
 577  0078               _GPIO_WriteHigh:
 579  0078 89            	pushw	x
 580       00000000      OFST:	set	0
 583                     ; 150     GPIOx->ODR |= (uint8_t)PortPins;
 585  0079 f6            	ld	a,(x)
 586  007a 1a05          	or	a,(OFST+5,sp)
 587  007c f7            	ld	(x),a
 588                     ; 151 }
 591  007d 85            	popw	x
 592  007e 81            	ret
 639                     ; 161 void GPIO_WriteLow(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
 639                     ; 162 {
 640                     	switch	.text
 641  007f               _GPIO_WriteLow:
 643  007f 89            	pushw	x
 644       00000000      OFST:	set	0
 647                     ; 163     GPIOx->ODR &= (uint8_t)(~PortPins);
 649  0080 7b05          	ld	a,(OFST+5,sp)
 650  0082 43            	cpl	a
 651  0083 f4            	and	a,(x)
 652  0084 f7            	ld	(x),a
 653                     ; 164 }
 656  0085 85            	popw	x
 657  0086 81            	ret
 704                     ; 174 void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
 704                     ; 175 {
 705                     	switch	.text
 706  0087               _GPIO_WriteReverse:
 708  0087 89            	pushw	x
 709       00000000      OFST:	set	0
 712                     ; 176     GPIOx->ODR ^= (uint8_t)PortPins;
 714  0088 f6            	ld	a,(x)
 715  0089 1805          	xor	a,	(OFST+5,sp)
 716  008b f7            	ld	(x),a
 717                     ; 177 }
 720  008c 85            	popw	x
 721  008d 81            	ret
 758                     ; 197 uint8_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
 758                     ; 198 {
 759                     	switch	.text
 760  008e               _GPIO_ReadInputData:
 764                     ; 199     return ((uint8_t)GPIOx->IDR);
 766  008e e601          	ld	a,(1,x)
 769  0090 81            	ret
 837                     ; 208 BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
 837                     ; 209 {
 838                     	switch	.text
 839  0091               _GPIO_ReadInputPin:
 841  0091 89            	pushw	x
 842       00000000      OFST:	set	0
 845                     ; 210     return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
 847  0092 e601          	ld	a,(1,x)
 848  0094 1405          	and	a,(OFST+5,sp)
 851  0096 85            	popw	x
 852  0097 81            	ret
 865                     	xdef	_GPIO_ReadInputPin
 866                     	xdef	_GPIO_ReadInputData
 867                     	xdef	_GPIO_WriteReverse
 868                     	xdef	_GPIO_WriteLow
 869                     	xdef	_GPIO_WriteHigh
 870                     	xdef	_GPIO_Write
 871                     	xdef	_GPIO_Init
 872                     	xdef	_GPIO_DeInit
 891                     	end
