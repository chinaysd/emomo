#include "stm8s_conf.h"



#define INT1_PORT 			GPIOD
#define INT1_PIN 				GPIO_PIN_4
#define INT2_PORT 			GPIOD
#define INT2_PIN 				GPIO_PIN_6


u8 Key_Port_Read(u8 num){
	if(num == 1){
		return GPIO_ReadInputPin(INT1_PORT, INT1_PIN);
	}else if(num == 2){
		return GPIO_ReadInputPin(INT2_PORT, INT2_PIN);
	}else{
		return 0;
	}
}

u8 Key_Port_Init(void){
	GPIO_Init(INT1_PORT, INT1_PIN, GPIO_MODE_IN_PU_NO_IT);
	GPIO_Init(INT2_PORT, INT2_PIN, GPIO_MODE_IN_PU_NO_IT); 
	return 1;
}
