
#include <stdlib.h>
#include <avr/io.h>
#include "BLdefComd.h"
#include "BLrxtx.h"
#include <avr/interrupt.h>



//uint32_t dutyCycle = 0;

uint8_t BluetoothMessage[6];
uint8_t bluetCommand;
uint16_t PWMvalue = 0;



void BL_GetMessage() // getting value from ring buffer to BlutoothMessage array
{
	
	for (int i=0; i<6; i++)
	{
		BluetoothMessage[i] = BL_GetChar();
	}
	BL_FlushRxBuf();  // flush our buffer and start from the beginning

}



void BL_DefComd()
{
	BL_GetMessage(); //pulling up buffer's data one by one
	if ((BluetoothMessage[0] == '-')|(BluetoothMessage[0] == '+'))
	{
		PWMvalue = atoi(BluetoothMessage+1); //convert our string into float integer	
	} 
		
}

