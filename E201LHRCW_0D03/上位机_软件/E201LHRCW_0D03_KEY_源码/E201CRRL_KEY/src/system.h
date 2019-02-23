#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "stm8s_conf.h"
#include "commu.h"
/*
	communication overflow time 
*/
#define COMMU_TIMEOUT_VALUE						500

#define ON_LINE_TIME								300
#define SHUTDOWN_TIME							14400
#define HEAT_AUTO_CLOSE_TIME					3600
#define COOL_AUTO_CLOSE_TIME					7200

#define LED_REFRESH_TIME							3000
/*
	key scan delay
*/
#define PRESS_DELAY_TIME							80
#define LONG_DELAY_TIME								200
/*
	foot led
*/
#define FOOT_LED_PORT	GPIOC
#define FOOT_LED_PIN		GPIO_PIN_1
#define Foot_Led_Set(x)	((x) ? (GPIO_WriteHigh(FOOT_LED_PORT, FOOT_LED_PIN)) : (GPIO_WriteLow(FOOT_LED_PORT, FOOT_LED_PIN)))

#define LED1_PORT	GPIOC
#define LED1_PIN		GPIO_PIN_4
#define Led1_Set(x)	((x) ? (GPIO_WriteHigh(LED1_PORT, LED1_PIN)) : (GPIO_WriteLow(LED1_PORT, LED1_PIN)))
#define LED2_PORT	GPIOC
#define LED2_PIN		GPIO_PIN_5
#define Led2_Set(x)	((x) ? (GPIO_WriteHigh(LED2_PORT, LED2_PIN)) : (GPIO_WriteLow(LED2_PORT, LED2_PIN)))


#define INT1_PORT	GPIOD
#define INT1_PIN		GPIO_PIN_4
#define INT1_Read()	GPIO_ReadInputPin(INT1_PORT, INT1_PIN)

#define INT_PORT		GPIOD
#define INT_PIN		GPIO_PIN_6
#define INT_Read()	GPIO_ReadInputPin(INT_PORT, INT_PIN)

/*PWM switch*/
#define PWM_Set(x)	((x) ? (TIM1_Cmd(ENABLE),TIM1_CtrlPWMOutputs(ENABLE)) : (TIM1_Cmd(DISABLE),TIM1_CtrlPWMOutputs(DISABLE)))

typedef enum{
	CHG_NONE_KEY = 0,
	CHG_KEY1 = 0X02,
	CHG_KEY2 = 0X01,
	CHG_KEY3 = 0X10,
	CHG_KEY4 = 0X08,
	CHG_KEY5 = 0X04,
	CHG_KEY6 = 0X20
};

typedef enum{
	TP_NONE_KEY = 0,
	TP_KEY1 = 0X02,
	TP_KEY2 = 0X01,
	TP_KEY3 = 0X10,
	TP_KEY4 = 0X08,
	TP_KEY5 = 0X04,
	TP_KEY6 = 0X20
};


/*
	key indicator
*/
typedef enum{
	KEY1_LED = 0XFE,
	KEY2_LED = 0XFD,
	KEY3_LED = 0XFB,
	KEY4_LED = 0XF7,
	KEY5_LED = 0XEF,
	KEY6_LED = 0XDF,
	BACKLIGHT_LED = 0XBF		// backlight
}KEY_LED_STA_t;

typedef enum{
	WORK_MODE = 0,
	LOCK_MODE
}SYSTEM_MODE_t;

typedef struct{
	FOOT_LED_STA_t Foot_Led_Status;
	CH_STA_t CH_Status;
	PUSHROD_STA_t Pushrod_Status;
	SYSTEM_MODE_t Mode;
	char LockFlag;
	char Updata_Flag;	
	char Heat_CloseFlag,		/*auto close start cnt flag*/
		 Cool_CloseFlag,
		 ShutDown_Flag;
	unsigned int Heat_CloseCnt,
				 Cool_CloseCnt,
				 ShutDown_Cnt;
	int SentCnt;
}SYSTEM_PARA_t;







void System_Init(void);
void System_Handle(void);
void System_TimeHandle(void);




#endif
