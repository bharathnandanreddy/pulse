/*
* ATmega16_WIFI
* http://www.electronicwings.com
*
*/


#define F_CPU 8000000UL      /* Define CPU Frequency e.g. here its Ext. 12MHz */
#include <avr/io.h>         /* Include AVR std. library file */
#include <util/delay.h>       /* Include Delay header file */
#include <stdbool.h>        /* Include standard boolean library */
#include <string.h>         /* Include string library */
#include <stdio.h>          /* Include standard IO library */
#include <stdlib.h>         /* Include standard library */
#include <avr/interrupt.h>      /* Include avr interrupt header file */
#include "USART_RS232_H_file.h" 
#include "USART_RS232_C_file.h"   /* Include USART header file */

boolean DEBUG=1;


int main(void)
{
 

             /* initialize 16x2 LCD*/
                 /* initialize ADC*/
       USART_Init();
//  while(1)
//  {
//     static double oldValue = 0;
//
//    static double oldChange = 0;
//
//    int rawValue =ADC_Read(0);                                         // Reading the sensors values
//
//    double value = alpha * oldValue + (1 - alpha) * rawValue;         // calculating values using the formula
//
//
//
//
//     espData("heart beat : ", 1000, DEBUG);
//     
//
//     sprintf(Temperature,"%d  %d ", value,rawValue);/* convert integer value to ASCII string */
//     espData(Temperature, 1000, DEBUG);/* send string data for printing */
//     _delay_ms(100);
//     memset(Temperature,0,10);
//     oldValue = value;
//  }



  
  char *ids=(char *)malloc(sizeof(char)*60);

  espData("AT\x0D", 1000, DEBUG); 
_delay_ms(100);
 espData("AT+RST\x0D", 1000, DEBUG);
  _delay_ms(1000);
//  //Reset the ESP8266 module
 espData("AT+CWMODE=3\x0D", 1000, DEBUG);
  _delay_ms(100);
 
    //sprintf(ids, "AT+CWJAP=\"%s\",\"%s\"\x0D", mySSID, myPWD);
     

//Set the ESP mode as station mode
  espData("AT+CWJAP=\"d-link\",\"nandan111\"\x0D", 1000, DEBUG);   //Connect to WiFi network
  /*while(!esp.find("OK")) 
  {          
      //Wait for connection
  }*/
  _delay_ms(1000);
 espData("AT+CIPMUX=0\x0D", 1000, DEBUG);       //Allow multiple connections
     _delay_ms(100);
    espData("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\x0D", 1000, DEBUG);
     _delay_ms(1000);
   


  while(1)
  {

         

//USART_SendString("Value to be sent: ");
        // Send a random number between 1 and 1000
        char *sendData=(char *)malloc(sizeof(char)*60);
       // sprintf(sendData, "GET /update?api_key=%s&%s=12", myAPI, myFIELD);
    
      char *_atCommand=(char *)malloc(sizeof(char)*20);
    //sprintf(_atCommand, "AT+CIPSTART=\"TCP\",\"%s\",%s", myHOST, myPORT);


    
  
      espData("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\x0D", 1000, DEBUG);
     _delay_ms(100);
   //  memset(_atCommand, 0, 20);
  //sprintf(_atCommand, "AT+CIPSEND=%d", (strlen(sendData)+2));
//  _atCommand[19] = 0;
espData("AT+CIPSEND=50\x0D", 1000, DEBUG);
int i=97;
sprintf(_atCommand, "GET /update?api_key=7T2BG5UAK4Q3AYFS\&field1=%d\x0D", i);
 
espData(_atCommand, 1000, DEBUG);

 i+=20;


  
//   USART_SendString("Value to be sent: ");
//   USART_SendString("12");
     

    _delay_ms(100);
      espData("AT+CIPCLOSE=0\x0D",1000,DEBUG);
          _delay_ms(1000);
   
  }

    _delay_ms(1000);
}

  char * espData(char *command, const int timeout, boolean debug)
{
 
  USART_SendString(command);
  USART_SendString("\n");
  
  char *response = "";

  return response;
}

char * read_String(){
int   i=0;
  char * a=(char *)malloc(sizeof(char)*20);
  a[i++]=USART_RxChar();
  while(a[i]!='\0' && i<20)
  {
    a[i++]=USART_RxChar();
  }
  return a;
}
