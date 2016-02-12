
#include <stdlib.h>
#include <avr/io.h>
#include "BLdefComd.h"
#include "BLrxtx.h"
#include <avr/interrupt.h>



//uint32_t dutyCycle = 0;

uint8_t BL_msg[16];
uint8_t bluetCommand;
uint16_t PWMvalue = 0;



void BL_GetMessage() // getting value from ring buffer to BlutoothMessage array
{
	
	for (int i=0; i<16; i++)
	{
		BL_msg[i] = BL_GetChar();
		if (BL_msg[i] == 0x0A) break;
	}
	BL_FlushRxBuf();  // flush our buffer and start from the beginning

}



void BL_DefComd()
{
	BL_GetMessage(); //pulling up buffer's data one by one
	if ((BL_msg[0] == '-')|(BL_msg[0] == '+'))
	{
		PWMvalue = atoi(BL_msg+1); //convert our string into float integer	
	} 
		
}

