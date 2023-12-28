#ifndef CONFIG_H
#define CONFIG_H

#include "stm32f4xx.h"
#include <stdint.h>

#include "modes/modes.h"

enum config_state
{
	P1_HOURS,
	P1_MIN1,
	P1_MIN2,
	P1_SEC1,
	P1_SEC2,

	P2_HOURS,
	P2_MIN1,
	P2_MIN2,
	P2_SEC1,
	P2_SEC2,

	P1_INC_MIN,
	P1_INC_SEC1,
	P1_INC_SEC2,

	P2_INC_MIN,
	P2_INC_SEC1,
	P2_INC_SEC2,

	MOVES1,
	MOVES2,

	BONUS_HOURS,
	BONUS_MIN1,
	BONUS_MIN2,
	BONUS_SEC1,
	BONUS_SEC2,

	CONFIG_DONE,
};

struct config_time
{
	uint8_t h;

	uint8_t m1;
	uint8_t m2;

	uint8_t s1;
	uint8_t s2;
};

typedef void (*config_completed_cb)(void);

typedef void (*on_entry)(config_completed_cb cb);
typedef void (*on_exit)(void);
typedef void (*on_plus)(void);
typedef void (*on_minus)(void);
typedef void (*on_left)(void);
typedef void (*on_right)(void);
typedef void (*display)(void);

struct config_interface
{
	on_entry on_entry;
	on_exit on_exit;
	on_plus on_plus;
	on_minus on_minus;
	on_left on_left;
	on_right on_right;
	display display;
};

__STATIC_FORCEINLINE uint8_t add_with_bounds(uint8_t val)
{
	return (val >= 9) ? 9 : ++val;
}

__STATIC_FORCEINLINE uint8_t sub_with_bounds(uint8_t val)
{
	return (val == 0) ? 0 : --val;
}

void config_on_entry(enum mode mode);
uint32_t config_on_tick(void);
void config_on_exit(void);

#endif /* CONFIG_H */
