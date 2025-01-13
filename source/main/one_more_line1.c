/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_more_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:03:30 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:09:41 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/game.h"
#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../mlx/mlx.h"

void	put_image_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->wall, x
		* game->window->title_size, y * game->window->title_size);
}

void	put_image_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->collectible, x
		* game->window->title_size, y * game->window->title_size);
}

void	put_image_exit(t_game *game, int x, int y)
{
	if (game->map->exit_isopen == 0)
		mlx_put_image_to_window(game->window->mlx_ptr,
			game->window->win_ptr, game->textures->exit_closed, x
			* game->window->title_size, y * game->window->title_size);
	else if (game->map->exit_isopen == 1)
		mlx_put_image_to_window(game->window->mlx_ptr,
			game->window->win_ptr, game->textures->exit_open, x
			* game->window->title_size, y * game->window->title_size);
}

void	put_image_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->player, x
		* game->window->title_size, y * game->window->title_size);
}

void	put_image_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->floor, x
		* game->window->title_size, y * game->window->title_size);
}
