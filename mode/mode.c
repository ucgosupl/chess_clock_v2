#include "mode.h"

#include <stdlib.h>

#include "fixed/mode_fixed.h"
#include "fixed_control/mode_fixed_control.h"
#include "bonus/mode_bonus.h"
#include "bonus_control/mode_bonus_control.h"

static enum mode mode;

static const struct config_controller * set_mode_fixed_1m(void);
static const struct config_controller * set_mode_fixed_5m(void);
static const struct config_controller * set_mode_fixed_15m(void);
static const struct config_controller * set_mode_fixed_30m(void);
static const struct config_controller * set_mode_fixed_1h(void);
static const struct config_controller * set_mode_fixed_1h30min(void);

static const struct config_controller * set_mode_bonus_1m_inc_1s(void);

void mode_set(enum mode m)
{
	mode = m;
}

const struct config_controller * mode_config_controller_get(void)
{
	switch (mode)
	{
		case FIXED_CUSTOM:
			return fixed_config_controller_get();

		case BONUS_CUSTOM:
			return bonus_config_controller_get();

		case BONUSC_CUSTOM:
			return bonus_control_config_controller_get();

		case FIXEDC_CUSTOM:
			return fixed_control_config_controller_get();
		
		case FIXED_1M:
			return set_mode_fixed_1m();
						
		case FIXED_5M:
			return set_mode_fixed_5m();
				
		case FIXED_15M:
			return set_mode_fixed_15m();
		
		case FIXED_30M:
			return set_mode_fixed_30m();
						
		case FIXED_1H:
			return set_mode_fixed_1h();
				
		case FIXED_1H_30M:
			return set_mode_fixed_1h30min();
		
		case BONUS_1M_1S:
			return set_mode_bonus_1m_inc_1s();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}

const struct mode_builder * mode_builder_get(void)
{
	switch (mode)
	{
		case FIXED_1M:
		case FIXED_5M:
		case FIXED_15M:
		case FIXED_30M:
		case FIXED_1H:
		case FIXED_1H_30M:
		case FIXED_CUSTOM:
			return fixed_mode_builder_get();

		case BONUS_1M_1S:
		case BONUS_CUSTOM:
			return bonus_mode_builder_get();

		case BONUSC_CUSTOM:
			return bonus_control_mode_builder_get();

		case FIXEDC_CUSTOM:
			return fixed_control_mode_builder_get();
			
		default:
			//TODO: handle errors
			return NULL;
	}
}

const struct game_controller * mode_game_controller_get(void)
{
	switch (mode)
	{
		case FIXED_1M:
		case FIXED_5M:
		case FIXED_15M:
		case FIXED_30M:
		case FIXED_1H:
		case FIXED_1H_30M:
		case FIXED_CUSTOM:
			return fixed_game_controller_get();

		case BONUS_1M_1S:
		case BONUS_CUSTOM:
			return bonus_game_controller_get();

		case BONUSC_CUSTOM:
			return bonus_control_game_controller_get();
		
		case FIXEDC_CUSTOM:
			return fixed_control_game_controller_get();
		
		default:
			//TODO: handle errors
			return NULL;
	}
}

static void empty_on_entry(config_completed_cb_t cb)
{
	cb();
}

static void empty_fun(void)
{

}

static const struct config_controller config_empty = {
	empty_on_entry,
	empty_fun,
	empty_fun,
	empty_fun,
	empty_fun,
	empty_fun,
	empty_fun,
};

static const struct config_controller * set_mode_fixed_1m(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 1, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_5m(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 5, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_15m(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 15, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_30m(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 30, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_1h(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 0, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_1h30min(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 30, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_1m_inc_1s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 1, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 1));

	return &config_empty;
}
