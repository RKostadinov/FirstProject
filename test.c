#include <stdio.h>
#include <card.h>
int main()
{

    struct card_t attacker = {"attacker", 1, 2, 0}; //"name" , attack , HP , mana 
    struct card_t defender = {"defender", 1 ,3, 0}; //"name" , attack , HP , mana 

     printf("%d\n", attack(&attacker, &defender));
    // printf("Attacker HP : %d\n", attacker.hp); Remove comment to print the Attacker HP
    // printf("Defender HP : %d\n", defender.hp); Remove comment to print the Defender HP    

 return 0;
}
