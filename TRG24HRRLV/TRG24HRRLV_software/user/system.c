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
    if(TEST_PIN == 0)                                                      //����R21û�н�����Ϊ�������
    {
       if(Get_Key == MSG_KEY_NONE)
        {
           Rev_Data_Handle();                                              //���յ����ݴ���
           if(!App_Para.App_Flag)                                          //�����־App_Flag����������ģ��(1)�밴��(0)       
           {
              App_Para.App_Flag = 1;
              App_Para.Data = STOP; 
              App_Para.VOICE_DATA = 0;                                    //�ظ������������л�ָ������VOICE_DATA
              App_Para.VOICE_DATA_STOP = 0;                               //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
              if(App_Para.VOICE_DATA_STOP_END)                            //�Ƹ�ֹͣʱ������ģ�鷵�ص�����VOICE_DATA_STOP_END
              {
                 App_Para.VOICE_DATA_STOP_END = 0x0100;
                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP_END);
                 App_Para.VOICE_DATA_STOP_END = 0;                        //������һ�Σ�����������
              }
           }
           Heat_Function_Para.Heat_Flag     = 0;                                    //����ʱ���Ȳ���־λ����
           Fool_Led_Para.Foot_Led_Flag = 0;                                    //����ʱ�ŵƱ�־λ����
           Mass_Para.Mass_Flag = 0;
        }
        else if(Get_Key == MSG_KEY1_PRESS)//K7
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                        //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);   //������һ��
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HEAD_DOWN;        
        }
        else if(Get_Key == MSG_KEY2_PRESS)//K5
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                      //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HEAD_UP;     
        }
        else if(Get_Key == MSG_KEY3_PRESS)//K4
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                     //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = OPEN;         
        }
        else if(Get_Key == MSG_KEY4_PRESS)//K6
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                   //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
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
           if(App_Para.VOICE_DATA_STOP != 0x0101)                  //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HOME_POSITION;         
        }
        else if(Get_Key == MSG_KEY6_PRESS)//K2
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
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
           if(!Heat_Function_Para.Heat_Flag)//���Ȳ���־λ��������һ��
           {
               App_Para.App_Flag  = 1;
               Heat_Function_Para.Heat_Flag = 1;
               ++ Heat_Function_Para.Heat_Cnt;//�л�����
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
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           //���ƹ���
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
           //�ŵƹ���
           #if FOOL_LED_FUNCTION_DISABLE
		   if(!Fool_Led_Para.Foot_Led_Flag)//�ŵƱ�־λ��������һ��
		   {
			  App_Para.App_Flag	= 1;
			  Fool_Led_Para.Foot_Led_Flag = 1;
			  ++ Fool_Led_Para.Foot_Led_Cnt;//�ŵ��л�����
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
		   //�����ʹ��
           #if MASS_FUNCTION_ENABLE
           if(!Mass_Para.Mass_Flag)//������־λ��������һ��
		   {
			  App_Para.App_Flag	= 1;
			  Mass_Para.Mass_Flag = 1;
			  ++ Mass_Para.Mass_Cnt;//������л�����
			  if(Mass_Para.Mass_Cnt & 0x01)
			  {
			     //��ʱ��ʱ������
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //ֹͣ�������ҹر������
			     Mass_Para.Mass_Cnt30Min_Flag = True;
				 App_Para.Data = MASS_OPEN; 
				 LED2_SET(1);
			  }
			  else
			  {
			     //��ʱ��ʱ������
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //ֹͣ�������ҹر������
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
           ++ Double_Change_Mode.Double_Push_Cnt;     //˫����������
           Double_Change_Mode.Double_Push_Flag = 1;   //˫��������־��1����ʼ����
           if(2 == Double_Change_Mode.Double_Push_Cnt)
           {
               Double_Change_Mode.Double_Push_Cnt = 0;//˫��������������
               Double_Change_Mode.Double_Push_Flag = 0;//˫��������־����
               Double_Change_Mode.Double_Push_Flag_Cnt = 0;
               App_Para.App_Flag  = 1;
               
               Double_Change_Mode.Change_Time_Flag = 1;//����20S�ظ������ļ�����־λ
               Double_Change_Mode.Change_Time_Cnts = 0;//����20S�ظ������ļ�������

               if(Double_Change_Mode.Change_Temp_Cnts_Flag)//����20S�ظ������ı�־
               {
		          if(App_Para.VOICE_DATA != 0x0300)//�ظ�����ָ��
	              {
	                 App_Para.VOICE_DATA = 0x0300;
	                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
	                 App_Para.App_Flag  = 0;

	                 Double_Change_Mode.Change_Time_Flag = 0;//������־λ
                     Double_Change_Mode.Change_Time_Cnts = 0;//��������

                     Double_Change_Mode.Change_Temp_Cnts_Flag = 0;//����20S�ı�������
	              }
               }
               else
               {
                   if(!Double_Change_Mode.Change_OnlyOne_Flag)//�ϵ��һ��˫�����Ͳ���ָ��
                   {
                      Double_Change_Mode.Change_OnlyOne_Flag = 1;
                      if(App_Para.VOICE_DATA != 0x0300)//�ظ�����ָ��
   		              {
   		                 App_Para.VOICE_DATA = 0x0300;
   		                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
   		                 App_Para.App_Flag  = 0;
   		              }
                   }
		           else                    //20S��˫�����������л�ָ��
		           {
		               if(App_Para.VOICE_DATA != 0x0200)//�����л�ָ��
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
    /**************************************************************����R21�ӵ�������Ϊ���³���****************************************************/ 
    /******************************************************************************************************************************************/ 
    else
    {
        if(Get_Key == MSG_KEY_NONE)
        {
           Rev_Data_Handle();                                     //���յ����ݴ���
           if(!App_Para.App_Flag)                                          //�����־App_Flag����������ģ��(1)�밴��(0)       
           {
              App_Para.App_Flag = 1;
              App_Para.Data = STOP; 
              App_Para.VOICE_DATA = 0;                                    //�ظ������������л�ָ������VOICE_DATA
              App_Para.VOICE_DATA_STOP = 0;                               //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
              if(App_Para.VOICE_DATA_STOP_END)                            //�Ƹ�ֹͣʱ������ģ�鷵�ص�����VOICE_DATA_STOP_END
              {
                 App_Para.VOICE_DATA_STOP_END = 0x0100;
                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP_END);
                 App_Para.VOICE_DATA_STOP_END = 0;                        //������һ�Σ�����������
              }
           }
           Heat_Function_Para.Heat_Flag     = 0;                                    //����ʱ���Ȳ���־λ����
           Fool_Led_Para.Foot_Led_Flag = 0;                                    //����ʱ�ŵƱ�־λ����
           Mass_Para.Mass_Flag = 0;
        }
        else if(Get_Key == MSG_KEY1_PRESS)//K7
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                        //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);   //������һ��
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HEAD_UP;        
        }
        else if(Get_Key == MSG_KEY2_PRESS)//K5
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                      //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HEAD_DOWN;     
        }
        else if(Get_Key == MSG_KEY3_PRESS)//K4
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                     //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = CLOSE;         
        }
        else if(Get_Key == MSG_KEY4_PRESS)//K6
        {
           App_Para.App_Flag  = 0;
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           if(App_Para.VOICE_DATA_STOP != 0x0101)                   //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
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
           if(App_Para.VOICE_DATA_STOP != 0x0101)                  //�Ƹ˶�ʱ������ģ�鷵�ص�����VOICE_DATA_STOP
           {
              App_Para.VOICE_DATA_STOP = 0x0101;
              App_Para.VOICE_DATA_STOP_END = 0x0100;
              Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA_STOP);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           App_Para.Data = HOME_POSITION;         
        }
        else if(Get_Key == MSG_KEY6_PRESS)//K2
        {
           if(Demo_Para.Demo_Flag)
           {
              Voice_Protocol_Send(0xA5,0XFA,0x0A00);
           }
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           //�����ջ�ʧ��
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
           //�ŵƹ���ʧ��
           #if FOOL_LED_FUNCTION_DISABLE
		   if(!Fool_Led_Para.Foot_Led_Flag)//�ŵƱ�־λ��������һ��
		   {
			  App_Para.App_Flag	= 1;
			  Fool_Led_Para.Foot_Led_Flag = 1;
			  ++ Fool_Led_Para.Foot_Led_Cnt;//�ŵ��л�����
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
           //�����ʹ��
           #if MASS_FUNCTION_ENABLE
           if(!Mass_Para.Mass_Flag)//������־λ��������һ��
		   {
			  App_Para.App_Flag	= 1;
			  Mass_Para.Mass_Flag = 1;
			  ++ Mass_Para.Mass_Cnt;//������л�����
			  if(Mass_Para.Mass_Cnt & 0x01)
			  {
			     //��ʱ��ʱ������
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //ֹͣ�������ҹر������
			     Mass_Para.Mass_Cnt30Min_Flag = True;
				 App_Para.Data = MASS_OPEN; 
				 LED1_SET(1);
			  }
			  else
			  {
			     //��ʱ��ʱ������
			     Mass_Para.App_Mass_Cnt1s = 0;
			     Mass_Para.Mass_Cnt30Min = 0;
			     //ֹͣ�������ҹر������
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
           Double_Change_Mode.Change_OnlyOne_Flag = 0;//��ǰ��������ʱ����ʼ��˫������
           //���ƴ�ʧ��
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
           //���Ȳ���ʹ��
           #if HEAT_FUNCTION_ENABLE
           if(!Heat_Function_Para.Heat_Flag)//���Ȳ���־λ��������һ��
           {
               App_Para.App_Flag  = 1;
               Heat_Function_Para.Heat_Flag = 1;
               ++ Heat_Function_Para.Heat_Cnt;//�л�����
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
           ++ Double_Change_Mode.Double_Push_Cnt;     //˫����������
           Double_Change_Mode.Double_Push_Flag = 1;   //˫��������־��1����ʼ����
           if(2 == Double_Change_Mode.Double_Push_Cnt)
           {
               Double_Change_Mode.Double_Push_Cnt = 0;//˫��������������
               Double_Change_Mode.Double_Push_Flag = 0;//˫��������־����
               Double_Change_Mode.Double_Push_Flag_Cnt = 0;
               App_Para.App_Flag  = 1;
               
               Double_Change_Mode.Change_Time_Flag = 1;//����20S�ظ������ļ�����־λ
               Double_Change_Mode.Change_Time_Cnts = 0;//����20S�ظ������ļ�������

               if(Double_Change_Mode.Change_Temp_Cnts_Flag)//����20S�ظ������ı�־
               {
		          if(App_Para.VOICE_DATA != 0x0300)//�ظ�����ָ��
	              {
	                 App_Para.VOICE_DATA = 0x0300;
	                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
	                 App_Para.App_Flag  = 0;

	                 Double_Change_Mode.Change_Time_Flag = 0;//������־λ
                     Double_Change_Mode.Change_Time_Cnts = 0;//��������

                     Double_Change_Mode.Change_Temp_Cnts_Flag = 0;//����20S�ı�������
	              }
               }
               else
               {
                   if(!Double_Change_Mode.Change_OnlyOne_Flag)//�ϵ��һ��˫�����Ͳ���ָ��
                   {
                      Double_Change_Mode.Change_OnlyOne_Flag = 1;
                      if(App_Para.VOICE_DATA != 0x0300)//�ظ�����ָ��
   		              {
   		                 App_Para.VOICE_DATA = 0x0300;
   		                 Voice_Protocol_Send(0xA5,0XFA,App_Para.VOICE_DATA);
   		                 App_Para.App_Flag  = 0;
   		              }
                   }
		           else                    //20S��˫�����������л�ָ��
		           {
		               if(App_Para.VOICE_DATA != 0x0200)//�����л�ָ��
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
  TimeOutDet_Init();       //����������ʼ��
  Timer_Init();            //��ʱ����ʼ��
  Uart_Init();         //���ڳ�ʼ��
  //Led_App_Handle(LED_NUM); //LED��ʼ��
  Led_Init();
  Test_Init();
  Key_Init();              //������ʼ��
  Key_Register(Key_Handle);//�����ص�
  WDTCON |= 0X40;          //�����Ź�
  EA = 1;                  //�����ն�
}

void System_Handle(void)
{
   WDTCON |= 0X40;//ι��
   Key_Poll();    //����������
   if(TimeOutDet_Check(&TimeOut_Para[0]))//20MS����һ�ε��ж����
   {
      TimeOut_Record(&TimeOut_Para[0],OnLine_Time); 
      if(!App_Para.VOICE_DATA)
      {
         Protocol_Send(SEND_ADDR,SEND_ID,App_Para.Data);//ȫ�ֱ���Data
      }         
   }
   if(Auto_Close_Push_Para.Auto_Close_Push_Cnts  > Auto_Close_Time)//�Ƹ˶���30S�Զ��رյ��ж����
   {
       Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;              //�Ƹ��Զ��رյļ�������
       Auto_Close_Push_Para.Auto_Close_Push_Flag = 0;              //�Ƹ��Զ��رյļ�����־
       Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 0;
       if(Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag) //������һ��
       {
           Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 0;
           Voice_Protocol_Send(0xA5,0XFA,Data_Stop_End);//�����Ƹ�ָֹͣ���������ģ��:�Ƹ�ֹͣ��
       }
       App_Para.Data = STOP;//Ȼ�����·���ָֹͣ��
   }
   
}

/**************************************************
*�������ƣ�void timer0/1/2() interrupt 1/3/5
*�������ܣ���ʱ���жϲ�������
*��ڲ�����void
*���ڲ�����void
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
        Double_Change_Mode.Double_Push_Flag_Cnt = 0;//˫��������������
        Double_Change_Mode.Double_Push_Flag = 0;    //˫��������־λ����
        Double_Change_Mode.Double_Push_Cnt = 0;     //˫�������ж��Ƿ�������

        /********************���ΰ��ŵƿ���*********************************/
		if(!Fool_Led_Para.Foot_Led_Flag)//�ŵƱ�־λ��������һ��
		{
		   App_Para.App_Flag = 1;
		   Fool_Led_Para.Foot_Led_Flag = 1;
		   ++ Fool_Led_Para.Foot_Led_Cnt;//�ŵ��л�����
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
  if(Auto_Close_Push_Para.Auto_Close_Push_Flag)       //�Զ��ر��Ƹ˱�־
  {
     Auto_Close_Push_Para.Auto_Close_Push_Cnts ++;    //�Զ��ر��Ƹ˼�������
  }
  if(Double_Change_Mode.Change_Time_Flag)           //˫���л����߲����ı�־
  {
     if(Double_Change_Mode.Change_Time_Cnts++ > Change_Time_Cnt20s)//20S
     {
        Double_Change_Mode.Change_Time_Flag = 0;    //˫���л����߲����ı�־����
        Double_Change_Mode.Change_Time_Cnts = 0;    //˫���л����߲����ı�������
        Double_Change_Mode.Change_Temp_Cnts_Flag = 1;//�ǲ����ػ����л��������־����
     }
  }
  /*********************************************************************************************/
  /**************************************** ���Ȳ��Զ��ر�ʱ��**********************************/
  /*********************************************************************************************/
  if(Heat_Function_Para.Heat_Cnt30Min_Flag)
  {
     Heat_Function_Para.App_Heat_Cnt1s ++;
  }
  if(Heat_Function_Para.App_Heat_Cnt1s > 2000)//1���ʱ���
  {
     Heat_Function_Para.App_Heat_Cnt1s = 0;
     Heat_Function_Para.Heat_Cnt30Min ++;
  }
  if(Heat_Function_Para.Heat_Cnt30Min > 1800)//30�����Զ��رշ��Ȳ�1800
  {
     //��ʱ��ʱ������
     Heat_Function_Para.App_Heat_Cnt1s = 0;
     Heat_Function_Para.Heat_Cnt30Min  = 0;
     //ֹͣ�������ҹرշ��Ȳ�
     Heat_Function_Para.Heat_Cnt30Min_Flag = False;  
     App_Para.Data = HEAT_OFF;
     //�����л���������
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
  /******************************************������Զ��ر�ʱ��*******************************/
  /*********************************************************************************************/
  #if 1
  if(Mass_Para.Mass_Cnt30Min_Flag)
  {
     Mass_Para.App_Mass_Cnt1s ++;
  }
  if(Mass_Para.App_Mass_Cnt1s > 2000)//1���ʱ���
  {
     Mass_Para.App_Mass_Cnt1s = 0;
     Mass_Para.Mass_Cnt30Min ++;
  }
  if(Mass_Para.Mass_Cnt30Min > 1800)    //30�����Զ��ر������1800
  {
     //��ʱ��ʱ������
     Mass_Para.App_Mass_Cnt1s = 0;
     Mass_Para.Mass_Cnt30Min = 0;
     //ֹͣ�������ҹر������
     Mass_Para.Mass_Cnt30Min_Flag = False;
     App_Para.Data = MASS_CLOSE; 
     //����л���������
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
	TF2 = 0;   //�������
 
}


