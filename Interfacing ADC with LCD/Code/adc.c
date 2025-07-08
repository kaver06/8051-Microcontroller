#include <reg52.h>
#include <globals.h>

#define adc_port P1

unsigned char adc_data;
sbit rd = P3^0; 
sbit wr = P3^1; 
sbit intr = P3^2; 
sbit cs = P3^3; 

void adc_conversion()
{
	cs = 0;
	wr = 0; 
	wr = 1; 
	cs = 1; 
	while(intr); 
}
void read_adc()
{
	cs = 0; 
	rd = 0; 
	adc_data = adc_port;
	rd = 1; 
	cs = 1;
}
void display(void)
{
	unsigned int digit_array[3],digit;
	
	digit = (adc_data / 100u) % 10u;
	digit_array[2] = digit + 0x30;
	
	digit = (adc_data / 10u) % 10u;
	digit_array[1] = digit + 0x30;
	
	digit = adc_data % 10u;
	digit_array[0] = digit + 0x30;
	SendData(digit_array[2]);
	delay(2);
	SendData(digit_array[1]);
	delay(2);
	SendData(digit_array[0]);
	delay(2);
	SendCommand(0x8C); 
	delay(2);
}