# include "header_solong/fonction.h"

int	validate_wall(char **map, int width, int height, char *map_name)
{
	int linecount;

	linecount = count_lines(map_name);
	ft_printf("\nValidating map\n");
	ft_printf("Map dimensions: %d x %d|\n", width, height);
	ft_printf("1st line: %s|\n", map[0]);
	ft_printf("Last line: %s|\n", map[height - 1]);
	ft_printf("1st column: %c|\n", map[0][0]);
	ft_printf("Last column: %c|\n", map[height - 1][width - 1]);
    if (!map || width <= 0 || height <= 0)
        ft_exit_error("Error\nInvalid map dimensions or null pointer");
	ft_printf("Map is not null\n");
    if (!validate_rectangle(map, width, height, linecount - 1))
        ft_exit_error("Error\nMap is not rectangular");
	ft_printf("Map is rectangular\n");
    if (!validate_first_line(map, width))
        ft_exit_error("Error\n1st line is not valid");
	ft_printf("1st line is valid\n");
    if (!validate_last_line(map, width, height))
        ft_exit_error("Error\nLast line is not valid");
	ft_printf("Last line is valid\n");
    if (!validate_first_column(map, height))
        ft_exit_error("Error\n1st column is not valid");
	ft_printf("1st column is valid\n");
    if (!validate_last_column(map, width, height))
        ft_exit_error("Error\nLast column is not valid");
	ft_printf("Last column is valid\n");
    ft_printf("Map is valid\n");
	return (1);
}

int	validate_first_line(char **map, int width)
{
    int	x;

    x = 0;
    while (x < width)
    {
        if (map[0][x] != '1')
            return (0);
        x++;
    }
    return (1);
}

int	validate_last_line(char **map, int width, int height)
{
    int	x;

    x = 0;
    while (x < width)
    {
        if (map[height - 1][x] != '1')
            return (0);
        x++;
    }
    return (1);
}

int	validate_first_column(char **map, int height)
{
    int	y;

    y = 0;
    while (y < height)
    {
        if (map[y][0] != '1')
            return (0);
        y++;
    }
    return (1);
}

int	validate_last_column(char **map, int width, int height)
{
    int	y;

    y = 0;
    while (y < height)
    {
        if (map[y][width - 1] != '1')
            return (0);
        y++;
    }
    return (1);
}
