/******************** (C) COPYRIGHT 2012 青风电子 ********************
 * 文件名  ：main
 * 描述    ：         
 * 实验平台：青风stm8发板
 * 描述    ：按键中断
 * 作者    ：青风
 * 店铺    ：qfv5.taobao.com
  硬件：key1-- pf7      key2 --pf6       key3--pf5
**********************************************************************/
#include "key_exti.h"
#include "stm8s_gpio.h"
#include "stm8s_exti.h"

void EXIT_KEY_Init(void)
{
   GPIO_Init(KEY1_PORT,KEY1_PIN,GPIO_MODE_IN_PU_NO_IT );//定义key的管脚的模式
   GPIO_Init(KEY2_PORT,KEY2_PIN,GPIO_MODE_IN_PU_NO_IT );
   GPIO_Init(KEY3_PORT,KEY3_PIN,GPIO_MODE_IN_PU_NO_IT );
   EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOE, EXTI_SENSITIVITY_FALL_ONLY);
}

