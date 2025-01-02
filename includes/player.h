#ifndef PLAYER_H
#define PLAYER_H



#include <stdlib.h>
#include <stdio.h>


typedef struct s_stat {
    int current;
    int max;
} t_stat;

typedef struct s_player {
	char	*class;
	int		health;
	int		regeneration;
	int		damage;
	int		defense;
	int		melee_damage;
	int		range_damage;
	int		elemental_damage;
	int		attack_speed;
	int		critical_rate;
	int		critical_damage;
	int		dodge;
	int		speed;
	int		luck;
	int		armor_penetration;

} t_player;

#endif