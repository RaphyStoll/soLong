#include "header_solong/fonction.h"
#include "header_solong/game.h"
#include "mlx/mlx.h"

int	close_window(void *param)
{
	t_game *game;

    game = (t_game *)param;
    ft_printf("Closing the window...\n");
    mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
    free(game->window);
    free(game->map);
    free(game->textures);
    free(game);
    exit(0);
}