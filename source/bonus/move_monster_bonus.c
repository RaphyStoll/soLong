#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include <time.h>

void	monster_move(t_game *game)
{
	t_monster	*current;
	int			dir;
	int seed;
	current = game->monster;
	while (current)
	{
		seed = rand();
		dir = pseudo_random(seed) % 4;
		if (dir == 0 && is_walkable(game, current->x, current->y - 1))
			move_monster_up(game, current);
		else if (dir == 1 && is_walkable(game, current->x, current->y + 1))
			move_monster_down(game, current);
		else if (dir == 2 && is_walkable(game, current->x - 1, current->y))
			move_monster_left(game, current);
		else if (dir == 3 && is_walkable(game, current->x + 1, current->y))
			move_monster_right(game, current);
		current = current->next;
	}
}
int is_walkable(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	if (game->map->map[y][x] == '1' || game->map->map[y][x] == 'C')
		return (0);
	return (1);
}
