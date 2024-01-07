#include "mode_bonus_control.h"

#include <stdlib.h>
#include <string.h>

#include "display/display.h"

static enum edit_state state;

static struct config_time p1_time;
static struct config_time p2_time;

static struct config_moves p1_moves;
static struct config_moves p2_moves;

static config_completed_cb_t completed_cb = NULL;

static uint8_t * const config_state_to_val_mapper[EDIT_STATE_MAX] = 
{
	&p1_time.h,
	&p1_time.m1,
	&p1_time.m2,
	&p1_time.s1,
	&p1_time.s2,

	&p2_time.h,
	&p2_time.m1,
	&p2_time.m2,
	&p2_time.s1,
	&p2_time.s2,

	&p1_moves.moves1,
	&p1_moves.moves2,

	&p2_moves.moves1,
	&p2_moves.moves2,

	NULL,
};

static void ms2config(struct config_time *ct, ms_t time)
{
    ct->h = MS2H(time);
	time %= MS_IN_H;

	ms_t m = MS2MIN(time);
	ct->m1 = m / 10;
	ct->m2 = m % 10;
	time %= MS_IN_MIN;

	ms_t s = time / MS_IN_S;
	ct->s1 = s / 10;
	ct->s2 = s % 10;
}

static void moves2config(struct config_moves *cm, moves_t moves)
{
	cm->moves1 = moves / 10;
	cm->moves2 = moves % 10;
}

static void edit_bonus_control_on_entry(config_completed_cb_t cb)
{
    const struct game_controller *game = bonus_control_game_controller_get();

    ms2config(&p1_time, game->time_get(PLAYER1));
    ms2config(&p2_time, game->time_get(PLAYER2));

	moves2config(&p1_moves, game->moves_get(PLAYER1));
	moves2config(&p2_moves, game->moves_get(PLAYER2));

	state = EDIT_P1_HOURS;

	completed_cb = cb;
}

static void edit_bonus_control_on_exit(void)
{
	const struct edit_builder *builder = bonus_control_edit_builder_get();

	builder->edit_time(PLAYER1, TIME_TO_MS(p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2));
	builder->edit_time(PLAYER2, TIME_TO_MS(p2_time.h, p2_time.m1*10 + p2_time.m2, p2_time.s1*10 + p2_time.s2));
	builder->edit_moves(PLAYER1, p1_moves.moves1 * 10 + p1_moves.moves2);
	builder->edit_moves(PLAYER2, p2_moves.moves1 * 10 + p2_moves.moves2);
}

static void edit_bonus_control_on_plus(void)
{
	if (state < EDIT_P2_MOVES2 + 1)
		*config_state_to_val_mapper[state] = add_with_bounds(*config_state_to_val_mapper[state]);
}

static void edit_bonus_control_on_minus(void)
{
	if (state < EDIT_P2_MOVES2 + 1)
		*config_state_to_val_mapper[state] = sub_with_bounds(*config_state_to_val_mapper[state]);
}

static void edit_bonus_control_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void edit_bonus_control_on_right(void)
{
	state++;
	
	if (EDIT_P2_MOVES2 < state)
	{
		state = EDIT_DONE;
		if (NULL != completed_cb)
		{
			completed_cb();
		}
	}
}

static void edit_bonus_control_display(void)
{
	if (state < EDIT_P1_MOVES1)
	{
		display_show_edit_time(&p1_time, &p2_time, state);
	}
	else if (state < EDIT_DONE)
	{
		display_show_edit_moves(&p1_moves, &p2_moves, state);
	}
	else
	{

	}
}

static const struct config_controller edit_controller_bonus_control =
{
		edit_bonus_control_on_entry,
		edit_bonus_control_on_exit,
		edit_bonus_control_on_plus,
		edit_bonus_control_on_minus,
		edit_bonus_control_on_left,
		edit_bonus_control_on_right,
		edit_bonus_control_display,
};

const struct config_controller * bonus_control_edit_controller_get(void)
{
	return &edit_controller_bonus_control;
}
