#include "header/fonction.h"
#include "header/player.h"

void	set_guerrier(t_player *player)
{
	player->class = "GUERRIER";
	player->health = 5;
	player->regeneration = 10;
	player->damage = 10;
	player->defense = 10;
	player->melee_damage = 10;
	player->range_damage = 0;
	player->elemental_damage = 0;
	player->attack_speed = 1;
	player->critical_rate = 1;
	player->critical_damage = 100;
	player->dodge = 1;
	player->speed = 1;
	player->luck = 1;
	player->armor_penetration = 1;
}

void	set_archer(t_player *player)
{
	player->class = "ARCHER";
	player->health = 3;
	player->regeneration = 10;
	player->damage = 10;
	player->defense = 10;
	player->melee_damage = 0;
	player->range_damage = 10;
	player->elemental_damage = 0;
	player->attack_speed = 1;
	player->critical_rate = 1;
	player->critical_damage = 100;
	player->dodge = 1;
	player->speed = 1;
	player->luck = 1;
	player->armor_penetration = 1;
}

void	set_mage(t_player *player)
{
	player->class = "MAGE";
	player->health = 3;
	player->regeneration = 10;
	player->damage = 10;
	player->defense = 10;
	player->melee_damage = 0;
	player->range_damage = 0;
	player->elemental_damage = 10;
	player->attack_speed = 1;
	player->critical_rate = 1;
	player->critical_damage = 100;
	player->dodge = 1;
	player->speed = 1;
	player->luck = 1;
	player->armor_penetration = 1;
}

void	set_chevalier(t_player *player)
{
	player->class = "CHEVALIER";
	player->health = 4;
	player->regeneration = 10;
	player->damage = 10;
	player->defense = 10;
	player->melee_damage = 10;
	player->range_damage = 0;
	player->elemental_damage = 0;
	player->attack_speed = 1;
	player->critical_rate = 1;
	player->critical_damage = 100;
	player->dodge = 1;
	player->speed = 1;
	player->luck = 1;
	player->armor_penetration = 1;
}

void set_class(t_player *player, char *className)
{
	if (ft_strcmp(className, "GUERRIER") == 0)
		set_guerrier(player);
	else if (ft_strcmp(className, "ARCHER") == 0)
		set_archer(player);
	else if (ft_strcmp(className, "MAGE") == 0)
		set_mage(player);
	else if (ft_strcmp(className, "CHEVALIER") == 0)
		set_chevalier(player);
	else
	{
		printf("Invalid class\n");
		exit(1);
	}
}