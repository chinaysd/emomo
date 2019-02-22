#include "adc.h"


unsigned int AdcValue;

void ADCwork(edAdcChannel Channel,unsigned char Clk)
{
    unsigned int SetAdcIo; 
	ADCCON   = ADCCON & (~0X1F) | Channel | (Clk<<5) ;	//配置ADC输入通道和采集时钟频率
	ADCCON|=0x80;								   //打开ADC模块电源
	SetAdcIo = (0x0001 << Channel) & (~0Xfe00) ;   
	ADCCFG0  = (unsigned char)SetAdcIo;			   //配置为ADC输入
	ADCCFG1  = (unsigned char)(SetAdcIo >> 8);

	ADCCON|=0x40;							 //启动ADC采集
	while(!(ADCCON&0x10));	         		 //等待 ADC转换完成;
	//AdcValue=(ADCVH<<4)+(ADCVL>>4);
	AdcValue=(unsigned int)ADCVH;		   					 //ADC高8位存入8位寄存器
	AdcValue = (AdcValue<<4)+ADCVL;			     //取得adc的值
	AdcValue =  AdcValue>>4;
}