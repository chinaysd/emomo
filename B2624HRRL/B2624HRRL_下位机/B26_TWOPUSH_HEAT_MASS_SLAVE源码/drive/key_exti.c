/******************** (C) COPYRIGHT 2012 ������ ********************
 * �ļ���  ��main
 * ����    ��         
 * ʵ��ƽ̨�����stm8����
 * ����    �������ж�
 * ����    �����
 * ����    ��qfv5.taobao.com
  Ӳ����key1-- pf7      key2 --pf6       key3--pf5
**********************************************************************/
#include "key_exti.h"
#include "stm8s_gpio.h"
#include "stm8s_exti.h"

void EXIT_KEY_Init(void)
{
   GPIO_Init(KEY1_PORT,KEY1_PIN,GPIO_MODE_IN_PU_NO_IT );//����key�Ĺܽŵ�ģʽ
   GPIO_Init(KEY2_PORT,KEY2_PIN,GPIO_MODE_IN_PU_NO_IT );
   GPIO_Init(KEY3_PORT,KEY3_PIN,GPIO_MODE_IN_PU_NO_IT );
   EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOE, EXTI_SENSITIVITY_FALL_ONLY);
}

