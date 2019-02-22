/**
  ******************************************************************************
  * @file    stm8s_it.c
  * @author   MCD Application Team
  * @version  V2.0.0
  * @date     25-February-2011
  * @brief    Main Interrupt Service Routines.
  *           This file provides template for all peripherals interrupt service
  *           routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s_it.h"
#include "stm8s.h"
#include "stm8s_spi.h"
#include "stm8s_gpio.h"
#include "stm8s_clk.h"
#include "stm8s_exti.h"
#include "stm8s_uart1.h"
#include "led.h"
#include "uart.h"
#include "tim1.h"
#include "key.h"
#include "TimeOut.h"
#include "mass.h"

extern unsigned int u8TimeLock;

uint8_t UART1_GET_BUF;
bsp_status BSP_STATUS;



#if 1
int Led_Status()
{
  if(BSP_STATUS.Light_Status == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Heat_Mode_Status()
{
  if(BSP_STATUS.Heat_Status == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Push_A1_Mode_Status()
{
   if(BSP_STATUS.Pushrod_A1_Status == 1)
   {
     return 1;
   }
   else
   {
     return 2;
   }
}

int Push_A2_Mode_Status()
{
    if(BSP_STATUS.Pushrod_A2_Status == 1)
   {
     return 1;
   }
   else
   {
     return 3;
   }
}

int Push_B1_Mode_Status()
{
    if(BSP_STATUS.Pushrod_B1_Status == 1)
   {
     return 1;
   }
   else
   {
     return 5;
   }
}

int Push_B2_Mode_Status()
{
    if(BSP_STATUS.Pushrod_B2_Status == 1)
   {
     return 1;
   }
   else
   {
     return 4;
   }
}

int Push_C1_Mode_Status()
{
    if(BSP_STATUS.Pushrod_C1_Status == 1)
   {
     return 1;
   }
   else
   {
     return 2;
   }
}

int Push_C2_Mode_Status()
{
   if(BSP_STATUS.Pushrod_C2_Status == 1)
   {
     return 1;
   }
   else
   {
     return 2;
   }
}
#if 1
int Pushrod_All_Mode_Stop_Status()
{
  #if 1
  if((BSP_STATUS.Pushrod_A1_Status == 0)||(BSP_STATUS.Pushrod_A2_Status == 0)||(BSP_STATUS.Pushrod_B2_Status == 0)||(BSP_STATUS.Pushrod_reset == 0)||(BSP_STATUS.Pushrod_B1_Status == 0)||(BSP_STATUS.Pushrod_C1_Status == 0)||(BSP_STATUS.Pushrod_C2_Status == 0))
  {
     return 1;
  }
  else
  {
     return 2;
  }
  #endif
}
#endif
int Pushrod_reset_Mode_Status()
{
    if(BSP_STATUS.Pushrod_reset == 1)
   {
     return 1;
   }
   else
   {
     return 2;
   }
}
int Mass_Mode_Status()
{
   if(BSP_STATUS.Mass_Status == 1)
   {
     return 1;
   }
   else
   {
     return 0;
   }
}
#endif

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
  * @brief Dummy Interrupt routine
  * @par Parameters:
  * None
  * @retval
  * None
*/
INTERRUPT_HANDLER(NonHandledInterrupt, 25)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*_COSMIC_*/

/**
  * @brief TRAP Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
/**
  * @brief Top Level Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TLI_IRQHandler, 0)

{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Auto Wake Up Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Clock Controller Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTA Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTB Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTC Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTD Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTE Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#ifdef STM8S903
/**
  * @brief External Interrupt PORTF Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(EXTI_PORTF_IRQHandler, 8)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /*STM8S903*/

#if defined (STM8S208) || defined (STM8AF52Ax)
/**
  * @brief CAN RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_RX_IRQHandler, 8)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

/**
  * @brief CAN TX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_TX_IRQHandler, 9)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /*STM8S208 || STM8AF52Ax */

/**
  * @brief SPI Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Timer1 Update/Overflow/Trigger/Break Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
  //TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
  //TimingDelay_Decrement();
  //if(u8TimeLock != 0x00) u8TimeLock--; //
}

/**
  * @brief Timer1 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#ifdef STM8S903
/**
  * @brief Timer5 Update/Overflow/Break/Trigger Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_UPD_OVF_BRK_TRG_IRQHandler, 13)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
/**
  * @brief Timer5 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_CAP_COM_IRQHandler, 14)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */
/**
  * @brief Timer2 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

/**
  * @brief Timer2 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /*STM8S903*/

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S105) || defined (STM8AF62Ax) ||\
    defined (STM8AF52Ax) || defined (STM8AF626x)
/**
  * @brief Timer3 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

/**
  * @brief Timer3 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /*STM8S208, STM8S207 or STM8S105 or STM8AF62Ax or STM8AF52Ax or STM8AF626x */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S103) || defined (STM8AF62Ax) ||\
    defined (STM8AF52Ax) || defined (STM8S903)
