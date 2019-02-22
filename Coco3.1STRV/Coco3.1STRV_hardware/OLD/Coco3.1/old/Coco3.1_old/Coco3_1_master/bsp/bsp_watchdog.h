#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_

#include "sc92f837x_c.h"

#define WATCHDOG_ENABLE      1
#define WATCHDOG_DISABLE     0


#if WATCHDOG_ENABLE 

#define WATCHDOG_REGISTER       WDTCON 
#define WATCHDOG_OPEN           (WATCHDOG_REGISTER = 0X10) 
#define WATCHDOG_CLEAR          (WATCHDOG_REGISTER = 0X10) 

#endif

void WatchDog(void);
void WatchDog_Clear(void);



#endif