#include "system.h"

extern AUTO_CLOSE_PUSH_PARA_t Auto_Close_Push_Para;
extern DEMO_PARA_t Demo_Para;
extern APP_PARA_t App_Para;
extern HEAT_FUNCTION_PARA_t Heat_Function_Para;
extern MASS_PARA Mass_Para;
unsigned char UartSendFlag;
unsigned char UartReceiveFlag;


/*****************************************接收数据变量定义**********************************************/
unsigned char Res,Rev_Num,Rev_Sum,Rev_String[REV_BUF_SIZE];
unsigned int Temp;
/*****************************************************************************************************/

void Uart_Init(void)
{
    SCON=0x50;
	PCON|=0x80;
	T2CON&=~0x30;
	TMCON|=0x02;
	TMOD&=0x0f;
	TMOD|=0x20;
	TH1=256 - Freq/9600/16/2*2;
	TR1=0;
	TR1=1;
	EUART=1; 
}

void Send_Byte(unsigned char TX_BUF)
{
    SBUF = TX_BUF;
    while(!UartSendFlag);
    UartSendFlag = 0;
}

unsigned char Send_Data(PROTOCOL_TX *p)
{
    static unsigned char i;
    for(i = 0; i < BUF_SIZE; i ++)
    {
       Send_Byte(p->Buf[i]);
    }
    return 0;
}

unsigned char Protocol_Send(unsigned char addr,unsigned char id,unsigned char TX_DATA)
{
    PROTOCOL_TX buf;
    memset(&buf,0,sizeof(buf));
    buf.Buf_Para.ADDR = addr;
    buf.Buf_Para.ID   = id;
    buf.Buf_Para.DATA = TX_DATA;
    buf.Buf_Para.CHECKSUM = (unsigned char)(buf.Buf_Para.ADDR + buf.Buf_Para.ID + buf.Buf_Para.DATA);
    return Send_Data(&buf);
}

/*****************************************************接收子函数******************************************/

unsigned char Rev_Data(void)
{
    static unsigned char SSDAT;
    while(!UartReceiveFlag);
    UartReceiveFlag = 0;
    SSDAT = SBUF;
    return SSDAT;
}

unsigned char IF_Rev_Data(void)
{
    if(Rev_Num & 0x80)
    {
       Rev_Num &= 0x00;
       return 1;        
    }
    else 
    {
        return 0;
    }
}

void Serial_Rev_Data(void)
{
    Res = Rev_Data();
    if((Rev_Num & 0x80) == 0)
    {
        if(Rev_Num & 0x40)
        {
            if(Res == 0xfb)
            {
               Rev_Num |= 0x80; 
            }
            else 
            {
               Rev_Num &= 0x00; 
            }
        }
        else 
        {
            if(Rev_Num == 5)
            {
                if(Res == Rev_Sum)
                {
                   Rev_Num |= 0x40; 
                }
                else
                {
                   Rev_Num &= 0x00;  
                }
            }
            else
            {
                Rev_String[Rev_Num] = Res;
                Rev_Num ++;
                Rev_Sum = (unsigned char)(Rev_String[0]+Rev_String[1]+Rev_String[2]+Rev_String[3]+Rev_String[4]);
                if(Rev_String[0] != 0xA5)
                {
                   Rev_Num &= 0X00; 
                }
            }
        }
    }
}

void Send_Three_Data(void)
{
	unsigned char i;
	extern APP_PARA_t App_Para;
	App_Para.Data = STOP;
	for(i = 0 ; i < TEN_STOP_DATA; i ++)
	{
		Protocol_Send(SEND_ADDR,SEND_ID,App_Para.Data);//全局变量Data
	}
}

