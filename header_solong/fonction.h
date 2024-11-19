#ifndef FONCTION_H
#define FONCTION_H

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//! main
int main(int argc, char **argv);
//int in_life(t_player *player);
//void open_window(void *mlx_ptr, void *win_ptr);

//! remove_new_line
void	remove_all_newlines(char **map);
void	remove_newline_in_line(char *line);

//! open_map
char **open_and_read_map(char *map_name);
char **read_map(int fd);
int open_new_map(char *map_name);
int count_lines(char *map_name);

//! select_class
// void	set_guerrier(t_player *player);
// void	set_archer(t_player *player);
// void	set_mage(t_player *player);
// void	set_chevalier(t_player *player);
// void	set_class(t_player *player, char *className);

//! utils
int ft_strcmp(char *s1, char *s2);
void	ft_exit_error(char* message);
int	ft_strlen(char *str);

//! wall_validation
int validate_wall(char **map, int width, int height, char *map_name);
int validate_rectangle(char **map, int width, int height, int linecount);
int validate_first_line(char **map, int width);
int validate_last_line(char **map, int width, int height);
int validate_first_column(char **map, int height);
int validate_last_column(char **map, int width, int height);

#endif