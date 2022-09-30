/*Header file guard*/
#ifndef __HLCD_INTERFACE_H__
#define __HLCD_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/
#define LCD_ROW_0   (0x00)
#define LCD_ROW_1   (0x40)

#define LCD_COL_0   (0x00)
#define LCD_COL_1   (0x01)
#define LCD_COL_2   (0x02)
#define LCD_COL_3   (0x03)
#define LCD_COL_4   (0x04)
#define LCD_COL_5   (0x05)
#define LCD_COL_6   (0x06)
#define LCD_COL_7   (0x07)
#define LCD_COL_8   (0x08)
#define LCD_COL_9   (0x09)
#define LCD_COL_10   (0x0A)
#define LCD_COL_11   (0x0B)
#define LCD_COL_12   (0x0C)
#define LCD_COL_13   (0x0D)
#define LCD_COL_14   (0x0E)
#define LCD_COL_15   (0x0F)





void hlcd_init(void);
void hlcd_displayCharacter(u8_t au8_characterData);
void hlcd_displayString(u8_t* pu8_stringdata);
void hlcd_displayPosition(u8_t au8_row ,u8_t au8_col);

#endif /*__HLCD_INTERFACE_H__*/