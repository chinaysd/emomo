/******************** (C) COPYRIGHT 2014 ������ ********************
 * �ļ���  ��main
 * ����    ��
 * ʵ��ƽ̨�����stm8����
 * ����    ������
 * ����    �����
 * ����    ��qfv5.taobao.com
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
