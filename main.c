#include <stdio.h>
#include "player.h"
#include "deck.h"



int main()
{
    struct player_t player1;
    struct player_t player2;

    //int turn=1;

    init_player(&player1);
    init_hand_cards(&player1.hand);
   

  struct  card_t attacker1  = {"Green", 10, 10, 1};
  struct  card_t attacker2  = {"Blue", 7, 3, 4};
  struct  card_t attacker3  = {"Yellow", 6, 4, 5};
  struct  card_t attacker4  = {"Red", 8, 2, 7};
  struct  card_t attacker5  = {"Purple", 5, 8, 4};
  struct  card_t attacker6  = {"Black", 2, 10, 2};
  struct  card_t attacker7  = {"Brown", 3, 6, 1};
  struct  card_t attacker8  = {"Gray", 5, 5, 3};
  struct  card_t attacker9  = {"Orange", 6, 3, 4};
  struct  card_t attacker10 = {"Lime", 4, 2, 3};   
 
   
    push_card(attacker1,  &player1.deck);
    push_card(attacker2,  &player1.deck);
    push_card(attacker3,  &player1.deck);
    push_card(attacker4,  &player1.deck);
    push_card(attacker5,  &player1.deck);
    push_card(attacker6,  &player1.deck);
    push_card(attacker7,  &player1.deck);
    push_card(attacker8,  &player1.deck);
    push_card(attacker9,  &player1.deck);
    push_card(attacker10, &player1.deck);

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

    
    draw_card(&player1.deck, &player1.hand);
    draw_card(&player1.deck, &player1.hand);
    draw_card(&player1.deck, &player1.hand);
    draw_card(&player1.deck, &player1.hand);
    print_hand(&player1);
    
        play_card_from_hand(&player1, 0);
        printf("\n");
 print_hand(&player1);
 printf("\n");
 turn_begin(&player1);
 print_hand(&player1);
 change_hp(&player1, 10);
 printf("%d",player1.hp);
		return 0;
	}