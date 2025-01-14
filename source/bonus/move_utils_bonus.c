/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:11 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:23 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

BOOL	is_void_case(char **map, int x, int y)
{
	if (map[y][x] == '0')
		return (TRUE);
	return (FALSE);
}

BOOL	is_collectible(char **map, int x, int y)
{
	if (map[y][x] == 'C')
		return (TRUE);
	return (FALSE);
}

BOOL	is_exit_close(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}

BOOL	is_exit_open(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (TRUE);
	return (FALSE);
}

BOOL	is_wall(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (TRUE);
	return (FALSE);
}
