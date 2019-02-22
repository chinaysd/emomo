#include "adc.h"


unsigned int AdcValue;

void ADCwork(edAdcChannel Channel,unsigned char Clk)
{
    unsigned int SetAdcIo; 
	ADCCON   = ADCCON & (~0X1F) | Channel | (Clk<<5) ;	//����ADC����ͨ���Ͳɼ�ʱ��Ƶ��
	ADCCON|=0x80;								   //��ADCģ���Դ
	SetAdcIo = (0x0001 << Channel) & (~0Xfe00) ;   
	ADCCFG0  = (unsigned char)SetAdcIo;			   //����ΪADC����
	ADCCFG1  = (unsigned char)(SetAdcIo >> 8);

	ADCCON|=0x40;							 //����ADC�ɼ�
	while(!(ADCCON&0x10));	         		 //�ȴ� ADCת�����;
	//AdcValue=(ADCVH<<4)+(ADCVL>>4);
	AdcValue=(unsigned int)ADCVH;		   					 //ADC��8λ����8λ�Ĵ���
	AdcValue = (AdcValue<<4)+ADCVL;			     //ȡ��adc��ֵ
	AdcValue =  AdcValue>>4;
}