/*
 * USART.c
 *
 * Created: 11/24/2016 7:51:51 AM
 * Author : VarzariA
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

#define FOSC 16000000H
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init()
{
	UCSR0B = (1<<RXCIE0) | (1<< RXEN0) | (1<<TXEN0);
	UCSR0C = (1<<UCSZ00) | (1<< UCSZ01); //8 bit
	UBRR0 = 103; //BaudRate 9600
}

int UErrors = 0;

ISR(USART_RX_vect)
{
	if((UCSR0A & (1<<FE0)) || (UCSR0A & (1<<DOR0)) || (UCSR0A & (1<<UPE0)))
	{
		UErrors++;
	}
	else
	{
		unsigned char data = UDR0;
		if (data == 'A')
		PORTB |= (1<<5);
		else
		if(data == 'S')
		PORTB &= ~(1<<5);
    }
}

int main(void)
{
	sei();

    DDRB |= (1<<5);

	USART_Init();
    /* Replace with your application code */
    while (1) 
    {
	 
    }
}

