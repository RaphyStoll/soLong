/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:32:50 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:23 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/macro_bonus.h"

BOOL	have_item(t_map *map)
{
	if (map->items > 0)
		return (TRUE);
	return (FALSE);
}

BOOL	have_exit(t_map *map)
{
	if (map->exit == 1)
		return (TRUE);
	return (FALSE);
}

BOOL	have_player(t_map *map)
{
	if (map->player == 1)
		return (TRUE);
	return (FALSE);
}

int	have_other(t_map *map)
{
	int	y;
	int	x;

	if (!map || !map->map)
		ft_exit_error("Error\nMap data is invalid");
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] != 'C' && map->map[y][x] != 'P'
				&& map->map[y][x] != '0' && map->map[y][x] != '1'
				&& map->map[y][x] != 'E' && map->map[y][x] != 'M')
			{
				return (FALSE);
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	valid_map(t_map *map)
{
	if (!have_other(map))
		ft_exit_error("Error\nautre symbol non autoriser dans .ber\n");
	if (!validate_wall(map))
		ft_exit_error("Error\nWall is not valid\n");
	if (!have_item(map))
		ft_exit_error("Eroor\nItem not found\n");
	if (!have_exit(map))
		ft_exit_error("Error\nExit not found or > 1\n");
	if (!have_player(map))
		ft_exit_error("Error\nPlayer not found or > 1\n");
}
