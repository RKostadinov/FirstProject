#include<stdio.h>
#include "board.h"

void init_board(struct board_t *board){
    int i, k;
    for (i = 0; i < 5; i++){
        for (k = 0; k <= 1; k++){
            board->game[k][i].name = NULL;
            board->game[k][i].damage = 0;
            board->game[k][i].hp = 0;
            board->game[k][i].mana = 0;
            
        }
       
    }
    board->game[1][5].name = NULL;
    board->game[1][5].damage = 0;
    board->game[1][5].hp = 0;
    board->game[1][5].mana = 0;
    
}

int can_play_card(struct board_t *board, int player, int card, int num_lane){
    if(can_put_card(board->players[player].hand.hand_cards[card],board->players[player].pool)
    && board->game[player][num_lane].hp == 0){
        return 1;
    }
    return 0;
}

int play_card(struct board_t *board, int player, int card, int num_lane){
    board->game[player][num_lane] = board->players[player].hand.hand_cards[card];
    return 0;
}

void turn_end(struct board_t *board, int player){
   
    int i;
    for(i=0; i<5;i++){
        if(board->game[0][i].hp != 0 && board->game[1][i].hp != 0) attack(&board->game[0][i], &board->game[1][i]);
        if(board->game[0][i].hp != 0 && board->game[1][i].hp == 0) board->players[1].hp -= board->game[0][i].damage;
        if(board->game[0][i].hp == 0 && board->game[1][i].hp != 0) board->players[0].hp -= board->game[1][i].damage;
    }
   
    board->player_turn = player;
}

int winner(struct board_t board) 
{
    if(board.players[0].hp > 0 && board.players[1].hp > 0) return 0;
    if(board.players[0].hp <= 0 && board.players[1].hp > 0) return 2;
    if(board.players[0].hp > 0 && board.players[1].hp <= 0) return 1;
}

void print_board(struct board_t *board, struct player_t player, int turn){
    print_player(board->players[0]);
    printf("------------------------------------------------------ \n");
    print_hand(&board->players[0]);
    int i;
     printf("\n######################################################\n");
    printf("#");    
    for (i = 1; i <= 5; i++)
        {
          printf(" "); 
          print_card(board->game[0][i]);
          printf(" #");
        }
        printf("\n\n#");
        
  for (i = 1; i <= 5; i++)
        {
          printf(" "); 
          print_card(board->game[1][i]);
          printf(" #");
        }
        printf("\n######################################################\n");
       print_hand(&board->players[1]);   
        printf("\n------------------------------------------------------ \n");
       print_player(board->players[1]);
}