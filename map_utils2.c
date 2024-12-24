#include "header_solong/fonction.h"
#include "header_solong/maps.h"

int isWall(t_map *map, int x, int y)
{
	if(map->map[x][y] == 1)
		return 1;
	return 0;
}
