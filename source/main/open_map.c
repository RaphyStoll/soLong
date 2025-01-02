#include "../gnl/get_next_line.h"
#include "../includes/main/fonction.h"

// Ouvrir un fichier et retourner le descripteur de fichier
int open_new_map(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	//$ ft_printf("fd = %d\n", fd);
	if (fd < 0)
		ft_exit_error("Error\nFailed to open map file");
	return (fd);
}

// Lire les lignes d'un fichier et les stocker dans un tableau
char **read_map(int fd)
{
	//$ ft_printf("fd read = %d\n", fd);
	char	**map;
	char	*line;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * 1000);
	if (!map)
		ft_exit_error("Error\nFailed to allocate memory for map");
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i++] = line;
	}
	map[i] = NULL;
	return (map);
}

// Ouvrir un fichier, lire les lignes et les stocker dans un tableau
char **open_and_read_map(char *map_name)
{
    char	**map;
    int		lines_count;
	int		fd;

    // Compter les lignes pour allouer `map`
	lines_count = count_lines(map_name);
    // Rouvrir le fichier pour lire les lignes
    fd = open_new_map(map_name);

	//$ ft_printf("fd = %d\n", fd);
	//$ ft_printf("fd open and read = %d\n", fd);
    // Allouer de l'espace pour la carte
    map = malloc(sizeof(char *) * (lines_count + 1));
    if (!map)
		ft_exit_error("Error\nFailed to allocate memory for map");
    // Lire les lignes et les stocker dans `map`
	map = read_map(fd);
    close(fd);
	remove_all_newlines(map);
    return (map);
}
