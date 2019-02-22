//*************************************************************************************************
//  Copyright (c) 	ÉîÛÚÊÐÈüÔªÎ¢µç×ÓÓÐÏÞ¹«Ë¾
//	ÎÄ¼þÃû³Æ	:  S_TouchKeyCFG.c
//	×÷Õß			: 
//	Ä£¿é¹¦ÄÜ	:  ´¥¿Ø¼üÅäÖÃÎÄ¼þ
// 	°æ±¾			:
// 	¸ü¸Ä¼ÇÂ¼	:
//
//	×¢ÒâÊÂÏî	:  ÓÃ»§ÐèÒªÅäÖÃµÄÎÄ¼þÔÚS_TouchKeyCFG.hÖÐ
//    ¿â°æ±¾±ê¼Ç: 
//
//************************************************************************************************

#include "lib/S_TouchKeyCFG.h"

//===========================================================================
//¼Ä´æÆ÷¶¨Òå
/*TouchKey*/
sfr	TKCR			=	0xE8;	//TouchKey¿ØÖÆ¼Ä´æÆ÷		
sfr	TKPVALL			=	0x9F;	//Êý×Ö¼ÆÊýÆ÷Ô¤ÉèÖµ¼Ä´æÆ÷µÍ8Î»
sfr	TKPVALH			=	0x9E;	//Êý×Ö¼ÆÊýÆ÷Ô¤ÉèÖµ¼Ä´æÆ÷¸ß7Î»
sfr	TKSTA			=	0x9D;	//TouchKey×´Ì¬¼Ä´æÆ÷
sfr	TKCFG3			=	0x9C;	//TouchKeyÅäÖÃ¼Ä´æÆ÷3
sfr	TKCFG2			=	0x9B;	//TouchKeyÅäÖÃ¼Ä´æÆ÷2
sfr	TKCFG1			=	0x9A;	//TouchKeyÅäÖÃ¼Ä´æÆ÷1
sfr	TKCNTL			=	0x97;	//TouchKey¼ÆÊýÆ÷ÖµµÍ8Î»
sfr	TKCNTH			=	0x96;	//TouchKey¼ÆÊýÆ÷Öµ¸ß7Î»

/*TKCR*/
sbit	ENTKS	=	TKCR^7;	//TouchKey¿ª¹ØµçÔ´
sbit	TRIG	=	TKCR^6;	//TouchKey´¥·¢¿ª¹Ø£ºÐ´1ÓÐÐ§£¬´¥·¢Ò»´ÎkeyÉ¨ÃèÖÜÆÚ
sbit	CHRVS	=	TKCR^4;//³äµçµçÔ´Ñ¡Ôñ£º1:VDD	0:ÄÚ½¨ÎÈÑ¹Ô´


/*PSW*/
sfr 	PSW	= 0xD0;		//³ÌÐò×´Ì¬×Ö
sbit 	CY	= PSW^7;


//===========================================================================
//È«¾Ö±äÁ¿¶¨Òå
unsigned	char	xdata	SOCAPI_TouchKeyStatus;					//API½Ó¿Ú×´Ì¬£ºbit7-Ò»ÂÖÉ¨ÃèÍê³É±êÖ¾  1:Íê³É 	0£ºÎ´Íê³É
																	//			   		bit6-Í¨µÀ´¥Ãþ¼ÆÊýÒç³ö±êÖ¾ 1:Òç³ö	 0:Î´Òç³ö
//===============================================================================
//È«¾Ö±äÁ¿ÉùÃ÷£º¸ÃÇøÓò²»¿ÉÐÞ¸Ä
unsigned 	int 	xdata	RawData [SOCAPI_SET_TOUCHKEY_TOTAL];			
unsigned 	int		xdata	BaseLine[SOCAPI_SET_TOUCHKEY_TOTAL];
unsigned  	int	 	xdata	FilterData[SOCAPI_SET_TOUCHKEY_TOTAL];												
unsigned	char  	xdata	RestAreaCnt[SOCAPI_SET_TOUCHKEY_TOTAL]; 			
unsigned	char  	xdata	TouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];				
unsigned	char  	xdata	NoTouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];  			
unsigned	char	xdata	CurrentChannel[SOCAPI_SET_TOUCHKEY_TOTAL];						   
unsigned 	char	xdata	ConfirmTouchCnt=SOCAPI_SET_TOUCHKEY_CONFIRM_CNT;	
unsigned    char    xdata   LowFingerDataCnt[SOCAPI_SET_TOUCHKEY_TOTAL]; 

