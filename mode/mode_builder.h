#ifndef MODE_BUILDER_H
#define MODE_BUILDER_H

#include <stdint.h>

#include "player.h"
#include "moves.h"
#include "time.h"

typedef void (*init_t)(void);
typedef void (*set_time_t)(enum player p, ms_t t);
typedef void (*set_increment_t)(enum player p, ms_t i);
typedef void (*set_bonus_t)(enum player p, ms_t b);
typedef void (*set_moves_t)(enum player p, moves_t m);

struct mode_builder
{
    init_t init;
    set_time_t set_time;
    set_increment_t set_increment;
    set_bonus_t set_bonus;
    set_moves_t set_moves;
};

struct edit_builder
{
    set_time_t edit_time;
    set_moves_t edit_moves;
};

#endif /* MODE_BUILDER_H */