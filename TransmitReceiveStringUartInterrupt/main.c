#include <avr/io.h>
#include <avr/interrupt.h>


#include "BLrxtx.h" // ring buffer routine
#include "BLdefComd.h" // define bluetooth command
#include "PWM.h"

int main(void) // main function do something
{
	
	//uint8_t txMessage[16] = "Hello World!\r\n";
	BL_Init(MYUBRR);
	PWM_Init();
	
	while(1)
	{
		if (BLmesIsComplete)  // if the last got byte is 0x0A (LF)
		{
			BL_DefComd();
			BLmesIsComplete = 0;
		}
			
		if (PWMvalue)
		{			
			PWM_PinValue();
		}
					
		//if (txCount == 0)	
		//{				
			//BL_SendStr(txMessage);
		//}
		
	}
}

