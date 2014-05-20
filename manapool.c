#include "manapool.h"
#include <stdio.h>

void manapool_create(struct manapool_t *pool)
{
	pool -> mana_now = 1; 
}

int mana_push (struct manapool_t *pool, int add)
{
    pool -> mana_now += add;
    return 0;
}

int mana_get (struct manapool_t *pool, int get)
{
    pool -> mana_now -=get;
    return 0;
}

int can_put_card(struct card_t card_to_put, struct manapool_t pool)
{
    if (pool.mana_now>=card_to_put.mana)
        return 1;
    else
        return 0;
}

void put_card(struct card_t card_to_put,struct manapool_t *pool, struct deck_t *player_deck){
	if(can_put_card(card_to_put, *pool)){
            pool->mana_now-=card_to_put.mana;
			push_card(card_to_put, player_deck);
		
        }   
        else {
		printf("Not enough mana! \n");	
            }
	}
