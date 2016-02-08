#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "GetWeight.h"
#include "UartInit.h"




int main(void) // main function do something
{
	sei();
	
	UART_Init();
	
	
	while(1)
	{
		if ((usartRxBuf[rxBufTail-1] == 0x0A) && (rxCount > 0) && (usartRxBuf[rxBufHead] == 'S')) 
		{
			
		USART_GetCurrentWeight();  // here we getting current weight
		}
	}
}

// this is second change
