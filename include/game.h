#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "snake.h"

typedef struct {
	board_t board;
	snake_t snake;
	int running;
} game_t;

void init_game(game_t * game);

#endif

