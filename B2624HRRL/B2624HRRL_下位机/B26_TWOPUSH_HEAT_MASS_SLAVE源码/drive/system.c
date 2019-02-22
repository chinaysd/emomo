#include "stm8s.h"
#include "system.h"
//static unsigned char around = 0;
unsigned int u8TimeLock=0;
extern unsigned char share_time_flag;

void System_Init(void)
{

  TimeOutDet_Init();
  Push_Init();
  Led_Init();
  Heat_Init();
  Key_Init();
  Mass_Init();
  Mass_Deinit();
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
  USART_Configuration();//串口配置
  Push_All_Close();
  //Tim1_Init();
  tim4_init();
  enableInterrupts(); //开启中断
}
void System_Handle(void)
{
      /********所有推杆********************/
static unsigned char data = 0;
switch (data)
{
    case 0:
			if((Key5_Down(GPIOD,GPIO_PIN_2) == 0)&&(Key6_Down(GPIOD,GPIO_PIN_3) == 0))////////********有问题A推杆
			{

				if(Push_A1_Mode_Status() == 1)
				{
				Push_A1_Open();
				}
				else if(Push_A2_Mode_Status() == 1)
				{
				Push_A2_Open();
				}
				else if(Push_B2_Mode_Status() == 1)
				{
				Push_B1_Open();
				}
				else if(Push_B1_Mode_Status() == 1)
				{
				Push_B2_Open();
				}
				else if(Pushrod_reset_Mode_Status() == 1)
				{
				Push_A1_B2_Reset();
				}
				else
				{
				Push_All_Close();
				}
				if(Led_Status() == 1)
				{
				Led_Open();
				}
				else
				{
				Led_Close();
				}
				if(Heat_Mode_Status() == 1)
				{
				   Heat_Open();
				}
				else
				{
				  Heat_Close();
				}
				if(Mass_Mode_Status() == 1)
				{
				  Mass_Handle();
				}
				else
				{
				  Mass_Deinit();
                }

			}
		   data = 1;
		   break;

    case 1:
		    if((Key5_Down(GPIOD,GPIO_PIN_2) == 1)&&(Key6_Down(GPIOD,GPIO_PIN_3) == 1))
	        {
  						    if(Push_A1_Mode_Status() == 1)
							{
								Push_A2_Open();
							}
							else if(Push_A2_Mode_Status() == 1)
							{
							    Push_A1_Open();
							}
							else if(Push_B2_Mode_Status() == 1)
							{
							    Push_B2_Open();
							}
							else if(Push_B1_Mode_Status() == 1)
							{
							    Push_B1_Open();
							}
							else if(Pushrod_reset_Mode_Status() == 1)
							{
							   Push_A2_B1_Reset();
							}
							else
							{
							   Push_All_Close();
							}
							if(Led_Status() == 1)
							{
							  Led_Open();
							}
							else
							{
							  Led_Close();
							}
							if(Heat_Mode_Status() == 1)
							{
							   Heat_Open();
							}
							else
							{
							  Heat_Close();
							}
							if(Mass_Mode_Status() == 1)
							{
							  Mass_Handle();
							}
							else
							{
							  Mass_Deinit();
			                }
	        }
		   data = 2;
		   break;
   case 2:
   	       if((Key6_Down(GPIOD,GPIO_PIN_3) == 0)&&(Key5_Down(GPIOD,GPIO_PIN_2) == 1))////////********有问题A推杆
	        {
					   if(Push_A1_Mode_Status() == 1)
			           {
			                Push_A2_Open();
			           }
					   else if(Push_A2_Mode_Status() == 1)
					   {
					        Push_A1_Open();
					   }
					   else if(Push_B1_Mode_Status() == 1)
					   {
					        Push_B2_Open();
					   }
                       else if(Push_B2_Mode_Status() == 1)
                       {
                            Push_B1_Open();
                       }
					   else if(Pushrod_reset_Mode_Status() == 1)
					   {
					        Push_A1_B1_Reset();
					   }
					   else
					   {
					        Push_All_Close();
                       }
					   if(Led_Status() == 1)
		               {
		                 Led_Open();
		               }
		               else
		               {
		                 Led_Close();
		               }
					    if(Heat_Mode_Status() == 1)
						{
						   Heat_Open();
						}
						else
						{
						  Heat_Close();
						}
						if(Mass_Mode_Status() == 1)
						{
						  Mass_Handle();
						}
						else
						{
						  Mass_Deinit();
		                }
		             }
		    data = 3;
		    break;
	case 3:
		    if((Key6_Down(GPIOD,GPIO_PIN_3) == 1)&&(Key5_Down(GPIOD,GPIO_PIN_2) == 0))
		    {
						  if(Push_A1_Mode_Status() == 1)
						  {
							   Push_A1_Open();
						  }
						  else if(Push_A2_Mode_Status() == 1)
						  {
						       Push_A2_Open();
						  }
						  else if(Push_B1_Mode_Status() == 1)
						  {
						       Push_B1_Open();
						  }
						  else if(Push_B2_Mode_Status() == 1)
						  {
						       Push_B2_Open();
						  }
						  else if(Pushrod_reset_Mode_Status() == 1)
						  {
						       Push_A2_B2_Reset();
						  }
						  else
						  {
						       Push_All_Close();
						  }
						  if(Led_Status() == 1)
						  {
							Led_Open();
						  }
						  else
						  {
							Led_Close();
						  }
						if(Heat_Mode_Status() == 1)
						{
						   Heat_Open();
						}
						else
						{
						  Heat_Close();
						}
						if(Mass_Mode_Status() == 1)
						{
						  Mass_Handle();
						}
						else
						{
						  Mass_Deinit();
		                }
		    }
            data = 0;
		    break;
	default:break;
    }
}
