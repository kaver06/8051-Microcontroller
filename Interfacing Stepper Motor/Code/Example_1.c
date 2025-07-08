#include <reg51.h>

#define MOTORPORT P2

unsigned char sequence[]={0x09, 0x03, 0x06, 0x0C};

void Delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i = 0; i < ms; i++)
	for(j = 0; j < 1275; j++);
}
void RotateClockWise(unsigned int angle)
{
	unsigned int steps = angle/1.8f;
	unsigned int i;
	for(i = 0; i < steps; i++)
	{
		MOTORPORT = sequence[i%4];
		Delay(10);
	}
}
void RotateAntiClockWise(unsigned char angle)
{
	unsigned int steps = angle/1.8f;
	unsigned int i;
	for(i = 0; i < steps; i++)
	{
		MOTORPORT = sequence[3 - i%4];
		Delay(10);
	}
}
void main()
{
	while(1)
	{
		RotateClockWise(180);
		RotateAntiClockWise(180);
	}
}