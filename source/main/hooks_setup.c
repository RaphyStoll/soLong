/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:38:57 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:12 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/keymap.h"
#include "../includes/main/macro.h"
#include "../mlx/mlx.h"

int	handle_key(int keycode, t_game *game)
{
	int	i;

	i = 0;
	while (game->keymap[i].keycode)
	{
		if (game->keymap[i].keycode == keycode)
		{
			game->keymap[i].action(game);
			return (FALSE);
		}
		i++;
	}
	ft_printf("keycode non mappée= %d\n", keycode);
	return (FALSE);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window->win_ptr, 2, 1L << 0, handle_key, game);
	mlx_hook(game->window->win_ptr, 12, 1L << 15, redraw_window, game);
	mlx_hook(game->window->win_ptr, 17, 0L, close_window, game);
}
