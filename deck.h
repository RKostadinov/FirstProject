#ifndef ___Random___
#define ___Random___

#include "card.h"
#define MAX_SIZE 30


struct deck_t{
	int top;
	struct card_t card[MAX_SIZE];
};

struct hand_t{
    int top;
    struct card_t hand_cards[MAX_SIZE];
};

int push_card(struct card_t card_to_push, struct deck_t *player_deck);
int draw_card(struct deck_t *player_deck, struct hand_t *hand);
int look_card(struct deck_t *player_deck);
void init_hand_cards(struct hand_t *player_hand);


#endif