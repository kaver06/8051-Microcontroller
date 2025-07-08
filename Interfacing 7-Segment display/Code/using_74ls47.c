#include <REGX51.h>

sbit LT = P3^0;

void Delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i=0; i < ms; i++)
	for (j=0; j < 1275;j++);
}
void main()
{
	int count;

	P2 =0x00;
	LT = 0;

	LT = 0;
	Delay(1000) ;
	LT = 1;

	while(1)
	{
		for(count =0; count < 10; count++)
		{
			P2 = count;
			Delay(100);
		}
	}
}