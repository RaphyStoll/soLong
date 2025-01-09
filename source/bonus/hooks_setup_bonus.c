#include "../../mlx/mlx.h"
#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/keymap_bonus.h"
#include "../includes/bonus/macro_bonus.h"

int	handle_key(int keycode, t_game *game)
{
	int	i;

	i = 0;
	while (game->keymap[i].keycode)
	{
		if (game->keymap[i].keycode == keycode)
		{
			game->keymap[i].action(game);
			return (false);
		}
		i++;
	}
	ft_printf("keycode non mappée= %d\n", keycode);
	return (false);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window->win_ptr, 2, 1L << 0, handle_key, game);
	mlx_hook(game->window->win_ptr, 12, 1L << 15, redraw_window, game);
	mlx_hook(game->window->win_ptr, 17, 0L, close_window, game);
}