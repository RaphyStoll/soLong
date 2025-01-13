/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:43 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:38:18 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../mlx/mlx.h"

int	close_window(t_game *game)
{
	ft_printf("Closing the window...\n");
	mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	free_all(game);
	exit(0);
}
