#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../includes/bonus/maps_bonus.h"

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
