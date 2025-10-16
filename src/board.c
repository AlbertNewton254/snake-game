#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void init_board(board_t * board) {
	board->height = HEIGHT;
	board->width = WIDTH;

	board->grid = (char **) malloc(HEIGHT * sizeof(char *));
	for (int y = 0; y < HEIGHT; y++) {
		board->grid[y] = (char *) malloc(WIDTH * sizeof(char));
		for (int x = 0; x < WIDTH; x++) {
			if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
				board->grid[y][x] = '#';
			} else {
				board->grid[y][x] = ' ';
			}
		}
	}

	board->score = 0;
	board->food_x = WIDTH / 4;
	board->food_y = HEIGHT / 4;
	board->grid[board->food_y][board->food_x] = '*';
}

void print_board(board_t * board) {
	system("clear");
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			putchar(board->grid[y][x]);
		}
		putchar('\n');
	}
	printf("Score: %d\n", board->score);
}

