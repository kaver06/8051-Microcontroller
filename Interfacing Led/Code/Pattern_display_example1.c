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
{
	int value[8]={1,2,4,8,16,32,64,128},i;
	LED_PORT = 0x00;
	while(1)
	{  	
		for (i= 0; i <= 8; i++) 
	   	{
			LED_PORT=~value[i];
			delay(100);
	   	}							
	}
//Alternartive code by finding the powers
	/*unsigned int count;
	unsigned int result;
	while(1)
	{  	result=1;
		LED_PORT = 0x00;
		LED_PORT=~result;
		delay(100);
		for (i= 0x00; i <= 0x08; i++) 
	   	{
	    	result *= 2;
			LED_PORT=~result;
			delay(100);
	   	}
	}*/
} 