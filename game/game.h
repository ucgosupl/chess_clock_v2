#include <stdint.h>

enum state {NOT_STARTED, P1, P2};

void game_init(uint32_t time);
void game_start(void);
void game_move(enum state player);
enum state game_state_get(void);
void game_time_update(void);
uint32_t game_p1_time_get(void);
uint32_t game_p2_time_get(void);
