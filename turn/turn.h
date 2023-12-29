#ifndef TURN_H_
#define TURN_H_

enum turn {PLAYER1, PLAYER2};

typedef void (*on_move_t)(enum turn who_moved);

void turn_subscribe(on_move_t cb);
void turn_update(void);
enum turn turn_get(void);

#endif /* TURN_H_ */
