/*
 * IncFile1.h
 *
 * Created: 08.02.2016 7:29:16
 *  Author: Stas
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define SIZE_BUF 32

extern unsigned char usartRxBuf[SIZE_BUF];
extern unsigned char rxBufTail;
extern unsigned char rxBufHead;
extern unsigned char rxCount;



void UART_Init();

void ControlBottomValue();  

unsigned char usart_GetRxCount(void);

void USART_FlushRxBuf(void);

unsigned char USART_GetChar(void);


#endif /* INCFILE1_H_ */