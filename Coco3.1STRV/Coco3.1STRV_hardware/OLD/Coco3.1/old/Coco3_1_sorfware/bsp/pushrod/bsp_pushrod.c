#include "bsp_pushrod.h"

uint8_t  Pushrod_Init(uint8_t ID)
{
  if(ID == 0)
  {
    GPIO_Init(PUSH1A_PORT,PUSH1A_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH1A_SET(0);
    GPIO_Init(PUSH2A_PORT,PUSH2A_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH2A_SET(0);
  }
  else if(ID == 1)
  {
    GPIO_Init(PUSH1B_PORT,PUSH1B_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH1B_SET(0);
    GPIO_Init(PUSH2B_PORT,PUSH2B_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH2B_SET(0);
  }
  else if(ID == 2)
  {
    GPIO_Init(PUSH1C_PORT,PUSH1C_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH1C_SET(0);
    GPIO_Init(PUSH2C_PORT,PUSH2C_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
    PUSH2C_SET(0);
  }
  else
  {
    return 0;
  }
  return 1;
}

uint8_t Pushrod_App_Init(Pushrod_Para_t *p)
{
  uint8_t Pushrod_Init(uint8_t ID);
  return Pushrod_Init(p->ID);
}
