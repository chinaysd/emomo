#include "heat.h"


void Heat_Init(void)
{
   P02PM;
   P03PM;
   HEAT1_CLOSE;
   HEAT2_CLOSE;
}

void  HEAT1_SET(void)
{
   HEAT1_OPEN;
}
void  HEAT2_SET(void)
{
   HEAT2_OPEN;
}

void  HEAT1_RESET(void)
{
   HEAT1_CLOSE;
   
}
void  HEAT2_RESET(void)
{
   HEAT2_CLOSE;
}