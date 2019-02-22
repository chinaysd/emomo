#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm8s.h"

#define LED_ENABLE     1
#define LED_DISABLE    0

#if LED_ENABLE
#define LED_PORT       GPIOA
#define LED_PIN        GPIO_PIN_3
#endif

void Led_Init(void);
void Led_Open(void);
void Led_Close(void);
void BackCall_Led(void (*ptr)());

#endif

