
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "GetWeight.h"


unsigned char usartRxBuf[SIZE_BUF];
unsigned char rxBufTail = 0;
unsigned char rxBufHead = 0;
unsigned char rxCount = 0;
unsigned char Message[16];
float CurrentWeight = 0;
float DetectValue;



//macros and variables


ISR (USART_RX_vect)   // interrupt routine
{
	if(rxCount < SIZE_BUF)
	{
		usartRxBuf[rxBufTail] = UDR0;
		rxBufTail++;
		if(rxBufTail == SIZE_BUF) rxBufTail = 0;
		rxCount++;
	}
}
//hello I added comment

void ControlBottomValue()   // function for detecting value of weight
{
	DDRB |= (1<<PORTB3);
	if (CurrentWeight>3.5)
	{
		PORTB |= (1<<PORTB3);
	}
	else
	{
		PORTB &=~ (1<<PORTB3);
	}
	
}

unsigned char usart_GetRxCount(void) // I don't know what is it for
{
	return rxCount;
}

void USART_FlushRxBuf(void)  // flush our ring buffer after getting all of the array's member in out CurrentValue variable
{
	rxBufTail = 0;
	rxBufHead = 0;
	rxCount = 0;
}

unsigned char USART_GetChar(void) // забираем из буфера по указателю башки по одному символу
{
	unsigned char sym;
	if(rxCount > 0)
	{
		sym	= usartRxBuf[rxBufHead];
		rxCount --;
		rxBufHead++;
		if(rxBufHead == SIZE_BUF) rxBufHead = 0;
		return sym;
	}
	return 0;
}

void USART_GetCurrentWeight() // getting weight value from ring buffer
{
	
	for (int i=0; i<16; i++)
	{
		Message[i] = USART_GetChar();
	}
	USART_FlushRxBuf();  // flush our buffer and start from the beginning
	CurrentWeight = atof(Message+6); //convert our string into float integer
	ControlBottomValue(); // compare the value of variable currentweight with set value (1.5 kg for instance)
	
}