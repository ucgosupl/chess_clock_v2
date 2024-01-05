#include "mode_bonus.h"

#include <stdlib.h>
#include <string.h>

#include "display/display.h"

static enum config_state state;

static struct config_time p1_time;
static struct config_time p2_time;
static struct config_time p1_inc;
static struct config_time p2_inc;

static config_completed_cb_t completed_cb = NULL;

static uint8_t * const config_state_to_val_mapper[CONFIG_STATE_MAX] = 
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

	&p1_inc.m2,
	&p1_inc.s1,
	&p1_inc.s2,

	&p2_inc.m2,
	&p2_inc.s1,
	&p2_inc.s2,

	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
};

static void bonus_on_entry(config_completed_cb_t cb)
{
	memset(&p1_time, 0, sizeof(struct config_time));
	memset(&p2_time, 0, sizeof(struct config_time));
	memset(&p1_inc, 0, sizeof(struct config_time));
	memset(&p2_inc, 0, sizeof(struct config_time));

	state = P1_HOURS;

	completed_cb = cb;
}

static void bonus_on_exit(void)
{
	const struct mode_builder *builder = bonus_mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, p1_inc.m1*10 + p1_inc.m2, p1_inc.s1*10 + p1_inc.s2));
}

static void bonus_on_plus(void)
{
	if (state < P2_INC_SEC2 + 1)
		*config_state_to_val_mapper[state] = add_with_bounds(*config_state_to_val_mapper[state]);
}

static void bonus_on_minus(void)
{
	if (state < P2_INC_SEC2 + 1)
		*config_state_to_val_mapper[state] = sub_with_bounds(*config_state_to_val_mapper[state]);
}

static void bonus_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void bonus_on_right(void)
{
	state++;
	
	if (P2_INC_SEC2 < state)
	{
		state = CONFIG_DONE;
		if (NULL != completed_cb)
		{
			completed_cb();
		}
	}
}

static void bonus_display(void)
{
	if (state < P1_INC_MIN)
	{
		display_show_config_time(&p1_time, &p2_time, state);
	}
	else if (state < MOVES1)
	{
		display_show_config_inc(&p1_inc, &p2_inc, state);
	}
}

static const struct config_controller config_bonus =
{
		bonus_on_entry,
		bonus_on_exit,
		bonus_on_plus,
		bonus_on_minus,
		bonus_on_left,
		bonus_on_right,
		bonus_display,
};

const struct config_controller * bonus_config_controller_get(void)
{
	return &config_bonus;
}
