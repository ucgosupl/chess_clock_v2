#include <stdint.h>

#include "time.h"

enum state {NOT_STARTED, P1, P2};

void game_init(ms_t time, ms_t inc);
void game_start(void);
void game_move(enum state player);
enum state game_state_get(void);
void game_time_update(void);
ms_t game_p1_time_get(void);
ms_t game_p2_time_get(void);
