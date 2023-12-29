#ifndef STATE_CONFIG_H_
#define STATE_CONFIG_H_

#include "mode/mode.h"
#include "events/events.h"

void config_on_entry(enum mode mode);
uint32_t config_on_tick(events_t events);
void config_on_exit(void);

#endif /* STATE_CONFIG_H_ */
