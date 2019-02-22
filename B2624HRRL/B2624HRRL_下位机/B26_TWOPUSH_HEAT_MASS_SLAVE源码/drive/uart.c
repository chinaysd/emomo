#include "uart.h"
#include <stdarg.h>
#include <stdio.h>

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/

void USART_Configuration(void)//���ڳ�ʼ������
  {

    UART1_DeInit();
    UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, \
    UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_RX_ENABLE);//�����ʣ��ֽ�����1��ֹͣλ������żЧ��λ����ͬ��ģʽ��������ܺͷ���
   // UART1_Init((u32)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_RX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE,ENABLE  );//���óɽ����ж�
    UART1_Cmd(ENABLE );
   }

void UART_send_byte(uint8_t byte) //����1�ֽ�����
{
    UART1_SendData8((unsigned char)byte);
  /* Loop until the end of transmission */
   while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);//��������Ϊ��
}

void UART_Send(uint8_t *Buffer, uint16_t Length)
{
  uint16_t l= 0;
  for(;l<Length;l++)
    UART_send_byte(Buffer[l]);
}

uint8_t UART_Recive(void)
{
      uint8_t UART1_Re_Buf;
     while (UART1_GetFlagStatus(UART1_FLAG_RXNE) == RESET);//�������ݼĴ����ǿ�
     UART1_Re_Buf=UART1_ReceiveData8();
     return  UART1_Re_Buf;
}


PUTCHAR_PROTOTYPE ////����һ���ַ�Э��
{
/* ��Printf���ݷ������� */
  UART1_SendData8((unsigned char) ch);
  while (!(UART1->SR & UART1_FLAG_TXE));//�������δ��ɣ� //��־λδ��λ����ѭ���ȴ�
  return (ch);

}


