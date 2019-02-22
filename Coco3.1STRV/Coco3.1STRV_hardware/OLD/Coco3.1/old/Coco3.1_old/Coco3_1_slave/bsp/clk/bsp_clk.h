#ifndef _BSP_CLK_H_
#define _BSP_CLK_H_

#include "stm8s.h"


void Clk_Init(void);
void BackCall_Clk(void (*clk)());


#endif
