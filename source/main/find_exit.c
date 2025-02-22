/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:39:51 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:53:49 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find_player_x.c
#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

// Fonction pour trouver la position x du joueur 'P' sur la carte
int	find_exit_x(t_game *game)
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
			if (game->map->map[y][x] == 'E')
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nExit 'E' not found on the map");
	return (DEFAULT);
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int	find_exit_y(t_game *game)
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
			if (game->map->map[y][x] == 'E')
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nExit 'E' not found on the map");
	return (DEFAULT);
}
