#ifndef __CARD__
#define __CARD__

struct card_t{
    char *name;
    int damage;
    int hp;
    int mana;
};

int attack(struct card_t *attacker, struct card_t *defender);
void print_card(struct card_t card);
#endif