#include "manapool.h"
#include <stdio.h>
//Creates a manapool.Sets the mana to 1
void manapool_create(struct manapool_t *pool)
{
	pool -> mana_now = 1; 
}
//Pushes mana to pool.Add is how much we want to add
int mana_push (struct manapool_t *pool, int add)
{
    pool -> mana_now += add;
    return 0;
}
//Substracts mana from pool.get is ho much we want to remove
int mana_get (struct manapool_t *pool, int get)
{
    pool -> mana_now -=get;
    return 0;
}
//Checks if there is enough mana to summon the card
int can_put_card(struct card_t card_to_put, struct manapool_t pool)
{
    if (pool.mana_now>=card_to_put.mana)
        return 1;
    else
        return 0;
}
//Puts a card to the deck.Useless now
void put_card(struct card_t card_to_put,struct manapool_t *pool, struct deck_t *player_deck)
{
	if(can_put_card(card_to_put, *pool))
        {
            mana_get(pool,card_to_put.mana);
            push_card(card_to_put, player_deck);
		
        }   
            else 
                {
		printf("Not enough mana! \n");	
                }
}