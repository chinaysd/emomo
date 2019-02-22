
#ifndef S_IIC_BUS_C_HEADER
#define S_IIC_BUS_C_HEADER
#define	Debug				1
//=====================================
//		声明可供外部调用的函数
//=====================================
extern	void	iic_bus_init(void);
extern	void	Debug_TouchKeyIICInit(void);
extern	void	Debug_SenddataRestart(void);
/*=============================================
函数名称:  		iic_bus_init()
函数功能:  		硬件IIC初始化
调用规则:  		系统初始化调用
函数返回类型: 	无
函数返回值定义:	无
================================================*/
#endif
