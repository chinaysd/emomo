#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"

#include "time1.h"
#include "adc.h"
#include "push.h"
#include "light.h"
#include "heat.h"
#include "timeout.h"
#include "cool.h"





#define ADCEN    1
#define ADCDIS   0
#define PUSHEN   1
#define PUSHDIS  0
#define HEATEN   1
#define HEATDIS  0

#define TOUCH_SHAKE_TIME     10000


void System_Init(void);
void System_Handle(void);





#endif