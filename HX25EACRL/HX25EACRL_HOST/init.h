#ifndef __INIT_H__
#define __INIT_H__


//子程序定义
#define   PROGRAM_A_HX25_WITH_A_PUSHROD      (INT8U)0x1     //HX25单推程序（触摸按键顺序：Light>Open>Close>Massage>Cool）
#define   PROGRAM_B_HX25_WITH_TOW_PUSHROD    (INT8U)0x2     //HX25双推程序（触摸按键顺序：Light/Cool>Open>Close>Up>Down）
#define   PROGRAM_C_HX36_WITH_A_PUSHROD      (INT8U)0x3     //HX36单推程序（触摸按键顺序：Light>Open>Close>Massage>Cool）带Light触摸按键，Cool指示灯在最右边（Cool的指示灯）
#define   PROGRAM_D_HX36_WITH_A_PUSHROD      (INT8U)0x4     //HX36单推程序（触摸按键顺序：无>Open>Close>Massage>Cool）        不带Light触摸按键，Cool指示灯在最左边（Light的指示灯）
#define   PROGRAM_E_HX36_WITH_TOW_PUSHROD    (INT8U)0x5     //HX36双推程序（触摸按键顺序：Cool>Open>Close>Up>Down）


#define     IO_SENDER_PIN  	          P20	  //P2.0数据口
#define     IO_SWITCH_PIN  	          P40	  //P4.0总开关
#define     IO_SWITCH_LIGHT_PIN  	  P12	  //P1.2总开关的灯	  L1
#define     IO_LED_LIGHT_PIN  	      P41	  //P4.1  Light		  L2
#define     IO_LED_PUSHRODA_H_PIN  	  P30	  //P3.0  推杆A升高开关的LED	  L3
#define     IO_LED_PUSHRODA_L_PIN  	  P31	  //P3.1  推杆A降低开关的LED	  L4
#define     IO_LED_MASSAGE_PIN  	  P32	  //P3.2  马达(推杆B升高)开关的LED	   L5
#define     IO_LED_COLD_PIN  	      P34	  //P3.4  制冷(推杆B降低)开关的LED	   L6


#define     IO_SENDER_MODE            P20PM	  //设置P20为强推挽IO
#define     IO_SWITCH_MODE            P40IM	  //设置P40为高阻态IO
#define     IO_SWITCH_LIGHT_MODE      P12PM	  //设置P12为强推挽IO
#define	    IO_LED_LIGHT_MODE		  P41PM	  //设置P41为强推挽IO
#define	    IO_LED_PUSHRODA_H_MODE	  P30PM	  //设置P30为强推挽IO
#define	    IO_LED_PUSHRODA_L_MODE	  P31PM	  //设置P31为强推挽IO
#define	    IO_LED_MASSAGE_MODE		  P32PM	  //设置P32为强推挽IO
#define	    IO_LED_COLD_MODE		  P34PM	  //设置P34为强推挽IO


#define     SENDER_WRITE_1           IO_SENDER_PIN=1;    //数据输出口P2.0输出高电平
#define     SENDER_WRITE_0           IO_SENDER_PIN=0;    //数据输出口P2.0输出低电平

#define     LED_SWITCH_ON            IO_SWITCH_LIGHT_PIN=1;       //总开关的LED打开
#define     LED_SWITCH_OFF           IO_SWITCH_LIGHT_PIN=0;       //总开关的LED关闭
#define     LED_LIGHT_ON             IO_LED_LIGHT_PIN=1;          //灯控制开关的LED打开
#define     LED_LIGHT_OFF            IO_LED_LIGHT_PIN=0;          //灯控制开关的LED关闭
#define     LED_PUSHRODA_H_ON        IO_LED_PUSHRODA_H_PIN=1;     //推杆A升高开关的LED打开
#define     LED_PUSHRODA_H_OFF       IO_LED_PUSHRODA_H_PIN=0;     //推杆A升高开关的LED关闭
#define     LED_PUSHRODA_L_ON        IO_LED_PUSHRODA_L_PIN=1;     //推杆A降低开关的LED打开
#define     LED_PUSHRODA_L_OFF       IO_LED_PUSHRODA_L_PIN=0;     //推杆A降低开关的LED关闭
#define     LED_MASSAGE_ON           IO_LED_MASSAGE_PIN=1;        //马达(推杆B升高)开关的LED打开
#define     LED_MASSAGE_OFF          IO_LED_MASSAGE_PIN=0;        //马达(推杆B升高)开关的LED关闭
#define     LED_COLD_ON              IO_LED_COLD_PIN=1;           //制冷(推杆B降低)开关的LED打开
#define     LED_COLD_OFF             IO_LED_COLD_PIN=0;           //制冷(推杆B降低)开关的LED关闭


extern   void  GPIO_init();
extern   void  Time1_init();

#endif