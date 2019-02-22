#include "light.h"

void LED_Init(void)
{
  P00PM;
  P01PM;
  P05PM;
}

void FOOT_LED_SET(void)
{
 FOOT_LED_OPEN;
}

void FOOT_LED_RESET(void)
{
 FOOT_LED_CLOSE;
}

void CUP_LED_SET(void)
{
 CUP_LED_OPEN;
}

void CUP_LED_RESET(void)
{
 CUP_LED_CLOSE;
}
