#include	"h\SC91F831_C.h"
#include	"config.h"
#include	"key.h"
#include	"init.h"
#include    "intrins.h"
#include	"command.h"


INT8U 	   KeyDebunce=0;				  //按键消抖
bit		   KeystatusFlag=0;			      //按键状态标志

bit		 TouchKey_Flag = enable;          //上电初始化触摸按键有效
INT8U    u8LoadProgram = 0x0;
INT8U    keyStates[6]={0};

bit      Start_Counttime_A;
bit      Start_Counttime_B;
INT8U    Start_Counttime_Cnt;

INT8U key_press_flag,key_cnt_flag,heat_switch;
INT16U key_cnt,last_key,heat_switch_cnt;
INT8U  start_turnOnMassage,start_turnOnColdLight;
INT8U heat_cnt;
//TK4------	K4 -------推杆A降低				0x0010
//TK6------	K5 -------马达震动(推杆B升高)	0x0040
//TK7------	K6 -------制冷(推杆B降低)       0x0080
//TK13-----	K2 -------Light		            0x2000
//TK14-----	K3 -------推杆A升高	            0x4000
//K1 ------ P4.0
unsigned char Key_String[4];
unsigned int Cnt;
unsigned char Temp_Cnt,Only_One_Flag;

void Keyfunction(void)
{
   static unsigned int MyKey_Data;
//第一，第二套程序，HX25程序
	   if(Key_Buf!=0)	//键按下
	   {
	   	   if(++KeyDebunce>=2)				   //消抖
		   {
		      KeyDebunce=0;
		      if(!KeystatusFlag)
			  {
			  	 KeystatusFlag=1;
				 MyKey_Data=Key_Buf;			//获取按键的值	
				 switch(MyKey_Data)
				 {
				 	case 0x2000:	//TK13----- K2 -------Light	   0x2000
					{
					   if(last_key != 0x2000){
							last_key = 0x2000;
                            switch(Cnt)
                            {
                                case 0x00:
                                          turnOnBackLight();//0x01
                                          Cnt = 1;
                                          break;
                                case 0x01:
                                          turnOffBackLight();//0x02
                                          Cnt = 2;
                                          break;
                                case 0x02:
                                          turnOnColdLight();//0x04
                                          Cnt = 0;
                                          break;
                                default:
                                          Cnt = 0x00;
                                          break;
                            }
					   	}
					   break;
					}

					case  0x4000:	 //TK14-----K3 -------推杆A升高	  0x4000
					{//推杆A升					
					    //pushrodApushHigh();	//0X20
					    turnOffColdLight();//0x08
						Start_Counttime_A = enable;
						break;				
					}
				 
				 	case  0x0010: 	 //TK4------K4 -------推杆A降低	  0x0010
					{//推杆A降
						//pushrodApushLow();//0X40
						pushrodApushHigh();//0x10
						Start_Counttime_A = enable;
						break;
					}

					case  0x0040:    //TK6------K5 -------马达震动(推杆B升高)	0x0040
					{   
					    #if 0
						pushrodBpushHigh();//0XA0
					    Start_Counttime_B = enable;
					    #endif
					    break;					
					}
					case  0x0080:    //TK7------K6 -------制冷(推杆B降低)   0x0080
					{
				  	    //pushrodBpushLow();//0XC0
					    //Start_Counttime_B = enable;
					    #if 1
					    if(last_key != 0x0080)
					    {
					        last_key = 0x0080;
					        ++ Temp_Cnt;
    					    if(Temp_Cnt & 0x01)
    					    {
                                pushrodApushLow();//0x20
                                isColding = 1;
                                u16Cnt4hours = 0;
    					    }
    					    else
    					    {
    					        pushrodAFinish();//0x40
    					        isColding = 0;
                                u16Cnt4hours = 0;
    					    }
					    }
					    #endif
						break;
				    }					 
					default:break;
				 }			  
			  }			   
		   }	   
	   }	   
	   else	//无按键			
	   {
		  if(KeystatusFlag)		 //松手
		  {
			 KeystatusFlag =0;
			 switch(MyKey_Data)	    //单按键，松手有效
			 {
				case  0x2000:	  //TK13----- K2 -------Light	  0x2000
				{	
                    if(last_key == 0x2000)
                    {
                        last_key = 0;
                        
                    }
				    break;
				}

				case  0x4000:	  //TK14-----K3 -------推杆A升高  0x4000
				{ 
				    if(Start_Counttime_A == enable)
					{
						Start_Counttime_A = disable;
						Start_Counttime_Cnt =0;
						pushrodBpushLow();				
					}
				    break;
				}

				case  0x0010: 	  //TK4------K4 -------推杆A降低  0x0010
				{
				    if(Start_Counttime_A == enable)
					{
					    Start_Counttime_A = disable;
					    Start_Counttime_Cnt =0;
					    pushrodBpushLow();				
					}
				   	break;					  
				}  			
			    case  0x0040:      //TK6------K5 -------马达震动(推杆B升高)	0x0040
				{      
				       #if 0
					   if(Start_Counttime_B == enable)
					   {
						   Start_Counttime_B = disable;
						   pushrodBFinish();					
					   }
					   #endif
				    break;
				}
				case  0x0080:      //TK7------K6 -------制冷(推杆B降低)   0x0080
				{
				       #if 0
					   if(Start_Counttime_B == enable)
					   {
						   Start_Counttime_B = disable;
						   pushrodBFinish();					
					   }
					   #endif
					   if(last_key == 0x0080)
					   {
					      last_key = 0;
					   }
				       break;
				}					   
 	            default:break;						
			 }	
		  }
	      KeyDebunce=0;
	   }
  }


