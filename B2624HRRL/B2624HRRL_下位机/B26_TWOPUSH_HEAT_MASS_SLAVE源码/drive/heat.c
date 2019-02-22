#include "heat.h"
#include "stm8s_gpio.h"


void Heat_Init(void)
{
  GPIO_Init(Heat_PD4_PORT,Heat_PD4_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
}

void Heat_Open(void)
{
  GPIO_WriteHigh(Heat_PD4_PORT,Heat_PD4_PIN);
}

void Heat_Close(void)
{
  GPIO_WriteLow(Heat_PD4_PORT,Heat_PD4_PIN);
}