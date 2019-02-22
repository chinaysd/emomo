#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "sc92f837x_c.h"

#define LED_ENABLE      1
#define LED_DISABLE     0

#if LED_ENABLE

#define LED_PORT    P0
#define LED_PIN     P00
#define LED_SET(X) (LED_PIN = X)

#endif

void Led_Init(void);


#endif