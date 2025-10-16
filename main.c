#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
#include "snake.h"
#include "board.h"
#include "terminal.h"

#define DELAY 200000

int main(void) {
	srand(time(NULL));
	game_t game;
	init_game(&game);

	enable_raw_mode();

	while (game.running) {
		if (kbhit()) {
			char c = getch();
			switch (c) {
				case 'w': if (game.snake.direction != 'D') game.snake.direction = 'U'; break;
				case 's': if (game.snake.direction != 'U') game.snake.direction = 'D'; break;
				case 'a': if (game.snake.direction != 'R') game.snake.direction = 'L'; break;
				case 'd': if (game.snake.direction != 'L') game.snake.direction = 'R'; break;
				default:
					while (kbhit()) getch();
					break;
			}
		}

		move_snake(&game.snake, &game.board, &game.running);
		print_board(&game.board);
		usleep(DELAY);
	}

	disable_raw_mode();
	printf("Game Over!\n");
	return 0;
}

