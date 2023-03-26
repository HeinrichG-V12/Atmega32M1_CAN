/*
 * Atmega32M1_CAN.c
 *
 * Created: 26.03.2023 11:54:02
 * Author : Heinrich
 */ 

#include <avr/io.h>
#include "can/can_network.h"
#include "timer/timer.h"
#include "helpers.h"

int main(void)
{
	
	can_network_init(1);
	init_1ms_timer();
	sei();
	
	
	
    /* Replace with your application code */
    while (1) 
    {
		if (bit_check(TIMER_TASKS, BIT_TIMER_250ms))
		{
			bit_clear(TIMER_TASKS, BIT_TIMER_250ms);
			can_send_message();
		}
    }
}

