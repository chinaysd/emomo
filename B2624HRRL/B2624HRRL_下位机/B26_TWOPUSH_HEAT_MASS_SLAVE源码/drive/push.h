#ifndef _push_h_
#define _push_h_

#include "stm8s_gpio.h"

#define PUSH_A1    1
#define PUSH_A2    1
#define PUSH_B1    1
#define PUSH_B2    1
#define PUSH_C1    1
#define PUSH_C2    1
#define delay_share_time    100

#if     PUSH_A1
#define PUSH_A1_PIN       GPIO_PIN_5
#define PUSH_A1_PORT      GPIOC
#endif

#if     PUSH_A2
#define PUSH_A2_PIN       GPIO_PIN_4
#define PUSH_A2_PORT      GPIOC
#endif

#if     PUSH_B1
#define PUSH_B1_PIN       GPIO_PIN_6
#define PUSH_B1_PORT      GPIOC
#endif

#if     PUSH_B2
#define PUSH_B2_PIN       GPIO_PIN_7
#define PUSH_B2_PORT      GPIOC
#endif

#if     PUSH_C1
#define PUSH_C1_PIN       GPIO_PIN_3
#define PUSH_C1_PORT      GPIOC
#endif

#if     PUSH_C2
#define PUSH_C2_PIN       GPIO_PIN_5
#define PUSH_C2_PORT      GPIOD
#endif


void Push_Init(void);

void Push_A1_Open(void);
void Push_A2_Open(void);

void Push_B1_Open(void);
void Push_B2_Open(void);

void Push_C1_Open(void);
void Push_C2_Open(void);

void Push_A1_Close(void);
void Push_A2_Close(void);

void Push_B1_Close(void);
void Push_B2_Close(void);

void Push_C1_Close(void);
void Push_C2_Close(void);

void Push_A1_B2_Reset(void);
void Push_A2_B1_Reset(void);

void Push_A1_B1_Reset(void);
void Push_A2_B2_Reset(void);

void Push_All_Close(void);
#endif