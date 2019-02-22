#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "sc92f837x_c.h"


#define  LED_NUM     2
#define  LED_ERROR   1
#define  LED_SUCCESS 0


typedef struct
{
    unsigned char ID;
}
LED_PARA_T;


unsigned char Led_App_Handle(unsigned char sum);


#endif