int   	xdata 	DifferAccum[SOCAPI_SET_TOUCHKEY_TOTAL]; 
char	xdata	SetNoiseThreshold=SOCAPI_SET_NOISE_THRESHOLD;

//×Ô¶¨Òå±äÁ¿
unsigned int xdata  UpdateBaseLNum; 					// µ¥¼ü³¤°´Ê§Ð§Ê±¼ä



//Íâ²¿±äÁ¿½Ó¿Ú
extern 	unsigned	char	data		CurrentChannelMax;		//µ±Ç°Ñ¡ÖÐµÄkeysensorµÄ¸öÊý
extern  bit bMultiple;	//¶à°´¼ü±êÖ¾	
extern 	bit GetIsNeedUpdateBaseline(void);
extern  void SetNeedUpdateBaseline(void);
extern  unsigned  int SensorKeyFlag(void);
extern  void MultipleDeal(unsigned char CycleCnt);



//ºê¶¨Òå½Ó¿Ú




//=================================================================================	
// º¯Êý½Ó¿Úµ÷ÓÃ²¿·Ö

//************************************************************************
// º¯Êý¹¦ÄÜ:  °´¼ü×î³¤µÄÊä³öÊ±¼ä
// ÊäÈë: ÎÞ
// Êä³ö: ¸´Î»Ê±¼ä
//Õâ¸ö·µ»ØÖµµÄÉèÖÃ£¬ ÊÇ¸ù¾ÝÓÐ¶à³¤Ê±¼äÆô¶¯TouchKeyRestart£¨£©Ò»´Î
//ÀýÈç12ms Æô¶¯Ò»´Î£¬ ÄÇ900*12ms = 10800ms, 10.8s ´Ë°´¼üÎÞÐ§¡£
//************************************************************************
unsigned int SetOneKeyPushResetTime(void)   
{
	return SOCAPI_SET_KEY_CONTI_TIME;  
}

//************************************************************************
// º¯Êý¹¦ÄÜ:  ¶¯Ì¬¸üÐÂ»ùÏßµÄÊ±¼ä
// ÊäÈë: ÎÞ
// Êä³ö: 
//£
//************************************************************************

unsigned int SetFlowResetTime(void)   
{
	return SOCAPI_SET_SYNC_UPDATE; 
}



//************************************************************************
// º¯Êý¹¦ÄÜ: ¸üÐÂËÙ¶È 
// ÊäÈë: ÎÞ
// Êä³ö:ãÐÖµ
// ±¸×¢: ¶¨ÒåãÐÖµ´óÐ¡£¬ ¿ÉÑ¡µÄÖµ0~255.Ò»°ãÉèÖÃÎª120£¬½Ï´óµÄ²ÎÊýÊýÖµ
// ÄÜ¹»²úÉú½ÏÂýµÄ»ù±¾Ïß¸üÐÂËÙ¶È¡£
//************************************************************************

int  GetBaselineUpdateThreshold(void)
{
	return SOCAPI_SET_UPDATE_SPEED; 
}



unsigned char GetInitAutoUpdateTime(void)
{
	return SOCAPI_INIT_AUTO_UPDATE_TIME; 
}

//************************************************************************
// º¯Êý¹¦ÄÜ: ½øÐÐCS ²âÊÔ
// ÊäÈë: ÎÞ
// Êä³ö: 
// ±¸×¢: 
//************************************************************************
char GetCsFunction(void)
{
	return SOCAPI_SET_CS_FUNCTION; 
}


//************************************************************************
//º¯Êý¹¦ÄÜ: »ñÈ¡µ±Ç°µÄfinger Öµ
//ÊäÈë: index 
//Êä³ö: Êä³öÊÖÖ¸ãÐÖµ
//
//************************************************************************
int  GetCurrFingerValue(unsigned char i)
{
	char j = 0; 
	int idata FingerThresholdtmp[16]={\
		SOCAPI_KEY0_FINGER_THRESHOLD,\
		SOCAPI_KEY1_FINGER_THRESHOLD,\
		SOCAPI_KEY2_FINGER_THRESHOLD,\
		SOCAPI_KEY3_FINGER_THRESHOLD,\
		SOCAPI_KEY4_FINGER_THRESHOLD,\
		SOCAPI_KEY5_FINGER_THRESHOLD,\
		SOCAPI_KEY6_FINGER_THRESHOLD,\
		SOCAPI_KEY7_FINGER_THRESHOLD,\
		SOCAPI_KEY8_FINGER_THRESHOLD,\
		SOCAPI_KEY9_FINGER_THRESHOLD,\
		SOCAPI_KEY10_FINGER_THRESHOLD,\
		SOCAPI_KEY11_FINGER_THRESHOLD,\
		SOCAPI_KEY12_FINGER_THRESHOLD,\
		SOCAPI_KEY13_FINGER_THRESHOLD,\
		SOCAPI_KEY14_FINGER_THRESHOLD,\
		SOCAPI_KEY15_FINGER_THRESHOLD		
	};

	j = CurrentChannel[i]; 
	return FingerThresholdtmp[j]; 

}


