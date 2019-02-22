#ifndef _BSP_KEY_H_
#define _BSP_KEY_H_

#include "sc92f837x_c.h"

#define KEY_ENABLE        1
#define KEY_DISABLE       0


#if KEY_ENABLE

#define  RESET_KEY1_PIN           P24 
#define  RESET_KEY1_DOWN          RESET_KEY1_PIN == 0
#define  RESET_KEY1_UP            RESET_KEY1_PIN == 1

#define  LEFT_KEY2_PIN            P21
#define  LEFT_KEY2_DOWN           LEFT_KEY2_PIN == 0
#define  LEFT_KEY2_UP             LEFT_KEY2_PIN == 1

#define  RIGHT_KEY3_PIN           P20
#define  RIGHT_KEY3_DOWN          RIGHT_KEY3_PIN == 0
#define  RIGHT_KEY3_UP            RIGHT_KEY3_PIN == 1

#define  FOUR_LEFT_KEY4_PIN       P26
#define  FOUR_LEFT_KEY4_DOWN      FOUR_LEFT_KEY4_PIN == 0
#define  FOUR_LEFT_KEY4_UP        FOUR_LEFT_KEY4_PIN == 1

#define  FOUR_RIGHT_KEY5_PIN      P15
#define  FOUR_RIGHT_KEY5_DOWN     FOUR_RIGHT_KEY5_PIN == 0
#define  FOUR_RIGHT_KEY5_UP       FOUR_RIGHT_KEY5_PIN == 1

#define  FOUR_GETUP_KEY6_PIN      P14
#define  FOUR_GETUP_KEY6_DOWN     FOUR_GETUP_KEY6_PIN == 0
#define  FOUR_GETUP_KEY6_UP       FOUR_GETUP_KEY6_PIN == 1

#define  FOUR_GETDOWN_KEY7_PIN    P25
#define  FOUR_GETDOWN_KEY7_DOWN   FOUR_GETDOWN_KEY7_PIN == 0
#define  FOUR_GETDOWN_KEY7_UP     FOUR_GETDOWN_KEY7_PIN == 1

#endif

typedef struct
{
	unsigned char RESET_KEY1_FLAG;
	unsigned char LEFT_KEY2_FLAG;
	
	unsigned char RIGHT_KEY3_FLAG;
	unsigned char FOUR_LEFT_KEY4_FLAG;
	
	unsigned char FOUR_RIGHT_KEY5_FLAG;
	unsigned char FOUR_GETUP_KEY6_FLAG;
	
	unsigned char FOUR_GETDOWN_KEY7_FLAG;
	unsigned char KEY_VALUE;
}
KEY_PARA_TX;

typedef enum
{
	KEY1_VALUE=0X01,
	KEY2_VALUE,
	KEY3_VALUE,
	KEY4_VALUE,
	KEY5_VALUE,
	KEY6_VALUE,
	KEY7_VALUE
};

void Key_Init(void);
void BackCall_Key(void (*ptr)());



#endif

