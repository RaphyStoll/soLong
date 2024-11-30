#include "header_solong/fonction.h"
#include "header_solong/maps.h"

void free_map(t_map *map)
{
	int i;

	if (!map)
		return;
    if (map->map)
    {
        i = 0;
        while (i < map->height)
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
    if (map->map_name)
        free(map->map_name);
    free(map);
}
