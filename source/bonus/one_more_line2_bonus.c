/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_more_line2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:27 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:41:56 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void	put_monster_up(t_game *game, int target_x, int target_y)
{
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->textures->monster_up, target_x * TILE_SIZE, target_y * TILE_SIZE);
}
