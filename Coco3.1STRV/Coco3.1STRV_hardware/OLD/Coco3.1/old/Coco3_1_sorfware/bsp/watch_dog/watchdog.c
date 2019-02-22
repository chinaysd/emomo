#include "watchdog.h"


void WatchDog_Enable(void)
{
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_SetPrescaler(IWDG_Prescaler_256);
  IWDG_SetReload(0xff);
  IWDG_ReloadCounter();
  IWDG_Enable();
}

void WatchDog_Clear(void)
{
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  IWDG_SetPrescaler(IWDG_Prescaler_256);
  IWDG_SetReload(0xff);
  IWDG_ReloadCounter();
  IWDG_Enable();
}



