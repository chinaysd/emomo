#include "bsp_key.h"

void Key_Init(void)
{
  GPIO_Init(KEY6_PORT,KEY6_PIN,GPIO_MODE_IN_PU_NO_IT);
  GPIO_Init(KEY5_PORT,KEY5_PIN,GPIO_MODE_IN_PU_NO_IT);
}

unsigned char Key_Status(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  if(0 == GPIO_ReadInputPin(GPIOx,GPIO_Pin))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

unsigned char Key1_Status(GPIO_TypeDef* gpiox, GPIO_Pin_TypeDef gpio_Pin)
{
  if(0 == GPIO_ReadInputPin(gpiox,gpio_Pin))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}



