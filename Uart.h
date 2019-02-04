/*
 * Uart.h
 *
 * 
 *  Author: YOGI
 */ 


#ifndef UART_H_
#define UART_H_

// ATMEGA2560

#include <avr/interrupt.h>

#define F_CPU		11059200UL
#define BAUDRATE1 ((F_CPU)/(9600*16UL)-1)
#define BAUDRATEG2 ((F_CPU)/(115200*16UL)-1)

 void uart_init1(uint8_t TypeUART);
 void send_data(unsigned char data[]);
 void send_string (unsigned char buff[]);




#endif /* UART_H_ */