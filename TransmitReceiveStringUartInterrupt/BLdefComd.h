
#ifndef BLdefComd_H_
#define BLdefComd_H_


extern void BL_DefComd();  // define bluetooth command

void BL_GetMessage();

uint8_t BL_msg[16]; // bluetooth message

extern uint16_t PWMvalue;
extern uint8_t bluetCommand;
	
void UART_Init (unsigned int ubrr); // initialize UART


#endif 

