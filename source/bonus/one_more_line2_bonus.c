/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_more_line2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:27 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:45:32 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

void	put_monster_up(t_game *game, int target_x, int target_y)
{
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		game->textures->monster_up, target_x * TILE_SIZE, target_y * TILE_SIZE);
}
