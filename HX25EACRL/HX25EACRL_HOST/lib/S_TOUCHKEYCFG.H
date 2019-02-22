//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子有限公司
//	文件名称	:  S_TouchKeyCFG.h
//	作者			: 
//	模块功能	:  触控键配置文件
// 	版本			:
// 	更改记录	:
//
//	注意事项	:  用户配置文件，用户可修改
//
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__

//==========================================================================
//触控按键基本配置部分，用户可修改

//触控按键寄存器设置
//-----------------------------------------------------------------------
//TKCFG1:
// bit[6:4] = 001 滤波长度为2 个系统时钟
//          = 010 滤波长度为4 个系统时钟
//          = 011 滤波长度为8 个系统时钟
//          = 100 滤波长度为12 个系统时钟
//          = 101 滤波长度为16 个系统时钟
//          = 110 滤波长度为24 个系统时钟
//          = 111 滤波长度为32 个系统时钟
//----------------------------------------------------------------------
//CTIME = n  时 (TKCFG2	TKCFG1)的设置,
//CTIME = 0x0f  (0x0f	    0x6b)
//CTIME = 0x0b 	(0x0b		0x5b)
//CTIME = 0x0a 	(0x0a		0x5b)
//CTIME = 0x09 	(0x09		0x5b)
//CTIME = 0x08 	(0x08		0x4b)
//CTIME = 0x06 	(0x06		0x3b)
//CTIME = 0x05 	(0x05		0x3b)
//CTIME = 0x03 	(0x03		0x2b)
//例如: 
//不共用项目配置CTIME = 8，即TKCFG2= 0x08,TKCFG1 = 0x4b
//共用项目配置: CTIME = b, 即TKCFG2= 0x0b,TKCFG1 = 0x5b

//--------------------------------------------------
//TKCFG3 = (充电电压--- 比较电压)
// 0x38       (4v     --1.22v)
// 0x30       (3.67v -- 1.22v)
// 0x28       (3.33v -- 1.22v)
// 0x20       (3v  ---- 1.22v)
// 0x18       (2.75v -- 1.22v)
// 0x23       (3v   ---- 1.5v)
// 0x37       (3.67v-----  2v)
// 0x27       (3v  ------- 2v)
// 0x1f       (2.75v------ 2v)

//---------------------------------------------------------------------------
//用户只需要修改SOCAPI_SET_TKCFG2;根据共用与不共用项目来设置
#define				SOCAPI_SET_TKCFG1							0x4b	//SFR:TKCFG1配置；默认为0x4b不需要修改					
#define				SOCAPI_SET_TKCFG2							0x42    //SFR:TKCFG2配置；不共用：0x08，共用：0x0b		01--0010			
#define				SOCAPI_SET_TKCFG3							0x38	//SFR:TKCFG3配置；默认为0x38不需要修改			--111000
//---------------------------------------------------------------------------

//触控按键的个数，通道设置，每bit控制一个通道
#define		        SOCAPI_SET_TOUCHKEY_TOTAL					5 		//用户实际使用的按键通道的数量,TK14,TK13,TK12,TK10,TK9； 
#define				SOCAPI_SET_TOUCHKEY_CHANNEL					0x60D0  //bit15~bit0对应TK15~TK0;  对应为置1则为TK，对应位置0则为IO


//触控按键的程序检测确认次数
#define			 	SOCAPI_SET_TOUCHKEY_CONFIRM_CNT				10 	 	//确认按键次数(4~30之间，检测次数越大，反应越慢)

//触控按键的噪音值
#define				SOCAPI_SET_NOISE_THRESHOLD					22		//设置噪音阈值范围:16~40

//每一路通道触控按键的手指阈值，范围0~65535，此为有效差值=（baseline-Finger）*0.6，数值越大，灵敏度越低，反之亦然。
//baseline为手指没按下的rawdata值,Finger为手指按下后的rawdata值
//乘以0.6是留点余量，因为每个人的手指接触面积不一样,用户也可根据触摸效果适当的增加或减小。
//用户只需要设置实际使用的通道手指阈值，其余没用到的通道可以随机数; 
#define				SOCAPI_KEY0_FINGER_THRESHOLD					230	 	
#define				SOCAPI_KEY1_FINGER_THRESHOLD					180
#define				SOCAPI_KEY2_FINGER_THRESHOLD					180
#define				SOCAPI_KEY3_FINGER_THRESHOLD					180
#define				SOCAPI_KEY4_FINGER_THRESHOLD				80	       //4        180*0.5-10
#define				SOCAPI_KEY5_FINGER_THRESHOLD					150
#define				SOCAPI_KEY6_FINGER_THRESHOLD				80	       //6        180*0.5-10
#define				SOCAPI_KEY7_FINGER_THRESHOLD				80	       //7        180*0.5-10
#define				SOCAPI_KEY8_FINGER_THRESHOLD					100
#define				SOCAPI_KEY9_FINGER_THRESHOLD					40		     
#define				SOCAPI_KEY10_FINGER_THRESHOLD					40		     
#define				SOCAPI_KEY11_FINGER_THRESHOLD					150
#define				SOCAPI_KEY12_FINGER_THRESHOLD					35			 
#define				SOCAPI_KEY13_FINGER_THRESHOLD				55	      //13        160*0.5-10
#define				SOCAPI_KEY14_FINGER_THRESHOLD				60	      //14        140*0.5-10
#define				SOCAPI_KEY15_FINGER_THRESHOLD					180

//=1 表示单键, = 0 表示双键或者滑条
#define 			SOCAPI_SET_SLIDE_KEY_FUNCTION					1		//=0 表示单键, = 1 表示组合双键或者滑条


//---------------------------------------------------------------------------
//-------------------以下参数不允许用户修改----------------------------------
#define 			SOCAPI_SET_UPDATE_SPEED							120		//更新速度。可选的值0~255.默认120
#define				SOCAPI_SET_KEY_CONTI_TIME						40000	//按键最长的输出时间,int 型，默认1500
#define				SOCAPI_SET_SYNC_UPDATE							450		//动态更新基线的时间,unsigned int，默认450
#define				SOCAPI_INIT_AUTO_UPDATE_TIME					48		//初始化自动校准时间，0--100 范围，默认48
#define				SOCAPI_AUTO_UPDATE_TIME							2		//动态校准时间，默认2
#define				SOCAPI_MAX_KEY_NUM_INVALID						3		//多少个键抑制，默认3
#define  			SOCAPI_FINGER_MAX_VALUE							2000	//抗干扰消顶数据，默认2000
#define				SOCAPI_SET_CS_FUNCTION							0		//=1 表示进行CS 测试， =0表示不进行CS测试，默认0

#endif //__S_TOUCHKEYCFG_H__
//===========================================================================


