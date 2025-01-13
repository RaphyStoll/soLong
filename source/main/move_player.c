/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:40:49 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:40:50 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

int	move_player_up(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y - 1;
	move_is_possible(game, target_x, target_y);
	ft_printf("Moves = %d\n", game->map->moves);
	return (false);
}

int	move_player_down(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y + 1;
	move_is_possible(game, target_x, target_y);
	ft_printf("Moves = %d\n", game->map->moves);
	return (false);
}

int	move_player_left(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x - 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y);
	ft_printf("Moves = %d\n", game->map->moves);
	return (false);
}

int	move_player_right(t_game *game)
{
	int	target_x;
	int	target_y;

	target_x = game->map->player_x + 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y);
	ft_printf("Moves = %d\n", game->map->moves);
	return (false);
}
