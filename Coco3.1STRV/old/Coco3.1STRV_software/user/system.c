#include "system.h"
static unsigned char Cnt;
unsigned char Uart1SendFlag,Uart1ReceiveFlag;

TIMEOUT_PARA TimeOut_Para[2],Key_Para[2];
KEY_PARA_TX KEY_Para_tx;
unsigned char flag;
unsigned char Reset_Flag,first_flag,second_flag;

/************************************************* 所有功能标志定义*******************************************************/
 
unsigned char PUSH_RESET_FLAG,PUSH_STOP_FLAG,
	            LUMBER_OPEN_FLAG,LUMBER_CLOSE_FLAG,
              HEAD_OPEN_FLAG,HEAD_CLOSE_FLAG,
              PUSH_OPEN_FLAG,PUSH_CLOSE_FLAG,
 
              FOOT_STATUS_FLAG,Close_Foot_Led_Flag,
              Mass_Open_Flag,Mass_Close_Flag,
              Heat_Open_Flag,Heat_Close_Flag,
              
              Sleep_Position_Flag,Set_Sleep_Position_Flag,
              Watch_TV_Position_Flag,Set_Watch_TV_Position_Flag,
              Reading_Position_Flag,Set_Reading_Position_Flag,
						  COOL_STATUS_FLAG;
/************************************************************************************************************************/


/***************************************************接收数据的定义*******************************************************/

unsigned int i;
unsigned int res;
static unsigned char rev_num;
unsigned int temp;
PROTOCOL_TX rev_para;
unsigned char sum;
unsigned char Rev_Buf[Rev_Byte_Num];

/************************************************************************************************************************/

