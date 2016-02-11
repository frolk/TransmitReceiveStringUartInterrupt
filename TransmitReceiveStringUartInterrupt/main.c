#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "UARTrxtx.h"
#include "UartInit.h"
#include "PWM.h"

int main(void) // main function do something
{
	
	
	sei();
	//
	UART_Init(MYUBRR);
	//
	//uint8_t txMessage[16] = "Hello World!\r\n";
	
	PWM_Init();
	
	while(1)
	{
		
				if ((usartRxBuf[rxBufTail-1] == 0x0A) && (rxCount > 0))
					{
						USART_GetBluetMessage();
					}
					
					if(bluetCommand)
					{
						OCR0A = bluetCommand;
					}
		
		//if (txCount == 0)	
		//{				
			//USART_SendStr(txMessage);
		//}
		
	}
}

