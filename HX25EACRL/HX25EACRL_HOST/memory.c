#include	"h\SC91F831_C.h"
#include	"memory.h"
#include	"config.h"
#include    "intrins.h"
#include	"key.h"


INT8U  code * POINT ;
INT8U  Turn_Number1[4]={0x00,0x00,0x00,0x00};
INT8U  Turn_Number2[4]={0x00,0x00,0x00,0x00};
//INT8U  PowerDown_Number[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/********************IAPд�����ݺ���********************/
void  Byte_Write(INT8U DATA , INT8U ADD_OFFSET)
{
  IAPDAT=DATA;		     //������DATA��IAP���ݼĴ���
  IAPADL=ADD_OFFSET;	 //д���ֵַ
  IAPKEY=0xF0;			 //��ֵ�ɸ���ʵ�ʵ���;��֤����ָ��ִ�к󵽶�IAPCTL��ֵǰʱ����С��240(0xf0)��ϵͳʱ�ӣ�����IAP���ܹر�
  IAPCTL=0x0A;			 //ִ��IAPд�������ͬʱCPU 8M Hold 1ms
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}

/********************IAP��ȡ���ݺ���********************/
INT8U  Byte_Read(INT8U ADD_OFFSET)
{
   POINT=ADD_BASE+ADD_OFFSET;
   return (*POINT);
}

