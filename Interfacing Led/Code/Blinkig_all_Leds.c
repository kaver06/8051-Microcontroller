#include <REGX51.h>

void Delay(unsigned char ms)
{
	unsigned int i;
	unsigned char j;
	for (i = 0; i < 1275; i++)
	for(j = 0; j < ms; j++);
}
void main()
{
	P2 = 0x00;
	while(1)
	{
		P2 = 0x00;
		Delay(100);
	
		P2 = 0xFF;
		Delay(100);
	}
}