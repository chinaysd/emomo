#ifndef __TIM1_H
#define __TIM1_H
#include "stm8s_tim1.h"
#include "stm8s_tim4.h"

void Tim1_Init(void);
void tim4_init(void);
void TimingDelay_Decrement(void);
void delay_ms( u32 nTime);
#endif