#include	"h\SC91F831_C.h"
#include	"memory.h"
#include	"config.h"
#include    "intrins.h"
#include	"key.h"


INT8U  code * POINT ;
INT8U  Turn_Number1[4]={0x00,0x00,0x00,0x00};
INT8U  Turn_Number2[4]={0x00,0x00,0x00,0x00};
//INT8U  PowerDown_Number[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

/********************IAP写入数据函数********************/
void  Byte_Write(INT8U DATA , INT8U ADD_OFFSET)
{
  IAPDAT=DATA;		     //送数据DATA到IAP数据寄存器
  IAPADL=ADD_OFFSET;	 //写入地址值
  IAPKEY=0xF0;			 //此值可根据实际调整;保证本条指令执行后到对IAPCTL赋值前时间间隔小于240(0xf0)个系统时钟，否则IAP功能关闭
  IAPCTL=0x0A;			 //执行IAP写入操作，同时CPU 8M Hold 1ms
  _nop_();
  _nop_();
  _nop_();
  _nop_();
}

/********************IAP读取数据函数********************/
INT8U  Byte_Read(INT8U ADD_OFFSET)
{
   POINT=ADD_BASE+ADD_OFFSET;
   return (*POINT);
}

