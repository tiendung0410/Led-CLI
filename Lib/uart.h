#ifndef UART_H
#define UART_H

#include "stdint.h"
void receive_data(uint8_t c);
void uart_handle(void);
void uart_init(void);
#endif
