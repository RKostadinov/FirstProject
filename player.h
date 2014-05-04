#ifndef __player__
#define __player__
 
#include "deck.h"
#include "card.h"
#include "manapool.h"


struct player_t {
	int hp;
	struct deck_t deck;
	struct manapool_t pool;
};

void init_player(struct player_t *player);
int change_hp(struct player_t *player, int hp);


#endif