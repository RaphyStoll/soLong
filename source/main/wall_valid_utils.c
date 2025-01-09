#include "../includes/main/fonction.h"
#include "../includes/main/macro.h"
#include "../includes/main/maps.h"

int	validate_rectangle(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		if ((int)ft_strlen(map.map[y]) != map.width)
			return (false);
		y++;
	}
	return (true);
}
