//************************************************************
// Copyright (c) ��������Ԫ΢�������޹�˾
// �ļ�����	:	data_type.h
// ����		:	
// ����������:	
// �汾		:	
// ���ļ�¼	:	
//*************************************************************

#ifndef DATA_TYPE_C_HEADER
#define DATA_TYPE_C_HEADER

/*
typedef bit 			BOOL; 		// ����������λ������
typedef unsigned char	CHAR;		// �ַ�����
typedef unsigned char 	INT8U; 		// �޷���8λ���ͱ���  
typedef signed char 	INT8S; 		// �з���8λ���ͱ���  
typedef unsigned int 	INT16U; 	// �޷���16λ���ͱ��� 
typedef signed int 		INT16S; 	// �з���16λ���ͱ���
typedef unsigned long 	INT32U; 	// �޷���32λ���ͱ���
typedef signed long 	INT32S; 	// �з���32λ���ͱ��� 
typedef float 			FP32; 		// �����ȸ�����(32λ����) 
typedef double 			FP64; 		// ˫���ȸ�����(64λ����)
*/

#define   BOOL     bit 			 		// ����������λ������
#define   CHAR     unsigned char		// �ַ�����
#define   INT8U    unsigned char 		// �޷���8λ���ͱ���  
#define   INT8S    signed char 	 		// �з���8λ���ͱ���  
#define   INT16U   unsigned int 	 	// �޷���16λ���ͱ��� 
#define   INT16S   signed int 		 	// �з���16λ���ͱ���
#define   INT32U   unsigned long 	 	// �޷���32λ���ͱ���
#define   INT32S   signed long 		    // �з���32λ���ͱ��� 
#define   FP32     float 			 	// �����ȸ�����(32λ����) 
#define   FP64     double 			 	// ˫���ȸ�����(64λ����)

#define		BS(SFR,NUM)		(SFR|=(1<<NUM))             //λ��1
#define		BC(SFR,NUM)		(SFR&=~(1<<NUM))		    //λ��0

#define 	true		1
#define 	false		0
#define 	enable		1
#define 	disable		0



#endif
