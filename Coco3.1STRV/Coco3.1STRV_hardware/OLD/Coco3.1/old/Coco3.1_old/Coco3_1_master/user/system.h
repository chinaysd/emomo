#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "sc92f837x_c.h"
#include "bsp_key.h"
#include "bsp_led.h"
#include "bsp_watchdog.h"
#include "bsp_interrupt.h"
#include "bsp_timer.h"
#include "TimeOut.h"
#include "bsp_uart1.h"

#define Delay_Time     1000
#define Shakes_Time    10
#define OnLine_Time    25

#define True      1
#define False     0

typedef enum
{
   KEY_LOOP_NUM0,
	 KEY_LOOP_NUM1,
	 KEY_LOOP_NUM2,
	 KEY_LOOP_NUM3,
	 KEY_LOOP_NUM4,
	 KEY_LOOP_NUM5,
	 KEY_LOOP_NUM6,
	 KEY_LOOP_NUM7
};


void System_Init(void);
void System_Handle(void);





#endif