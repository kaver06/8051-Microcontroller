#include <reg52.h>
#define LCDPORT P2

sbit RS = P3^5;
sbit RW = P3^6;
sbit EN = P3^7;

void delay(unsigned char ms)
{
	unsigned char i;
	unsigned int j;
	for (i = 0; i < ms; i++)
		for(j = 0; j < 1275; j++);
}
void SendData(unsigned char dat)
{
	RS = 1;
	RW = 0;
	EN = 1;
	LCDPORT = dat; 
	EN = 0;
	delay(10);
	EN = 1;
}
void SendCommand(unsigned char cmd)
{
	RS = 0;
	RW = 0;
	EN = 1;
	LCDPORT = cmd;
	EN = 0;
	delay(10);
	EN = 1;
}
void WriteString(unsigned char *str)
{
	unsigned int i = 0;
	while(str[i] != '\0')
	{
		SendData(str[i]);
		i++;
	}
}

void InitializeLCD(void)
{
	LCDPORT = 0x00;

	RS = 0;
	RW = 0;
	EN = 0;
	SendCommand(0x38); 
	SendCommand(0x0C); 
	SendCommand(0x01); 
	SendCommand(0x06);
	SendCommand(0x80); 
}