#ifndef BOARD_H
#define	BOARD_H

#include "player.h"

struct board_t 
{
	struct card_t game[2][5];
};

int can_play_card(struct board_t *board, int player, int card, int num_lane); 

int play_card(struct board_t *board, int player, int card, int num_lane); 

void turn_end(struct board_t *board, int player); 





#endif

