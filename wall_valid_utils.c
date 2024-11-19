#include "header_solong/fonction.h"

int	validate_rectangle(char **map, int width, int height, int linecount)
{
    int	y;

    y = 0;
    while (y < height && y < linecount)
    {
        if ((int)ft_strlen(map[y]) != width)
            return (0);
        y++;
    }
    return (1);
}
