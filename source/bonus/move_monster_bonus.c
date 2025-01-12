#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"

void	monster_move(t_game *game)
{
	t_monster *current = game->monster;
    int new_x, new_y;

    while (current)
    {
        // Exemple de logique de mouvement : un mouvement aléatoire
		static int seed;
        int direction = pseudo_random(seed++) % 4; // 0 = haut, 1 = bas, 2 = gauche, 3 = droite
        new_x = current->monster_x;
        new_y = current->monster_y;

        if (direction == 0 && is_walkable(game, new_x, new_y - 1))
            new_y--;
        else if (direction == 1 && is_walkable(game, new_x, new_y + 1))
            new_y++;
        else if (direction == 2 && is_walkable(game, new_x - 1, new_y))
            new_x--;
        else if (direction == 3 && is_walkable(game, new_x + 1, new_y))
            new_x++;

        // Met à jour la position si le mouvement est valide
        if (new_x != current->monster_x || new_y != current->monster_y)
        {
            current->old_monster_x = current->monster_x;
            current->old_monster_y = current->monster_y;
            current->monster_x = new_x;
            current->monster_y = new_y;
        }

        current = current->next;
    }
}

int is_walkable(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
        return (0);
    if (game->map->map[y][x] == '1') // '1' représente un mur
        return (0);
    return (1); // Case libre
}