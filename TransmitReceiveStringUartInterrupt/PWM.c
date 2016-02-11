
#include <avr/io.h>
#include "BLdefComd.h"


void PWM_Init()
{
	DDRD = (1 << PORTD6);
	TCCR0A = (1<<COM0A1)|(1<<WGM00)|(1<<WGM01); // 0x83 Fast PWM
	TCCR0B = (1 << CS00);	
}


void PWM_PinValue()
{
	OCR0A = PWMvalue;		
	PWMvalue = 0;
}
