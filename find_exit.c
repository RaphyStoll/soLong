// find_player_x.c
#include "header_solong/maps.h"
#include "header_solong/fonction.h"

// Fonction pour trouver la position x du joueur 'P' sur la carte
int find_exit_x(t_map *map)
{
    int y;
    int x;

    if (!map || !map->map)
        ft_exit_error("Error\nMap data is invalid");

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == 'E')
            {
                return x;
            }
            x++;
        }
        y++;
    }
    ft_exit_error("Error\nExit 'E' not found on the map");
    return -1; // Valeur de retour par défaut (ne devrait jamais être atteinte)
}

// Fonction pour trouver la position y du joueur 'P' sur la carte
int find_exit_y(t_map *map)
{
    int y;
    int x;

    if (!map || !map->map)
        ft_exit_error("Error\nMap data is invalid");

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->map[y][x] == 'E')
            {
                return y;
            }
            x++;
        }
        y++;
    }
    ft_exit_error("Error\nExit 'E' not found on the map");
    return -1; // Valeur de retour par défaut (ne devrait jamais être atteinte)
}