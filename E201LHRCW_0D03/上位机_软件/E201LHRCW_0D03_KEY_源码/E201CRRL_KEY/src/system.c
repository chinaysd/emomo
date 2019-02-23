#include "system.h"
#include "key.h"
#include "commu.h"
#include "timeout.h"
#include "iic.h"
#include <string.h>

// private variable
static IIC_PARA_t IIC_Para[IIC_NUM];
static SYSTEM_PARA_t System_Para;
static TIMEOUT_PARA ONLine_Time,Shutdown_Time,Heat_Close_Time,Cool_Close_Time,Pwm_Time;
static TIMEOUT_PARA LedRefresh_Time,Scan_Time[IIC_NUM];
static unsigned char ReadBuf[IIC_NUM];

//global variable
extern u8 Serial_SentByte(u8 data);
// function declare
static void Led_Pwm_Init(void);

static t_KEY_MSG key_msg = MSG_KEY_NONE;


/*
	TIM4 
	1MS
*/
#define Delay 		125//	319
static void Tim4_Init(void)
{
	TIM4_DeInit();
	TIM4_TimeBaseInit( TIM4_PRESCALER_128,Delay-1);
	TIM4_PrescalerConfig(TIM4_PRESCALER_128,TIM4_PSCRELOADMODE_IMMEDIATE);
	TIM4_ARRPreloadConfig(ENABLE);
	TIM4_ITConfig( TIM4_IT_UPDATE , ENABLE);
	TIM4_UpdateDisableConfig(DISABLE);
	TIM4_UpdateRequestConfig( TIM4_UPDATESOURCE_GLOBAL);
	TIM4_Cmd(ENABLE );
}


/*
	ø¥√≈π∑
*/
static void Iwdg_Init(void)
{	
	IWDG_Enable();
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(IWDG_Prescaler_256);
	IWDG_SetReload(0XFF);
	IWDG_ReloadCounter();
}

static System_Sundry_Init(void){
	GPIO_Init(LED1_PORT, LED1_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);		//pwm
	GPIO_Init(LED2_PORT, LED2_PIN, GPIO_MODE_OUT_PP_HIGH_FAST);
	Led1_Set(0);
	Led2_Set(0);
	GPIO_Init(INT_PORT, INT_PIN, GPIO_MODE_IN_PU_NO_IT);
	GPIO_Init(INT1_PORT, INT1_PIN, GPIO_MODE_IN_PU_NO_IT);
}
void delay(u16 delay){
	int i,j,l;
	for(i = 0; i < 20;i ++){
		for(j = 0;j < 50 ;j ++){
			for(l = 0; l< delay;l ++);
		}
	}
}
void System_Init(void){
	int i = 0;
	CLK_DeInit();
 	 /* Clock divider to HSI/1 */
  	CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
	System_Sundry_Init();
	Tim4_Init();
	Commu_Init();
	Led_Pwm_Init();	
	delay(500);
	for(i = 0;i < IIC_NUM;i ++){
		IIC_Para[i].ID = i;
		IIC_Init(&IIC_Para[i]);
	}
	TimeOutDet_Init();
	TimeOut_Record(&ONLine_Time, ON_LINE_TIME);
//	TimeOut_Record(&Shutdown_Time,SHUTDOWN_TIME);
	System_Para.ShutDown_Flag = TRUE;
	System_Para.ShutDown_Cnt = 0;
	//TimeOut_Record(&LedRefresh_Time, 0);
	Iwdg_Init();
	enableInterrupts();
}

/*
	PWM  ‰≥ˆ
*/
static void Led_Pwm_Init(void) {
	TIM1_DeInit(); 
  	TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, 600, 0);
	/*TIM1_Pulse = CCR4_Val*/
	TIM1_OC4Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, 1000, TIM1_OCPOLARITY_LOW,
		TIM1_OCIDLESTATE_SET);
	/* TIM1 counter enable */
	TIM1_Cmd(DISABLE);
	/* TIM1 Main Output Enable */
	TIM1_CtrlPWMOutputs(DISABLE);
}

