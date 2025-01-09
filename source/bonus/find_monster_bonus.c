#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

int	find_monster_x(t_game *game)
{
	int	y;
	int	x;

	if (!game->map || !game->map->map)
		ft_exit_error("Error\nMap data is invalid");
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'M')
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nMonster 'M' not found on the map");
	return (default);
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int	find_monster_y(t_game *game)
{
	int y;
	int x;

	if (!game->map || !game->map->map)
		ft_exit_error("Error\nMap data is invalid");

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'P')
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nMonster 'M' not found on the map");
	return (default);
}