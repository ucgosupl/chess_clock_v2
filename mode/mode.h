#ifndef MODE_H_
#define MODE_H_

#include <stdint.h>

#include "game_controller.h"
#include "mode_builder.h"
#include "mode/config_controller.h"

enum mode
{
	FIXED_CUSTOM,
	BONUS_CUSTOM,
	BONUSC_CUSTOM,
	FIXEDC_CUSTOM,

	FIXED_1M,
	FIXED_5M,
	FIXED_15M,
	FIXED_30M,
	FIXED_1H,
	FIXED_1H_30M,

	BONUS_1M_1S,
	BONUS_3M_2S,
	BONUS_5M_3S,
	BONUS_10M_5S,
	BONUS_15M_10S,
	BONUS_1H30M_30S,

	BONUSC_1H30M_30S_40MOV_30M,

	FIXEDC_1H30M_30MOV_1H,

	MODES_MAX,
};

void mode_set(enum mode m);

const struct config_controller * mode_config_controller_get(void);
const struct mode_builder * mode_builder_get(void);
const struct game_controller * mode_game_controller_get(void);
const struct edit_builder * mode_edit_builder_get(void);
const struct config_controller * mode_edit_controller_get(void);

#endif /* MODE_H_ */
