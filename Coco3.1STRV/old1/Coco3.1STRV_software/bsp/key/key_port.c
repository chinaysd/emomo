#include "sys_config.h"



#define KEY1_PIN						P14
#define KEY2_PIN						P26
#define KEY3_PIN						P15
#define KEY4_PIN						P20
#define KEY5_PIN						P21
#define KEY6_PIN						P24
#define KEY7_PIN						P25

unsigned char Key_Port_Read(unsigned char num){
	if(num == 1){
		return KEY1_PIN;
	}else if(num == 2){
		return KEY2_PIN;
	}else if(num == 3){
		return KEY3_PIN;
	}else if(num == 4){
		return KEY4_PIN;
	}else if(num == 5){
		return KEY5_PIN;
	}else if(num == 6){
		return KEY6_PIN;
	}else if(num == 7){
		return KEY7_PIN;
	}else{
		return 0XFF;
	}
}

unsigned char Key_Port_Init(void){
	CLR_REG_CON(2, 0);
	SET_IO_PU(2, 0);
	
	CLR_REG_CON(2, 1);
	SET_IO_PU(2, 1);
	
	CLR_REG_CON(2, 4);
	SET_IO_PU(2, 4);
		
	CLR_REG_CON(2, 5);
	SET_IO_PU(2, 5);
	
	CLR_REG_CON(2, 6);
	SET_IO_PU(2, 6);
	
	CLR_REG_CON(1, 4);
	SET_IO_PU(1, 4);
	
	CLR_REG_CON(1, 5);
	SET_IO_PU(1, 5);
	
	return 1;
}
