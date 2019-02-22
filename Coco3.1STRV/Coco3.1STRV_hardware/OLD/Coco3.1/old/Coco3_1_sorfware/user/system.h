#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "stm8s.h"
#include "bsp_led.h"
#include "bsp_clk.h"
#include "watchdog.h"
#include "interrupt_enable.h"
#include "bsp_timer.h"
#include "TimeOut.h"
#include "bsp_pushrod.h"
#include "bsp_uart.h"
#include "string.h"

#define Delay_Time    1000

void System_Init(void);
void System_Handle(void);


#endif

