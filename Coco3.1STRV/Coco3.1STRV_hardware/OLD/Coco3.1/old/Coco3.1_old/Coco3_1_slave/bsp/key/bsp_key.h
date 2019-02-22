#ifndef _BSP_KEY_H_
#define _BSP_KEY_H_

#include "stm8s_gpio.h"

#define KEY_ENABLE     1
#define KEY_DISABLE    0

#if KEY_ENABLE
#define KEY6_PORT      GPIOD
#define KEY6_PIN       GPIO_PIN_3

#define KEY5_PORT      GPIOD
#define KEY5_PIN       GPIO_PIN_2
#endif

void Key_Init(void);
unsigned char Key_Status(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
unsigned char Key1_Status(GPIO_TypeDef* gpiox, GPIO_Pin_TypeDef gpio_Pin);

#endif
