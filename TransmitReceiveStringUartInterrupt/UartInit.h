
#ifndef UARTINIT_H_
#define UARTINIT_H_

	
#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


UART_Init void(unsigned int ubrr); // initialize UART

#endif /* UARTINIT_H_ */