#ifndef __MEMORY_H__
#define __MEMORY_H__ 

#include	"config.h"

#define    ADD_BASE   0x1F00		    //定义IAP的基址

extern     void    Byte_Write(INT8U DATA , INT8U ADD_OFFSET);
extern     INT8U   Byte_Read(INT8U ADD_OFFSET);


#endif