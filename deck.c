#include  "deck.h"
#include <stdio.h>

    void init_deck(struct deck_t *player_deck)
{
	player_deck->top = 0;
}

    int push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
        if (player_deck -> top <= 30)
{ 
    player_deck->card[player_deck->top++] = card_to_push; 
    return 1;
}
else printf("Error: Deck is full! ");
        return 0;
    
    }


int draw_card(struct deck_t *deck, struct hand_t *hand)
{
        if (deck->top > 0)
{
            hand->hand_cards[hand->top++] = deck->card[--deck->top];
            return 1;
         
}
        else return 0;
}


int look_card(struct deck_t *player_deck)
{
        if(player_deck->top > 0) 
{
            printf("-Next card:\ncard NAME: %s\ncard DAMAGE: %d\ncard HP: %d\ncard MANA: %d\n",
            player_deck->card[player_deck->top].name,
            player_deck->card[player_deck->top].damage,
            player_deck->card[player_deck->top].hp,
            player_deck->card[player_deck->top].mana);
            
            return 1;
        
}
        else  
        {
            printf ("Error: Deck is empty!"); 
            return 0;
        }
        
}

void init_hand_cards(struct hand_t *player_hand) 
{
    player_hand->top = 0;
}
