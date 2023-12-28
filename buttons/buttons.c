#include "buttons.h"

#include "stm32f4xx_hal.h"

/*
 * PC08 - player 1
 * PC09 - player 2
 * PC13 - play/pause
 * PC06 - +
 * PB08 - -
 * PB09 - <
 * PC05 - >
 */

void buttons_init(void)
{

}

bool buttons_is_p1_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == GPIO_PIN_RESET;
}

bool buttons_is_p2_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9) == GPIO_PIN_RESET;
}

bool buttons_is_play_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET;
}

bool buttons_is_plus_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_RESET;
}

bool buttons_is_minus_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_RESET;
}

bool buttons_is_left_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_RESET;
}

bool buttons_is_right_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5) == GPIO_PIN_RESET;
}
