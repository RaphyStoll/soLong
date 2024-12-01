#include "header_solong/fonction.h"
#include "header_solong/maps.h"

t_map	*map_init(t_game *game, char *av)
{

	game->map = NULL;
	game->map = malloc(sizeof(t_map));
	if(!game->map)
		ft_exit_error("Error\nt_map malloc failed");
	map_setup(game, av);
	valid_map(game->map);
	return (game->map);
}

//set les valeurs de base de la structure map
t_map	*map_setup(t_game *game, char *av)
{

	//$ ft_printf("\n===map_setup===\n"); //$
	game->map->map_name = av;
	game->map->moves = 0;
	game->map->collected = 0;
	game->map->exit_isopen = 0;
	//$ ft_printf("mapname = %s\n", map->map_name);
	//$ ft_printf("moves = %d\n",map->moves);
	//$ ft_printf("collected = %d\n",map->collected);
	//$ ft_printf("exit = %d\n",map->exit_isopen);
	game->map->height = count_lines(game->map->map_name);
	//$ ft_printf("height = %d\n",map->height); //$
	game->map->width = count_width(game->map->map_name);
	//$ ft_printf("width = %d\n",map->width);
	game->map->map = open_and_read_map(game->map->map_name);
	game->map->items = count_item(game->map);
	//$ ft_printf("items = %d\n",map->items);
	game->map->exit = count_exit(game->map);
	game->map->player = count_player(game->map);
	game->map->player_x = find_player_x(game);
	game->map->player_y = find_player_y(game);
	//$ ft_printf("player x = %d y = %d\n",map->player_x, map->player_y);
	//$ ft_printf("===Ok===\n\n");
	return (game->map);
}
