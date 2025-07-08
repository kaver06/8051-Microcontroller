void InitializeLCD(void);
void WriteString(unsigned char *str);
void delay(unsigned char ms);
void adc_conversion();
void read_adc();
void SendData(unsigned char dat);
void SendCommand(unsigned char cmd);
void display(void);