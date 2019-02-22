#ifndef _BSP_PUSHROD_H_
#define _BSP_PUSHROD_H_

#include "stm8s.h"

#define PUSHROD_NUM       (3)

#define PUSHROD_ENABLE    1
#define PUSHROD_DISABLE   0

typedef struct
{
  uint8_t ID;
}
Pushrod_Para_t;

#if PUSHROD_ENABLE
#define PUSH1A_PORT       GPIOC
#define PUSH1A_PIN        GPIO_PIN_5
#define PUSH1A_SET(X)     ((X)? GPIO_WriteHigh(GPIOC,GPIO_PIN_5):GPIO_WriteLow(GPIOC,GPIO_PIN_5))

#define PUSH2A_PORT       GPIOC
#define PUSH2A_PIN        GPIO_PIN_4
#define PUSH2A_SET(X)     ((X)? GPIO_WriteHigh(GPIOC,GPIO_PIN_4):GPIO_WriteLow(GPIOC,GPIO_PIN_4))

#define PUSH1B_PORT       GPIOC
#define PUSH1B_PIN        GPIO_PIN_6
#define PUSH1B_SET(X)     ((X)? GPIO_WriteHigh(GPIOC,GPIO_PIN_6):GPIO_WriteLow(GPIOC,GPIO_PIN_6))

#define PUSH2B_PORT       GPIOC
#define PUSH2B_PIN        GPIO_PIN_7
#define PUSH2B_SET(X)     ((X)? GPIO_WriteHigh(GPIOC,GPIO_PIN_7):GPIO_WriteLow(GPIOC,GPIO_PIN_7))

#define PUSH1C_PORT       GPIOC
#define PUSH1C_PIN        GPIO_PIN_3
#define PUSH1C_SET(X)     ((X)? GPIO_WriteHigh(GPIOC,GPIO_PIN_3):GPIO_WriteLow(GPIOC,GPIO_PIN_3))

#define PUSH2C_PORT       GPIOD
#define PUSH2C_PIN        GPIO_PIN_5
#define PUSH2C_SET(X)     ((X)?GPIO_WriteHigh(GPIOD,GPIO_PIN_5):GPIO_WriteLow(GPIOD,GPIO_PIN_5))
#endif

uint8_t  Pushrod_Init(uint8_t ID);
uint8_t Pushrod_App_Init(Pushrod_Para_t *p);

#endif

