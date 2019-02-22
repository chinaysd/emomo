#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "sc92f732x_c.h"
#include "TimeOut.h"
#include "bsp_led.h"
#include "bsp_timer.h"
#include "bsp_uart.h"
#include "key.h"
#include "bsp_test.h"
#include "bsp_voice.h"

#define True     1
#define False    0


#define OnLine_Time       40
#define Auto_Close_Time   60000
#define Change_Time_Cnt20s  40000

#define Data_Stop_End   0x0100
#define Data_Stop       0x0101

#define HEAT_FUNCTION_DISABLE     0
#define HEAT_FUNCTION_ENABLE      1

#define FOOL_LED_FUNCTION_DISABLE 0
#define FOOT_LED_FUNCTION_ENABLE  1

#define MASS_FUNCTION_DISABLE     0
#define MASS_FUNCTION_ENABLE      1

#define LARBUM_PUSH_FUNCTION_DISABLE  0
#define LARBUM_PUSH_FUNCTION_ENABLE   1


/*****************************马达变量结构体定义****************************************/
typedef struct
{
   unsigned char Mass_Flag;
   unsigned int Mass_Cnt;
   /****************以下为定时变量***************/
   unsigned char Mass_Cnt30Min_Flag;
   unsigned int  App_Mass_Cnt1s;
   unsigned int  Mass_Cnt30Min;
   /********************************************/
}
MASS_PARA;
/***************************************************************************************/


/*******************************脚灯变量结构体定义**************************************/
typedef struct
{
   unsigned char Foot_Led_Flag;
   unsigned int  Foot_Led_Cnt;
}
FOOL_LED_PARA_t;
/***************************************************************************************/

/*******************************发热布结构体定义***************************************/
typedef struct
{
   unsigned char Heat_Flag;
   unsigned int Heat_Cnt;
   unsigned char Heat_Cnt30Min_Flag;
   unsigned int Heat_Cnt30Min;
   unsigned int App_Heat_Cnt1s;
}
HEAT_FUNCTION_PARA_t;
/**************************************************************************************/

/******************************双击和切换结构体的变量定义************************************/
typedef struct
{
  unsigned char Double_Push_Cnt,Double_Push_Flag;
  unsigned int  Double_Push_Flag_Cnt;

  unsigned char Change_Time_Flag;
  unsigned int  Change_Time_Cnts;
  unsigned int  Change_Temp_Cnts_Flag;
  unsigned char Change_OnlyOne_Flag; 
}
DOUBLE_CHANGE_MODE_t;
/***************************************************************************************/


/****************************************** 推杆自动停止结构体变量定义***************************************/
typedef struct
{
  unsigned char Auto_Close_Push_Flag;
  unsigned int  Auto_Close_Push_Cnts;

  unsigned char Voice_AutoClosePush_OnlyOneFlag;
  unsigned char Voice_AutoClosePush_OnlyOneEndFlag;
}
AUTO_CLOSE_PUSH_PARA_t;
/******************************************************************************************************/

/*******************************************演示结构体变量定义*****************************************/
typedef struct
{
   unsigned char Demo_Flag;
}
DEMO_PARA_t;
/******************************************************************************************************/

/********************************************全局变量定义**********************************************/
typedef struct
{
   unsigned char Data;
   unsigned int  VOICE_DATA,VOICE_DATA_STOP,VOICE_DATA_STOP_END;
   unsigned char App_Flag;
}
APP_PARA_t;
/*******************************************************************************************************/




void System_Init(void);
void System_Handle(void);




#endif
