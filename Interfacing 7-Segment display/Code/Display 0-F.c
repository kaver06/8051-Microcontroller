#include <REGX51.h>

unsigned char displayCodes [16] = {	0x3F,0x06,0x5B,0x4F,
									0x66,0x6D,0x7D,0x07,
									0x7F,0x67,0x77,0x7c, 
									0x39,0x5E,0x79,0x71};
void Delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i = 0; i < ms; i++)
		for(j=0; j < 1275; j++);
}
 
void main()
{
	int count;
	P2 = 0x00;
	while (1)
	{
		for(count = 0; count < 16; count++)
		{
			P2=displayCodes[count];
			Delay(100);
		}
	}
}