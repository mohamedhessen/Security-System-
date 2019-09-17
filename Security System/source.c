/*
 * source.c
 *
 *  Created on: Aug 17, 2019
 *      Author: mom
 */


#include"STD_TYPES.h"
#include"MATH.h"
#include"DIO_PRIVATE.h"
#include"DIO_INTERFACE.h"
void DIO_SetPinDirection_u8(u8 u8PortId_Copy,u8 u8PinId_copy,u8 u8Value_copy)
{


if(u8PortId_Copy<4 && u8PinId_copy<=7)
{
	if(u8Value_copy==INPUT)
	{
switch(u8PortId_Copy)
{
case PORT0 :CLEAR_BIT( DDRA_REG,u8PinId_copy); break;
case PORT1 :CLEAR_BIT( DDRB_REG,u8PinId_copy); break;
case PORT2 :CLEAR_BIT( DDRC_REG,u8PinId_copy); break;
case PORT3 :CLEAR_BIT( DDRD_REG,u8PinId_copy); break;
}
	}
	else if (u8Value_copy==OUTPUT)
	{
		switch(u8PortId_Copy)
		{
		case PORT0 :SET_BIT( DDRA_REG,u8PinId_copy); break;
		case PORT1 :SET_BIT( DDRB_REG,u8PinId_copy); break;
		case PORT2 :SET_BIT( DDRC_REG,u8PinId_copy); break;
		case PORT3 :SET_BIT( DDRD_REG,u8PinId_copy); break;
		}
	}
	else
	{
		/* DO noTHING*/
	}

}
else
{/*DO NOTHING*/}

}




void DIO_SetPinValue_u8(u8 u8PortId_Copy,u8 u8PinId_copy,u8 u8Value_copy)
{


if(u8PortId_Copy<4 && u8PinId_copy<=7)
{
	if(u8Value_copy==LOW)
	{
switch(u8PortId_Copy)
{
case PORT0 :CLEAR_BIT( PORTA_REG,u8PinId_copy); break;
case PORT1 :CLEAR_BIT( PORTB_REG,u8PinId_copy); break;
case PORT2 :CLEAR_BIT( PORTC_REG,u8PinId_copy); break;
case PORT3 :CLEAR_BIT( PORTD_REG,u8PinId_copy); break;
}
	}
	else if (u8Value_copy==HIGH)
	{
		switch(u8PortId_Copy)
		{
		case PORT0 :SET_BIT( PORTA_REG,u8PinId_copy); break;
		case PORT1 :SET_BIT( PORTB_REG,u8PinId_copy); break;
		case PORT2 :SET_BIT( PORTC_REG,u8PinId_copy); break;
		case PORT3 :SET_BIT( PORTD_REG,u8PinId_copy); break;
		}
	}
	else
	{
		/* DO noTHING*/
	}

}
else
{/*DO NOTHING*/}

}



u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{

	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((u8PortIdCopy <= 4) && (u8PinIdCopy <= 7))
	{

		switch (u8PortIdCopy)
		{
			case PORT0: u8ResultLocal= GET_BIT(PINA_REG,u8PinIdCopy); break;
			case PORT1: u8ResultLocal= GET_BIT(PINB_REG,u8PinIdCopy); break;
			case PORT2: u8ResultLocal= GET_BIT(PINC_REG,u8PinIdCopy); break;
			case PORT3: u8ResultLocal= GET_BIT(PIND_REG,u8PinIdCopy); break;
		}
	}

	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}

	return u8ResultLocal;
}



void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{

	switch (u8PortId)
	{
		case     PORT0: DDRA_REG = u8PortDir; break;
		case     PORT1: DDRB_REG = u8PortDir; break;
		case     PORT2: DDRC_REG = u8PortDir; break;
		case     PORT3: DDRD_REG = u8PortDir; break;
		default:        break;
	}
}

void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
{
	/* Check on the Required PORT Number */
	switch (u8PortId)
	{
		case     PORT0: PORTA_REG = u8PortVal; break;
		case     PORT1: PORTB_REG = u8PortVal; break;
		case     PORT2: PORTC_REG = u8PortVal; break;
		case     PORT3: PORTD_REG = u8PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}



