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
#include "voice_data.h"

#define WATCH_DOG_CLEAR
#define WATCH_DOG_ENABLE

#define Push_Auto_Close_Time     30
#define Auto_Close_Time1s          1000

typedef struct
{
     unsigned char Key_Push_Stop_Flag;
     unsigned char Key_Push_Start_Flag;
     unsigned char Push_Auto_Close_Flag;
     unsigned int   Push_Auto_Close_Cnt1s;
     unsigned int   Push_Auto_Close_Cnts;

     unsigned char PushOnlyOne_Flag;
}
PUSH_STATUS_PARA_t;

typedef struct
{
     unsigned char Demo_Start_Flag;
     unsigned char Demo_Stop_Flag;
     unsigned char Demo_Flag;
}
DEMO_STATUS_PARA_t;



void System_Init(void);
void System_Handle(void);




#endif

