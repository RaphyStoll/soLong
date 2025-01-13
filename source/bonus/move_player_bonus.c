/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:09 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:33:10 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

int	move_player_up(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y - 1;
	move_is_possible(game, target_x, target_y, 'U');
	put_moves(game);
	return (false);
}

int	move_player_down(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y + 1;
	move_is_possible(game, target_x, target_y, 'D');
	put_moves(game);
	return (false);
}

int	move_player_left(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x - 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y, 'L');
	put_moves(game);
	return (false);
}

int	move_player_right(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x + 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y, 'R');
	put_moves(game);
	return (false);
}
