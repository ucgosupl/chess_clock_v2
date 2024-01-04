#ifndef STATE_CONFIG_H_
#define STATE_CONFIG_H_

#include "events/events.h"
#include "../state.h"

void config_on_entry(void);
enum state config_on_tick(events_t events);
void config_on_exit(void);

#endif /* STATE_CONFIG_H_ */