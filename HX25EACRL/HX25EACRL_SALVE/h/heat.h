#ifndef _HEAT_H_
#define _HEAT_H_


#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"

#define IO_HEAT1_PIN     P02
#define IO_HEAT2_PIN     P03

#define HEAT1_OPEN        IO_HEAT1_PIN=1;
#define HEAT2_OPEN        IO_HEAT2_PIN=1;

#define HEAT1_CLOSE       IO_HEAT1_PIN=0;
#define HEAT2_CLOSE       IO_HEAT2_PIN=0;

void Heat_Init(void);

void  HEAT1_SET(void);
void  HEAT2_SET(void);

void  HEAT1_RESET(void);
void  HEAT2_RESET(void);







#endif