#include "bsp_watchdog.h"

void WatchDog(void)
{
	WATCHDOG_OPEN;
}

void WatchDog_Clear(void)
{
	WATCHDOG_CLEAR;
}
