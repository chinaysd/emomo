#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"

#define  FOOT_LED_PIN    P00
#define  CUP_LED_PIN     P01

#define  FOOT_LED_OPEN    FOOT_LED_PIN=1
#define  FOOT_LED_CLOSE   FOOT_LED_PIN=0
#define  CUP_LED_OPEN     CUP_LED_PIN=1
#define  CUP_LED_CLOSE    CUP_LED_PIN=0

void LED_Init(void);
void FOOT_LED_SET(void);
void FOOT_LED_RESET(void);
void CUP_LED_SET(void);
void CUP_LED_RESET(void);



#endif