/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:11 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:36:10 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

bool	is_void_case(char **map, int x, int y)
{
	if (map[y][x] == '0')
		return (true);
	return (false);
}

bool	is_collectible(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		return (true);
	return (false);
}

bool	is_exit_close(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (true);
	return (false);
}

bool	is_exit_open(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (true);
	return (false);
}

bool	is_wall(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (true);
	return (false);
}
