#ifndef _system_h_
#define _system_h_

#include "led.h"
#include "mass.h"
#include "heat.h"
#include "push.h"
#include "key.h"
#include "stm8s_clk.h"
#include "uart.h"
#include "sysclock.h"
#include "stm8s_it.h"
#include "tim1.h"
#include "TimeOut.h"
#include "stm8s_tim4.h"


void System_Init(void);
void System_Handle(void);


#endif