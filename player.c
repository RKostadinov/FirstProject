#include <stdio.h>
#include "player.h"

void init_player(struct player_t *player){
	player -> hp = 0;

};

int change_hp(struct player_t *player, int hp)
{
	if (hp => 30) player->hp = 30
	else player->hp += hp; 
	if (player->hp < 0) {player_>hp = 0}
}
