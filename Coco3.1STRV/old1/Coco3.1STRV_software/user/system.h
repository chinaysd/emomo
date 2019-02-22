#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "sc92f837x_c.h"
#include "TimeOut.h"
#include "bsp_led.h"
#include "bsp_timer.h"
#include "bsp_uart.h"
#include "key.h"
#include "sys_config.h"
#include "bsp_pushrod_direction.h"

#define WATCH_DOG_CLEAR
#define WATCH_DOG_ENABLE




void System_Init(void);
void System_Handle(void);




#endif