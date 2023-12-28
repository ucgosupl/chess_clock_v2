#include <stdint.h>
#include "time.h"

void display_init(void);
void display_clear(void);
void display_show_mode(uint32_t mode);
void display_show_time(ms_t p1, ms_t p2);
void display_show_config_time(ms_t p1, ms_t p2, uint32_t state);
void display_show_config_inc(ms_t config_inc_p1, ms_t config_inc_p2, uint32_t state);
void display_show_config_moves(uint32_t moves, uint32_t state);
void display_show_config_bonus(ms_t bonus, uint32_t state);

