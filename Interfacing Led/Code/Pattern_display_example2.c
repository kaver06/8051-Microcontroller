#include <REGX51.h>

#define LED_PORT P2
void delay(unsigned char ms)
	{
	unsigned int i;
	unsigned char j;
	for (i = 0; i < 1275; i++)
	for(j = 0; j < ms; j++);
}
void main()
{	int i;
	LED_PORT = 0x00;
	while(1)
	{  	
		LED_PORT=0xFF;
		for (i= 0; i <= 8; i++) 
	   	{
		  LED_PORT&=~(1<<i);
		  delay(100);
	   	}							
	}
} 