
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "GetWeight.h"
#include "UARTrxtx.h"



uint8_t usartTxBuf[SIZE_BUF];
uint8_t txBufTail = 0;
uint8_t txBufHead = 0;
uint8_t txCount = 0;
uint8_t txMessage[16]; // Transmit variables

uint8_t usartRxBuf[SIZE_BUF];
uint8_t rxBufTail = 0;
uint8_t rxBufHead = 0;
uint8_t rxCount = 0;
uint8_t rxMessage[16]; // Receive variables

//float CurrentWeight = 0;
//float DetectValue;

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

ISR (USART_TX_vect)   // transmit interrupt routine
{
	if(txCount) > 0 
	{
		UDR0 = usartTxBuf [txBufHead]; // take one byte from buffer and put it into transmit register
		txCount--;
		txBufHead++;
		if(txBufHead == SIZE_BUF) txBufHead = 0; 
		
	}
}


void USART_PutChar(uint8_t sym)// write next symbol into ring buffer
{
	if (((UCSR0A & (1<<UDRE0)) != 0) && (txCount == 0)) UDR0 = sym; // if udr is empty and it's first byte from
																	// ring buffer we write it directly into udr
    else
	{
		if (txCount < SIZE_BUF)
		{
			usartTxBuf[txBufTail] = sym; // second and the next bytes we write into ring buffer with txBufTaail pointer
			txCount++;  // increase variable that tells us how much unread data locate in ring buffer
			txBufTail++; // increase our pointer
			if (txBufTail == SIZE_BUF) txBufTail = 0; // if pointer reached end of buffer - reset it
	
		}
	}
}

//void ControlBottomValue()   // function for detecting value of weight
//{
	//DDRB |= (1<<PORTB3);
	//if (CurrentWeight>3.5)
	//{
		//PORTB |= (1<<PORTB3);
	//}
	//else
	//{
		//PORTB &=~ (1<<PORTB3);
	//}
	//
//} //bottom control function from previous version of this file


void USART_FlushRxBuf(void)  // flush our ring buffer after getting all of the array's member in out CurrentValue variable
{
	rxBufTail = 0;
	rxBufHead = 0;
	rxCount = 0;
}

uint8_t USART_GetChar(void) // take one symbol from buffer using the Head pointer
{
	uint8_t sym;
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
		rxMessage[i] = USART_GetChar();
	}
	USART_FlushRxBuf();  // flush our buffer and start from the beginning
	CurrentWeight = atof(rxMessage+6); //convert our string into float integer
	ControlBottomValue(); // compare the value of variable currentweight with set value (1.5 kg for instance)
	
}