#include "push.h"


void Push_Init(void)
{
  P20PM;
  P21PM;
  P24PM;
  P25PM;
}
  
void PushA1_Open(void)
{
  IO_PUSHA1_OPEN;
}

void PushA2_Close(void)
{
  IO_PUSHA2_CLOSE;
}

void PushA1_Stop(void)
{
  IO_PUSHA1_STOP;
}

void PushA2_Stop(void)
{
  IO_PUSHA2_STOP;
}

void PushB1_Open(void)
{

  IO_PUSHB1_OPEN;
}

void PushB2_Close(void)
{
  IO_PUSHB2_CLOSE;
}

void PushB1_Stop(void)
{
  IO_PUSHB1_STOP;
}

void PushB2_Stop(void)
{
  IO_PUSHB2_STOP;
}



