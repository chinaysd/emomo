#ifndef _BSP_INTERRUPT_H_
#define _BSP_INTERRUPT_H_

#include "sc92f837x_c.h"

#define INTERRUPT_ENABLE      1
#define INTERRUPT_DISABLE     0

#if INTERRUPT_ENABLE
#define INTERRUPT_REGISTER      EA
#define INTERRUPT_OPEN          (INTERRUPT_REGISTER = 1)
#define INTERRUPT_CLOSE         (INTERRUPT_REGISTER = 0)
#endif

void Interrupt_Init(void);


#endif