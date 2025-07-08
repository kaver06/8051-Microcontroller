#include <REGX51.h>
#include <math.h>

#define DACPORT P2

void main()
{
 unsigned int i;
 float value;

 DACPORT = 0x00;
 while(1)
 {
	 for(i = 0; i < 360; i++)
	 {
		 value = (unsigned char)((sin(i*3.14159f/180.0f)+ 1) * 127);
		 DACPORT = value;
	 }
 }
}