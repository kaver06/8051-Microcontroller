#include <REGX51.h>
#include <stdio.h>
#include <math.h>

#define LCDPORT P3
#define COMMAND 0x01
#define CHARACTER 0x02

sbit RS = P2^0;
sbit RW = P2^1;
sbit E = P2^2;

void Delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i = 0; i < ms; i++)
	 for(j = 0; j < 1275; j++);
}
void SendData(unsigned char dat, unsigned char type)
{
	if(type == COMMAND)
	 RS = 0;
	 else if(type == CHARACTER)
	 RS = 1;
	 RW = 0;
	 E = 1;

	 LCDPORT = dat;

	 E = 0;
	 Delay(10);
	 E = 1;
}
void WriteString(unsigned char *str)
{
 unsigned int i = 0;
 while(str[i] != '\0')
 {
 	SendData(str[i], CHARACTER);
 	i++;
 }
}
void InitializeLCD()
{
 SendData(0x38, COMMAND);
 SendData(0x0F, COMMAND);
 SendData(0x06, COMMAND);
 SendData(0x01, COMMAND);
 SendData(0x80, COMMAND);
}
void main()
{
 unsigned int theta;
 unsigned char buffer[50];

 LCDPORT = 0x00;

 RS = 0;
 RW = 0;
 E = 0;
 InitializeLCD();
 for(theta = 0; theta <= 360; theta++)
 {
	sprintf(buffer, "sin(%d) = %f",theta,
 	sin(theta*3.14159/180.0));
 	WriteString(buffer);
 	Delay(100);
 	SendData(0x01, COMMAND);
 	SendData(0x80, COMMAND);
 }
 while(1);
} 