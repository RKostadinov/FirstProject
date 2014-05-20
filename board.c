#include <stdio.h>
#include "board.h"


int can_play_card(struct board_t *board, int player, int card, int num_lane)
{
if (&board.game[player][num_lane] != card)	return 1;
else return 0;
}

 
int play_card(struct board_t *board, int player, int card, int num_lane)
{
	for (num_lane=0; num_lane<5; num_lane++)
	{
		if (can_play_card(*board, player, num_lane))
		{
			board->game[player][num_lane] = card;
			return 1;
		}
		else return 0;
	}
}


void turn_end(struct board_t *board, struct player_t player1, struct player_t player2)
{

} 
