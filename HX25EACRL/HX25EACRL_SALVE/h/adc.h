#ifndef _ADC_H_
#define _ADC_H_



#include "h\SC92F732X_C.h"

typedef enum
{
             AIN0=0,
			 AIN1,
			 AIN2,
			 AIN3,
			 AIN4,
			 AIN5,
			 AIN6,
			 AIN7,
			 AIN8,
			 AIN9,
			 VDD_DIV4=0xf
}edAdcChannel;

void ADCwork(edAdcChannel Channel,unsigned char Clk);













#endif