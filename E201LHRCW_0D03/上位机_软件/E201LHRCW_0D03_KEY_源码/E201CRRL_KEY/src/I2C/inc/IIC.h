#ifndef IIC_H_
#define IIC_H_


#define IIC_DelayBaseValue 	0
#define IIC_DelayTime  		0

#define IIC_SDA  	0
#define IIC_SCL	1

#define IN	0
#define OUT	1

#define IIC_NUM		2
#define CHG_ID		0
#define TP_ID			1
/*
	IIC add 
*/
#define WRITE_DATA_ADD			0X5A
#define READ_DATA_ADD			0X5B


typedef struct{
	int ID;
//	IIC_STATUS_t Status;
}IIC_PARA_t;



int IIC_Init(IIC_PARA_t *p);

int  IIC_Read_Data(IIC_PARA_t *p,unsigned char Add,unsigned char *Read_Data);

int  IIC_Write_Data(IIC_PARA_t *p,unsigned char Add,unsigned char Write_Data);


#endif
