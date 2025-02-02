/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:34:45 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:12 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"
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
		return (TRUE);
	}
	return (FALSE);
}
