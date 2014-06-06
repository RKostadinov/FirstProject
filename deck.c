#include  "deck.h"
#include <stdio.h>
//Initialises the deck. Top = 0.
    void init_deck(struct deck_t *player_deck)
{
	player_deck->top = 0;
}
//Initialises hand cards. Top())
    void init_hand_cards(struct hand_t *player_hand) 
{
    player_hand->top = 0;
}

//Pushes the selected card into the player`s deck.
    int push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
        if (player_deck -> top < 30)
    { 
    player_deck->card[player_deck->top++] = card_to_push; 
    return 1;
    }
else printf("Error: Deck is full! ");
        return 0;
    
}

//Pops a card from deck(stack) and puts it in the player`s hand. Top(deck) -=1. Top(hand) += 1.
int draw_card(struct deck_t *deck, struct hand_t *hand)
{
        if (deck->top > 0)
{
            hand->hand_cards[hand->top++] = deck->card[--deck->top];
            return 1;
         
}
        else return 0;
}

//Printing the elements of the card without removing it from the deck(stack)
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
