#ifndef __CARD__
#define __CARD__

struct card_t
    {
        char name[50];
        int damage;
        int hp;
        int mana;
    };

int attack(struct card_t *attacker, struct card_t *defender);

#endif
