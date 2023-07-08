#include<STC89C5xRC.H>
#define __UART_H__
void UART_Init();
void UART_SendByte(unsigned  char Byte);
void UART_SendString(char * string);

