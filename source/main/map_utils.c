#include "../includes/main/fonction.h"
#include "../includes/main/maps.h"

// Comptez le nombre de lignes dans un fichier
int	count_lines(char *map_name)
{
	char	*line;
	int		lines_count;
	int		fd;

	lines_count = 0;
	fd = open_new_map(map_name);
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		lines_count++;
	}
	close(fd);
	return (lines_count);
}

// Compte la largeur de la carte en lisant la première ligne du fichier
int	count_width(char *map_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open_new_map(map_name);
	if (fd < 0)
		ft_exit_error("Error\nFailed to open the map file for width counting");
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_exit_error("Error\nMap file is empty");
	}
	width = ft_strlen(line);
	free(line);
	close(fd);
	return (width - 1);
}

// compte le nombre d'item total a collecter
int	count_item(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	count_exit(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	count_player(t_map *map)
{
	int y;
	int x;
	int count;

	count = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}