#include <stdint.h>

#include "mode_interface.h"

void game_init(const struct mode_interface *mode);
void game_start(void);
void game_on_tick(void);
void game_time_update(void);

