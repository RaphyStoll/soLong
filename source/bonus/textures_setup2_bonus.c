/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:53:21 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:01:57 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void	textures_setup_monstrer(t_game *game)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	textures->monster_up = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/monster_up_red.xpm", &textures->width,
			&textures->height);
	textures->monster_down = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/monster_down_red.xpm", &textures->width,
			&textures->height);
	textures->monster_right = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/monster_right_red.xpm", &textures->width,
			&textures->height);
	textures->monster_left = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/monster_left_red.xpm", &textures->width,
			&textures->height);
	if (!textures->monster_up || !textures->monster_down
		|| !textures->monster_left || !textures->monster_right)
		ft_exit_error("Error\ntextures_monster_setup failed");
}

void	textures_setup_player(t_game *game)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	textures->player_up = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/ship_up.xpm", &textures->width, &textures->height);
	textures->player_down = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/ship_down.xpm", &textures->width,
			&textures->height);
	textures->player_left = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/ship_left.xpm", &textures->width,
			&textures->height);
	textures->player_right = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/ship_right.xpm", &textures->width,
			&textures->height);
	if (!textures->player_up || !textures->player_down
		|| !textures->player_left || !textures->player_right)
		ft_exit_error("Error\ntextures_monster_setup failed");
}
