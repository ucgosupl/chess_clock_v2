#ifndef MODE_FIXED_CONTROL_H
#define MODE_FIXED_CONTROL_H

#include "mode/mode_builder.h"
#include "mode/config_controller.h"
#include "mode/game_controller.h"

const struct config_controller * fixed_control_config_controller_get(void);
const struct game_controller * fixed_control_game_controller_get(void);
const struct mode_builder * fixed_control_mode_builder_get(void);
const struct edit_builder * fixed_control_edit_builder_get(void);
const struct config_controller * fixed_control_edit_controller_get(void);

#endif /* MODE_FIXED_H */