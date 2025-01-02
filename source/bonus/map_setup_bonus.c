#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/maps_bonus.h"

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
	//$ft_printf("\n===map_setup===\n"); //$
	game->map->map_name = av;
	game->map->moves = 0;
	game->map->collected = 0;
	game->map->exit_isopen = 0;
	game->map->height = count_lines(game->map->map_name);
	game->map->width = count_width(game->map->map_name);
	game->map->map = open_and_read_map(game->map->map_name);
	game->map->items = count_item(game->map);
	game->map->exit = count_exit(game->map);
	game->map->player = count_player(game->map);
	game->map->player_x = find_player_x(game);
	game->map->player_y = find_player_y(game);
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->exit_x = find_exit_x(game);
	game->map->exit_y = find_exit_y(game);

	/* //$
	int y = 0;
	int x = 0;
	ft_printf("map_name: %s\n", game->map->map_name); //$
	while(x < game->map->height)
	{
		y = 0;
		while(y < game->map->width)
		{
			ft_printf("%c", game->map->map[x][y]); //$
			y++;
		}
		ft_printf("\n"); //$
		x++;
	}
	ft_printf("height: %d\n", game->map->height); //$
	ft_printf("width: %d\n", game->map->width); //$
	ft_printf("collected: %d\n", game->map->collected); //$
	ft_printf("moves: %d\n", game->map->moves); //$
	ft_printf("items: %d\n", game->map->items); //$
	ft_printf("player: %d\n", game->map->player); //$
	ft_printf("player_x: %d\n", game->map->player_x); //$
	ft_printf("player_y: %d\n", game->map->player_y); //$
	ft_printf("exit: %d\n", game->map->exit); //$
	ft_printf("exit_x: %d\n", game->map->exit_x); //$
	ft_printf("exit_y: %d\n", game->map->exit_y); //$
	ft_printf("exit_isopen: %d\n", game->map->exit_isopen); //$
	*/
	return (game->map);
}
