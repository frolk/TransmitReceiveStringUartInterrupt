#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>


#include "UARTrxtx.h"
#include "UartInit.h"


uint8_t rxMessage[16]; 

int main(void) // main function do something
{
	
	
	sei();
	
	UART_Init(MYUBRR);
	
	uint8_t txMessage[16] = "Hello World!";
	
	while(1)
	{
		
		USART_SendStr(txMessage);
		
	}
}

