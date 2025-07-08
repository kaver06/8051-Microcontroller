#include <reg52.h>
#include <globals.h>

void main()
{
	InitializeLCD();
	WriteString("ADC VALUE = ");
	delay(1);
	while(1)
	{
		adc_conversion();
		read_adc();
		display();
	}
}