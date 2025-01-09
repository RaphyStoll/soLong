#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../mlx/mlx.h"

int	close_window(t_game *game)
{
	ft_printf("Closing the window...\n");
	mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	free(game->window);
	free(game->map);
	free(game->textures);
	free(game);
	exit(0);
}