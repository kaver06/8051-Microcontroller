#include <REGX51.h>

#define DACPORT P2


void main()
{
	int val = 0;
	DACPORT = 0x00;
	while(1)
	{
	 for(val = 0; val < 256; val++)
	 {
		 DACPORT = (unsigned char)val;
	 }
	}
}