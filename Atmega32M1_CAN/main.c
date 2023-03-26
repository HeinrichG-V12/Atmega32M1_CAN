/*
 * Atmega32M1_CAN.c
 *
 * Created: 26.03.2023 11:54:02
 * Author : Heinrich
 */ 

#include <avr/io.h>
#include "can/can_network.h"


int main(void)
{
	
	can_network_init(1);
	sei();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

