#ifndef LCD_H_
#define LCD_H_

/*Function prototype or Declaration */

void LCD_vidWriteData(u8 data ); /* function use to write Character in LCD by sending data */

void LCD_vidWriteComand(u8 Comand );/* function use to write command in LCD to initialize it */

void LCD_vidInit(void); /* use to initialize the LCD one time */

void LCD_vidWriteString(u8 *data );

void LCD_vidWriteNumber(f64 data );

void LCD_vidSetPosition(u8 row ,u8 col);

void LCD_vidClear(void);

#endif /* LCD_H_ */
