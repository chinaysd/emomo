#include "bsp_led.h"




void Led_Init(void)
{
	P0CON |= 0X01;
	P0PH  &= ~0X01;       //����P00Ϊ�������
	LED_SET(1);
	
}