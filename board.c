#include <stdio.h>
#include "board.h"
#include <string.h>


//Inits the board.All cards stats are set to zero.
void init_board(struct board_t *board)
{
    int i, k;
    for (i = 0; i < 5; i++)
    {
        for (k = 0; k <= 1; k++)
        {
            
            board->game[k][i].damage = 0;
            board->game[k][i].hp = 0;
            board->game[k][i].mana = 0;    
        }     
         
    }
}
//Checks if there is a possibility to play the card. if there is enough mana and if slot on board is free.
int can_play_card(struct board_t *board, int player, int card, int num_lane){
    if(can_put_card(board->players[player].hand.hand_cards[card],board->players[player].pool)
    && board->game[player][num_lane].hp == 0){
        return 1;
    }
    return 0;
}
//PLays a card from hand
int play_card(struct board_t *board, int player, int card, int num_lane){
    board->game[player][num_lane] = board->players[player].hand.hand_cards[card];
    return 0;
}
//End of turn.Attacking
void turn_end(struct board_t *board, int player){
   
    int i;
    for(i=0; i<5;i++){
        if(board->game[0][i].hp != 0 && board->game[1][i].hp != 0) attack(&board->game[0][i], &board->game[1][i]);
        if(board->game[0][i].hp != 0 && board->game[1][i].hp == 0) board->players[1].hp -= board->game[0][i].damage;
        if(board->game[0][i].hp == 0 && board->game[1][i].hp != 0) board->players[0].hp -= board->game[1][i].damage;
    }
   
    board->player_turn = player;
}
//checks if there is a winner
int winner(struct board_t board) 
{
    if(board.players[0].hp > 0 && board.players[1].hp > 0) return 0;
    if(board.players[0].hp <= 0 && board.players[1].hp > 0) return 2;
    if(board.players[0].hp > 0 && board.players[1].hp <= 0) return 1;
}


//Prints the board and all other lines and cards
void print_board(struct board_t *board){
    print_player(board->players[0]);
    printf("------------------------------------------------ \n");
    print_hand(&board->players[0]);
    int i;
     printf("\n################################################\n");
    printf("#");    
    for (i = 0; i <= 4; i++)
        {
          printf(" "); 
          print_card(board->game[0][i]);
          printf(" #");
        }
        printf("\n\n#");
        
  for (i = 0; i <= 4; i++)
        {
          printf(" "); 
          print_card(board->game[1][i]);
          printf(" #");
        }
        printf("\n################################################\n");
       print_hand(&board->players[1]);   
        printf("\n------------------------------------------------ \n");
      print_player(board->players[1]);
}
//Loads deck from file "Biggest achievement"
int load_deck(struct board_t *board, char* file) {
	FILE *deck ;
	char str[2000];
	char *buff;
        deck = fopen(file, "r");
	if (deck == NULL) return 0;
        
	while(fgets(str, 2000, deck)) 
        {
            
		buff = strtok(str, ",");
		sscanf(buff, "%d", board->players[board->player_turn].deck.card[board->players[board->player_turn].deck.top].name);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->players[board->player_turn].deck.card[board->players[board->player_turn].deck.top].mana);	
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->players[board->player_turn].deck.card[board->players[board->player_turn].deck.top].damage);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->players[board->player_turn].deck.card[board->players[board->player_turn].deck.top].hp);
		board->players[board->player_turn].deck.top++;	
               
                
	} 	
	fclose(deck);
        return 1;
}



//                  SPECIAL EFFECT - Radoslav
//                  Project for magic cards;
void special_effect(struct board_t *board, int card)
{
    switch(board->players[board->player_turn].hand.hand_cards[card].damage){
    
        case -1:
            change_hp(&board->players[board->player_turn], 3);
            break;
        case -2:
            change_hp(&board->players[!board->player_turn], -3);
            break;
        case -3:
            if(board->game[!board->player_turn][0].hp)
            {
                board->game[!board->player_turn][0].damage = 1;
                board->game[!board->player_turn][0].hp = 1;
            }      
            break;
        default:
            break;
    }
    board->players[board->player_turn].hand.hand_cards[card].hp = 0;
}
