#include "mode_fixed.h"

#include <stdlib.h>
#include <string.h>

#include "display/display.h"

static enum edit_state state;

static struct config_time p1_time;
static struct config_time p2_time;

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

	NULL,
	NULL,

	NULL,
	NULL,

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

static void edit_fixed_on_entry(config_completed_cb_t cb)
{
    const struct game_controller *game = fixed_game_controller_get();

    ms2config(&p1_time, game->time_get(PLAYER1));
    ms2config(&p2_time, game->time_get(PLAYER2));

	state = EDIT_P1_HOURS;

	completed_cb = cb;
}

static void edit_fixed_on_exit(void)
{
	const struct edit_builder *builder = fixed_edit_builder_get();

	builder->edit_time(PLAYER1, TIME_TO_MS(p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2));
	builder->edit_time(PLAYER2, TIME_TO_MS(p2_time.h, p2_time.m1*10 + p2_time.m2, p2_time.s1*10 + p2_time.s2));
}

static void edit_fixed_on_plus(void)
{
	if (state < EDIT_P2_SEC2 + 1)
		*config_state_to_val_mapper[state] = add_with_bounds(*config_state_to_val_mapper[state]);
}

static void edit_fixed_on_minus(void)
{
	if (state < EDIT_P2_SEC2 + 1)
		*config_state_to_val_mapper[state] = sub_with_bounds(*config_state_to_val_mapper[state]);
}

static void edit_fixed_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void edit_fixed_on_right(void)
{
	state++;
	
	if (EDIT_P2_SEC2 < state)
	{
		state = EDIT_DONE;
		if (NULL != completed_cb)
		{
			completed_cb();
		}
	}
}

static void edit_fixed_display(void)
{
	display_show_edit_time(&p1_time, &p2_time, state);
}

static const struct config_controller edit_controller_fixed =
{
		edit_fixed_on_entry,
		edit_fixed_on_exit,
		edit_fixed_on_plus,
		edit_fixed_on_minus,
		edit_fixed_on_left,
		edit_fixed_on_right,
		edit_fixed_display,
};

const struct config_controller * fixed_edit_controller_get(void)
{
	return &edit_controller_fixed;
}
