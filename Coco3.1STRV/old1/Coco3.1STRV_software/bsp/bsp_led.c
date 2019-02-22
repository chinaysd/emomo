#include "bsp_led.h"

LED_PARA_T   Led_Para[LED_NUM];

unsigned char Led_Init(unsigned char id)
{
    if(id > LED_NUM)
        return LED_ERROR;
    if(id == 0)
    {
        P0CON |= 0X02;
        P0PH  &= ~0X02;
        return LED_SUCCESS;
    }
    else if(id == 1)
    {
        P0CON |= 0X01;
        P0PH  &= ~0X01;
        return LED_SUCCESS;
    }
    return LED_ERROR;
}

unsigned char Led_App_Init(LED_PARA_T *P)
{
    unsigned char Led_Init(unsigned char ID);
    return Led_Init(P->ID);
}


unsigned char Led_App_Handle(unsigned char sum)
{
    static unsigned char i;
    if(sum > LED_NUM)
       return LED_ERROR;
    for(i = 0; i < sum; i ++)
    {
       Led_Para[i].ID = i;
       Led_App_Init(&Led_Para[i]);       
    }
    if(i != sum)
    {
        return LED_ERROR;
    }
    else
    {
        return LED_SUCCESS;
    }   
}






