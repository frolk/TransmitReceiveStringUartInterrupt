
#include <avr/io.h>
#include "BLdefComd.h"


void PWM_Init()
{
	// setting up 8-bit timer/counter	
	DDRD = (1 << PORTD6);
	TCCR0A = (1<<COM0A1)|(1<<WGM00)|(1<<WGM01); // 0x83 Fast PWM
	TCCR0B = (1 << CS00);
	
	// setting up 16-bit timer/counter
	
	// set up the pin PB1(oc1A) like output
	DDRD = (1 << PORTB1);
	// set non-inverting mode and 10bit fast pwm (top = 0x3fff)
	TCCR1A = (1 << COM1A1)|(1 << COM1B1)|(1 << WGM10)|(1 << WGM11); 
	OCR1AH = 0x1F;
	OCR1AL = 0xFF;
	TCCR1B = (1 << WGM12)|(1 << CS10);
	
		
}





void PWM_PinValue()
{
	OCR0A = PWMvalue;		
	PWMvalue = 0;
}
