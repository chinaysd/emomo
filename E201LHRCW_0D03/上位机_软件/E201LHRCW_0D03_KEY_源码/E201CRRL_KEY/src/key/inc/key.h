#ifndef KEY_H_
#define KEY_H_

#include "stm8s_conf.h"


/**
	@function: 按键扫描的时间定义
	@brief: 时基125us
*/
#define 	KEY_SCAN_TIME			20				//	20ms		
#define 	KEY_JITTER_TIME			30				// 	20ms
#define 	KEY_CP_TIME				1500				//	ms
#define 	KEY_CPH_TIME			50				//  200ms	长按保持触发时�

/**
	@function:msg
	@brief:  支持短按，长按，长按保持，长按放手
*/ 
typedef enum
{
	MSG_KEY_NONE=0,
	MSG_KEY1_PRESS,
	MSG_KEY1_SHORT_PRESS,
	MSG_KEY1_LONGPRESS,
	MSG_KEY1_LONGPRESS_RE,
	MSG_KEY2_PRESS,
	MSG_KEY2_SHORT_PRESS,
	MSG_KEY2_LONGPRESS,
	MSG_KEY2_LONGPRESS_RE,
	MSG_KEY3_PRESS,
	MSG_KEY3_SHORT_PRESS,
	MSG_KEY3_LONGPRESS,
	MSG_KEY3_LONGPRESS_RE,
	MSG_KEY4_PRESS
}t_KEY_MSG;



















/************************************************************/

/**
	@function:IO 和按键扫描状态的初始化
*/
void KEY_Init(void);

/**
	@function:按键的扫描
	@return :t_KEY_MSG 类型的消息，消息集在t_KEY_MSG中定义
*/
t_KEY_MSG KEY_Scan(void);

#endif