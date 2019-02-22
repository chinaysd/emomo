#include "led.h"
#include "stm8s_gpio.h"

void Led_Init(void)
{
  GPIO_Init(Led_Port,Led_Pin,GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_WriteLow(Led_Port,Led_Pin);
}

void Led_Open(void)
{
   GPIO_WriteHigh(Led_Port,Led_Pin);
}

void Led_Close(void)
{
   GPIO_WriteLow(Led_Port,Led_Pin);
}

void Led_reset(void)
{
   GPIO_WriteReverse(Led_Port,Led_Pin);
}


