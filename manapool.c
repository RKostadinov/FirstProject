#include "manapool.h"
#include <stdio.h>

int mana_push (struct manapool_t *pool, int add)
{
    pool -> mana_now += add;
}

int mana_get (struct manapool_t *pool, int get)
{
    pool -> mana_now -=get;
}

int can_put_card(struct card_t card_to_put, struct manapool_t pool)
{
    if (pool.mana_now>=card_to_put.mana)
        return 1;
    else
        return 0;
}
