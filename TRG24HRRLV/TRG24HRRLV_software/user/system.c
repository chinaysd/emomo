#include "system.h"

TIMEOUT_PARA TimeOut_Para[2];
FOOL_LED_PARA_t Fool_Led_Para;
MASS_PARA Mass_Para;
HEAT_FUNCTION_PARA_t Heat_Function_Para;
DOUBLE_CHANGE_MODE_t Double_Change_Mode;
AUTO_CLOSE_PUSH_PARA_t Auto_Close_Push_Para;
DEMO_PARA_t Demo_Para;
APP_PARA_t App_Para;


void Key_Handle(unsigned char Get_Key)
{      
    if(TEST_PIN == 0)                                                      //电阻R21没有接上则为这个程序
    {
       if(Get_Key == MSG_KEY_NONE)
        {
           Rev_Data_Handle();                                              //接收的数据处理
           if(!App_Para.App_Flag)                                          //这个标志App_Flag区别于语音模组(1)与按键(0)       
           {
              App_Para.App_Flag = 1;
              App_Para.Data = STOP; 
              App_Para.VOICE_DATA = 0;                                    //重复播报和语音切换指令清零VOICE_DATA
              App_Para.VOICE_DATA_STOP = 0;                               //推杆动时给语音模组返回的数据VOICE_DATA_STOP
              if(App_Para.VOICE_DATA_STOP_END)                            //推杆停止时给语音模组返回的数据VOICE_DATA_STOP_END
              {
                 App_Para.VOICE_DATA_STOP_END = 0x0100;
                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP_END);
                 App_Para.VOICE_DATA_STOP_END = 0;                        //仅发送一次，发送完清零
              }
           }
           Heat_Function_Para.Heat_Flag     = 0;                                    //松手时发热布标志位清零
           Fool_Led_Para.Foot_Led_Flag = 0;                                    //松手时脚灯标志位清零
           Mass_Para.Mass_Flag = 0;
        }
        else if(Get_Key == MSG_KEY1_PRESS)//K7
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                        //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);   //仅发送一次
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HEAD_DOWN;        
        }
        else if(Get_Key == MSG_KEY2_PRESS)//K5
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                      //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HEAD_UP;     
        }
        else if(Get_Key == MSG_KEY3_PRESS)//K4
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                     //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = OPEN;         
        }
        else if(Get_Key == MSG_KEY4_PRESS)//K6
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                   //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = CLOSE;               
        }
        else if(Get_Key == MSG_KEY5_LONGPRESS_HD)//K1
        {
           App_Para.App_Flag  = 0;
           Double_Change_Mode.Double_Push_Cnt = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                  //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HOME_POSITION;         
        }
        else if(Get_Key == MSG_KEY6_PRESS)//K2
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           #if LARBUM_PUSH_FUNCTION_DISABLE
           App_Para.App_Flag  = 0;
           if(App_Para.VOICE_DATA_STOP != 0x0101)
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           App_Para.Data = LARBUM_DOWN;
           #endif
           #if HEAT_FUNCTION_ENABLE
           if(!Heat_Function_Para.Heat_Flag)//发热布标志位，仅进来一次
           {
               App_Para.App_Flag  = 1;
               Heat_Function_Para.Heat_Flag = 1;
               ++ Heat_Function_Para.Heat_Cnt;//切换变量
               if(Heat_Function_Para.Heat_Cnt & 0x01)
               {
                 Heat_Function_Para.App_Heat_Cnt1s = 0; 
                 Heat_Function_Para.Heat_Cnt30Min  = 0;
                 Heat_Function_Para.Heat_Cnt30Min_Flag = True;
                 App_Para.Data = HEAT_ON;
                 LED1_SET(1);               
               }
               else
               {
                 Heat_Function_Para.Heat_Cnt30Min_Flag = False;  
                 App_Para.Data = HEAT_OFF;
                 LED1_SET(0); 
               }
           }
           #endif
        }
        else if(Get_Key == MSG_KEY7_PRESS)//K3
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           //腰推功能
           #if LARBUM_PUSH_FUNCTION_DISABLE
           App_Para.App_Flag  = 0;
           if(App_Para.VOICE_DATA_STOP != 0x0101)
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           App_Para.Data = LARBUM_UP;
           #endif
           //脚灯功能
           #if FOOL_LED_FUNCTION_DISABLE
		   if(!Fool_Led_Para.Foot_Led_Flag)//脚灯标志位，仅进来一次
		   {
			  App_Para.App_Flag	= 1;
			  Fool_Led_Para.Foot_Led_Flag = 1;
			  ++ Fool_Led_Para.Foot_Led_Cnt;//脚灯切换变量
			  if(Fool_Led_Para.Foot_Led_Cnt & 0x01)
			  {
				 App_Para.Data = FOOT_LIGHT_OPEN; 
			  }
			  else
			  {
				 App_Para.Data = FOOT_LIGHT_CLOSE; 
			  }
		   } 
           #endif
		   //震动马达使能
           #if MASS_FUNCTION_ENABLE
           if(!Mass_Para.Mass_Flag)//震动马达标志位，仅进来一次
		   {
			  App_Para.App_Flag	= 1;
			  Mass_Para.Mass_Flag = 1;
			  ++ Mass_Para.Mass_Cnt;//震动马达切换变量
			  if(Mass_Para.Mass_Cnt & 0x01)
			  {
			     //计时定时器清零
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //停止计数并且关闭震动马达
			     Mass_Para.Mass_Cnt30Min_Flag = True;
				 App_Para.Data = MASS_OPEN; 
				 LED2_SET(1);
			  }
			  else
			  {
			     //计时定时器清零
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //停止计数并且关闭震动马达
			     Mass_Para.Mass_Cnt30Min_Flag = False;
				 App_Para.Data = MASS_CLOSE; 
				 LED2_SET(0);
			  }
		   }
           #endif
        }
        else if(Get_Key == MSG_KEY5_SHORT_PRESS)//K1     MSG_KEY5_PRESS
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           ++ Double_Change_Mode.Double_Push_Cnt;     //双击计数变量
           Double_Change_Mode.Double_Push_Flag = 1;   //双击计数标志至1，开始计数
           if(2 == Double_Change_Mode.Double_Push_Cnt)
           {
               Double_Change_Mode.Double_Push_Cnt = 0;//双击计数变量清零
               Double_Change_Mode.Double_Push_Flag = 0;//双击计数标志清零
               Double_Change_Mode.Double_Push_Flag_Cnt = 0;
               App_Para.App_Flag  = 1;
               
               Double_Change_Mode.Change_Time_Flag = 1;//超出20S重复播报的计数标志位
               Double_Change_Mode.Change_Time_Cnts = 0;//超出20S重复播报的计数变量

               if(Double_Change_Mode.Change_Temp_Cnts_Flag)//超出20S重复播报的标志
               {
		          if(App_Para.VOICE_DATA != 0x0300)//重复播报指令
	              {
	                 App_Para.VOICE_DATA = 0x0300;
	                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
	                 App_Para.App_Flag  = 0;

	                 Double_Change_Mode.Change_Time_Flag = 0;//计数标志位
                     Double_Change_Mode.Change_Time_Cnts = 0;//计数变量

                     Double_Change_Mode.Change_Temp_Cnts_Flag = 0;//超出20S的变量清零
	              }
               }
               else
               {
                   if(!Double_Change_Mode.Change_OnlyOne_Flag)//上电第一次双击发送播报指令
                   {
                      Double_Change_Mode.Change_OnlyOne_Flag = 1;
                      if(App_Para.VOICE_DATA != 0x0300)//重复播报指令
   		              {
   		                 App_Para.VOICE_DATA = 0x0300;
   		                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
   		                 App_Para.App_Flag  = 0;
   		              }
                   }
		           else                    //20S内双击发送名字切换指令
		           {
		               if(App_Para.VOICE_DATA != 0x0200)//名字切换指令
			           {
			              App_Para.VOICE_DATA = 0X0200;
			              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
			              App_Para.App_Flag  = 0;
			           }
		           }
               }
           }
        } 
    }        
    /******************************************************************************************************************************************/
    /**************************************************************电阻R21接地下拉则为以下程序****************************************************/ 
    /******************************************************************************************************************************************/ 
    else
    {
        if(Get_Key == MSG_KEY_NONE)
        {
           Rev_Data_Handle();                                     //接收的数据处理
           if(!App_Para.App_Flag)                                          //这个标志App_Flag区别于语音模组(1)与按键(0)       
           {
              App_Para.App_Flag = 1;
              App_Para.Data = STOP; 
              App_Para.VOICE_DATA = 0;                                    //重复播报和语音切换指令清零VOICE_DATA
              App_Para.VOICE_DATA_STOP = 0;                               //推杆动时给语音模组返回的数据VOICE_DATA_STOP
              if(App_Para.VOICE_DATA_STOP_END)                            //推杆停止时给语音模组返回的数据VOICE_DATA_STOP_END
              {
                 App_Para.VOICE_DATA_STOP_END = 0x0100;
                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP_END);
                 App_Para.VOICE_DATA_STOP_END = 0;                        //仅发送一次，发送完清零
              }
           }
           Heat_Function_Para.Heat_Flag     = 0;                                    //松手时发热布标志位清零
           Fool_Led_Para.Foot_Led_Flag = 0;                                    //松手时脚灯标志位清零
           Mass_Para.Mass_Flag = 0;
        }
        else if(Get_Key == MSG_KEY1_PRESS)//K7
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                        //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);   //仅发送一次
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HEAD_UP;        
        }
        else if(Get_Key == MSG_KEY2_PRESS)//K5
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                      //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HEAD_DOWN;     
        }
        else if(Get_Key == MSG_KEY3_PRESS)//K4
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                     //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = CLOSE;         
        }
        else if(Get_Key == MSG_KEY4_PRESS)//K6
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                   //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = OPEN;               
        }
        else if(Get_Key == MSG_KEY5_LONGPRESS_HD)//K1
        {
           App_Para.App_Flag  = 0;
           Double_Change_Mode.Double_Push_Cnt = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                  //推杆动时给语音模组返回的数据VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           App_Para.Data = HOME_POSITION;         
        }
        else if(Get_Key == MSG_KEY6_PRESS)//K2
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           //腰推收回失能
           #if LARBUM_PUSH_FUNCTION_DISABLE
           App_Para.App_Flag  = 0;
           if(App_Para.VOICE_DATA_STOP != 0x0101)
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           App_Para.Data = LARBUM_DOWN;
           #endif
           //脚灯功能失能
           #if FOOL_LED_FUNCTION_DISABLE
		   if(!Fool_Led_Para.Foot_Led_Flag)//脚灯标志位，仅进来一次
		   {
			  App_Para.App_Flag	= 1;
			  Fool_Led_Para.Foot_Led_Flag = 1;
			  ++ Fool_Led_Para.Foot_Led_Cnt;//脚灯切换变量
			  if(Fool_Led_Para.Foot_Led_Cnt & 0x01)
			  {
				 App_Para.Data = FOOT_LIGHT_OPEN; 
			  }
			  else
			  {
				 App_Para.Data = FOOT_LIGHT_CLOSE; 
			  }
		   } 
           #endif
           //震动马达使能
           #if MASS_FUNCTION_ENABLE
           if(!Mass_Para.Mass_Flag)//震动马达标志位，仅进来一次
		   {
			  App_Para.App_Flag	= 1;
			  Mass_Para.Mass_Flag = 1;
			  ++ Mass_Para.Mass_Cnt;//震动马达切换变量
			  if(Mass_Para.Mass_Cnt & 0x01)
			  {
			     //计时定时器清零
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //停止计数并且关闭震动马达
			     Mass_Para.Mass_Cnt30Min_Flag = True;
				 App_Para.Data = MASS_OPEN; 
				 LED1_SET(1);
			  }
			  else
			  {
			     //计时定时器清零
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //停止计数并且关闭震动马达
			     Mass_Para.Mass_Cnt30Min_Flag = False;
				 App_Para.Data = MASS_CLOSE; 
				 LED1_SET(0);
			  }
		   }
           #endif
        }
        else if(Get_Key == MSG_KEY7_PRESS)//K3
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//当前按键按下时，初始化双击功能
           //腰推打开失能
           #if LARBUM_PUSH_FUNCTION_DISABLE
           App_Para.App_Flag  = 0;
           if(App_Para.VOICE_DATA_STOP != 0x0101)
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           App_Para.Data = LARBUM_UP;
           #endif
           //发热布打开使能
           #if HEAT_FUNCTION_ENABLE
           if(!Heat_Function_Para.Heat_Flag)//发热布标志位，仅进来一次
           {
               App_Para.App_Flag  = 1;
               Heat_Function_Para.Heat_Flag = 1;
               ++ Heat_Function_Para.Heat_Cnt;//切换变量
               if(Heat_Function_Para.Heat_Cnt & 0x01)
               {
                 Heat_Function_Para.App_Heat_Cnt1s = 0; 
                 Heat_Function_Para.Heat_Cnt30Min  = 0;
                 Heat_Function_Para.Heat_Cnt30Min_Flag = True;
                 App_Para.Data = HEAT_ON;
                 LED2_SET(1);               
               }
               else
               {
                 Heat_Function_Para.App_Heat_Cnt1s = 0; 
                 Heat_Function_Para.Heat_Cnt30Min  = 0;
                 Heat_Function_Para.Heat_Cnt30Min_Flag = False;  
                 App_Para.Data = HEAT_OFF;
                 LED2_SET(0); 
               }
           }
           #endif
        }
        else if(Get_Key == MSG_KEY5_SHORT_PRESS)//K1    MSG_KEY5_PRESS
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           ++ Double_Change_Mode.Double_Push_Cnt;     //双击计数变量
           Double_Change_Mode.Double_Push_Flag = 1;   //双击计数标志至1，开始计数
           if(2 == Double_Change_Mode.Double_Push_Cnt)
           {
               Double_Change_Mode.Double_Push_Cnt = 0;//双击计数变量清零
               Double_Change_Mode.Double_Push_Flag = 0;//双击计数标志清零
               Double_Change_Mode.Double_Push_Flag_Cnt = 0;
               App_Para.App_Flag  = 1;
               
               Double_Change_Mode.Change_Time_Flag = 1;//超出20S重复播报的计数标志位
               Double_Change_Mode.Change_Time_Cnts = 0;//超出20S重复播报的计数变量

               if(Double_Change_Mode.Change_Temp_Cnts_Flag)//超出20S重复播报的标志
               {
		          if(App_Para.VOICE_DATA != 0x0300)//重复播报指令
	              {
	                 App_Para.VOICE_DATA = 0x0300;
	                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
	                 App_Para.App_Flag  = 0;

	                 Double_Change_Mode.Change_Time_Flag = 0;//计数标志位
                     Double_Change_Mode.Change_Time_Cnts = 0;//计数变量

                     Double_Change_Mode.Change_Temp_Cnts_Flag = 0;//超出20S的变量清零
	              }
               }
               else
               {
                   if(!Double_Change_Mode.Change_OnlyOne_Flag)//上电第一次双击发送播报指令
                   {
                      Double_Change_Mode.Change_OnlyOne_Flag = 1;
                      if(App_Para.VOICE_DATA != 0x0300)//重复播报指令
   		              {
   		                 App_Para.VOICE_DATA = 0x0300;
   		                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
   		                 App_Para.App_Flag  = 0;
   		              }
                   }
		           else                    //20S内双击发送名字切换指令
		           {
		               if(App_Para.VOICE_DATA != 0x0200)//名字切换指令
			           {
			              App_Para.VOICE_DATA = 0X0200;
			              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
			              App_Para.App_Flag  = 0;
			           }
		           }
               }
           }
        }
    }
}


