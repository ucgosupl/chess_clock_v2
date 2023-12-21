#include "buttons.h"

#include "stm32f4xx_hal.h"

/*
 * PC13 - player 1
 * PC09 - player 2
 * PC08 - play/pause
 * PB08 - +
 * PC06 - -
 * PB09 - >
 * PC06 - <
 */

void buttons_init(void)
{

}

bool buttons_is_p1_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET;
}

bool buttons_is_p2_pressed(void)
{
	return HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_9) == GPIO_PIN_RESET;
}
