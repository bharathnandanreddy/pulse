/*
 * USART_RS232_C_file.c
 * http://www.electronicwings.com
 *
 */ 

#include "USART_RS232_H_file.h"            /* Include USART header file */

void USART_Init()       /* USART initialize function */
{
#ifdef DOUBLE_SPEED_MODE
  UCSRA =0;
#endif
  UCSRB=1<<TXEN | 1<<RXEN; /* Enable USART transmitter and receiver */
  UCSRC=1<<URSEL | 1<<UCSZ1 | 1<<UCSZ0; /* Write USCRC for 8 bit data and 1 stop bit */ 
  uint16_t ubrr=8;
  UBRRL = 5;              /* Load UBRRL with lower 8 bit of prescale value */
  UBRRH = 0;         /* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxChar()                 /* Data receiving function */
{
  while (!(UCSRA & (1 << RXC)));          /* Wait until new data receive */
  return(UDR);                  /* Get and return received data */ 
}

void USART_TxChar(char data)            /* Data transmitting function */
{
 while(!(UCSRA & (1<<UDRE)));
UDR=data;         /* Wait until data transmit and buffer get empty */
}

void USART_SendString(char *str)          /* Send string of USART data function */ 
{
    int i=0;                                  
  while (str[i]!=0)
  {
    USART_TxChar(str[i]);           /* Send each char of string till the NULL */
    i++;
  }
}
