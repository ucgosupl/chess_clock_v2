#ifndef MODE_BONUS_CONTROL_H
#define MODE_BONUS_CONTROL_H

#include "mode/mode_builder.h"
#include "mode/config_controller.h"
#include "mode/game_controller.h"

const struct config_controller * bonus_control_config_controller_get(void);
const struct game_controller * bonus_control_game_controller_get(void);
const struct mode_builder * bonus_control_mode_builder_get(void);
const struct edit_builder * bonus_control_edit_builder_get(void);
const struct config_controller * bonus_control_edit_controller_get(void);

#endif /* MODE_BONUS_CONTROL_H */