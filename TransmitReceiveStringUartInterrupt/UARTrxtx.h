
#ifndef UARTrxtx_H_
#define UARTrxtx_H_

#include <avr/io.h>


#define SIZE_BUF 32

extern uint8_t usartRxBuf[SIZE_BUF];
extern uint8_t rxBufTail;
extern uint8_t rxBufHead;
extern uint8_t rxCount;


extern uint8_t usartTxBuf[SIZE_BUF];
extern uint8_t txBufTail;
extern uint8_t txBufHead;
extern uint8_t txCount;


void USART_GetBluetMessage();

void USART_FlushRxBuf(void);

uint8_t USART_GetChar(void);

void USART_FlushTxBuf(void);

void USART_PutChar(uint8_t sym);

void USART_SendStr(uint8_t *data);

extern void USART_GetCurrentWeight();



#endif

