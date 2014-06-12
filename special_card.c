#include "special_cards.h"
#include <stdio.h>
#include "board.h" 

void special_card(struct board_t *board, int card)
{
    if(board->players[board->player_turn].hand.hand_cards[card].name == "SPECIAL1")
    {  
        change_hp(&board->players[!board->player_turn], -5); 
    }

    if(board->players[board->player_turn].hand.hand_cards[card].name == "SPECIAL2")
    {  
        change_hp(&board->players[board->player_turn], 5); 
    }

    if(board->players[board->player_turn].hand.hand_cards[card].name == "SPECIAL3")
    {  
        mana_push(&board->players[board->player_turn].pool, 5);
    }
    
    if(board->players[board->player_turn].hand.hand_cards[card].name == "SPECIAL4")
    {  
        mana_push(&board->players[!board->player_turn].pool, -5);
    }

    if(board->players[board->player_turn].hand.hand_cards[card].name == "SPECIAL5")
    {  
        change_hp(&board->players[!board->player_turn], -5);
        change_hp(&board->players[board->player_turn], 5);
    }
}