#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

t_monster	*monster_init(t_game *game)
{
	ft_printf("monster_init\n");
	game->monster = malloc(sizeof(t_monster));
	if (!game->monster)
		ft_exit_error("Error\nt_monster malloc failed");
	game->monster = load_monsters(game);
	ft_printf("monster_init end\n");
	return (game->monster);
}

t_monster *load_monsters(t_game *game)
{
    int y = 0;
    while (y < game->map->height)
    {
        int x = 0;
        while (x < game->map->width)
        {
            if (game->map->map[y][x] == 'M')
                monster_add(game, x, y);
            x++;
        }
        y++;
    }
	return (game->monster);
}

t_monster *monster_add(t_game *game, int x, int y)
{
    t_monster *new_m;
	static int id;
    new_m = malloc(sizeof(t_monster));
    if (!new_m)
        ft_exit_error("Error\nmonster malloc failed");

    new_m->id = id++; 
	ft_printf("monster id = %d\n", new_m->id);
    new_m->monster_x = x;
    new_m->monster_y = y;
    new_m->old_monster_x = x;
    new_m->old_monster_y = y;
    new_m->dir = 0;
    new_m->next = NULL;
    new_m->next = game->monster;
    game->monster = new_m;
	return (game->monster);
}