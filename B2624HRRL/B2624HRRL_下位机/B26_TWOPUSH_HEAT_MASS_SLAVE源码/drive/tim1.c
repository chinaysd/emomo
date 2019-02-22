#include "tim1.h"
static  u32 TimingDelay;

void Tim1_Init(void)
{
  TIM1_TimeBaseInit(16,TIM1_COUNTERMODE_UP,1000,0);//16分频，向上计数，计数完了触发中断，如果想
//再 1MS 触发中断，则计数器应该计数 1000 次，1MHZ/1000=1KHZ，正好就是 1ms。
  TIM1_ARRPreloadConfig(ENABLE);//使能自动重装
  TIM1_ITConfig(TIM1_IT_UPDATE , ENABLE);//数据更新中断
  TIM1_Cmd(ENABLE);//开定时器
}

void tim4_init(void)
{
   TIM4_DeInit();  
   TIM4_TimeBaseInit(TIM4_PRESCALER_128, 125);
   TIM4_ARRPreloadConfig(ENABLE);
   TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
   TIM4_Cmd(ENABLE);


}



void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
     {
	TimingDelay--;
      }
}

void delay_ms( u32 nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}