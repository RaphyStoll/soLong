/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:32:27 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:53:49 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// find_player_x.c
#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

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
	return (DEFAULT);
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
	return (DEFAULT);
}
