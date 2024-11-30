#include "header_solong/fonction.h"
#include "header_solong/maps.h"
#include "header_solong/window.h"

t_map *window_setup(t_map *map, t_window *window)
{
	window->mlx_ptr = mlx_init();
	window->title_size = 32;
	window->win_width = window->title_size * map->width;
	window->win_height = window->title_size * map->height;
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->win_width,
					window->win_height, "Solong");
	return (window);
}