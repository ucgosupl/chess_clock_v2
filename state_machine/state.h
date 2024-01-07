#ifndef STATE_H
#define STATE_H

#include "events/events.h"

enum state {MODE, CONFIG, GAME, EDIT, STATE_MAX};

typedef void (*state_init_t)(void);
typedef void (*state_entry_t)(void);
typedef enum state (*state_tick_t)(events_t events);
typedef void (*state_exit_t)(void);

struct state_interface
{
    state_init_t init;
    state_entry_t on_entry;
    state_tick_t on_tick;
    state_exit_t on_exit;
};

#endif /* STATE_H */