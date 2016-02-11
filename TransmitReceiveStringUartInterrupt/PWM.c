
#include <avr/io.h>
#include "PWM.h"
#include <avr/interrupt.h>

//uint32_t dutyCycle = 0;



void PWM_Init()
{
	DDRD = (1 << PORTD6);
	TCCR0A = (1<<COM0A1)|(1<<WGM00)|(1<<WGM01); // 0x83 Fast PWM
	sei();	
	TCCR0B = (1 << CS00);
}

