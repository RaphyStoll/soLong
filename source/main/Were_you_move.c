#include "../includes/main/fonction.h"
#include "../includes/main/game.h"

void	move_is_possible(t_game *game, int target_x, int target_y)
{
	if (is_wall(game->map->map, target_x, target_y))
		moved_in_a_wall(game);
	else if (is_exit_close(game->map->map, target_x, target_y)
		&& (game->map->collected != game->map->items))
		moved_in_a_closed_exit(game, target_x, target_y);
	else if (is_exit_open(game->map->map, target_x, target_y)
		&& (game->map->exit_isopen == 1))
		moved_in_an_open_exit(game, target_x, target_y);
	else if (is_collectible(game->map->map, target_x, target_y))
		moved_in_a_collectible(game, target_x, target_y);
	else if (is_void_case(game->map->map, target_x, target_y))
		moved_in_a_void_case(game, target_x, target_y);
	return ;
}
