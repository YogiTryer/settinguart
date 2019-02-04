/*
 * Uart.c
 *
 *
 *  Author: YOGI
 */ 
#include <util/delay.h>
#include <string.h>
#include <avr/sleep.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "Uart.h"

	
		
	void uart_init1(uint8_t TypeUART)
	{

		if (TypeUART==0)
		{	UBRR0L=BAUDRATE2;
			UBRR0H=(BAUDRATE2>>8);
		} 
		if (TypeUART==1)
		{
			UBRR0L=BAUDRATE1;
			UBRR0H=(BAUDRATE1>>8);
		}
		UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
		UCSR0B = (1<<RXCIE0)|(1<<TXEN0)|(1<<RXEN0);
		sei();
	}

	void send_data(unsigned char data[])
	{
		while((UCSR0A&(1<<UDRE0))==0);
		UDR0=data;
	}
	void send_string(unsigned char buff[])
	{
		int i=0;
		while (buff[i]>0)
		{
			send_data(buff[i++]);
		}
		
	}	


