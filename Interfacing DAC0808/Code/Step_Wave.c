#include <REGX51.h>

#define DACPORT P2

void delay(unsigned int ms)
{
	int i,j;
	for(i=0;i<ms;i++)
		for(j=0;j<1275;j++);
}

void main()
{
	int new_val;
	int val;
	DACPORT = 0x00;

	while(1)
	{
		for(val = 0; val < 256;val+=42.6)
		 {
		 	 DACPORT =val ;
			 new_val=val;
		 }
		 for(val = new_val; val >=0; val-=42.6)
		 {
		 	 DACPORT =val ;
		 }
	}
}