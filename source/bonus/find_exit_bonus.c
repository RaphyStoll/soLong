/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:32:18 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:40:29 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find_player_x.c
#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

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
	return (default);
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
	return (default);
}
