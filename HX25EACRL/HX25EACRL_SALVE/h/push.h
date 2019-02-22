#ifndef _PUSH_H_
#define _PUSH_H_


#include "h\SC92F732X_C.h"
#include "732X_IO.h"
#include "MYDEFINE.H"
#include"intrins.h"

#define    PUSHA1_PIN	   P20
#define    PUSHA2_PIN	   P21
#define    PUSHB1_PIN	   P24
#define    PUSHB2_PIN	   P25

#define    IO_PUSHA1_OPEN     PUSHA1_PIN=1
#define    IO_PUSHA2_CLOSE    PUSHA2_PIN=1
#define    IO_PUSHA1_STOP     PUSHA1_PIN=0
#define    IO_PUSHA2_STOP     PUSHA2_PIN=0

#define    IO_PUSHB1_OPEN     PUSHB1_PIN=1
#define    IO_PUSHB2_CLOSE    PUSHB2_PIN=1
#define    IO_PUSHB1_STOP     PUSHB1_PIN=0
#define    IO_PUSHB2_STOP     PUSHB2_PIN=0




void Push_Init(void);
void PushA1_Open(void);
void PushA2_Close(void);
void PushA1_Stop(void);
void PushA2_Stop(void);

void PushB1_Open(void);
void PushB2_Close(void);
void PushB1_Stop(void);
void PushB2_Stop(void);





#endif