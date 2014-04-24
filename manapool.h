#ifndef ___MANAPOOL___
#define ___MANAPOOL___

#include "card.h"

struct manapool_t
{
    int mana_now;
};

void manapool_create(struct manapool_t *pool);
int mana_push (struct manapool_t *pool, int add);
int mana_get (struct manapool_t *pool, int get);
int can_put_card(struct card_t card, struct manapool_t pool);

#endif
