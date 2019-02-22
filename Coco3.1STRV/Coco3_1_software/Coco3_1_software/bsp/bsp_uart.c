#include "bsp_uart.h"
#include "string.h"
#include "system.h"

unsigned char Uart1SendFlag,Uart1ReceiveFlag;
unsigned char Rev_String[REV_BUF_SIZE];

char Rev_Flag;
/***************************************************接收数据的变量定义****************************************/
unsigned char Rev_Num,Rev_Sum;
unsigned int Temp;

extern void Read_Position_Control(void);
extern void WatchTV_Position_Control(void);
extern void Sleep_Position_Control(void);
extern void SeatOpen_Control(void);
extern void SeatClose_Control(void);
extern void HeadUp_Control(void);
extern void HeadDown_Control(void);
extern void LumberUp_Control(void);
extern void LumberDown_Control(void);
extern void LegUp_Control(void);
extern void LegDown_Control(void);
extern void HomePosition_Control(void);
extern void Push_Stop_Control(void);
extern void Push_Stop_Send_Data(void);
extern void Push_Start_Send_Data(void);
extern void Demo_Stop_Send_Data(void);
extern DEMO_STATUS_PARA_t Demo_Status_Para;
extern PUSH_STATUS_PARA_t Push_Status_Para;
extern unsigned char Data;
extern char rev_cmp_flag;


void Uart_Init(unsigned char Freq,unsigned int baud)
{
    P1CON &= 0xF5;                     //TX设置为强推挽输出高，RX设置为输入带上拉
	P1PH  |= 0x0A;
	
	OTCON = 0xC0;                      //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;                     //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;        //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 = 0x01;                        //开启SSI中断     
}



/*************************************发送数据子函数*****************************************/

void Uart1_Buf_TX(unsigned char DATA)
{
	SSDAT = DATA;
	while(!Uart1SendFlag);
	Uart1SendFlag = 0;
}

unsigned char Send_Data(PROTOCOL_TX *p)
{
    unsigned char i;
    for(i = 0; i < BUF_SIZE; i++)
    {
      Uart1_Buf_TX(p->Buf[i]);
    }
    return 0;
}    

unsigned char Protocol_Send(unsigned char id,unsigned char addr,unsigned char TX_DATA)
{
  PROTOCOL_TX buf;
  memset(&buf,0,sizeof(buf));
  buf.Buf_Format.ID        = id;
  buf.Buf_Format.ADDR      = addr;
  buf.Buf_Format.DATA1     = TX_DATA;
  buf.Buf_Format.CHECKSUM  = (unsigned char)(buf.Buf_Format.ID + buf.Buf_Format.ADDR + buf.Buf_Format.DATA1);   
  return Send_Data(&buf);    
}

/******************************************接收子函数********************************************/

unsigned char Rev_Byte(void)
{
    return SSDAT;
}

unsigned char IF_REV_STRING(void)
{
  if(Rev_Num & 0x80)
  {
      Rev_Num = 0x00;
      return 1;
  }
  else 
  {
      return 0;
  }
}

void Serial_Rev_IQH(void)
{

	volatile unsigned char Res;
    Res = Rev_Byte();
	#if 0
	rev_buf[rev_num_] = Res;
	
	rev_num_ ++;
	
	if(rev_num_ ++ >= REV_BUF_SIZE-1){
		rev_num_ = 0;
		rev_cmp_flag = 1;
	}
	if(rev_num_ > 1){
		if(rev_buf[0] != 0xa5){
			rev_num_ = 0;
		}
	}
    #else
    if((Rev_Num & 0X80) == 0)
    {
        if(Rev_Num &0x40)
        {
        
            if(Res == 0xfb)
            {
               Rev_Num |= 0x80; 
                rev_cmp_flag = 1;
            }
            else
            {
               Rev_Num &= 0x00;
            }
        }
        else
        {
        	if(Rev_Num == 5){
	            if(Res == Rev_Sum)
	            {
	                Rev_Num |= 0x40;
	            }else{
					Rev_Num = 0;
				}
        	}
            Rev_String[Rev_Num] = Res;
            Rev_Num ++;
            Rev_Sum = (unsigned char)(Rev_String[0] + Rev_String[1] + Rev_String[2] + Rev_String[3] + Rev_String[4]); 
			if(Rev_String[0] != 0xA5)
            {
              Rev_Num = 0x00; 
              Rev_Sum = 0;
            }
        }
    }
	#endif
}

