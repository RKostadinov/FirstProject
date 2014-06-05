#include <stdio.h>
#include "board.h"





int main()
{ 
    struct board_t board;
    init_board(&board);
    board.player_turn = 0;
    init_player(&board.players[0]);
    init_player(&board.players[1]);
    
    init_hand_cards(&board.players[0].hand);
    init_hand_cards(&board.players[1].hand);
    int card_to_play, card = 2, j;
    board.players[0].name = "ÏåøÓ";
    board.players[1].name = "ÃîøÓ";
    
    load_deck(&board, "deck1.csv");
    board.player_turn = 1;
    load_deck(&board, "deck_2.csv");
      
for (j = 0; j<=4; j++)
{    
    draw_card(&board.players[0].deck, &board.players[0].hand);
    draw_card(&board.players[1].deck, &board.players[1].hand);
}

    

/*
    if(board.players[!board.player_turn].hand.hand_cards[card].damage < 0)
    {
        
        special_effect(&board, card);
    }
    
*/

    print_board(&board);
    
    
return 0;
	}