void System_Init(void)
{
  TimeOutDet_Init();       //计数变量初始化
  Timer_Init();            //定时器初始化
  Uart_Init();         //串口初始化
  //Led_App_Handle(LED_NUM); //LED初始化
  Led_Init();
  Test_Init();
  Key_Init();              //按键初始化
  Key_Register(Key_Handle);//按键回调
  WDTCON |= 0X40;          //开看门狗
  EA = 1;                  //开总终端
}

void System_Handle(void)
{
   WDTCON |= 0X40;//喂狗
   Key_Poll();    //按键处理函数
   if(TimeOutDet_Check(&TimeOut_Para[0]))//20MS发送一次的判断语句
   {
      TimeOut_Record(&TimeOut_Para[0],OnLine_Time); 
      if(!App_Para.VOICE_DATA)
      {
         Protocol_Send(SEND_ADDR,SEND_ID,App_Para.Data);//全局变量Data
      }         
   }
   if(Auto_Close_Push_Para.Auto_Close_Push_Cnts  > Auto_Close_Time)//推杆动后30S自动关闭的判断语句
   {
       Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;              //推杆自动关闭的计数变量
       Auto_Close_Push_Para.Auto_Close_Push_Flag = 0;              //推杆自动关闭的计数标志
       Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 0;
       if(Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag) //仅进来一次
       {
           Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 0;
           Voice_Protocol_Send(0xA5,0XFA,Data_Stop_End);//发送推杆停止指令告诉语音模组:推杆停止了
       }
       App_Para.Data = STOP;//然后向下发送停止指令
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
  TL0 = (65536 - 6000)%256;
  TH0 = (65536 - 6000)/256;
  TimeOutDet_DecHandle();
  if(Double_Change_Mode.Double_Push_Flag)
  {
     if(Double_Change_Mode.Double_Push_Flag_Cnt++ > 700)//500ms
     {
        Double_Change_Mode.Double_Push_Flag_Cnt = 0;//双击计数变量清零
        Double_Change_Mode.Double_Push_Flag = 0;    //双击计数标志位清零
        Double_Change_Mode.Double_Push_Cnt = 0;     //双击计数判断是否有两次

        /********************单次按脚灯开启*********************************/
		if(!Fool_Led_Para.Foot_Led_Flag)//脚灯标志位，仅进来一次
		{
		   App_Para.App_Flag = 1;
		   Fool_Led_Para.Foot_Led_Flag = 1;
		   ++ Fool_Led_Para.Foot_Led_Cnt;//脚灯切换变量
		   if(Fool_Led_Para.Foot_Led_Cnt & 0x01)
		   {
			  App_Para.Data = FOOT_LIGHT_OPEN; 
		   }
		   else
		   {
			  App_Para.Data = FOOT_LIGHT_CLOSE; 
		   }
		}  
		/*****************************************************************/
     }
  }
  if(Auto_Close_Push_Para.Auto_Close_Push_Flag)       //自动关闭推杆标志
  {
     Auto_Close_Push_Para.Auto_Close_Push_Cnts ++;    //自动关闭推杆计数变量
  }
  if(Double_Change_Mode.Change_Time_Flag)           //双击切换或者播报的标志
  {
     if(Double_Change_Mode.Change_Time_Cnts++ > Change_Time_Cnt20s)//20S
     {
        Double_Change_Mode.Change_Time_Flag = 0;    //双击切换或者播报的标志清零
        Double_Change_Mode.Change_Time_Cnts = 0;    //双击切换或者播报的变量清零
        Double_Change_Mode.Change_Temp_Cnts_Flag = 1;//是播报呢还是切换由这个标志决定
     }
  }
  /*********************************************************************************************/
  /**************************************** 发热布自动关闭时间**********************************/
  /*********************************************************************************************/
  if(Heat_Function_Para.Heat_Cnt30Min_Flag)
  {
     Heat_Function_Para.App_Heat_Cnt1s ++;
  }
  if(Heat_Function_Para.App_Heat_Cnt1s > 2000)//1秒的时间段
  {
     Heat_Function_Para.App_Heat_Cnt1s = 0;
     Heat_Function_Para.Heat_Cnt30Min ++;
  }
  if(Heat_Function_Para.Heat_Cnt30Min > 1800)//30分钟自动关闭发热布1800
  {
     //计时定时器清零
     Heat_Function_Para.App_Heat_Cnt1s = 0;
     Heat_Function_Para.Heat_Cnt30Min  = 0;
     //停止计数并且关闭发热布
     Heat_Function_Para.Heat_Cnt30Min_Flag = False;  
     App_Para.Data = HEAT_OFF;
     //发热切换变量清零
     Heat_Function_Para.Heat_Cnt = 0;
     if(TEST_PIN == 0)
     {
        LED1_SET(0); 
     }
     else
     {
        LED2_SET(0);
     }
  }
  /*********************************************************************************************/
  /******************************************震动马达自动关闭时间*******************************/
  /*********************************************************************************************/
  #if 1
  if(Mass_Para.Mass_Cnt30Min_Flag)
  {
     Mass_Para.App_Mass_Cnt1s ++;
  }
  if(Mass_Para.App_Mass_Cnt1s > 2000)//1秒的时间段
  {
     Mass_Para.App_Mass_Cnt1s = 0;
     Mass_Para.Mass_Cnt30Min ++;
  }
  if(Mass_Para.Mass_Cnt30Min > 1800)    //30分钟自动关闭震动马达1800
  {
     //计时定时器清零
     Mass_Para.App_Mass_Cnt1s = 0;
     Mass_Para.Mass_Cnt30Min = 0;
     //停止计数并且关闭震动马达
     Mass_Para.Mass_Cnt30Min_Flag = False;
     App_Para.Data = MASS_CLOSE; 
     //马达切换变量清零
     Mass_Para.Mass_Cnt = 0x00;
     if(TEST_PIN == 0)
     {
        LED2_SET(0);
     }
     else
     {
        LED1_SET(0);
     }
  }
  #endif
}

void timer1() interrupt 3
{

}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零
 
}


