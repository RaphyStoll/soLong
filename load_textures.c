#include "header_solong/game.h"
#include "mlx/mlx.h"

void put_textures(t_game *game)
{
    int x;
	int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->floor, x * game->window->title_size, y * game->window->title_size);
            if (game->map->map[y][x] == '1')
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->wall, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'C')
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->collectible, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'P')
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->player, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 0)
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->exit_closed, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 1)
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->exit_open, x * game->window->title_size, y * game->window->title_size);
            x++;
        }
        y++;
    }
}

void load_textures(t_game *game)
{
    int width;
    int height;

	ft_printf("mlx_ptr = %d\n", game->window->mlx_ptr);
    game->textures->floor = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/background.xpm", &width, &height);
	if(!game->textures->floor)
		ft_exit_error("Error\nloading floor failed");
    game->textures->wall = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/wall.xpm", &width, &height);
    game->textures->collectible = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/collectable.xpm", &width, &height);
    game->textures->player = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/ship_left.xpm", &width, &height);
    game->textures->exit_closed = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/exit.xpm", &width, &height);
    game->textures->exit_open = mlx_xpm_file_to_image(game->window->mlx_ptr, "textures/test1/exit.xpm", &width, &height);
    if (!game->textures->floor || !game->textures->wall || !game->textures->collectible ||
        !game->textures->player || !game->textures->exit_closed || !game->textures->exit_open)
    {
        ft_exit_error("Error\nFailed to load one or more textures\n");
    }
}
