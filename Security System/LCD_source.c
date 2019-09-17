/*
 * LCD_source.c
 *
 *  Created on: Aug 23, 2019
 *      Author: mom
 */
#include"STD_TYPES.h"
#include"MATH.h"
#include"DIO_INTERFACE.h"
#include"LCD_INTERFACE.h"
#include "avr/delay.h"
/****************LcdWriteCmd function****************/
/*
 **
 *send command to data-cmd pass
 */
void LcdWriteCmd(u8 u8CmdCopy)
{
	DIO_SetPinValue_u8(PORT1,RS,LOW);      /*cmd mode*/
	DIO_SetPinValue_u8(PORT1,RD_WR,LOW);   /*write pin enabling*/
	DIO_SetPinValue_u8(PORT1,ENABLE,HIGH);   /*enable high*/
	DIO_SetPortValue(PORT0,u8CmdCopy);
	DIO_SetPinValue_u8(PORT1,ENABLE,LOW);/*enable low*/
	_delay_ms(5);
	DIO_SetPinValue_u8(PORT1,ENABLE,HIGH);   /*enable high*/
	_delay_ms(10);
}
void LcdWriteData(u8 u8DataCopy)
{
	    DIO_SetPinValue_u8(PORT1,RS,HIGH);      /*cmd mode*/
		DIO_SetPinValue_u8(PORT1,RD_WR,LOW);   /*write pin enabling*/
		DIO_SetPinValue_u8(PORT1,ENABLE,HIGH);   /*enable high*/
		DIO_SetPortValue(PORT0,u8DataCopy);
		DIO_SetPinValue_u8(PORT1,ENABLE,LOW);/*enable low*/
		_delay_ms(5);
		DIO_SetPinValue_u8(PORT1,ENABLE,HIGH);   /*enable high*/
		_delay_ms(10);
}

void LCD_INIT()
{

	/* Delay 30ms to ensure the initialization of the LCD driver */
		_delay_ms(30);

		/* Return Home  */
		LcdWriteCmd(lcd_Home);
		_delay_ms(15);

		/* Function Set  */
		LcdWriteCmd(lcd_FunctionSet8bit);
		_delay_ms(1);

		/* Display ON OFF Control */
		LcdWriteCmd(lcd_DisplayOn);
		_delay_ms(1);

		/* Clear Display */
		LcdWriteCmd(lcd_Clear);
		_delay_ms(15);

		/* Entry Mode Set  */
		LcdWriteCmd(lcd_EntryMode);
		_delay_ms(2);
		DIO_SetPinDirection_u8(PORT3,PIN7,OUTPUT);
		DIO_SetPinValue_u8(PORT3,PIN7,HIGH);
}
void LCD_String (u8 *str)		/* Send words to LCD function */
{
	int i;
	for(i=0;str[i]!='\0';i++)		/* Send each char of string till the end */
	{
		LcdWriteData (str[i]);
		_delay_ms(2);
	}
}


void PORT_INIT()
{
	DIO_SetPortDirection(PORT0,PORT_OUTPUT);
	DIO_SetPortDirection(PORT1,PORT_OUTPUT);
}

void GetRowcol(u8 row, u8 col)
{
u8 locpos=col+row*0x40;
locpos|=0x80;
LcdWriteCmd(locpos);
}
