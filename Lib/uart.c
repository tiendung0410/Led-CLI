#include "uart.h"
#include "string.h"
#include "cli_command.h"

#define MAX_DATA_UART	100

char uart_buff[MAX_DATA_UART];

static uint8_t uart_len =0;
uint8_t uart_flag =0;
void receive_data(uint8_t data_rx)
{
	if(data_rx == '\n')//nhan xong
	{
		uart_buff[uart_len++] = '\0';
		uart_flag = 1;
	}
	else//van dang nhan
	{
		uart_buff[uart_len++] = data_rx;
	}
}

void uart_handle()
{
	if(uart_flag)
	{
		 (uart_buff,uart_len);
		uart_len=0;
		uart_flag =0;
	}
}
void uart_init()
{
	
}
