#ifndef INC_HD44780_H_
#define INC_HD44780_H_

void LCD_Init(void);

void LCD_SendCommand(uint8_t command);
void LCD_SendData(uint8_t data);
void LCD_Clear(void);
void LCD_PrintString(const uint8_t *str);

#endif /* INC_HD44780_H_ */
