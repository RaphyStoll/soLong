#include "header_solong/maps.h"
#include "header_solong/fonction.h"

t_map	*map_init(char *map_name)
{
	t_map	*map;

	map = NULL;
	map = malloc(sizeof(t_map));
	map_setup(map, map_name);
	valid_map(map);
	return (map);
}

//set les valeurs de base de la structure map
t_map	*map_setup(t_map *map, char *av)
{

	//$ ft_printf("\n===map_setup===\n"); //$
	map->map_name = av;
	map->moves = 0;
	map->collected = 0;
	map->exit_isopen = 0;
	//$ ft_printf("mapname = %s\n", map->map_name);
	//$ ft_printf("moves = %d\n",map->moves);
	//$ ft_printf("collected = %d\n",map->collected);
	//$ ft_printf("exit = %d\n",map->exit_isopen);
	map->height = count_lines(map->map_name);
	//$ ft_printf("height = %d\n",map->height); //$
	map->width = count_width(map->map_name);
	//$ ft_printf("width = %d\n",map->width);
	map->map = open_and_read_map(map->map_name);
	map->items = count_item(map);
	//$ ft_printf("items = %d\n",map->items);
	map->exit = count_exit(map);
	map->player = count_player(map);
	map->player_x = find_player_x(map);
	map->player_y = find_player_y(map);
	//$ ft_printf("player x = %d y = %d\n",map->player_x, map->player_y);
	//$ ft_printf("===Ok===\n\n");
	return (map);
}
