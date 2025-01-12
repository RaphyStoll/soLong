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