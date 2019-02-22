#ifndef _key_h_
#define _key_h_
#include "stm8s_gpio.h"
#include "stm8s.h"

#define uint unsigned int

#define Key5     1
#define Key6     1



#if  Key5
#define  Key5_PIN     GPIO_PIN_3
#define  Key5_PORT     GPIOD
#endif

#if  Key6
#define  Key6_PIN     GPIO_PIN_2
#define  Key6_PORT     GPIOD
#endif

void Key_Init(void);
void delay1_ms(uint timer);

BitStatus Key5_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
BitStatus Key6_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);


#endif