//************************************************************************
//º¯Êý¹¦ÄÜ: »ñÈ¡µ±Ç° ×î´óµÄÓÐÐ§finger Öµ
//ÊäÈë: index 
//Êä³ö: Êä³öÓÐÐ§µÄÖµ
//
//************************************************************************

int GetNosicMinValue(unsigned char i)
{
	int SetFingerThresholdtmp;
	SetFingerThresholdtmp = GetCurrFingerValue(i); 
	SetFingerThresholdtmp *= 10;
	if(SetFingerThresholdtmp >= SOCAPI_FINGER_MAX_VALUE)
		SetFingerThresholdtmp = SOCAPI_FINGER_MAX_VALUE;

	SetFingerThresholdtmp = SOCAPI_FINGER_MAX_VALUE;		// ²âÊÔEFT 
	return SetFingerThresholdtmp; 

}

//************************************************************************
//º¯Êý¹¦ÄÜ:¼ì²âÊÇ·ñÊÇµ¯»É»¬Ìõ»òÕßË«¼ü
//ÊäÈë: ÎÞ 
//Êä³ö: =1 ±íÊ¾ÊÇ»¬Ìõ»òÕßÊÇË«¼ü
//
//************************************************************************
unsigned char IsDoubleKeyOrSlideKey(void)
{
#if (SOCAPI_SET_SLIDE_KEY_FUNCTION)
	return 1;
#else
	return 0; 
#endif

}


//*************************************************************************
//			¼ì²â°´¼üµ¯Æð´ÎÊý
//
//
//
//
//*************************************************************************
unsigned 	char GetUpConfirmCnt(void)
{
	return ConfirmTouchCnt>>1;
}




//*************************************************************
// º¯ÊýÃû	£ºvoid CurrentSensorChoose(void)
// ×÷Õß		£º
// ¹¦ÄÜ		£ºµ±Ç°Í¨µÀÑ¡Ôñ
// ²ÎÊý		£ºÎÞ
// ·µ»ØÖµ	£ºÎÞ
// µ÷ÓÃÈ«¾Ö±äÁ¿£ºÎÞ
// ÐÞ¸ÄÈ«¾Ö±äÁ¿£ºÎÞ
// ±¸×¢		£º
//**************************************************************
void CurrentSensorChoose(void)
{
	unsigned char  	i;
	unsigned char  	Ctk_Channel_mark=0;
	unsigned 	int	CurrentSensorKey; 
	
	CurrentSensorKey = SOCAPI_SET_TOUCHKEY_CHANNEL; 
		
	for(i=0;i<16;i++)
	{
		if(CurrentSensorKey&(0x01<<i))
		{
			CurrentChannel[Ctk_Channel_mark]=i;						//Ñ¡Ôñ´¥Ãþµ±Ç°µÄÍ¨µÀ
			Ctk_Channel_mark++;
		}
		CurrentChannelMax=Ctk_Channel_mark;							//µ±Ç°Ñ¡ÔñµÄ°´¼üÊý 
	}
}


//*************************************************************
// º¯ÊýÃû	£ºvoid TouchKeyCFGInit(void)
// ×÷Õß		£º
// ¹¦ÄÜ		£º³õÊ¼»¯TK ¼Ä´æÆ÷µÈ
// ²ÎÊý		£ºÎÞ
// ·µ»ØÖµ	£ºÎÞ
// µ÷ÓÃÈ«¾Ö±äÁ¿£ºÎÞ
// ÐÞ¸ÄÈ«¾Ö±äÁ¿£ºÎÞ
// ±¸×¢		£º
//**************************************************************

