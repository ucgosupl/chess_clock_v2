#include "stm32f4xx_hal.h"

#define RS_PIN GPIO_PIN_12
#define RW_PIN GPIO_PIN_10
#define E_PIN GPIO_PIN_11
#define D4_PIN GPIO_PIN_1
#define D5_PIN GPIO_PIN_2
#define D6_PIN GPIO_PIN_0
#define D7_PIN GPIO_PIN_3

#define LCD_PORT GPIOC

static void LCD_Enable(void);
static void LCD_Send4Bits(uint8_t data);

static void delay_ms(uint32_t ms)
{
    HAL_Delay(ms);
}

static void LCD_Enable(void)
{
    HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_SET);
    delay_ms(1);
    HAL_GPIO_WritePin(LCD_PORT, E_PIN, GPIO_PIN_RESET);
    delay_ms(1);
}

static void LCD_Send4Bits(uint8_t data)
{
    HAL_GPIO_WritePin(LCD_PORT, D4_PIN, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_PORT, D5_PIN, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_PORT, D6_PIN, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_PORT, D7_PIN, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void LCD_SendCommand(uint8_t command) {
    HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);

    LCD_Send4Bits(command >> 4);
    LCD_Enable();
    LCD_Send4Bits(command);
    LCD_Enable();

    delay_ms(2); // Wait for the command to be executed
}

void LCD_SendData(uint8_t data) {
    HAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);

    LCD_Send4Bits(data >> 4);
    LCD_Enable();
    LCD_Send4Bits(data);
    LCD_Enable();

    delay_ms(1); // Wait for the command to be executed
}

void LCD_Init(void) {
    delay_ms(50); // Wait for the voltage to stabilize

    // Initialize the LCD
    LCD_SendCommand(0x33); // Initialization for 4-bit mode
    LCD_SendCommand(0x32); // Initialization for 4-bit mode
    LCD_SendCommand(0x28); // 4-bit mode, 2 lines, 5x8 font
    LCD_SendCommand(0x0C); // Display on, cursor and blink off
    LCD_SendCommand(0x06); // Increment cursor position, no display shift
    LCD_SendCommand(0x01); // Clear the display

    delay_ms(2); // Wait for the LCD to stabilize
}

void LCD_Clear(void)
{
    LCD_SendCommand(0x01); // Clear the display

    delay_ms(2); // Wait for the LCD to stabilize
}

void LCD_PrintString(const uint8_t *str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}
