/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:21:36 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:22:04 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

// Fonction pour trouver la position x du joueur 'P' sur la carte
int	find_item_x(t_game *game)
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
			if (game->map->map[y][x] == 'C')
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	ft_exit_error("Error\nItem 'C' not found on the map");
	return (default);
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int	find_item_y(t_game *game)
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
	ft_exit_error("Error\nItem 'C' not found on the map");
	return (default);
}