static void Led_Pwm_Handle(void){
	static unsigned int value = 0,num = 0;
	#define MAX_VALUE	600
	#define MIN_VALUE	0
	switch(num){
		case 0:{
			TimeOut_Record(&Pwm_Time, 3);
			if(value ++ > MAX_VALUE){
				value = MAX_VALUE;
				num = 1;
			}
			break;
		}
		case 1:{
			TimeOut_Record(&Pwm_Time, 2);
			if(value -- == MIN_VALUE){
				value = MIN_VALUE;
				num = 0;
			}
			break;
		}
		default:{
			num = 0;
			break;
		}
	}
	TIM1_SetCompare4(value);
}

static unsigned int System_Get_LedStatus(void){
	unsigned char LedStatus = 0XFF;
	if(System_Para.Foot_Led_Status == FOOT_LED_OFF){
		LedStatus |= ~KEY1_LED;		// open key1 led
	}else if(System_Para.Foot_Led_Status == FOOT_LED_ON){
		LedStatus &= KEY1_LED;
	}
	if(System_Para.CH_Status == CH_A_OFF){
		LedStatus |= ~KEY2_LED;
		LedStatus |= ~KEY5_LED;
	}else if(System_Para.CH_Status == CH_A_COOL){
		LedStatus &= KEY5_LED;
		LedStatus |= ~KEY2_LED;
	}else if(System_Para.CH_Status == CH_A_HEAT){
		LedStatus &= KEY2_LED;
		LedStatus |= ~KEY5_LED;
	}
	if(System_Para.LockFlag){
		LedStatus |= ~BACKLIGHT_LED;
		LedStatus &= KEY6_LED;
	}else{
		LedStatus &= BACKLIGHT_LED;
		LedStatus |= ~KEY6_LED;
	}
	return LedStatus;
}

static void Led_Display(void){
	unsigned char LedSta = 0,i = 0;
	/*send led state to touch IC*/
	LedSta = System_Get_LedStatus();
	for(i = 0; i < IIC_NUM;i++){
		IWDG_ReloadCounter();		
		disableInterrupts();
		IIC_Write_Data(&IIC_Para[i], WRITE_DATA_ADD, LedSta);
		enableInterrupts();
	}
}

static int System_Send_Message(unsigned int cont){
	COMMU_BUF_t TX_Buf;
	TX_Buf.Data_Format.Start = START_FIELD;
	TX_Buf.Data_Format.MessageID = NUM1;
	TX_Buf.Data_Format.Cont1 = Get_High(cont);
	TX_Buf.Data_Format.Cont2 = Get_Low(cont);
	TX_Buf.Data_Format.Checksum = (unsigned char)(TX_Buf.Data_Format.Start + TX_Buf.Data_Format.MessageID+
		  TX_Buf.Data_Format.Cont1 +  TX_Buf.Data_Format.Cont2);
	TX_Buf.Data_Format.Stop1 = Get_High(STOP_MESSAGE);
	TX_Buf.Data_Format.Stop2 = Get_Low(STOP_MESSAGE);
	disableInterrupts();
	Commu_Sent(&TX_Buf);
	enableInterrupts();
}

static int System_Backlight_Handle(void){
	static char Flag = 0;
	if(System_Para.CH_Status == CH_A_COOL){
		PWM_Set(0);
		TIM1_SetCompare4(1000);
		Led1_Set(1);
		Led2_Set(0);
		Flag = 0;
	}
	if(System_Para.CH_Status == CH_A_HEAT){
		PWM_Set(0);
		TIM1_SetCompare4(1000);
		Led1_Set(0);
		Led2_Set(1);
		Flag = 0;
	}
	if(System_Para.CH_Status == CH_A_OFF && System_Para.Foot_Led_Status == FOOT_LED_ON){
		Led2_Set(0);
		PWM_Set(1);
		if(!Flag){
			Flag = 1;
			TimeOut_Record(&Pwm_Time, 0);
		}
	}
	if(System_Para.CH_Status == CH_A_OFF && System_Para.Foot_Led_Status == FOOT_LED_OFF){
		Led1_Set(0);
		Led2_Set(0);
		PWM_Set(0);
		TIM1_SetCompare4(0);
		Flag = 0;
	}
	return 1;
}

