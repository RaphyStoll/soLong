/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:21 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:33:23 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

int	exit_is_open(t_game *game)
{
	if (game->map->items == game->map->collected)
	{
		game->map->exit_isopen = 1;
		game->map->map[game->map->exit_y][game->map->exit_x] = 'E';
		mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
			game->textures->exit_open, game->map->exit_x
			* game->window->title_size, game->map->exit_y
			* game->window->title_size);
		ft_printf("\033[36mPlayer collected all items\033[0m\n");
		ft_printf("\033[36mexit is open\033[0m\n");
		return (true);
	}
	return (false);
}
