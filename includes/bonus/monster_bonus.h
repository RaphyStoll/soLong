#ifndef MONSTER_BONUS_H
#define MONSTER_BONUS_H

#include "game_bonus.h"

typedef struct s_monster
{
	int id;
	int x;
	int y;
	int old_x;
	int old_y;
	int dir;
	struct s_monster *next;
} t_monster;

#endif