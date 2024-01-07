#include "display/display.h"

void display_show_config_time(struct config_time *p1, struct config_time *p2, enum config_state state)
{
    (void) p1;
    (void) p2;
    (void) state;
}

void display_show_config_inc(struct config_time *p1, struct config_time *p2, enum config_state state)
{
    (void) p1;
    (void) p2;
    (void) state;
}

void display_show_config_moves(struct config_moves *moves, enum config_state state)
{
    (void) moves;
    (void) state;
}

void display_show_config_bonus(struct config_time *bonus, enum config_state state)
{
    (void) bonus;
    (void) state;
}


void display_show_edit_time(struct config_time *p1, struct config_time *p2, enum edit_state state)
{
    (void) p1;
    (void) p2;
    (void) state;
}

void display_show_edit_moves(struct config_moves *p1, struct config_moves *p2, enum edit_state state)
{
    (void) p1;
    (void) p2;
    (void) state;
}
