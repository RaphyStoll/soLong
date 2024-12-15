#include "header_solong/game.h"
#include "header_solong/fonction.h"

int is_void_case(char **map, int x, int y)
{
	if (map[y][x] == '0')
		return (1);
	return (0);
}
int is_collectible(char **map, int x, int y)
{
    if (map[y][x] == 'C')
        return (1);
    return (0);
}

int is_exit_close(char **map, int x, int y)
{
    if (map[y][x] == 'E')
        return (1);
    return (0);
}

int is_exit_open(char **map, int exit_open, int x, int y)
{
    if (map[y][x] == 'E' && exit_open == 1)
        return (1);
    return (0);
}

int is_wall(char **map, int x, int y)
{
    if (map[y][x] == '1')
        return (1);
    return (0);
}
