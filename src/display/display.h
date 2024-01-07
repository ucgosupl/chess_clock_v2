#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>

#include "mode/config_view.h"

void display_init(void);
void display_update(void);

void display_show_mode(uint32_t mode);
void display_show_time(ms_t p1, ms_t p2);

void display_show_config_time(struct config_time *p1, struct config_time *p2, enum config_state state);
void display_show_config_inc(struct config_time *p1, struct config_time *p2, enum config_state state);
void display_show_config_moves(struct config_moves *moves, enum config_state state);
void display_show_config_bonus(struct config_time *bonus, enum config_state state);

void display_show_edit_time(struct config_time *p1, struct config_time *p2, enum edit_state state);
void display_show_edit_moves(struct config_moves *p1, struct config_moves *p2, enum edit_state state);

#endif /* DISPLAY_H */
