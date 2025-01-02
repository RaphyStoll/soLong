#include "../includes/main/game.h"
#include "../includes/main/fonction.h"
#include "../includes/main/macro.h"
#include "../mlx/mlx.h"

int exit_is_open(t_game *game)
{
	if (game->map->items == game->map->collected)
	{
		//$ft_printf("exit x = %d, exit y = %d\n", game->map->exit_x, game->map->exit_y);
		game->map->exit_isopen = 1;
		game->map->map[game->map->exit_y][game->map->exit_x] = 'E';
		mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->exit_open, game->map->exit_x * game->window->title_size, game->map->exit_y * game->window->title_size);
		ft_printf("\033[36mPlayer collected all items\033[0m\n");
		ft_printf("\033[36mexit is open\033[0m\n");
		return (true);
	}
	return (false);
}

