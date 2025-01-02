#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

t_textures	*textures_init(t_game *game)
{
	game->textures = NULL;
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		ft_exit_error("Error\nt_textures malloc failed");
	game->textures = textures_setup(game);
	put_textures(game);
	return (game->textures);
}

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
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->player_up, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 0)
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->exit_closed, x * game->window->title_size, y * game->window->title_size);
            else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 1)
                mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->exit_open, x * game->window->title_size, y * game->window->title_size);
            x++;
        }
        y++;
    }
}

t_textures *textures_setup(t_game *game)
{
	t_window *win;
	t_textures *textures;

	win = game->window;
	textures = game->textures;
    textures->floor = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/background.xpm", &textures->width, &textures->height);
	textures->wall = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/wall.xpm", &textures->width, &textures->height);
    textures->collectible = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/collectable.xpm", &textures->width, &textures->height);
	textures->player_up = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/ship_up.xpm", &textures->width, &textures->height);
	textures->player_down = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/ship_down.xpm", &textures->width, &textures->height);
	textures->player_left = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/ship_left.xpm", &textures->width, &textures->height);
	textures->player_right = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/ship_right.xpm", &textures->width, &textures->height);
	textures->exit_closed = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/exit_closed.xpm", &textures->width, &textures->height);
	textures->exit_open = mlx_xpm_file_to_image(win->mlx_ptr,
	"textures/test1/exit.xpm", &textures->width, &textures->height);
	return (game->textures);
}

void redraw(t_game *game, int target_x, int target_y, char a)
{	
	t_map		*map;
	t_window	*win;
	t_textures	*textures;
	char		old_cell;
	char		new_cell;

	map = game->map;
	win = game->window;
	textures = game->textures;
	old_cell = map->map[map->old_player_y][map->old_player_x];
	new_cell = map->map[map->player_y][map->player_x];
	if (old_cell == '0')
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->floor, map->old_player_x * TILE_SIZE, map->old_player_y * TILE_SIZE);
    else if (old_cell == 'C')
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->collectible, map->old_player_x * TILE_SIZE, map->old_player_y * TILE_SIZE);
    else if (old_cell == 'E')
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->exit_closed, map->old_player_x * TILE_SIZE, map->old_player_y * TILE_SIZE);
	if (new_cell == '1')
    	return ;
	put_player_texture(game, target_x, target_y, a);
}


void put_player_texture(t_game *game, int target_x, int target_y, char a)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	if (a == 'U')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_up, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'D')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_down, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'L')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_left, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'R')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_right, target_x * TILE_SIZE, target_y * TILE_SIZE);
}