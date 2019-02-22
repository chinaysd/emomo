/******************** (C) COPYRIGHT 2014 青风电子 ********************
 * 文件名  ：main
 * 描述    ：
 * 实验平台：青风stm8发板
 * 描述    ：串口
 * 作者    ：青风
 * 店铺    ：qfv5.taobao.com
**********************************************************************/

#include "stm8s.h"
#include "system.h"
//#include <stdio.h>



int main(void)
{
    System_Init();
    while (1)
    {
       System_Handle();
    }
}
