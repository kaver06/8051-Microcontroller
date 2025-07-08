#include <REGX51.h>

#define LED_PORT P2

void Delay(unsigned char ms)
	{
	unsigned int i;
	unsigned char j;
	for (i = 0; i < 1275; i++)
	for(j = 0; j < ms; j++);
}
void main()
{
	unsigned int count;
	unsigned int product;
	LED_PORT = 0x00;
	while(1)
	{
		for(count = 0x01; count <= 0x0A; count++)
		{
			product=0x5*count;
			LED_PORT = ~product;
			Delay(100);
		}
	}
}