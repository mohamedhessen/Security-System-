/*
 * KPD_source.c
 *
 *  Created on: Aug 27, 2019
 *      Author: mom
 */
#include "MATH.h"
#include"STD_TYPES.h"
#include "DIO_INTERFACE.h"
#include "KPD_INTERFACE.h"
#include<avr/delay.h>

//const u8 KPD_values[4][4]={{0x01,0x02,0x03,0x04},{0x05,0x06,0x07,0x08},{0x09,0x0A,0x0B,0x0C},{0x0D,0x0E,0x0F,0x10}};
//const u8 KPD_values[4][4]={0};
const u8 KPD_values[4][4]={48,49,50,51,52,53,54,55,56,57,58,43,45,42};
u8 GetPressedKey(void)
{
u8 loc_row;
u8 loc_col;
u8 u8ReturnPressesKey=NOT_PRESSEd;
for( loc_row=init_row ; loc_row<total_row; loc_row++ )
 {
      DIO_SetPinValue_u8(PORT3,loc_row,LOW);
  for(loc_col=init_coulom ; loc_col<total_coulom ;loc_col++)
    {
	if( !  DIO_GetPinValue(PORT3,loc_col)  )
	     {
		u8ReturnPressesKey=KPD_values[loc_row][loc_col-init_coulom];
		while(!   DIO_GetPinValue(PORT3,loc_col)  )
		     ;
	        _delay_ms(10);

	    }
	}
  //DIO_SetPinValue_u8(PORT3,loc_row,HIGH);

 }
return u8ReturnPressesKey;

}
