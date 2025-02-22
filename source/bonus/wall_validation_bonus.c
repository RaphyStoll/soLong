/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_validation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:39 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:12 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../includes/bonus/maps_bonus.h"

int	validate_wall(t_map *map)
{
	if (!map->map || map->width <= 0 || map->height <= 0)
		ft_exit_error("Error\nInvalid map dimensions or null pointer");
	if (!validate_rectangle(*map))
		ft_exit_error("Error\nMap is not rectangular");
	if (!validate_first_line(*map))
		ft_exit_error("Error\n1st line is not valid");
	if (!validate_last_line(*map))
		ft_exit_error("Error\nLast line is not valid");
	if (!validate_first_column(*map))
		ft_exit_error("Error\n1st column is not valid");
	if (!validate_last_column(*map))
		ft_exit_error("Error\nLast column is not valid");
	return (TRUE);
}

int	validate_first_line(t_map map)
{
	int	x;

	x = 0;
	while (x < map.width)
	{
		if (map.map[0][x] != '1')
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	validate_last_line(t_map map)
{
	int	x;

	x = 0;
	while (x < map.width)
	{
		if (map.map[map.height - 1][x] != '1')
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	validate_first_column(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		if (map.map[y][0] != '1')
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	validate_last_column(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		if (map.map[y][map.width - 1] != '1')
			return (FALSE);
		y++;
	}
	return (TRUE);
}
