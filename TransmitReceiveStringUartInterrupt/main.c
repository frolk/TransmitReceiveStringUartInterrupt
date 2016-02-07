#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

int main(void)
{
	UART_Init();
	
	
	while(1)
	{
		if ((usartRxBuf[rxBufTail-1] == 0x0A) && (rxCount > 0) && (usartRxBuf[rxBufHead] == 'S')) 
		{
			
		USART_GetCurrentWeight(); 
		}
	}
}