/*
 * app.c
 *
 *  Created on: Aug 27, 2019
 *      Author: mom
 */
#include "MATH.h"
#include<avr/io.h>
#include"STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "KPD_INTERFACE.h"
#include"LCD_INTERFACE.h"
#include<interrupt/io.h>
#include<avr/delay.h>
#define preload 87
#define desire 4
#define MAX 127
u8 i=0,open=0;
int main()
{

	TCCR0|=(1<<1)|(1<<3);
	SREG |=(1<<7);
	/*1.6*/
	PORT_INIT();
     LCD_INIT();
	DIO_SetPortDirection(PORT3,0x0f);
	DIO_SetPortValue(PORT3,0xff);
//	DIO_SetPinValue_u8(PORT3,PIN0,LOW);
	DIO_SetPinDirection_u8(PORT2,PIN7,HIGH);
	//u8 key_id=GetPressedKey();
u8 id[3];
while(1){
	while(1)
	{
		u8 key_id=GetPressedKey();

		   if(key_id==48)
			     		{
						LcdWriteData(key_id);
						id[i++]=key_id;
				       	}
		   if(key_id==49)
		   			{
		   				LcdWriteData(key_id);
		   				id[i++]=key_id;
		   			}
		   if(key_id==50)
		   			{
		   				LcdWriteData(key_id);
		   				id[i++]=key_id;
		   			}
		   if(key_id==51)
		   			{
		   				LcdWriteData(key_id);
		   				id[i++]=key_id;
		   			}
		   if(key_id==52)
		   			{
		   				LcdWriteData(key_id);
		   				id[i++]=key_id;
		   			}
		   if(key_id==53)
		   			{
		   				LcdWriteData(key_id);
		   				id[i++]=key_id;
		   			}
		 	if(key_id==54)
		 	{	DIO_SetPinValue_u8(PORT2,PIN7,HIGH);
		 	//_delay_ms(4000);
			//DIO_SetPinValue_u8(PORT2,PIN7,LOW);
			//_delay_ms(4000);
			LcdWriteData(key_id);
			id[i++]=key_id;
			//LcdWriteCmd(0xC5);
		 	}
		 	if(key_id==55)
		 	{
			LcdWriteData(key_id);
			id[i++]=key_id;//LcdWriteCmd(0xC5);
		 	}
		 	if(key_id==56)
		 				{
		 					LcdWriteData(key_id);
		 					id[i++]=key_id;
		 				}
	if(i==3)
	{
		TIMSK |=(1<<1);
		break;
	}
	}
}

    if( (id[0]==4) && (id[1]==1) && (id[2]==4))
    		{
    	open=1;
    		}
return 0;

}
ISR(TIMER_COMP_vect)
{
	static u8 counter=0;//static variable
		counter++;
		if(counter ==8)//when the counter reaches 1sec
		{
			PORTC=0x00;//toggle pin0 in portc
		}
		else if(counter==80)
		{
			PORTC=0xff;
			counter=0;//clears the counter
		}
}

