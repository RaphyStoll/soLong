/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:39:08 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:39:39 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find_player_x.c
#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

// Fonction pour trouver la position x du joueur 'P' sur la carte
int	find_player_x(t_game *game)
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
			if (game->map->map[y][x] == 'P')
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nPlayer 'P' not found on the map");
	return (default);
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int	find_player_y(t_game *game)
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
			if (game->map->map[y][x] == 'P')
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nPlayer 'P' not found on the map");
	return (default);
}
