/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:25:25 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:25:27 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

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
