#ifndef __PLAYER__
#define __PLAYER__
#include "deck.h"
#include "manapool.h"

struct player_t{
	char *name;
        int hp;
	struct deck_t deck;
	struct hand_t hand;
	struct manapool_t pool;
};

struct card_t play_card_from_hand (struct player_t *player, int card);
void init_player(struct player_t *player);
void turn_begin(struct player_t *player);
int change_hp(struct player_t *player, int hp);
void print_hand(struct player_t *pl);
void print_player(struct player_t player);
#endif

