//************************************************************
// Copyright (c) 深圳市赛元微电子有限公司
// 文件名称	:	data_type.h
// 作者		:	
// 最后更正日期:	
// 版本		:	
// 更改记录	:	
//*************************************************************

#ifndef DATA_TYPE_C_HEADER
#define DATA_TYPE_C_HEADER

/*
typedef bit 			BOOL; 		// 布尔变量（位变量）
typedef unsigned char	CHAR;		// 字符变量
typedef unsigned char 	INT8U; 		// 无符号8位整型变量  
typedef signed char 	INT8S; 		// 有符号8位整型变量  
typedef unsigned int 	INT16U; 	// 无符号16位整型变量 
typedef signed int 		INT16S; 	// 有符号16位整型变量
typedef unsigned long 	INT32U; 	// 无符号32位整型变量
typedef signed long 	INT32S; 	// 有符号32位整型变量 
typedef float 			FP32; 		// 单精度浮点数(32位长度) 
typedef double 			FP64; 		// 双精度浮点数(64位长度)
*/

#define   BOOL     bit 			 		// 布尔变量（位变量）
#define   CHAR     unsigned char		// 字符变量
#define   INT8U    unsigned char 		// 无符号8位整型变量  
#define   INT8S    signed char 	 		// 有符号8位整型变量  
#define   INT16U   unsigned int 	 	// 无符号16位整型变量 
#define   INT16S   signed int 		 	// 有符号16位整型变量
#define   INT32U   unsigned long 	 	// 无符号32位整型变量
#define   INT32S   signed long 		    // 有符号32位整型变量 
#define   FP32     float 			 	// 单精度浮点数(32位长度) 
#define   FP64     double 			 	// 双精度浮点数(64位长度)

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //位置1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		    //位清0

#define 	true		1
#define 	false		0
#define 	enable		1
#define 	disable		0



#endif