void Rev_Data_Handle(void)
{
    if(IF_Rev_Data())
    {
        Temp = (unsigned int)Get_32Bit(Rev_String[3],Rev_String[4]);
        memset(&Rev_String,0,sizeof(Rev_String));
        switch (Temp)
        {
            case COCO_Stop:                         //停止
                              if(Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag)
                              {
                                  Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 0;
                                  Voice_Protocol_Send(0xA5,0XFA,Data_Stop_End);
                              }
                              App_Para.Data = STOP;
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 0;
                              break;         
            case COCO_Recline:                        //座椅打开
                              
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
				    Send_Three_Data();		  
                              App_Para.Data = OPEN;
                              break;
            case COCO_Close:                         //座椅收回
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
				   Send_Three_Data();			  
                              App_Para.Data = CLOSE;
                              break;
            case COCO_Head_Up:                       //头枕打开
                              #ifdef  TABLE_DISABLE
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = HEAD_UP;
                              #endif
                              break;
            case COCO_Head_Down:                     //头枕收回
                              #ifdef TABLE_DISABLE
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = HEAD_DOWN;
                              #endif
                              break;
            case COCO_Lumbar_Up:                     //腰部打开
                              App_Para.App_Flag = 1;   
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = LARBUM_UP;
                                       
                              break;
            case COCO_Lumbar_Down:                   //腰部收回
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = LARBUM_DOWN; 
                              
                              break;
            case COCO_Home_Position:                 //复位
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = HOME_POSITION; 
                              break;
            case COCO_Sleep_Position:                //睡眠位置
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = SLEEP_POSITION; 
                              
                              break;
            case COCO_TV_Position:                   //看电视位置
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = WATCH_TV_POSITION; 
                              
                              break;
            case COCO_Reading_Position:              //阅读位置 
                              App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
                              App_Para.Data = READING_POSITION;
                              
                              break;
            case COCO_Set_Sleep_Position:            //设置睡眠位置
                              App_Para.Data = SET_SLEEP_POSITION;
                              App_Para.App_Flag = 1;
                              break;
            case COCO_Set_TV_Position:               //设置看电视位置
                              App_Para.Data = SET_WATCH_TV_POSITION;
                              App_Para.App_Flag = 1;
                              break;
            case COCO_Set_Reading_Position:          //设置阅读位置
                              App_Para.Data = SET_READING_POSITION;
                              App_Para.App_Flag = 1;
                              break;
            case COCO_Light_On:                      //打开脚灯
                              App_Para.Data = FOOT_LIGHT_OPEN;
                              App_Para.App_Flag = 1;
                              break;
            case COCO_Light_Off:                     //关闭脚灯
                              App_Para.Data = FOOT_LIGHT_CLOSE;
                              App_Para.App_Flag = 1;
                              break;
            case COCO_Heat_On:                       //发热布加热
                              App_Para.App_Flag = 1;
                              Heat_Function_Para.Heat_Cnt = 0x01;
                              Heat_Function_Para.App_Heat_Cnt1s = 0; 
			          Heat_Function_Para.Heat_Cnt30Min  = 0;
			          Heat_Function_Para.Heat_Cnt30Min_Flag = True;
			          App_Para.Data = HEAT_ON;
                              if(TEST_PIN == 0)
                              {
                                  LED1_SET(1);
                              }
                              else
                              {
                                  LED2_SET(1);
                              }
                              break;
            case COCO_Heat_Off:                      //发热布关闭
                              App_Para.App_Flag = 1;
                              Heat_Function_Para.Heat_Cnt = 0x00;
                              Heat_Function_Para.App_Heat_Cnt1s = 0; 
			          Heat_Function_Para.Heat_Cnt30Min  = 0;
			          Heat_Function_Para.Heat_Cnt30Min_Flag = False;
			          App_Para.Data = HEAT_OFF;
                              if(TEST_PIN == 0)
                              {
                                 LED1_SET(0); 
                              }
                              else
                              {
                                 LED2_SET(0);
                              }
                              break;
            case COCO_Massage_Start:                 //马达开启
                              App_Para.App_Flag = 1;
                              Mass_Para.Mass_Cnt = 0x01;
                              //计时定时器清零
			          Mass_Para.App_Mass_Cnt1s = 0;
			          Mass_Para.Mass_Cnt30Min = 0;
			          //停止计数并且关闭震动马达
			          Mass_Para.Mass_Cnt30Min_Flag = True;
                              App_Para.Data = MASS_OPEN;
                              if(TEST_PIN == 0)
                              {
                                 LED2_SET(1);
                              }
                              else
                              {
                                 LED1_SET(1);
                              }
                              break;
            case COCO_Massage_Stop:                  //马达关闭
                              App_Para.App_Flag = 1;
	                        Mass_Para.Mass_Cnt = 0x00;
	                          //计时定时器清零
  				   Mass_Para.App_Mass_Cnt1s = 0;
  				   Mass_Para.Mass_Cnt30Min = 0;
  				   //停止计数并且关闭震动马达
  				   Mass_Para.Mass_Cnt30Min_Flag = False;
                              App_Para.Data = MASS_CLOSE;
	                          if(TEST_PIN == 0)
	                          {
	                             LED2_SET(0);
	                          }
	                          else
	                          {
	                             LED1_SET(0);
	                          }
                              break;
            case Demo_Hello_Bella:
                              Demo_Para.Demo_Flag = 1;
                              App_Para.Data = HOME_POSITION; 
                              App_Para.App_Flag = 1;
                              break;
            case Thanks:
                              Demo_Para.Demo_Flag = 0;
                              //App_Flag = 1;
                              break;
            case COCO_TABLE_OPEN:
				   #ifdef TABLE_ENABLE
				    App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
				   Send_Three_Data();			  
                              App_Para.Data = HEAD_UP; 
				   #endif
				   break;
	     case 	COCO_TABLE_CLOSE:
		 	          #ifdef TABLE_ENABLE
                               App_Para.App_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Flag = 1;
                              Auto_Close_Push_Para.Auto_Close_Push_Cnts = 0;
                              if(!Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag)
                              {
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneFlag = 1;
                                 Auto_Close_Push_Para.Voice_AutoClosePush_OnlyOneEndFlag = 1;
                                 Voice_Protocol_Send(0xA5,0XFA,Data_Stop);
                              }
				   Send_Three_Data();		  
                              App_Para.Data = HEAD_DOWN;
				   #endif
				    break;
				
            default:
                              //Data = STOP;
                              break;
        } 
    }
    
}

/*****************************************************
*函数名称：void UartInt(void) interrupt 4
*函数功能：Uart0中断函数
*入口参数：void
*出口参数：void
*****************************************************/
void UartInt(void) interrupt 4
{
	if(TI)
	{
		TI = 0;	
		UartSendFlag = 1;		
	}
	if(RI)
	{
		RI = 0;	
		UartReceiveFlag = 1;
		Serial_Rev_Data();	
	}
  
}
