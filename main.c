#include <stdio.h>
//#include "player.h"
#include "board.h"

#define DEBUG printf(":)\n");



int main()
{
    struct board_t board;
    board.player_turn = 0;
    //struct player_t player2;


    init_player(&board.players[0]);
    init_hand_cards(&board.players[0].hand);

  struct  card_t attacker1  = {"Green", -1, 10, 1};
  struct  card_t attacker2  = {"Blue", 7, 3, 4};
  struct  card_t attacker3  = {"Yellow", 6, 4, 5};
  struct  card_t attacker4  = {"Red", 8, 2, 7};
  struct  card_t attacker5  = {"Purple", 5, 8, 4};
  struct  card_t attacker6  = {"Black", 2, 10, 2};
  struct  card_t attacker7  = {"Brown", 3, 6, 1};
  struct  card_t attacker8  = {"Gray", -1, 5, 3};
  struct  card_t attacker9  = {"Orange", 6, 3, 4};
  struct  card_t attacker10 = {"Lime", 4, 2, 1};

    push_card(attacker1,  &board.players[0].deck);
    push_card(attacker2,  &board.players[0].deck);
    push_card(attacker3,  &board.players[0].deck);
    push_card(attacker4,  &board.players[0].deck);
    push_card(attacker5,  &board.players[0].deck);
    push_card(attacker6,  &board.players[0].deck);
    push_card(attacker7,  &board.players[0].deck);
    push_card(attacker8,  &board.players[0].deck);
    push_card(attacker9,  &board.players[0].deck);
    push_card(attacker10, &board.players[0].deck);

/*
    init_player(&player2);
    init_hand_cards(&player2.hand);

   struct card_t defender1  = {"Dark_Green", 10, 10, 1};
   struct card_t defender2  = {"Dark_Blue", 7, 3, 4};
   struct card_t defender3  = {"Dark_Yellow", 6, 4, 5};
   struct card_t defender4  = {"Dark_Red", 8, 2, 7};
   struct card_t defender5  = {"Dark_Purple", 5, 8, 4};
   struct card_t defender6  = {"Dark_Black", 2, 10, 2};
   struct card_t defender7  = {"Dark_Brown", 3, 6, 1};
   struct card_t defender8  = {"Dark_Gray", 5, 5, 3};
   struct card_t defender9  = {"Dark_Orange", 6, 3, 4};
   struct card_t defender10 = {"Dark_Lime", 4, 2, 3};

    push_card(defender1,  &player2.deck);
    push_card(defender2,  &player2.deck);
    push_card(defender3,  &player2.deck);
    push_card(defender4,  &player2.deck);
    push_card(defender5,  &player2.deck);
    push_card(defender6,  &player2.deck);
    push_card(defender7,  &player2.deck);
    push_card(defender8,  &player2.deck);
    push_card(defender9,  &player2.deck);
    push_card(defender10, &player2.deck);
*/

    draw_card(&board.players[0].deck, &board.players[0].hand);
    draw_card(&board.players[0].deck, &board.players[0].hand);
    draw_card(&board.players[0].deck, &board.players[0].hand);
    draw_card(&board.players[0].deck, &board.players[0].hand);
    print_hand(&board.players[0]);
        //Board cards names should be always initialized before use ! (:
        board.game[0][2].name = NULL;
        if(can_play_card(&board,0,0,2)){
            play_card(&board,0,0,2);
            play_card_from_hand(&board.players[0], 0);
            printf("\t%s\n", board.game[0][2].name);
        }
        printf("\n");
        print_hand(&board.players[0]);
        printf("\n");
        turn_begin(&board.players[0]);
        print_hand(&board.players[0]);

return 0;
	}
