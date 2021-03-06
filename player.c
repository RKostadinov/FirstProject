#include <stdio.h>
#include "player.h"

//Inits player.Creates manapool.inits the deck.inits hand cards.player helath = 30.
void init_player(struct player_t *player)
{
    player->hp = 30;
    manapool_create(&player->pool);
    init_deck(&player->deck);
    init_hand_cards(&player->hand);
}

//Changes hp.
int change_hp(struct player_t *player, int hp)
{
	if (hp > 30) player -> hp = 30;
	else player  ->hp += hp;
	if (player -> hp  < 0) player -> hp = 0;
        return 0;
}
//Puts a card from hand to. Reorders hand cards.
struct card_t play_card_from_hand (struct player_t *player, int card)
{
    int i;

     struct card_t play_card = player->hand.hand_cards[card];
     if (can_put_card(play_card, player->pool))
     {
        for (i = card + 1; i < player->hand.top; i++)
        {
            player->hand.hand_cards[i-1] = player->hand.hand_cards[i];
            
        }
        --player->hand.top;
     }
     else printf("There isn't enough mana to play the card");

}
//next turn. Draws a card from deck. mana increases
void turn_begin(struct player_t *player)
{
	draw_card(&player->deck, &player->hand);
        player->pool.mana_now++;
}
//Prints the cards in the hand
void print_hand(struct player_t *player) 
{
    int i;
    printf("|");
    for (i = 0; i <player->hand.top; i++) 
    {
        printf(" ");
        print_card(player->hand.hand_cards[i]);
        printf(" |");
    }
}
//Prints the player stats
void print_player(struct player_t player)
{
printf("Player: %s, Health: %d, Mana: %d \n", player.name, player.hp,player.pool.mana_now);
}
