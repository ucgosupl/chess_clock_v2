#include "mode_fixed.h"

#include <stdlib.h>
#include <string.h>

#include "display/display.h"

static enum config_state state;

static struct config_time p1_time;
static struct config_time p2_time;

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

	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,

	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
};

static void fixed_on_entry(config_completed_cb_t cb)
{
	memset(&p1_time, 0, sizeof(struct config_time));
	memset(&p2_time, 0, sizeof(struct config_time));

	state = P1_HOURS;

	completed_cb = cb;
}

static void fixed_on_exit(void)
{
	const struct mode_builder *builder = fixed_mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(p1_time.h, p1_time.m1*10 + p1_time.m2, p1_time.s1*10 + p1_time.s2));
}

static void fixed_on_plus(void)
{
	if (state < P2_SEC2 + 1)
		*config_state_to_val_mapper[state] = add_with_bounds(*config_state_to_val_mapper[state]);
}

static void fixed_on_minus(void)
{
	if (state < P2_SEC2 + 1)
		*config_state_to_val_mapper[state] = sub_with_bounds(*config_state_to_val_mapper[state]);
}

static void fixed_on_left(void)
{
	if (0 < state)
	{
		state--;
	}
}

static void fixed_on_right(void)
{
	state++;
	
	if (P2_SEC2 < state)
	{
		state = CONFIG_DONE;
		if (NULL != completed_cb)
		{
			completed_cb();
		}
	}
}

static void fixed_display(void)
{
	display_show_config_time(&p1_time, &p2_time, state);
}

static const struct config_controller config_fixed =
{
		fixed_on_entry,
		fixed_on_exit,
		fixed_on_plus,
		fixed_on_minus,
		fixed_on_left,
		fixed_on_right,
		fixed_display,
};

const struct config_controller * fixed_config_controller_get(void)
{
	return &config_fixed;
}
