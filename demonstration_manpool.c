#include <stdio.h>
#include "card.h"
#include "manapool.h"

	int main ()
	{

		struct manapool_t pool;
		struct card_t card = {"Hineca", 6, 7, 7};

		manapool_create(&pool);
		printf("mana: %d\n", pool.mana_now);

		mana_push(&pool, 75);
		printf("mana: %d", pool.mana_now);

		if(can_put_card(card_to_push, pool)) 
		{
		mana_get(&pool, card_to_push.mana);
		printf("mana: %d", pool.mana_now);
		} 	
	
		else printf("NEMA MANA, BACE! KRIZA E!\n");

		return 0;
	}

