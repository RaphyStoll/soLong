/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:16 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:23 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

BOOL	is_monster(char **map, int x, int y)
{
	if (map[y][x] == 'M')
		return (TRUE);
	return (FALSE);
}

void	moved_in_a_monster(t_game *game, char a)
{
	put_player_texture(game, game->map->player_x, game->map->player_y, a);
	run_lose_game(game);
	ft_printf("\033[31mPlayer is on a monster\033[0m\n");
	return ;
}
