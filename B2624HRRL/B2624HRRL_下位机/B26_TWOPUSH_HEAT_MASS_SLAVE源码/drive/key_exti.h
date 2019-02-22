#ifndef  __KEY_EXTI_H
#define  __KEY_EXTI_H
#include "stm8s.h"

#define KEY1_PIN        GPIO_PIN_7 
#define KEY2_PIN        GPIO_PIN_6
#define KEY3_PIN        GPIO_PIN_5 
#define KEY1_PORT       GPIOE
#define KEY2_PORT       GPIOE
#define KEY3_PORT       GPIOE


void EXIT_KEY_Init(void);
#endif