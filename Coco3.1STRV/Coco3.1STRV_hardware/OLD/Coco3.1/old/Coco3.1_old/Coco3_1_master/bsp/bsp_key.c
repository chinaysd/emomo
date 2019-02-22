#include "bsp_key.h"


void Key_Init(void)
{
	P1CON &= ~0X30;
	P1PH  |= 0X30;     //����P14,P15����������
	P2CON &= ~0X73;
	P2PH  |= 0X73;     //����P20,P21P24,P25,P26����������  
}

void BackCall_Key(void (*ptr)())
{
	(*ptr)();
}