/**
  * @brief UART1 TX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
/**
  * @brief UART1 RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
 {
   while(UART1_GetITStatus(UART1_IT_RXNE) == RESET);
   UART1_GET_BUF = UART_Recive();

#if 1
   switch (UART1_GET_BUF)
   {
     case 0x12:

               BSP_STATUS.Pushrod_A1_Status = 1;
               break;
     case 0x01:

               BSP_STATUS.Pushrod_A2_Status = 1;
               break;
     case 0x02:

               BSP_STATUS.Pushrod_B2_Status = 1;
               break;
     case 0x09:
	 	       BSP_STATUS.Pushrod_reset = 1;
               break;
     case 0x11:
               if(BSP_STATUS.Light_Flag == 0)
               {
                 BSP_STATUS.Light_Flag = 1;
                 BSP_STATUS.Light_Status = 1;
                 int Led_Status();
               }
               else
               {
                 BSP_STATUS.Light_Flag = 0;
                 BSP_STATUS.Light_Status = 0;
                 int Led_Status();
               }
               break;
	 case 0x16:
	 	       BSP_STATUS.Pushrod_C2_Status = 1;
	 	       break;
     case 0x17:
               BSP_STATUS.Pushrod_B1_Status = 1;
               break;
     case 0x20:
               if(BSP_STATUS.Heat_Flag == 0)
               {
                  BSP_STATUS.Heat_Flag = 1;
                  BSP_STATUS.Heat_Status = 1;
                  int Heat_Mode_Status();
               }
               else
               {
                  BSP_STATUS.Heat_Flag = 0;
                  BSP_STATUS.Heat_Status = 0;
                  int Heat_Mode_Status();
               }
               break;
     case 0x21:
	 	       //Pushrod_C1_Status = 1;
               if(BSP_STATUS.Mass_Flag == 0)
               {
                 BSP_STATUS.Mass_Flag = 1;
                 BSP_STATUS.Mass_Status = 1;
                 int Mass_Mode_Status();
               }
               else
               {
                 BSP_STATUS.Mass_Flag = 0;
                 BSP_STATUS.Mass_Status = 0;
                 int Mass_Mode_Status();
               }

               break;
     case 0x55:
	 	       #if 1
               BSP_STATUS.Pushrod_A1_Status = 2;
               BSP_STATUS.Pushrod_A2_Status = 2;
               BSP_STATUS.Pushrod_B2_Status = 2;
			   BSP_STATUS.Pushrod_C1_Status = 2;
			   BSP_STATUS.Pushrod_C2_Status = 2;
               BSP_STATUS.Pushrod_reset = 2;
               BSP_STATUS.Pushrod_B1_Status = 2;
               //Pushrod_All_Stop_Status = 1;
			   #endif
               break;
     default:
               /************震动马达复位****************/
               BSP_STATUS.Mass_Flag = 0;
               BSP_STATUS.Mass_Status = 0;
               int Mass_Mode_Status();
               /***********发热布复位******************/
               BSP_STATUS.Heat_Flag = 0;
               BSP_STATUS.Heat_Status = 0;
               int Heat_Mode_Status();
               /************脚灯复位*******************/
               BSP_STATUS.Light_Flag = 0;
               BSP_STATUS.Light_Status = 0;
               int Led_Status();
               break;

   }
#endif

 }
#endif /*STM8S208 or STM8S207 or STM8S103 or STM8S903 or STM8AF62Ax or STM8AF52Ax */

/**
  * @brief I2C Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined (STM8S105) || defined (STM8AF626x)
/**
  * @brief UART2 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART2 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /* STM8S105 or STM8AF626x */

#if defined(STM8S207) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief UART3 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_TX_IRQHandler, 20)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART3 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_RX_IRQHandler, 21)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#if defined(STM8S207) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief ADC2 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC2_IRQHandler, 22)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#else /*STM8S105, STM8S103 or STM8S903 or STM8AF626x */
/**
  * @brief ADC1 interrupt routine.
  * @par Parameters:
  * None
  * @retval
  * None
  */
 INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /*STM8S208 or STM8S207 or STM8AF52Ax or STM8AF62Ax */

#ifdef STM8S903
/**
  * @brief Timer6 Update/Overflow/Trigger Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM6_UPD_OVF_TRG_IRQHandler, 23)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#else /*STM8S208, STM8S207, STM8S105 or STM8S103 or STM8AF52Ax or STM8AF62Ax or STM8AF626x */
/**
  * @brief Timer4 Update/Overflow Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
  TimeOutDet_DecHandle();
  MassTimeHandle();

  //Led_reset();
 }
#endif /*STM8S903*/

/**
  * @brief Eeprom EEC Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
