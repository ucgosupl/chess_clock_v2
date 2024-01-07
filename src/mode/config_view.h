#ifndef CONFIG_VIEW_H
#define CONFIG_VIEW_H

#include <stdint.h>
#include "time.h"

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

	CONFIG_STATE_MAX,
};

enum edit_state
{
	EDIT_P1_HOURS,
	EDIT_P1_MIN1,
	EDIT_P1_MIN2,
	EDIT_P1_SEC1,
	EDIT_P1_SEC2,

	EDIT_P2_HOURS,
	EDIT_P2_MIN1,
	EDIT_P2_MIN2,
	EDIT_P2_SEC1,
	EDIT_P2_SEC2,

	EDIT_P1_MOVES1,
	EDIT_P1_MOVES2,

	EDIT_P2_MOVES1,
	EDIT_P2_MOVES2,

	EDIT_DONE,

	EDIT_STATE_MAX,
};

struct config_time
{
	uint8_t h;

	uint8_t m1;
	uint8_t m2;

	uint8_t s1;
	uint8_t s2;
};

struct config_moves
{
	uint8_t moves1;
	uint8_t moves2;
};

typedef void (*show_mode_t)(uint32_t mode);
typedef void (*show_time_t)(ms_t p1, ms_t p2);
typedef void (*show_config_time_t)(struct config_time *p1, struct config_time *p2, enum config_state state);
typedef void (*show_config_inc_t)(struct config_time *p1, struct config_time *p2, enum config_state state);
typedef void (*show_config_moves_t)(struct config_moves *moves, enum config_state state);
typedef void (*show_config_bonus_t)(struct config_time *bonus, enum config_state state);

#endif /* CONFIG_VIEW_H */
