#include "key.h"
#include "stm8s_gpio.h"

#define uint unsigned int
#define uchar unsigned char

//static uint i,j;

//void delay1_ms(uint timer)
//{
//  for(i = timer;i >0;i--)
//  {
//    for(j=120;j>0;j--);
//  }
//}


void Key_Init(void)
{
   GPIO_Init(Key5_PORT,Key5_PIN,GPIO_MODE_IN_PU_NO_IT);
   GPIO_Init(Key6_PORT,Key6_PIN,GPIO_MODE_IN_PU_NO_IT);
}

BitStatus Key5_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef (GPIO_Pin))
{
   if(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0)
   {
      //delay1_ms(10);
      if(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0)
      {
       // while(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0);
        return 0;
      }
      else
      {
        return 1;
      }
   }
   else
   {
     return 1;
   }
}
#if 1
BitStatus Key6_Down(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
   if(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0)
   {
      //delay1_ms(10);
      if(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0)
      {
        //while(GPIO_ReadInputPin(GPIOx,GPIO_Pin) == 0);
        return 0 ;
      }
      else
      {
        return 1;
      }
   }
   else
   {
     return 1;
   }
}
#endif
