// find_player_x.c
#include "header_solong/fonction.h"
#include "header_solong/game.h"
#include "header_solong/macro.h"

// Fonction pour trouver la position x du joueur 'P' sur la carte
int find_item_x(t_game *game)
{
    int y;
    int x;

    if (!game->map || !game->map->map)
        ft_exit_error("Error\nMap data is invalid");

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->map[y][x] == 'C')
            {
                return (x);
            }
            x++;
        }
        y++;
    }
    ft_exit_error("Error\nItem 'C' not found on the map");
    return (default); // Valeur de retour par défaut (ne devrait jamais être atteinte)
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int find_item_y(t_game *game)
{
    int y;
    int x;

    if (!game->map || !game->map->map)
        ft_exit_error("Error\nMap data is invalid");

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->map[y][x] == 'P')
            {
                return (y);
            }
            x++;
        }
        y++;
    }
    ft_exit_error("Error\nItem 'C' not found on the map");
    return (default); // Valeur de retour par défaut (ne devrait jamais être atteinte)
}