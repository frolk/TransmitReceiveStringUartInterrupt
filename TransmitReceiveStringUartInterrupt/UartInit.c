
#include "UartInit.h"
#include <avr/io.h>

//
//#define FOSC 16000000// Clock Speed
//#define BAUD 9600
//#define MYUBRR FOSC/16/BAUD-1

//void UART_Init( unsigned int ubrr)
//{
	///*Set baud rate */
	//UBRR0H = (unsigned char)(ubrr>>8);
	//UBRR0L = (unsigned char)ubrr;
	///*Enable receiver and transmitter */
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	///* Set frame format: 8data, 1stop bit */
	//UCSR0C = (3<<UCSZ00);
	//sei();
	//}

void UART_Init() // initialize UART
{
	//set baud rate = 9600bps
	UBRR0H = 0x00;
	UBRR0L = 0x67;
	
	//set 1 stop bit, no parity bit and 8 bit character size
	UCSR0C = 0x06;
	
	//enable transmission and reception
	UCSR0B = 0x18;
	UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0);
	
} // my old uart init
