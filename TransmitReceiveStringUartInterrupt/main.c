#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "UARTrxtx.h"
#include "UartInit.h"


int main(void) // main function do something
{
	
	
	sei();
	
	UART_Init(MYUBRR);
	
	uint8_t txMessage[16] = "Hello World!\r\n";
	
	while(1)
	{
		if (txCount == 0)	
		{				
			USART_SendStr(txMessage);
		}
		
	}
}

