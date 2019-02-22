#include "cool.h"

void Cool_Init(void)
{
   P16PM;
   P17PM;
   P10PM;
   COOL_SET(0);
   COOL_CONFIG_SET(0);
   HEATER_CONFIG_SET(0);
}

unsigned char Cool_Handle(unsigned char id,unsigned char status)
{
    if(id > COOL_NUM)
		return COOL_ERROR;
    if(id == 0)
    {
      if(status == 0)
      {
           COOL_SET(status);
           COOL_CONFIG_SET(status);
           return COOL_SUCCESS;
      }
	  else if(status == 1)
	  {
	       COOL_SET(status);
           COOL_CONFIG_SET(status);
	       return COOL_SUCCESS;
	  }
	  else 
	  {
	       COOL_SET(0);
           COOL_CONFIG_SET(0);
	       return COOL_ERROR;
	  }
    }
	else if(id == 1)
	{
	  if(status == 0)
	  {
	       COOL_SET(status);
		   HEATER_CONFIG_SET(status);
	       return HEATER_SUCCESS;
	  }
	  else if(status == 1)
	  {
	       COOL_SET(status);
		   HEATER_CONFIG_SET(status);
	       return HEATER_SUCCESS;  
	  }
	  else 
	  {
	       COOL_SET(0);
		   HEATER_CONFIG_SET(0);
	       return HEATER_ERROR;
	  }
	}
	return COOL_ERROR;
}