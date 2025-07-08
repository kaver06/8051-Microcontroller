#include <REGX51.h>

void delay(unsigned char ms)
{
	unsigned int i;
	unsigned char j;
	for (i = 0; i < 1275; i++)
	for(j = 0; j < ms; j++);
}
void main()
{
	int i;
	P2 = 0x00;
	while(1)
	{
		P2=~0x55;
		delay(50);
		P2=~0xAA;
		delay(50);

	}
}