#if 1
unsigned char Rev_Data(void)
{
	return SSDAT;
}
unsigned char Serial_Get_Status(void)
{
	if(rev_num & 0x80)
	{
		rev_num = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

void Serial_Rev_IQH(void)
{
	res = Rev_Data();
	
	if((rev_num & 0x80) == 0)
	{
		if(rev_num & 0x40)
		{
			if(res == 0xFB)
			{
				rev_num |= 0x80;
			}
			else
			{
				rev_num = 0;
			}
		}
		else
		{
               if(rev_num == 5){
                if(res == sum)
                {
                    rev_num |= 0x40;				
                }	else{
                    rev_num = 0;
                }	
            }
			//else
			{
				Rev_Buf[rev_num] = res;
				rev_num++;
				sum = (unsigned char)((Rev_Buf[0])+(Rev_Buf[1])+(Rev_Buf[2])+(Rev_Buf[3])+(Rev_Buf[4]));
				if(Rev_Buf[0] != 0xA5)
				{
					rev_num = 0;
				}
//				if(rev_num > Rev_Byte_Num)
//				{
//					rev_num = 0;
//				}
			}
		}
	}
	
}
#endif

void Key_Scanf(void)
{
	switch (KEY_Para_tx.KEY_VALUE)
	{
			case KEY_LOOP_NUM0://座椅打开按键
													if(RESET_KEY1_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(RESET_KEY1_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 1;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM1;
													break;
			case KEY_LOOP_NUM1://腰靠打开按键
													if(LEFT_KEY2_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(LEFT_KEY2_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 1; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM2;
													break;
			case KEY_LOOP_NUM2://腰靠收回按键
													if(RIGHT_KEY3_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(RIGHT_KEY3_DOWN))
														{
															flag = 0;															
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 1;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM3;
													break;
			case KEY_LOOP_NUM3:// 复位按键
													if(FOUR_LEFT_KEY4_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_LEFT_KEY4_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 1;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM4;
													break;
			case KEY_LOOP_NUM4://头枕打开
				                  #if 1                   
													if(FOUR_RIGHT_KEY5_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_RIGHT_KEY5_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 1;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													#endif
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM5;
													break;
			case KEY_LOOP_NUM5://头枕收回
				                  #if 1                    
													if(FOUR_GETUP_KEY6_DOWN)//四向向上拨动接触点向下开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_GETUP_KEY6_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 1;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													#endif
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM6;
													break;
			case KEY_LOOP_NUM6://座椅收回按键
													if(FOUR_GETDOWN_KEY7_DOWN)
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_GETDOWN_KEY7_DOWN))
														{
															flag = 0;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 1;
															PUSH_STOP_FLAG    = 0;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}	
													}
													
													#if 1
													if(RESET_KEY1_UP && LEFT_KEY2_UP && RIGHT_KEY3_UP && FOUR_LEFT_KEY4_UP && FOUR_RIGHT_KEY5_UP && FOUR_GETUP_KEY6_UP && FOUR_GETDOWN_KEY7_UP)
													{
														
														if(!flag)
														{
															flag = 1;
															KEY_Para_tx.RESET_KEY1_FLAG = False;
															PUSH_RESET_FLAG   = 0;
															LUMBER_OPEN_FLAG  = 0; 
															LUMBER_CLOSE_FLAG = 0;
															HEAD_OPEN_FLAG    = 0;
															HEAD_CLOSE_FLAG   = 0;
															PUSH_OPEN_FLAG    = 0;
															PUSH_CLOSE_FLAG   = 0;
															PUSH_STOP_FLAG    = 1;
															FOOT_STATUS_FLAG  = 0;
															COOL_STATUS_FLAG  = 0;
															Close_Foot_Led_Flag = 0;
									
															Mass_Open_Flag  = 0;
															Mass_Close_Flag = 0;
															Heat_Open_Flag  = 0;
															Heat_Close_Flag = 0;
									
															Sleep_Position_Flag        = 0;
															Set_Sleep_Position_Flag    = 0;

															Watch_TV_Position_Flag     = 0;
															Set_Watch_TV_Position_Flag = 0;

															Reading_Position_Flag      = 0;
															Set_Reading_Position_Flag  = 0;
														}
													}
													#endif
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM0;
													break;
			default:
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM0;
													break;
				
		}
}

void Key_Handle(void)
{
	if(PUSH_RESET_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,HOME_POSITION);
	}
	else if(LUMBER_OPEN_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,LARBUM_UP);
	}
	else if(LUMBER_CLOSE_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,LARBUM_DOWN);
	}
	else if(HEAD_OPEN_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,HEAD_UP);
	}
	else if(HEAD_CLOSE_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,HEAD_DOWN);
	}
	else if(PUSH_OPEN_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,OPEN);
	}
	else if(PUSH_CLOSE_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,CLOSE);
	}
	else if(PUSH_STOP_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,STOP);
	}
	else if(FOOT_STATUS_FLAG)
	{
		Protocol_tx(IC_ADDR,IC_ID,FOOT_LIGHT_OPEN);
	}
	else if(COOL_STATUS_FLAG)// 制冷没有关闭
	{
		Protocol_tx(IC_ADDR,IC_ID,COOL_OPEN);
	}
	else if(Close_Foot_Led_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,FOOT_LIGHT_CLOSE);
	}
	else if(Mass_Open_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,MASS_OPEN);
	}
	else if(Mass_Close_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,MASS_CLOSE);
	}
	else if(Heat_Open_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,HEAT_ON);
	}
	else if(Heat_Close_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,HEAT_OFF);
	}
	else if(Sleep_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,SLEEP_POSITION);
	}
	else if(Set_Sleep_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,SET_SLEEP_POSITION);
	}
	else if(Watch_TV_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,WATCH_TV_POSITION);
	}
	else if(Set_Watch_TV_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,SET_WATCH_TV_POSITION);
	}
	else if(Reading_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,READING_POSITION);
	}
	else if(Set_Reading_Position_Flag)
	{
		Protocol_tx(IC_ADDR,IC_ID,SET_READING_POSITION);
	}
}

