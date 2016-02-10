
#ifndef INCFILE1_H_
#define INCFILE1_H_

#define SIZE_BUF 32

extern uint8_t usartRxBuf[SIZE_BUF];
extern uint8_t rxBufTail;
extern uint8_t rxBufHead;
extern uint8_t rxCount;


extern uint8_t usartTxBuf[SIZE_BUF];
extern uint8_t txBufTail = 0;
extern uint8_t txBufTail = 0;
extern uint8_t txCount = 0;
extern uint8_t txMessage[16];


void UART_Init();

//void ControlBottomValue();  

uint8_t usart_GetRxCount(void);

void USART_FlushRxBuf(void);

//uint8_t USART_GetChar(void);

void USART_FlushTxBuf(void);

void USART_PutChar(uint8_t sym);

void USART_SendStr(uint8_t *data);



#endif 