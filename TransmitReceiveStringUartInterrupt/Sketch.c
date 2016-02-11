
#include "Sketch.h"


void ControlBottomValue()   // function for detecting value of weight
{
	DDRB |= (1<<PORTB3);
	if (rxCurrentWeight>3.5)
	{
		PORTB |= (1<<PORTB3);
	}
	else
	{
		PORTB &=~ (1<<PORTB3);
	}
	
}

void BL_GetCurrentWeight() // getting weight value from ring buffer
{
	
	for (int i=0; i<16; i++)
	{
		rxMessage[i] = BL_GetChar();
	}
	BL_FlushRxBuf();  // flush our buffer and start from the beginning
	rxCurrentWeight = atof(rxMessage+6); //convert our string into float integer
	ControlBottomValue(); // compare the value of variable currentweight with set value (1.5 kg for instance)
	
}