void Rev_Data_Handle(void)
{
   if(IF_REV_STRING())
   {
       Temp = (unsigned int)Get_32Bit(Rev_String[3],Rev_String[4]);     
       memset(&Rev_String,0,sizeof(Rev_String));
       switch (Temp)
       {
           case COCO_Stop://推杆停止
                      Demo_Stop_Send_Data();
		   	  Push_Stop_Send_Data();
                      Push_Stop_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Recline://座椅推杆打开
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      SeatOpen_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Close://座椅关闭
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      SeatClose_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Lift:
		   	  Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      //Data = OPEN;
                      Rev_Flag = 1;
                      break;
           case COCO_Home_Position://复位
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      HomePosition_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Sleep_Position:  //睡觉位置
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      Sleep_Position_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_TV_Position://看电视位置
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      WatchTV_Position_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Reading_Position://阅读位置
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
                      Read_Position_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Set_Sleep_Position://设置睡觉位置
                      Demo_Stop_Send_Data();
                      Data = SET_SLEEP_POSITION;
                      Rev_Flag = 1;
                      break;
           case COCO_Set_TV_Position://设置看电视位置
                      Demo_Stop_Send_Data();
                      Data = SET_WATCH_TV_POSITION;
                      Rev_Flag = 1;
                      break;
           case COCO_Set_Reading_Position://设置阅读位置
                      Demo_Stop_Send_Data();
                      Data = SET_READING_POSITION;
                      Rev_Flag = 1;
                      break;
           case COCO_Head_Up://头枕打开
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  HeadUp_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Head_Down://头枕收回
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  HeadDown_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Lumbar_Up://腰部打开
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  LumberUp_Control();
                      Rev_Flag = 1;
                      break;
           case COCO_Lumbar_Down://腰部收回
                      Push_Status_Para.PushOnlyOne_Flag = 0;
                      Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  LumberDown_Control();
                      Rev_Flag = 1;
                      break;
	    case COCO_Foot_Up://腿部打开
	               Push_Status_Para.PushOnlyOne_Flag = 0;
			  Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  LegUp_Control();
			  Rev_Flag = 1;
			  break;
	    case COCO_Foot_Down://腿部收回
	               Push_Status_Para.PushOnlyOne_Flag = 0;
			  Demo_Stop_Send_Data();
		   	  Push_Start_Send_Data();
			  LegDown_Control();
			  Rev_Flag = 1;
			  break;
           case COCO_Light_On://脚灯打开
                      Demo_Stop_Send_Data();
                      Data = FOOT_LIGHT_OPEN;
                      Rev_Flag = 1;
                      break;
           case COCO_Light_Off://脚灯关闭
                      Demo_Stop_Send_Data();
                      Data = FOOT_LIGHT_CLOSE;
                      Rev_Flag = 1;
                      break;
           case COCO_Massage_Start://震动马达打开
                      Demo_Stop_Send_Data();
                      Data = MASS_OPEN;
                      Rev_Flag = 1;
                      break;
           case COCO_Massage_Stop://震动马达关闭
                      Demo_Stop_Send_Data();
                      Data = MASS_CLOSE;
                      Rev_Flag = 1;
                      break;
           case COCO_Heat_On://发热布打开
                      Demo_Stop_Send_Data();
                      Data = HEAT_ON;
                      Rev_Flag = 1;
                      break;
           case COCO_Heat_Off://发热布关闭
                      Demo_Stop_Send_Data();
                      Data = HEAT_OFF;
                      Rev_Flag = 1;
                      break;
           case Demo_Hello_Bella:
		   	  Demo_Status_Para.Demo_Flag = 1;
		   	  break;
           case Thanks:
		   	  Demo_Status_Para.Demo_Flag = 0;
		   	  break;
           default:
                      Data = 0x00;
                      break;
       }
   }       
}






