#include "bsp_led.h"




void Led_Open(void)
{
  GPIO_WriteHigh(GPIOA,GPIO_PIN_3);
}

void Led_Close(void)
{
  GPIO_WriteLow(GPIOA,GPIO_PIN_3);
}
void Led_Init(void)
{
  GPIO_Init(GPIOA,GPIO_PIN_3,GPIO_MODE_OUT_PP_LOW_FAST);
  Led_Close();
}

void BackCall_Led(void (*ptr)())
{
  (*ptr)();
}

