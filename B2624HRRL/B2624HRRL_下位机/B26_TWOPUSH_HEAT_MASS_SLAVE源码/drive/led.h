#ifndef _led_h_
#define _led_h_

#include "stm8s_gpio.h"

#define Led_Pin   GPIO_PIN_3
#define Led_Port  GPIOA

void Led_Init(void);
void Led_Open(void);
void Led_Close(void);
void Led_reset(void);


#endif