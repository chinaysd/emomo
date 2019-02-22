#include "bsp_clk.h"


void Clk_Init(void)
{
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}

void BackCall_Clk(void (*clk)())
{
  (*clk)();
}


