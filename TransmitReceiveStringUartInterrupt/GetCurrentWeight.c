


void USART_GetCurrentWeight() // getting weight value from ring buffer
{
	
	for (int i=0; i<16; i++)
	{
		Message[i] = USART_GetChar();
	}
	USART_FlushRxBuf();  // flush our buffer and start from the beginning
	CurrentWeight = atof(Message+6); //convert our string into float integer
	ControlBottomValue(); // compare the value of variable currentweight with set value (1.5 kg for instance)
	
}