static void System_Touch_DataHandle(void){
	static char RelaseFlag[IIC_NUM]  ,RunFlag[IIC_NUM] ,ReadFlag[IIC_NUM];
	/*read touch data*/
//	if(key_msg == MSG_KEY1_PRESS){
	if(!INT1_Read()){
		disableInterrupts();
//		key_msg == MSG_KEY_NONE;		
		memset(ReadBuf,0,sizeof(ReadBuf));
		IIC_Read_Data(&IIC_Para[TP_ID], READ_DATA_ADD, &ReadBuf[TP_ID]);
		enableInterrupts();
		if(System_Para.Pushrod_Status != PUSHROD_STOP){
			System_Para.Pushrod_Status = PUSHROD_STOP;
			System_Para.Updata_Flag = TRUE;
		}
	}
//	if(key_msg == MSG_KEY2_PRESS){
	if(!INT_Read()){
		disableInterrupts();
//		key_msg == MSG_KEY_NONE;
		memset(ReadBuf,0,sizeof(ReadBuf));
		IIC_Read_Data(&IIC_Para[CHG_ID], READ_DATA_ADD, &ReadBuf[CHG_ID]);
		enableInterrupts();
		if(System_Para.Pushrod_Status != PUSHROD_STOP){
			System_Para.Pushrod_Status = PUSHROD_STOP;
			System_Para.Updata_Flag = TRUE;
		}
	}
	
	/*tp handle data*/
	#if 1
	switch(ReadBuf[TP_ID]){
		case 0x00:{
			if(ReadBuf[TP_ID] == 0x00){	
				RelaseFlag[TP_ID] = 0;
				RunFlag[TP_ID] = 0;
			}
			break;
		}
		case 0x02:{	// heat
			if(!System_Para.LockFlag){
				if(!RelaseFlag[TP_ID]){
					RelaseFlag[TP_ID] = 1;
					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
					if(!RunFlag[TP_ID]){
						System_Para.Updata_Flag = TRUE;
						RunFlag[TP_ID] = TRUE;
						if(System_Para.CH_Status != CH_A_HEAT){
							System_Para.CH_Status = CH_A_HEAT;
						}else{
							System_Para.CH_Status = CH_A_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x04:{	// light
			if(!System_Para.LockFlag){
				if(!RelaseFlag[TP_ID]){
					RelaseFlag[TP_ID] = TRUE;
					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
					if(!RunFlag[TP_ID]){
						RunFlag[TP_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						if(System_Para.Foot_Led_Status != FOOT_LED_ON){
							System_Para.Foot_Led_Status = FOOT_LED_ON;
						}else{
							System_Para.Foot_Led_Status = FOOT_LED_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x10:{	// cool
			if(!System_Para.LockFlag){
				if(!RelaseFlag[TP_ID]){
					RelaseFlag[TP_ID] = TRUE;
					TimeOut_Record(&Scan_Time[TP_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
					if(!RunFlag[TP_ID]){
						System_Para.Updata_Flag = TRUE;
						RunFlag[TP_ID] = TRUE;
						if(System_Para.CH_Status != CH_A_COOL){
							System_Para.CH_Status = CH_A_COOL;
						}else{
							System_Para.CH_Status = CH_A_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x20:{	// close
		#if 1
			if(!System_Para.LockFlag){
				if(!RelaseFlag[TP_ID]){
					RelaseFlag[TP_ID] = 1;
					TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME);
					if(System_Para.Pushrod_Status != PUSHROD_STOP){
						System_Para.Updata_Flag = TRUE;
						System_Para.Pushrod_Status = PUSHROD_STOP;
					}
				}
				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
					if(!RunFlag[TP_ID]){
						RunFlag[TP_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						System_Para.Pushrod_Status = PUSHROD_A_CLOSE;
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			#endif
			break;
		}
		case 0x01:{	// open
		#if 1
			if(!System_Para.LockFlag){
				if(!RelaseFlag[TP_ID]){
					RelaseFlag[TP_ID] = 1;
					TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME);
					if(System_Para.Pushrod_Status != PUSHROD_STOP){
						System_Para.Updata_Flag = TRUE;
						System_Para.Pushrod_Status = PUSHROD_STOP;
					}
				}
				if(TimeOutDet_Check(&Scan_Time[TP_ID])){
					if(!RunFlag[TP_ID]){
						RunFlag[TP_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						System_Para.Pushrod_Status = PUSHROD_A_OPEN;
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			#endif
			break;
		}
		case 0x08:{	// lock
			if(!RelaseFlag[TP_ID]){
				RelaseFlag[TP_ID] = 1;
				TimeOut_Record(&Scan_Time[TP_ID], LONG_DELAY_TIME + 200);
			}
			if(TimeOutDet_Check(&Scan_Time[TP_ID])){
				static char SentFlag = 0;
				if(!RunFlag[TP_ID]){
					RunFlag[TP_ID] = 1;
					System_Para.Updata_Flag = TRUE;
					if(!System_Para.LockFlag){
						System_Para.LockFlag = TRUE;
						System_Para.SentCnt = 0;
					}else{
						System_Para.LockFlag = FALSE;
						System_Para.ShutDown_Flag = TRUE;
						System_Para.ShutDown_Cnt = 0;
					}
				}
			}
			break;
		}
		default:{
			RelaseFlag[TP_ID] = 0;
			RunFlag[TP_ID] = 0;			
			memset(ReadBuf,0,sizeof(ReadBuf));
			break;
		}
	}
	#endif
	/*CHG handle data*/
	#if 1
	switch(ReadBuf[CHG_ID]){
		case 0x00:{
			if(ReadBuf[CHG_ID] == 0x00){	// need to close pushrod
				RelaseFlag[CHG_ID] = 0;
				RunFlag[CHG_ID] = 0;
			}
			break;
		}
		case 0x02:{	// heat
			if(!System_Para.LockFlag){
				if(!RelaseFlag[CHG_ID]){
					RelaseFlag[CHG_ID] = 1;
					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
					if(!RunFlag[CHG_ID]){
						System_Para.Updata_Flag = TRUE;
						RunFlag[CHG_ID] = TRUE;
						if(System_Para.CH_Status != CH_A_HEAT){
							System_Para.CH_Status = CH_A_HEAT;
						}else{
							System_Para.CH_Status = CH_A_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x04:{	// light
			if(!System_Para.LockFlag){
				if(!RelaseFlag[CHG_ID]){
					RelaseFlag[CHG_ID] = TRUE;
					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
					static char SentFlag = 0;
					if(!RunFlag[CHG_ID]){
						RunFlag[CHG_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						if(!SentFlag){
							SentFlag = 1;
							System_Para.Foot_Led_Status= FOOT_LED_ON;
						}else{
							SentFlag = 0;
							System_Para.Foot_Led_Status= FOOT_LED_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x10:{	// cool
			if(!System_Para.LockFlag){
				if(!RelaseFlag[CHG_ID]){
					RelaseFlag[CHG_ID] = TRUE;
					TimeOut_Record(&Scan_Time[CHG_ID], PRESS_DELAY_TIME);
				}
				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
					if(!RunFlag[CHG_ID]){
						System_Para.Updata_Flag = TRUE;
						RunFlag[CHG_ID] = TRUE;
						if(System_Para.CH_Status != CH_A_COOL){
							System_Para.CH_Status = CH_A_COOL;
						}else{
							System_Para.CH_Status = CH_A_OFF;
						}
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			break;
		}case 0x20:{	// close
		#if 1
			if(!System_Para.LockFlag){
				if(!RelaseFlag[CHG_ID]){
					RelaseFlag[CHG_ID] = 1;
					TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME);
					if(System_Para.Pushrod_Status != PUSHROD_STOP){
						System_Para.Updata_Flag = TRUE;
						System_Para.Pushrod_Status = PUSHROD_STOP;
					}
				}
				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
					if(!RunFlag[CHG_ID]){
						RunFlag[CHG_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						System_Para.Pushrod_Status = PUSHROD_A_CLOSE;
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			#endif
			break;
		}
		case 0x01:{	// open
		#if 1
			if(!System_Para.LockFlag){
				if(!RelaseFlag[CHG_ID]){
					RelaseFlag[CHG_ID] = 1;
					TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME);
					if(System_Para.Pushrod_Status != PUSHROD_STOP){
						System_Para.Updata_Flag = TRUE;
						System_Para.Pushrod_Status = PUSHROD_STOP;
					}
				}
				if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
					if(!RunFlag[CHG_ID]){
						RunFlag[CHG_ID] = 1;
						System_Para.Updata_Flag = TRUE;	
						System_Para.Pushrod_Status = PUSHROD_A_OPEN;
					}
				}
			}else{
				memset(ReadBuf,0,sizeof(ReadBuf));
			}
			#endif
			
			break;
		}
		case 0x08:{	// lock
			if(!RelaseFlag[CHG_ID]){
				RelaseFlag[CHG_ID] = 1;
				TimeOut_Record(&Scan_Time[CHG_ID], LONG_DELAY_TIME + 200);
			}
			if(TimeOutDet_Check(&Scan_Time[CHG_ID])){
				static char SentFlag = 0;
				if(!RunFlag[CHG_ID]){
					RunFlag[CHG_ID] = 1;
					System_Para.Updata_Flag = TRUE;
					if(!System_Para.LockFlag){
						System_Para.LockFlag = TRUE;
						System_Para.SentCnt = 0;
					}else{
						System_Para.LockFlag = FALSE;
						System_Para.ShutDown_Flag = TRUE;
						System_Para.ShutDown_Cnt = 0;
					}
				}
			}
			break;
		}
		default:{
			RelaseFlag[CHG_ID] = 0;
			RunFlag[CHG_ID] = 0;
			memset(ReadBuf,0,sizeof(ReadBuf));
			break;
		}
	}
	#endif
}


void System_Handle(void){	
	static unsigned int OnLine_Data;
	/*refresh IWDG*/
	IWDG_ReloadCounter();
	/*led refresh handle
		there may be exceptions to the closing of the leds
		so ,refresh the leds on a regular basis
	*/
	if(TimeOutDet_Check(&LedRefresh_Time)){
		TimeOut_Record(&LedRefresh_Time, LED_REFRESH_TIME);
		Led_Display();
	}
	/*********************************************************************
	read touch 
	*********************************************************************/
	System_Touch_DataHandle();
	
	/*********************************************************************
	1.send constrol message to down machine
	2.send led state to touch IC
	*********************************************************/
	if(System_Para.Updata_Flag){		/*if the key is updata,send new data*/
		unsigned int SentData = 0;
		System_Para.Updata_Flag = FALSE;
	//	TimeOut_Record(&ONLine_Time, ON_LINE_TIME);		/*flush on_line timer*/
		//TimeOut_Record(&Shutdown_Time, SHUTDOWN_TIME);	/*flush shutdown timer*/
		TimeOut_Record(&LedRefresh_Time, LED_REFRESH_TIME);
		System_Para.ShutDown_Cnt = 0;
		/*cool_heat moudle*/
		if(System_Para.CH_Status == CH_A_OFF){
			System_Para.Cool_CloseFlag = FALSE;
			System_Para.Heat_CloseFlag = FALSE;
			System_Para.Cool_CloseCnt = 0;
			System_Para.Heat_CloseCnt = 0;
			SentData &= ~CONT_CH_A_COOL;
			SentData &= ~CONT_CH_A_HEAT;
			SentData |= CONT_CH_A_OFF;
		}else if(System_Para.CH_Status == CH_A_COOL){		
			System_Para.Cool_CloseFlag = TRUE;// start the auto close function
			System_Para.Heat_CloseFlag = FALSE;
			System_Para.Heat_CloseCnt = 0;
			SentData &= ~CONT_CH_A_HEAT;
			SentData &= ~CONT_CH_A_OFF;
			SentData  |= CONT_CH_A_COOL;
		}else if(System_Para.CH_Status == CH_A_HEAT){
			System_Para.Heat_CloseFlag = TRUE;		// start the auto close function
			System_Para.Cool_CloseFlag = FALSE;
			System_Para.Cool_CloseCnt = 0;
			SentData &= ~CONT_CH_A_OFF;
			SentData  &= ~ CONT_CH_A_COOL;
			SentData |= CONT_CH_A_HEAT;
		}else{
			/*add abnormal handle*/
		}
		
		/*led moudle*/
		if(System_Para.Foot_Led_Status == FOOT_LED_ON){
			SentData &= ~CONT_LED_OFF;
			SentData |= CONT_LED_ON;
		}else if(System_Para.Foot_Led_Status == FOOT_LED_OFF){
			SentData &= ~CONT_LED_ON;
			SentData |= CONT_LED_OFF;
		}
		
		/*pushrod moudle*/
		if(System_Para.Pushrod_Status == PUSHROD_STOP ||System_Para.Pushrod_Status == PUSHROD_A_STOP){
			SentData &= ~ CONT_PUSHROD_A_OPEN;
			SentData &= ~ CONT_PUSHROD_A_CLOSE;
			SentData |= CONT_PUSHROD_STOP;
		}else if(System_Para.Pushrod_Status == PUSHROD_A_OPEN){
			SentData &= ~ CONT_PUSHROD_A_STOP;
			SentData &= ~ CONT_PUSHROD_A_CLOSE;
			SentData |= CONT_PUSHROD_A_OPEN;
		}else if(System_Para.Pushrod_Status == PUSHROD_A_CLOSE){
			SentData &= ~ CONT_PUSHROD_A_OPEN;
			SentData &= ~ CONT_PUSHROD_A_STOP;
			SentData |= CONT_PUSHROD_A_CLOSE;
		}
		/*refresh led*/
		Led_Display();
		
		/*backlight moudle*/
		System_Backlight_Handle();
		
		/*send control message to MCU*/
		System_Send_Message(SentData);
		OnLine_Data = SentData;
	}

	/*100ms send a contact package*/
	if(TimeOutDet_Check(&ONLine_Time)){
		TimeOut_Record(&ONLine_Time, ON_LINE_TIME);
		System_Send_Message(OnLine_Data);
	}	

	/*heat 1 hours close*/
	if((System_Para.Heat_CloseCnt > HEAT_AUTO_CLOSE_TIME) && System_Para.CH_Status == CH_A_HEAT){
		System_Para.CH_Status = CH_A_OFF;
		System_Para.Updata_Flag = TRUE;
	}

	/*cool 2 hours close*/
	if((System_Para.Cool_CloseCnt > COOL_AUTO_CLOSE_TIME) && System_Para.CH_Status == CH_A_COOL){
		System_Para.CH_Status = CH_A_OFF;
		System_Para.Updata_Flag = TRUE;
	}

	/*4 hours to close all functions*/
	if(System_Para.ShutDown_Cnt > SHUTDOWN_TIME && System_Para.ShutDown_Flag){
		/*the state of the lock key*/
		System_Para.Updata_Flag = TRUE;
		System_Para.Foot_Led_Status = FOOT_LED_OFF;
		System_Para.CH_Status = CH_A_OFF;
		System_Para.Pushrod_Status = PUSHROD_STOP;
	//	IIC_Write_Data(&IIC_Para[0], WRITE_DATA_ADD, 0x00);
	//	IIC_Write_Data(&IIC_Para[1], WRITE_DATA_ADD, 0x00);
	//	System_Para.ShutDown_Flag = FALSE;
	//	while(1){
	//		IWDG_ReloadCounter();
	//	}
		System_Para.LockFlag = TRUE;
		System_Send_Message(CONT_LED_OFF|CONT_CH_A_OFF|CONT_PUSHROD_STOP);
		if(System_Para.SentCnt ++ > 10){
			System_Para.SentCnt = 0;
			System_Para.ShutDown_Flag = FALSE;
			System_Para.ShutDown_Cnt = 0;
		}
	}

	/* led pwm handle*/
	if(TimeOutDet_Check(&Pwm_Time)){
		Led_Pwm_Handle();
	}
}

void System_TimeHandle(void){
	static unsigned int CoolCntBase,HeatCntBase,ShutDownBase;
	if(System_Para.Cool_CloseFlag){
		if(CoolCntBase ++ > 999){
			CoolCntBase = 0;
			if(System_Para.Cool_CloseCnt ++ > COOL_AUTO_CLOSE_TIME){
				System_Para.Cool_CloseCnt = COOL_AUTO_CLOSE_TIME + 10;
			}
		}
	}
	if(System_Para.Heat_CloseFlag){
		if(HeatCntBase ++ > 999){
			HeatCntBase = 0;
			if(System_Para.Heat_CloseCnt ++ > HEAT_AUTO_CLOSE_TIME){
				System_Para.Heat_CloseCnt = HEAT_AUTO_CLOSE_TIME + 10;
			}
		}
	}
	if(System_Para.ShutDown_Flag){
		if(ShutDownBase ++ > 999){
			ShutDownBase = 0;
			if(System_Para.ShutDown_Cnt++ > SHUTDOWN_TIME){
				System_Para.ShutDown_Cnt = SHUTDOWN_TIME + 10;
			}
		}
	}

}



