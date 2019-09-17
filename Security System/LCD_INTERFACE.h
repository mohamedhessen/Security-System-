/*
 * LCD_INTERFACE.h
 *
 *  Created on: Aug 23, 2019
 *      Author: mom
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define RS PIN0
#define ENABLE PIN2
#define RD_WR PIN1


#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position


extern void  LcdWriteCmd(u8 u8CmdCopy);
extern void LcdWriteData(u8 u8DataCopy);
extern void LCD_INIT();
extern void LCD_String(u8 *str);
extern void PORT_INIT();
extern void GetRowcol(u8 row, u8 col);
#endif /* LCD_INTERFACE_H_ */

