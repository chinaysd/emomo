#include "stm8s_conf.h"

// simulate iic  
// tp
#define SDA1_PORT	GPIOD
#define SDA1_PIN		GPIO_PIN_2
#define SDA1_Read()	GPIO_ReadInputPin(SDA1_PORT, SDA1_PIN)
#define SDA1_Set(x)	((x) ? (GPIO_WriteHigh(SDA1_PORT, SDA1_PIN)) : (GPIO_WriteLow(SDA1_PORT, SDA1_PIN)))

#define SCL1_PORT	GPIOD
#define SCL1_PIN		GPIO_PIN_3
#define SCL1_Read()	GPIO_ReadInputPin(SCL1_PORT, SCL1_PIN)
#define SCL1_Set(x)	((x) ? (GPIO_WriteHigh(SCL1_PORT, SCL1_PIN)) : (GPIO_WriteLow(SCL1_PORT, SCL1_PIN)))

// chg
#define SDA0_PORT	GPIOC
#define SDA0_PIN		GPIO_PIN_6
#define SDA0_Read()	GPIO_ReadInputPin(SDA0_PORT, SDA0_PIN)
#define SDA0_Set(x)	((x) ? (GPIO_WriteHigh(SDA0_PORT, SDA0_PIN)) : (GPIO_WriteLow(SDA0_PORT, SDA0_PIN)))

#define SCL0_PORT	GPIOC
#define SCL0_PIN		GPIO_PIN_7
#define SCL0_Read()	GPIO_ReadInputPin(SCL0_PORT, SCL0_PIN)
#define SCL0_Set(x)	((x) ? (GPIO_WriteHigh(SCL0_PORT, SCL0_PIN)) : (GPIO_WriteLow(SCL0_PORT, SCL0_PIN)))

int IIC_Port_Init(int ID){
	if(ID == 0){
		GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		SDA0_Set(1);
		GPIO_Init(SCL0_PORT, SCL0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		SCL0_Set(1);
	}else if(ID == 1){
		GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		SDA1_Set(1);
		GPIO_Init(SCL1_PORT, SCL1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		SCL1_Set(1);
	}else{
		return 0;
	}
	return 1;
}
/*
	Func : 0 ->IN ;1 ->OUT
*/
int IIC_Port_SDA_Set(int ID,int Func){
	if(ID == 0){
		if(Func == 0){
			GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_IN_FL_NO_IT);
		}else if(Func == 1){
			GPIO_Init(SDA0_PORT, SDA0_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_IN_FL_NO_IT);
		}else if(Func == 1){
			GPIO_Init(SDA1_PORT, SDA1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}
/*
	Func : 0->SDA 1->SCL
	Data: 0->out 0;
*/
int IIC_Port_Write(int ID,int Func,int Data){
	if(ID == 0){
		if(Func == 0){
			SDA0_Set(Data);
		}else if(Func == 1){
			SCL0_Set(Data);
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			SDA1_Set(Data);
		}else if(Func == 1){
			SCL1_Set(Data);
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int IIC_Port_Read(int ID ,int Func ){
	if(ID == 0){
		if(Func == 0){
			return SDA0_Read();
		}else if(Func == 1){
			return SCL0_Read();
		}else{
			return 0;
		}
	}else if(ID == 1){
		if(Func == 0){
			return SDA1_Read();
		}else if(Func == 1){
			return SCL1_Read();
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

