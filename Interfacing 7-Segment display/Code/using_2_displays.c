#include <REGX51.h>

#define DATAPORT P2

sbit unit1 = P3^0;
sbit unit2 = P3^1;

code unsigned char displayCodes[16] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x98, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
};

void Delay(unsigned char ms)
{
    unsigned char i;
    unsigned int j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

void main()
{
    unsigned char oddNumber, i;

    DATAPORT = 0x00;
    unit1 = 0;
    unit2 = 0;

    while (1)
    {
        for (oddNumber = 1; oddNumber < 20; oddNumber += 2)
        {
            for (i = 0; i < 100; i++)
            {
                unit1 = 0;
                DATAPORT = displayCodes[oddNumber & 0x0F];
                unit2 = 1;
                Delay(1);

                unit2 = 0;
                DATAPORT = displayCodes[(oddNumber & 0xF0) >> 4];
                unit1 = 1;
                Delay(1);
            }
        }
    }
}
