#include "bsp_pushrod_direction.h"






void Push_Temp_Direction(void)
{
    	P1CON &= ~0X01;
		P1PH  |= 0X01;
}






