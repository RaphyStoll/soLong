/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:25:25 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:23 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

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