void Rev_Data_Handle(void)
{
	 if(Serial_Get_Status())
	 {
		temp = (unsigned int)Get_32bit(Rev_Buf[3],Rev_Buf[4]);
		memset(&Rev_Buf,0,sizeof(Rev_Buf));
		switch (temp)
		{
			case COCO_Stop:                                 //停止
				          #if 1
				          PUSH_RESET_FLAG   = 0;
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 1;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Recline:                                //座椅打开
				          #if 1			
			            PUSH_RESET_FLAG   = 0;
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 1;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Close: 				                       //座椅收回
				          #if 1
			            PUSH_RESET_FLAG   = 0;
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 1;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Home_Position:                                 //座椅复位
				          #if 1		
			            PUSH_RESET_FLAG   = 1;
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
				          
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
		            	#endif
				          break;
			case COCO_Head_Up:                                 //头枕打开
				          #if 1			
			            PUSH_RESET_FLAG   = 0;
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 1;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Head_Down:                                 //头枕收回
				          #if 1		
			            PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 1;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Light_On:                                 //脚灯开
				          #if 0			
			            PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 1;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Light_Off:                                 //脚灯关
				          #if 0			
			            PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 1;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Lumbar_Up:
				          #if 1                               //腰靠打开
			            PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 1; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Lumbar_Down:
				          #if 1                    //腰靠收回									
									PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 1;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            #endif
				          break;
			case COCO_Sleep_Position://睡眠位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 1;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
				          break;
			case COCO_TV_Position://看电视位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 1;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0; 
			            break;
			case COCO_Reading_Position://阅读位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 1;
									Set_Reading_Position_Flag  = 0;
			            break;
			case COCO_Set_Sleep_Position://记忆睡眠位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 1;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            break;
			case COCO_Set_TV_Position://记忆看电视位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 1;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
			            break;
			case COCO_Set_Reading_Position://记忆阅读位置
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 0;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 1;
			            break;
			default:
				          PUSH_RESET_FLAG   = 0;            
									LUMBER_OPEN_FLAG  = 0; 
									LUMBER_CLOSE_FLAG = 0;
									HEAD_OPEN_FLAG    = 0;
									HEAD_CLOSE_FLAG   = 0;
									PUSH_OPEN_FLAG    = 0;
									PUSH_CLOSE_FLAG   = 0;
									PUSH_STOP_FLAG    = 1;
									FOOT_STATUS_FLAG  = 0;
									COOL_STATUS_FLAG  = 0;
			            Close_Foot_Led_Flag = 0;
			
			            Mass_Open_Flag  = 0;
									Mass_Close_Flag = 0;
									Heat_Open_Flag  = 0;
									Heat_Close_Flag = 0;
			
			            Sleep_Position_Flag        = 0;
									Set_Sleep_Position_Flag    = 0;

									Watch_TV_Position_Flag     = 0;
									Set_Watch_TV_Position_Flag = 0;

									Reading_Position_Flag      = 0;
									Set_Reading_Position_Flag  = 0;
				          break;
		   }

	 }
}

void System_Init(void)
{
	TimeOutDet_Init();
	BackCall_Key(Key_Init);
	Led_Init();
	Timer_Init();
	BackCall_Uart1(12,Uart1_Init);
	WatchDog();
	Interrupt_Init();
}

void System_Handle(void)
{
	WatchDog_Clear();
	Rev_Data_Handle();
	Key_Scanf();
	if(TimeOutDet_Check(&TimeOut_Para[0]))
	{
		TimeOut_Record(&TimeOut_Para[0],OnLine_Time);
		Key_Handle();
	}
}

/**************************************************
*函数名称：void timer0/1/2() interrupt 1/3/5
*函数功能：定时器中断产生方波
*入口参数：void
*出口参数：void
**************************************************/
void timer0() interrupt 1
{
  TL0 = (65536 - 5900)%256;
	TH0 = (65536 - 5900)/256;	
	TimeOutDet_DecHandle();

}

void timer1() interrupt 3
{

}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零

}

void Uart1_Int() interrupt 7   //Uart1中断函数
{

	if(SSCON0&0x02)    //发送标志位判断
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))  //接收标志位判断
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
	  Serial_Rev_IQH();
	}	
}