void TouchKeyCFGInit(void)
{
	CurrentSensorChoose(); 
	TKCR=0x80;									//´ò¿ªTouch KeyµçÔ´;Ñ¡ÔñÄÚ½¨ÎÈÑ¹Ô´;
	TKCFG1= SOCAPI_SET_TKCFG1; //GetCFG1();				
	TKCFG2=	SOCAPI_SET_TKCFG2; //GetCFG2();				
	TKCFG3=	SOCAPI_SET_TKCFG3; //GetCFG3();		

	UpdateBaseLNum = 0; 

}


/////////////////////////////////////////////////////////////////////
//			¼ì²â°´¼ü½Ó¿Ú
//ÊäÈë: ÎÞ
//Êä³ö:°´¼üÍ¨µÀ£¬ ·µ»ØµÄÊÇÒ»¸öint , Í¨µÀÊý¡£ 
//±¸×¢: Õâ¸öº¯ÊýÍê³ÉÁË¼¸¸öÄÚÈÝ
//  1, µ÷ÓÃ´¥¿Ø¿â¼ì²âº¯ÊýSensorKeyFlag()
// 2,  ·ÖÎöµÃ³ö16¸öÍ¨µÀ£¬ÄÄ¸öÍ¨µÀÓÐ°´ÏÂ£¬°´ÏÂbit Î»ÉèÖÃÎª1£¬·ñÔòÎª0
// 3,  ¼ì²âÊÇ·ñÐèÒªÁ¢¼´¸üÐÂbaseline:  ´óÓÚMAX_KEY_RESET_BASELINE ¸ö°´¼ü°´ÏÂÊ±Á¢¼´¸üÐÂbaseline
// 4,  Ë«¼ü»òÕßµ¥¼ü°´ÏÂÊ±£¬ Ê±¼ä´óÓÚSetOneKeyPushResetTime()½á¹ûÊ±¸üÐÂbaseline 
/////////////////////////////////////////////////////////////////////
#if 1
unsigned int TouchKeyScan(void)
{
	unsigned char t;
	unsigned char MultipleCnt;
	unsigned int Keyvalue = 0; 
	unsigned int KeyData = 0; 

	MultipleCnt = 0;	

	if(GetIsNeedUpdateBaseline() == 0)				//¼ì²âÊÇ·ñÐèÒª¸üÐÂbaseline 
	{
		Keyvalue = SensorKeyFlag();					//SensorÅÐ¶Ï, ÕâÀïÈç¹ûbMultiple = 1 ±íÊ¾ÖÐ¼äÓÐ¸ÉÈÅ
	  												//·ÖÎö°´¼ü£¬µÃ³ö±ê×¼µÄ16Í¨µÀbit Î»
		for(t=0;t<CurrentChannelMax;t++)
		{
			Keyvalue = Keyvalue>>1;
			if(CY)
			{
				KeyData |= (0x01 << (CurrentChannel[t])); 	
				MultipleCnt++;
			}

		}

		if(MultipleCnt >=2 ) 	 									//½øÈë¶à°´¼ü´¦Àí
		{
			
			bMultiple=1;
			
			if(MultipleCnt >= SOCAPI_MAX_KEY_NUM_INVALID)
			{
				SetNeedUpdateBaseline(); 							// Á¢¼´¸üÐÂbaseline ,ÀýÈçÑÇ¿ËÁ¦°å¸ÇÉÏÈ¥
			}
			else
			{
			
				#if (SOCAPI_SET_SLIDE_KEY_FUNCTION)   //µ¯»É»¬ÌõµÄ»¬Ìõ¼ü°´ÏÂÔò²»ÈÏÎªÊÇ¶à¼ü
					bMultiple=0; 
				#endif 
			}
			
		}			

		if(bMultiple ==0)							//½øÈë°´¼üÅÐ¶Ï
		{		
				if(KeyData !=0x0)					    //µ¥¸ö°´¼ü´ïµ½¶à³¤Ê±¼ä¾Íupdate baseline 
				{
					UpdateBaseLNum++; 
				}
				else	
				{
					UpdateBaseLNum = 0; 	
				}
 
		}	
		else
		{		//¿¼ÂÇ»ùÏß¸üÐÂ
			UpdateBaseLNum ++; 
			KeyData = 0x0;
		}

		if(UpdateBaseLNum > SetOneKeyPushResetTime())	
 			SetNeedUpdateBaseline(); 

	
	}
			
	else
	{
		MultipleDeal(SOCAPI_AUTO_UPDATE_TIME);										//»ùÏß¸´Î»´¦Àí
	}
	
	return KeyData;
}
#endif 

