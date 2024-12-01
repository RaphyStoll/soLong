#include "header_solong/fonction.h"
#include "header_solong/game.h"
#include "mlx/mlx.h"

t_window *window_init(t_game *game)
{
	//$ ft_printf("==window init==\n");
	game->window = malloc(sizeof(t_window));
	//$ ft_printf("window malloc1\n");
	if (!game->window)
		ft_exit_error("Error\nt_window malloc failed");
	//$ ft_printf("window malloc2\n");
	game->window = window_setup(game);
	//$ ft_printf("window setup\n");
	//$ ft_printf("==window init ok==\n");
	return (game->window);
}

t_window	*window_setup(t_game *game)
{

	game->window->mlx_ptr = mlx_init();
	if(!game->window->mlx_ptr)
		ft_exit_error("Error\nmlx_init failed");
	game->window->title_size = 32;
	game->window->win_width = game->window->title_size * game->map->width;
	game->window->win_height = game->window->title_size * game->map->height;
	game->window->win_ptr = mlx_new_window(game->window->mlx_ptr,
			game->window->win_width,
			game->window->win_height, "Solong");
	if(!game->window->win_ptr)
		ft_exit_error("Error\nmlx_new_window failed");
	return (game->window);
}
