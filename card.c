#include "card.h"
#include <stdio.h>
//Attack function. Returns if there is a winner.
    int attack(struct card_t *attacker, struct card_t *defender)
    {
        if (((defender -> hp) - (attacker -> damage) > 0) && ((attacker -> hp)-(defender -> damage)>0))
        {
    (attacker -> hp -= defender -> damage);
    (defender -> hp -= attacker -> damage);
            return 3;
        }
        
        if (((defender -> hp) - (attacker -> damage) <= 0) && ((attacker -> hp)-(defender -> damage)<=0))
        {
    (attacker -> hp -= defender -> damage);
    (defender -> hp -= attacker -> damage);
            return 0;
        }
        if (attacker -> damage >= defender ->hp)      
        {     
    (attacker -> hp -= defender -> damage);
    (defender -> hp -= attacker -> damage);       
            return 1;
        }

            if (defender -> damage >= attacker -> hp)
        {
    (attacker -> hp -= defender -> damage);
    (defender -> hp -= attacker -> damage);
            return 2;
        }
        
    }  
//Prints the card elements damage|HP(mana_cost) 
    void print_card(struct card_t card)
    {
        printf("%d|%d(%d)", card.damage, card.hp, card.mana);
    }