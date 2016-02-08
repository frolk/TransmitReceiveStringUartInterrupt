
#include "UartInit.h"
#include <avr/io.h>


void UART_Init(unsigned int ubrr) // initialize UART
{
	//set baud rate = 9600bps
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	//set ; stop bit, no parity bit and 8 bit character size
	UCSR0C = 0x06;
	
	//enable transmission and reception
	UCSR0B = 0x18;
	UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0);
	
}
