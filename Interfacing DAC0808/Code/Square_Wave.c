#include <REGX51.h>

#define DACPORT P2

void Delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i = 0; i < ms; i++)
	 for(j = 0; j < 1275; j++);
}
void main()
{
	DACPORT = 0x00;
	while(1)
	{
	 DACPORT = ~DACPORT;
	 Delay(1);
	}
}