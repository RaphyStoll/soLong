#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../mlx/mlx.h"

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
	game->window->max_w = get_monitor_size(game, 'w');
	game->window->max_h = get_monitor_size(game, 'h');
	if(game->window->max_h == -1 || game->window->max_w == -1)
		ft_exit_error("Error\nmax_h or max_h = -1");
	if(game->window->win_height > game->window->max_h)
		ft_exit_error("Error\nMap is biggest than monitor height");
	if(game->window->win_width > game->window->max_w)
		ft_exit_error("Error\nMap is biggest than monitor width");
	return (game->window);
}

int	get_monitor_size(t_game *game, char a)
{
	int max_w;
	int max_h;

	if (mlx_get_screen_size(game->window->mlx_ptr, &max_w, &max_h) == 0)
	{
		ft_printf("Screen size: %d x %d\n", max_w, max_h);
	}
	if (a == 'w')
		return (max_w);
	else if (a == 'h')
		return (max_h);
	return (default);
}

int redraw_window(void *param)
{
    t_game *game;

    game = (t_game *)param;
    put_textures(game);
    return (false);
}