
#ifndef UARTINIT_H_
#define UARTINIT_H_


#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void UART_Init(unsigned int ubrr); // initialize UART

#endif /* UARTINIT_H_ */