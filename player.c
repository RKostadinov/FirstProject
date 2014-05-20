#include <stdio.h>
#include "player.h"


void init_player(struct player_t *player)
{
    player->hp = 30;
    manapool_create(&player->pool);
    init_deck(&player->deck);
}


int change_hp(struct player_t *player, int hp)
{
	if (hp > 30) player -> hp = 30;
	else player  ->hp += hp; 
	if (player -> hp  < 0) player -> hp = 0;
        return 0;
}

struct card_t play_card_from_hand (struct player_t *player, int card) 
{
    int i;
    
     struct card_t play_card = player->hand.hand_cards[card];
     if (can_put_card(play_card, player->pool))
     {

         for (i=card +1; i < player->hand.top ; i++)
             player->hand.hand_cards[i-1] = player->hand.hand_cards[i];
         --player->hand.top;
         printf("\n");
     
     }
     else printf("There isn't enough mana to play the card");
     
}

void turn_begin(struct player_t *player)
{


	draw_card(&player->deck, &player->hand);	

}

void print_hand(struct player_t *pl) {
    int i;
    for (i = 0; i <pl->hand.top; i++) {
        printf("Hand element %d ->  name: %s, %d, %d, %d\n", i, pl->hand.hand_cards[i].name, pl->hand.hand_cards[i].damage,
               pl->hand.hand_cards[i].hp, pl->hand.hand_cards[i].mana);
    }
    
}