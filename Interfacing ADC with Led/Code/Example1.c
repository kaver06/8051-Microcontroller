#include <reg52.h>

#define ADC_PORT P1
#define LED_PORT P2
			
unsigned char adc_data;

sbit rd = P3^0; 
sbit wr = P3^1; 
sbit intr = P3^2; 

void adc_conversion()
{ 
	wr = 0; 
	wr = 1; 
	while(intr); 
}
void read_adc()
{
	rd = 0; 
	adc_data = ADC_PORT; 
	rd = 1; 
}

void main()
{
	P2 = 0x00; 
	P1 = 0xFF;
	while(1)
	{
		adc_conversion();
		read_adc();
		LED_PORT = adc_data;
	}
}
