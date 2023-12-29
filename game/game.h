#include <stdint.h>

#include "events/events.h"
#include "mode_interface.h"

void game_init(const struct mode_interface *mode);
void game_on_tick(events_t events);
void game_time_update(void);

