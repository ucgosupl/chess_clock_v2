#include <stdint.h>


#include "time.h"
#include "mode_interface.h"

void game_init(const struct mode_interface *mode);
void game_start(void);
void game_move(enum state player);
enum state game_state_get(void);
void game_time_update(void);
ms_t game_p1_time_get(void);
ms_t game_p2_time_get(void);
