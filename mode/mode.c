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
static const struct config_controller * set_mode_bonus_3m_inc_2s(void);
static const struct config_controller * set_mode_bonus_5m_inc_3s(void);
static const struct config_controller * set_mode_bonus_10m_inc_5s(void);
static const struct config_controller * set_mode_bonus_15m_inc_10s(void);
static const struct config_controller * set_mode_bonus_1h30m_inc_30s(void);

static const struct config_controller * set_mode_bonus_control_1h30M_inc_30s_40mov_bonus_30min(void);

static const struct config_controller * set_mode_fixed_control_1h30M_30mov_bonus_1h(void);

typedef const struct config_controller * (*config_controller_get_t)(void);
typedef const struct mode_builder * (*mode_builder_get_t)(void);
typedef const struct game_controller * (*mode_game_controller_get_t)(void);
typedef const struct edit_builder * (*edit_builder_get_t)(void);
typedef const struct config_controller * (*edit_controller_t)(void);

struct mode_interface
{
	config_controller_get_t config_controller_get;
	mode_builder_get_t mode_builder_get;
	mode_game_controller_get_t game_controller_get;
	edit_builder_get_t	edit_builder_get;
	edit_controller_t edit_controller_get;
};

static const struct mode_interface mode_interface_mapper[MODES_MAX] =
{ 
	/* FIXED_CUSTOM,	*/	{fixed_config_controller_get, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* BONUS_CUSTOM,	*/	{bonus_config_controller_get, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUSC_CUSTOM,	*/	{bonus_control_config_controller_get, bonus_control_mode_builder_get, bonus_control_game_controller_get, bonus_control_edit_builder_get, bonus_control_edit_controller_get},
	/* FIXEDC_CUSTOM,	*/	{fixed_control_config_controller_get, fixed_control_mode_builder_get, fixed_control_game_controller_get, fixed_control_edit_builder_get, fixed_control_edit_controller_get},

	/* FIXED_1M,		*/	{set_mode_fixed_1m, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* FIXED_5M,		*/	{set_mode_fixed_5m, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* FIXED_15M,		*/	{set_mode_fixed_15m, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* FIXED_30M,		*/	{set_mode_fixed_30m, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* FIXED_1H,		*/	{set_mode_fixed_1h, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},
	/* FIXED_1H_30M,	*/	{set_mode_fixed_1h30min, fixed_mode_builder_get, fixed_game_controller_get, fixed_edit_builder_get, fixed_edit_controller_get},

	/* BONUS_1M_1S,		*/	{set_mode_bonus_1m_inc_1s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUS_3M_2S,		*/	{set_mode_bonus_3m_inc_2s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUS_5M_3S,		*/	{set_mode_bonus_5m_inc_3s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUS_10M_5S,	*/	{set_mode_bonus_10m_inc_5s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUS_15M_10S,	*/	{set_mode_bonus_15m_inc_10s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},
	/* BONUS_1H30M_30S,	*/	{set_mode_bonus_1h30m_inc_30s, bonus_mode_builder_get, bonus_game_controller_get, bonus_edit_builder_get, bonus_edit_controller_get},

	/* BONUSC_1H30M_30S_40MOV_30M, */	{set_mode_bonus_control_1h30M_inc_30s_40mov_bonus_30min, bonus_control_mode_builder_get, bonus_control_game_controller_get, bonus_control_edit_builder_get, bonus_control_edit_controller_get},

	/* FIXEDC_1H30M_30MOV_1H, */		{set_mode_fixed_control_1h30M_30mov_bonus_1h, fixed_control_mode_builder_get, fixed_control_game_controller_get, fixed_control_edit_builder_get, fixed_control_edit_controller_get},
};

void mode_set(enum mode m)
{
	mode = m;
}

const struct config_controller * mode_config_controller_get(void)
{
	return mode_interface_mapper[mode].config_controller_get();
}

const struct mode_builder * mode_builder_get(void)
{
	return mode_interface_mapper[mode].mode_builder_get();
}

const struct game_controller * mode_game_controller_get(void)
{
	return mode_interface_mapper[mode].game_controller_get();
}

const struct edit_builder * mode_edit_builder_get(void)
{
	return mode_interface_mapper[mode].edit_builder_get();
}

const struct config_controller * mode_edit_controller_get(void)
{
	return mode_interface_mapper[mode].edit_controller_get();
}

static void empty_on_entry(config_completed_cb_t cb)
{
	if (NULL != cb)
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

static const struct config_controller * set_mode_bonus_3m_inc_2s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 3, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 2));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_5m_inc_3s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 5, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 3));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_10m_inc_5s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 10, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 5));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_15m_inc_10s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(0, 15, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 10));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_1h30m_inc_30s(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 30, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 30));

	return &config_empty;
}

static const struct config_controller * set_mode_bonus_control_1h30M_inc_30s_40mov_bonus_30min(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 30, 0));
	builder->set_increment(PLAYER_BOTH, TIME_TO_MS(0, 0, 30));
	builder->set_moves(PLAYER_BOTH, 40);
	builder->set_bonus(PLAYER_BOTH, TIME_TO_MS(0, 30, 0));

	return &config_empty;
}

static const struct config_controller * set_mode_fixed_control_1h30M_30mov_bonus_1h(void)
{
	const struct mode_builder *builder = mode_builder_get();

	builder->init();
	builder->set_time(PLAYER_BOTH, TIME_TO_MS(1, 30, 0));
	builder->set_moves(PLAYER_BOTH, 30);
	builder->set_bonus(PLAYER_BOTH, TIME_TO_MS(1, 0, 0));

	return &config_empty;
}
