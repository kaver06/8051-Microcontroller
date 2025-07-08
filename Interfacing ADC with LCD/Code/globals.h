extern void InitializeLCD(void);
extern void WriteString(unsigned char *str);
extern void delay(unsigned char ms);
extern void adc_conversion();
extern void read_adc();
extern void SendData(unsigned char dat);
extern void SendCommand(unsigned char cmd);
extern void display(void);