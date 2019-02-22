#ifndef __INIT_H__
#define __INIT_H__


//�ӳ�����
#define   PROGRAM_A_HX25_WITH_A_PUSHROD      (INT8U)0x1     //HX25���Ƴ��򣨴�������˳��Light>Open>Close>Massage>Cool��
#define   PROGRAM_B_HX25_WITH_TOW_PUSHROD    (INT8U)0x2     //HX25˫�Ƴ��򣨴�������˳��Light/Cool>Open>Close>Up>Down��
#define   PROGRAM_C_HX36_WITH_A_PUSHROD      (INT8U)0x3     //HX36���Ƴ��򣨴�������˳��Light>Open>Close>Massage>Cool����Light����������Coolָʾ�������ұߣ�Cool��ָʾ�ƣ�
#define   PROGRAM_D_HX36_WITH_A_PUSHROD      (INT8U)0x4     //HX36���Ƴ��򣨴�������˳����>Open>Close>Massage>Cool��        ����Light����������Coolָʾ��������ߣ�Light��ָʾ�ƣ�
#define   PROGRAM_E_HX36_WITH_TOW_PUSHROD    (INT8U)0x5     //HX36˫�Ƴ��򣨴�������˳��Cool>Open>Close>Up>Down��


#define     IO_SENDER_PIN  	          P20	  //P2.0���ݿ�
#define     IO_SWITCH_PIN  	          P40	  //P4.0�ܿ���
#define     IO_SWITCH_LIGHT_PIN  	  P12	  //P1.2�ܿ��صĵ�	  L1
#define     IO_LED_LIGHT_PIN  	      P41	  //P4.1  Light		  L2
#define     IO_LED_PUSHRODA_H_PIN  	  P30	  //P3.0  �Ƹ�A���߿��ص�LED	  L3
#define     IO_LED_PUSHRODA_L_PIN  	  P31	  //P3.1  �Ƹ�A���Ϳ��ص�LED	  L4
#define     IO_LED_MASSAGE_PIN  	  P32	  //P3.2  ���(�Ƹ�B����)���ص�LED	   L5
#define     IO_LED_COLD_PIN  	      P34	  //P3.4  ����(�Ƹ�B����)���ص�LED	   L6


#define     IO_SENDER_MODE            P20PM	  //����P20Ϊǿ����IO
#define     IO_SWITCH_MODE            P40IM	  //����P40Ϊ����̬IO
#define     IO_SWITCH_LIGHT_MODE      P12PM	  //����P12Ϊǿ����IO
#define	    IO_LED_LIGHT_MODE		  P41PM	  //����P41Ϊǿ����IO
#define	    IO_LED_PUSHRODA_H_MODE	  P30PM	  //����P30Ϊǿ����IO
#define	    IO_LED_PUSHRODA_L_MODE	  P31PM	  //����P31Ϊǿ����IO
#define	    IO_LED_MASSAGE_MODE		  P32PM	  //����P32Ϊǿ����IO
#define	    IO_LED_COLD_MODE		  P34PM	  //����P34Ϊǿ����IO


#define     SENDER_WRITE_1           IO_SENDER_PIN=1;    //���������P2.0����ߵ�ƽ
#define     SENDER_WRITE_0           IO_SENDER_PIN=0;    //���������P2.0����͵�ƽ

#define     LED_SWITCH_ON            IO_SWITCH_LIGHT_PIN=1;       //�ܿ��ص�LED��
#define     LED_SWITCH_OFF           IO_SWITCH_LIGHT_PIN=0;       //�ܿ��ص�LED�ر�
#define     LED_LIGHT_ON             IO_LED_LIGHT_PIN=1;          //�ƿ��ƿ��ص�LED��
#define     LED_LIGHT_OFF            IO_LED_LIGHT_PIN=0;          //�ƿ��ƿ��ص�LED�ر�
#define     LED_PUSHRODA_H_ON        IO_LED_PUSHRODA_H_PIN=1;     //�Ƹ�A���߿��ص�LED��
#define     LED_PUSHRODA_H_OFF       IO_LED_PUSHRODA_H_PIN=0;     //�Ƹ�A���߿��ص�LED�ر�
#define     LED_PUSHRODA_L_ON        IO_LED_PUSHRODA_L_PIN=1;     //�Ƹ�A���Ϳ��ص�LED��
#define     LED_PUSHRODA_L_OFF       IO_LED_PUSHRODA_L_PIN=0;     //�Ƹ�A���Ϳ��ص�LED�ر�
#define     LED_MASSAGE_ON           IO_LED_MASSAGE_PIN=1;        //���(�Ƹ�B����)���ص�LED��
#define     LED_MASSAGE_OFF          IO_LED_MASSAGE_PIN=0;        //���(�Ƹ�B����)���ص�LED�ر�
#define     LED_COLD_ON              IO_LED_COLD_PIN=1;           //����(�Ƹ�B����)���ص�LED��
#define     LED_COLD_OFF             IO_LED_COLD_PIN=0;           //����(�Ƹ�B����)���ص�LED�ر�


extern   void  GPIO_init();
extern   void  Time1_init();

#endif