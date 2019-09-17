/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 17, 2019
 *      Author: mom
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PORT0 0
#define PORT1 1
#define PORT2 2
#define PORT3 3

#define INPUT 0
#define OUTPUT 1
#define PORT_OUTPUT 0xff
#define HIGH 1
#define PORT_HIGH 0xff
#define LOW 0

extern void DIO_SetPinDirection_u8(u8 u8PortId_Copy,u8 u8PinId_copy,u8 u8Value_copy);
extern void DIO_SetPinValue_u8(u8 u8PortId_Copy,u8 u8PinId_copy,u8 u8Value_copy);
extern u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);
extern void DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);
extern void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);


#endif /* DIO_INTERFACE_H_ */
