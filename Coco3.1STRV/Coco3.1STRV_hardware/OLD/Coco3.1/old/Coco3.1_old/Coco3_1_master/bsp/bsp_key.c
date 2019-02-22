#include "bsp_key.h"


void Key_Init(void)
{
	P1CON &= ~0X30;
	P1PH  |= 0X30;     //设置P14,P15带上拉输入
	P2CON &= ~0X73;
	P2PH  |= 0X73;     //设置P20,P21P24,P25,P26带上拉输入  
}

void BackCall_Key(void (*ptr)())
{
	(*ptr)();
}



