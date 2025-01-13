/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:38:29 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:38:31 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../mlx/mlx.h"

int	close_window(t_game *game)
{
	ft_printf("Closing the window...\n");
	mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	free_all(game);
	exit(0);
}
