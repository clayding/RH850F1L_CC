#include "uart.h"

extern void (*fputc)(char c);
static void putc(char c);

void uart_init(void)
{
    UART_InitTypeDef uart;
	memset(&uart,0,sizeof(UART_InitTypeDef));
    uart.uartn      = 0;
    uart.baudrate   = 115200;
    uart.stop_bits  = 0;
    uart.parity     = 0;
    //Transmission interrupt is generated at the completion of transmission.
    uart.opt_un.param_bits.tx_int_timing = 1;

    UART_Init(&uart);

    fputc = putc;
}

void putc(char c)
{
    char ch = c;
    UART_Send_Data(0,(uint8_t*)&ch,1);
}
