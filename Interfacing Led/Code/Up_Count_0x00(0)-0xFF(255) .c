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
	LED_PORT = 0x00;

	while(1)
	{
		for(count = 0x00; count <= 0xFF; count++)
		{
			LED_PORT = ~count;
			Delay(100);
		}
	}
}