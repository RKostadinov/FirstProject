#ifndef BOARD_H
#define	BOARD_H

#include "player.h"

struct board_t
{
	struct card_t game[2][5];
	struct player_t players[2];
	int player_turn;
};

void init_board(struct board_t *board);

int can_play_card(struct board_t *board, int player, int card, int num_lane);

int play_card(struct board_t *board, int player, int card, int num_lane);

void turn_end(struct board_t *board, int player);

void print_board(struct board_t *board, struct player_t player, int turn);



#endif

