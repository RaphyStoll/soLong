#include "header_solong/fonction.h"
#include "header_solong/textures.h"
#include "mlx/mlx.h"

#define TILE_SIZE 32 // Taille de chaque case (en pixels)

void put_textures(t_textures *textures, t_map *map, void *mlx_ptr, void *win_ptr)
{
    int x;
	int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            mlx_put_image_to_window(mlx_ptr, win_ptr, textures->floor, x * TILE_SIZE, y * TILE_SIZE);
            if (map->map[y][x] == '1')
                mlx_put_image_to_window(mlx_ptr, win_ptr, textures->wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (map->map[y][x] == 'C')
                mlx_put_image_to_window(mlx_ptr, win_ptr, textures->collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (map->map[y][x] == 'P')
                mlx_put_image_to_window(mlx_ptr, win_ptr, textures->player, x * TILE_SIZE, y * TILE_SIZE);
            else if (map->map[y][x] == 'E' && map->exit_isopen == 0)
                mlx_put_image_to_window(mlx_ptr, win_ptr, textures->exit_closed, x * TILE_SIZE, y * TILE_SIZE);
            else if (map->map[y][x] == 'E' && map->exit_isopen == 1)
                mlx_put_image_to_window(mlx_ptr, win_ptr, textures->exit_open, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void load_textures(t_textures *textures, void *mlx_ptr)
{
    int width;
    int height;

	ft_printf("mlx_ptr = %d\n", mlx_ptr);
    textures->floor = mlx_xpm_file_to_image(mlx_ptr, "textures/floor.xpm", &width, &height);
	if(!textures->floor)
		ft_exit_error("Error\nloading floor failed");
    textures->wall = mlx_xpm_file_to_image(mlx_ptr, "textures/wall.xpm", &width, &height);
    textures->collectible = mlx_xpm_file_to_image(mlx_ptr, "textures/collectible.xpm", &width, &height);
    textures->player = mlx_xpm_file_to_image(mlx_ptr, "textures/player.xpm", &width, &height);
    textures->exit_closed = mlx_xpm_file_to_image(mlx_ptr, "textures/exit_closed.xpm", &width, &height);
    textures->exit_open = mlx_xpm_file_to_image(mlx_ptr, "textures/exit_open.xpm", &width, &height);
    if (!textures->floor || !textures->wall || !textures->collectible ||
        !textures->player || !textures->exit_closed || !textures->exit_open)
    {
        ft_exit_error("Error\nFailed to load one or more textures\n");
    }
}
