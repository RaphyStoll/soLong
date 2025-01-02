#include "../includes/main/fonction.h"
#include "../includes/main/maps.h"
#include "../includes/main/macro.h"

int	validate_rectangle(t_map map)
{
	//$ ft_printf("=====is_rectangle====\n");
    int	y;

    y = 0;
    while (y < map.height)
    {
        if ((int)ft_strlen(map.map[y]) != map.width)
            return (false);
        y++;
    }

	//$ ft_printf("====end===="); //$
    return (true);
}
