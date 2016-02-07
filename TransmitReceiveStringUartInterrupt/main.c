#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define SIZE_BUF 32
unsigned char usartRxBuf[SIZE_BUF];
unsigned char rxBufTail = 0;
unsigned char rxBufHead = 0;
unsigned char rxCount = 0;
unsigned char Message[16];
float CurrentWeight = 0;
float DetectValue;



 //macros and variables

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
	sei();
}

ISR (USART_RX_vect)
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

void ControlBottomValue()
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

unsigned char usart_GetRxCount(void)
{
	return rxCount;
}

void USART_FlushRxBuf(void)
{
 	rxBufTail = 0;
	rxBufHead = 0;
	rxCount = 0;
}

unsigned char USART_GetChar(void)
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

void USART_GetCurrentWeight()
{
	
		for (int i=0; i<16; i++)
		{
			Message[i] = USART_GetChar();
		}
		USART_FlushRxBuf();
		CurrentWeight = atof(Message+6);
		ControlBottomValue();
	
}



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