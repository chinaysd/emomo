#ifndef _heat_h_
#define _heat_h_

#include "stm8s_gpio.h"

#define Heat    1

#if Heat
#define Heat_PD4_PIN  GPIO_PIN_4
#define Heat_PD4_PORT GPIOD
#endif

void Heat_Init(void);
void Heat_Open(void);
void Heat_Close(void);

#endif
