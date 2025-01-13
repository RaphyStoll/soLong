/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:26 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:45:20 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void	put_player_texture(t_game *game, int target_x, int target_y, char a)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	if (a == 'U')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_up,
			target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'D')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			textures->player_down, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'L')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			textures->player_left, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'R')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			textures->player_right, target_x * TILE_SIZE, target_y * TILE_SIZE);
}

void	put_monster_texture(t_game *game, int target_x, int target_y)
{
	int			r;
	static int	seed;
	t_textures	*textures;
	t_window	*win;

	textures = game->textures;
	win = game->window;
	r = pseudo_random(seed++) % 4;
	if (r == 0)
		put_monster_up(game, target_x, target_y);
	else if (r == 1)
		put_monster_up(game, target_x, target_y);
	else if (r == 2)
		put_monster_up(game, target_x, target_y);
	else if (r == 3)
		put_monster_up(game, target_x, target_y);
}
