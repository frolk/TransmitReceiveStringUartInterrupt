
#include "UartInit.h"
#include <avr/io.h>


void UART_Init(unsigned int ubrr) // initialize UART
{
	//set baud rate = 9600bps
	UBRR0H = (uint8_t)(ubrr>>8);
	UBRR0L = (uint8_t)ubrr;
	
	//set 1 stop bit, no parity bit and 8 bit character size
	UCSR0C = 0x06;  // (1<<UCSZ01)|(1<<UCSZ00)
	
	//enable transmission and reception 0x78
	UCSR0B |= (1<<RXCIE0)|(1<<TXCIE0)|(1<<RXEN0)|(1<<TXEN0); 
	
	
}
