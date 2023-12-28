#include <stdint.h>
#include "time.h"

void display_init(void);
void display_clear(void);
void display_show_mode(uint32_t mode);
void display_show_time(ms_t p1, ms_t p2);
void display_show_config_time(ms_t p1, ms_t p2, uint32_t state);
