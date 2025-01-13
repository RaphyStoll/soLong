#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"


void	free_monsters(t_game *game)
{
	t_monster	*monster;
	t_monster	*tmp;

	if (!game || !game->monster)
		return ;
	monster = game->monster;
	while (monster)
	{
		tmp = monster->next;
		free(monster);
		monster = tmp;
	}
	game->monster = NULL;
}