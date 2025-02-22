/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_setup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:01 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:41:36 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

t_monster	*monster_init(t_game *game)
{
	game->monster = malloc(sizeof(t_monster));
	if (!game->monster)
		ft_exit_error("Error\nt_monster malloc failed");
	game->monster = load_monsters(game);
	return (game->monster);
}

t_monster	*load_monsters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->map[y][x] == 'M')
			{
				monster_add(game, x, y);
			}
			x++;
		}
		y++;
	}
	return (game->monster);
}

t_monster	*monster_add(t_game *game, int x, int y)
{
	t_monster	*new_m;
	static int	id;

	new_m = malloc(sizeof(t_monster));
	if (!new_m)
		ft_exit_error("Error\nmonster malloc failed");
	new_m->id = id++;
	new_m->x = x;
	new_m->y = y;
	new_m->old_x = x;
	new_m->old_y = y;
	new_m->dir = 0;
	new_m->next = NULL;
	new_m->next = game->monster;
	game->monster = new_m;
	return (game->monster);
}
