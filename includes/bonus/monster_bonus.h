#ifndef MONSTER_BONUS_H
#define MONSTER_BONUS_H

#include "game_bonus.h"

typedef struct s_monster
{
	int id;
	int monster_x;
	int monster_y;
	int old_monster_x;
	int old_monster_y;
	int dir;
	struct s_monster *next;
} t_monster;

#endif