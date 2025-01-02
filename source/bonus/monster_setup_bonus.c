#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

t_monster	*monster_init(t_game *game)
{
	game->monster = malloc(sizeof(t_monster));
	if (!game->monster)
		ft_exit_error("Error\nt_monster malloc failed");
	game->monster = monster_setup(game);
	monster_setup(game);
	return (game->monster);
}

t_monster	*monster_setup(t_game *game)
{
	game->monster->id = 1;
	game->monster->monster_x = find_monster_x(game);
	game->monster->monster_y = find_monster_y(game);
	game->monster->old_monster_x = game->monster->monster_x;
	game->monster->old_monster_y = game->monster->monster_y;
	game->monster->dir = 0;
	game->monster->next = NULL;
}
