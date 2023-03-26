/*
 * can_network.c
 *
 * Created: 01.06.2022 17:21:56
 *  Author: Heinrich
 */ 

#include "can_network.h"

	/*
	There are three different types of CAN modules available:
	-> 2.0A - Considers 29 bit ID as an error
	-> 2.0B Passive - Ignores 29 bit ID messages
	-> 2.0B Active - Handles both 11 and 29 bit ID Messages
	*/
	
	/*	
	st_cmd_t message;
	
	message.id.ext = 0x180;
	// message.ctrl.ide = 0;			// standard CAN frame type (2.0A)
	
	message.ctrl.ide = 1;				// we are using extended ID, check can_lib.c:118
	message.ctrl.rtr = 0;				// this message object is not requesting a remote node to transmit data back
	message.dlc = 1;
	message.cmd = CMD_TX_DATA;
	// message.pt_data = 0x01;
	
	while(can_cmd(&message) != CAN_CMD_ACCEPTED);					// wait for MOb to configure
	while(can_get_status(&message) == CAN_STATUS_NOT_COMPLETED);	// wait for a transmit request to come in, and send a response
	*/

void can_network_init (uint8_t mode)
{
	can_init(mode);
}

void can_send_message (void)
{
	st_cmd_t message;
	message.id.ext = 0x180;
	message.ctrl.ide = 1;
	message.ctrl.rtr = 0;
	message.dlc = 2;
	message.cmd = CMD_TX_DATA;
	uint8_t pt_data[message.dlc];
	pt_data[0] = 0x00;
	pt_data[1] = 0xFF;
	message.pt_data = &pt_data[0];
	
	while(can_cmd(&message) != CAN_CMD_ACCEPTED);					// wait for MOb to configure
	while(can_get_status(&message) == CAN_STATUS_NOT_COMPLETED);	// wait for a transmit request to come in, and send a response	
}