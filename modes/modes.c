#include "modes.h"

#include <stdlib.h>

#include "game/game.h"

const struct mode_interface * fixed_init(ms_t time);
const struct mode_interface * bonus_init(ms_t time, ms_t inc);
const struct mode_interface * fixed_control_init(ms_t time, moves_t moves, ms_t bonus);
const struct mode_interface * bonus_control_init(ms_t time, ms_t inc, moves_t moves, ms_t bonus);

typedef void (*game_init_for_mode)(void *);

static void init_for_mode1(void *params);
static void init_for_mode2(void *params);
static void init_for_mode3(void *params);
static void init_for_mode4(void *params);

static game_init_for_mode modes_init[MODES_MAX] =
{
		init_for_mode1,
		init_for_mode2,
		init_for_mode3,
		init_for_mode4,
};

static void init_for_mode1(void *params)
{
	game_init(fixed_init(TIME_TO_MS(0, 5, 0)));
}

static void init_for_mode2(void *params)
{
	game_init(bonus_init(TIME_TO_MS(0, 5, 0), S2MS(3)));
}

static void init_for_mode3(void *params)
{
	game_init(fixed_control_init(TIME_TO_MS(0, 5, 0), 5, TIME_TO_MS(0, 5, 0)));
}

static void init_for_mode4(void *params)
{
	game_init(bonus_control_init(TIME_TO_MS(0, 5, 0), S2MS(3), 5, TIME_TO_MS(0, 5, 0)));
}

void modes_game_init(uint32_t mode)
{
	modes_init[mode](NULL);
}
