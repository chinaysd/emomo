#ifndef _COOL_H_
#define _COOL_H_



#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"


#define COOL_PIN   P10
#define COOL_SET(X)   ((X)?(COOL_PIN = 1):(COOL_PIN = 0))


#define COOL_CONFIG_PIN   P16
#define COOL_CONFIG_SET(X)     ((X)?(COOL_CONFIG_PIN = 1):(COOL_CONFIG_PIN = 0))

#define HEATER_CONFIG_PIN  P17
#define HEATER_CONFIG_SET(X)    ((X)?(HEATER_CONFIG_PIN = 1):(HEATER_CONFIG_PIN = 0))

#define COOL_ERROR       1
#define COOL_SUCCESS     0

#define HEATER_ERROR     1
#define HEATER_SUCCESS   0

#define COOL_NUM         2



void Cool_Init(void);
unsigned char Cool_Handle(unsigned char id,unsigned char status);









#endif