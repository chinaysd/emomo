#include "system.h"
static unsigned char Cnt;
unsigned char Uart1SendFlag,Uart1ReceiveFlag;

TIMEOUT_PARA TimeOut_Para[2],Key_Para[2];
KEY_PARA_TX KEY_Para_tx;

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
	if(TimeOutDet_Check(&TimeOut_Para[0]))
	{
		TimeOut_Record(&TimeOut_Para[0],OnLine_Time);
		switch (KEY_Para_tx.KEY_VALUE)
		{
			case KEY_LOOP_NUM0:
													if(RESET_KEY1_DOWN)//复位开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(RESET_KEY1_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY1_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM1;
													break;
			case KEY_LOOP_NUM1:
													if(LEFT_KEY2_DOWN)//左拨动开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(LEFT_KEY2_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY2_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM2;
													break;
			case KEY_LOOP_NUM2:
													if(RIGHT_KEY3_DOWN)//右拨动开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(RIGHT_KEY3_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY3_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM3;
													break;
			case KEY_LOOP_NUM3:
													if(FOUR_LEFT_KEY4_DOWN)//四向向左拨动接触点向右开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_LEFT_KEY4_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY4_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM4;
													break;
			case KEY_LOOP_NUM4:
													if(FOUR_RIGHT_KEY5_DOWN)//四向向右拨动接触点向左开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_RIGHT_KEY5_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY5_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM5;
													break;
			case KEY_LOOP_NUM5:
													if(FOUR_GETUP_KEY6_DOWN)//四向向上拨动接触点向下开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_GETUP_KEY6_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY6_VALUE);
														}	
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM6;
													break;
			case KEY_LOOP_NUM6:
													if(FOUR_GETDOWN_KEY7_DOWN)//四向向下拨动接触点向上开关按键
													{
														if(!KEY_Para_tx.RESET_KEY1_FLAG)
														{
															KEY_Para_tx.RESET_KEY1_FLAG = True;
															TimeOut_Record(&Key_Para[0],Shakes_Time);
														}
														if((TimeOutDet_Check(&Key_Para[0]))&&(FOUR_GETDOWN_KEY7_DOWN))
														{
															Protocol_tx(IC_ADDR,IC_ADDR,KEY7_VALUE);
														}	
													}
													if(RESET_KEY1_UP && LEFT_KEY2_UP && RIGHT_KEY3_UP && FOUR_LEFT_KEY4_UP && FOUR_RIGHT_KEY5_UP && FOUR_GETUP_KEY6_UP && FOUR_GETDOWN_KEY7_UP)
													{
														KEY_Para_tx.RESET_KEY1_FLAG = False;
														Protocol_tx(IC_ADDR,IC_ADDR,UNDATA);
													}
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM0;
													break;
			default:
													KEY_Para_tx.KEY_VALUE = KEY_LOOP_NUM0;
													break;
				
		}
		
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
	}	
}




