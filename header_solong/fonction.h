#ifndef FONCTION_H
#define FONCTION_H

# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "maps.h"
# include "textures.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

//! main
int main(int argc, char **argv);
//int in_life(t_player *player);
//void open_window(void *mlx_ptr, void *win_ptr);

//! map setup
t_map	*map_setup(t_map *map, char *av);
t_map	*map_init(char *map_name);
//! map is valid
void	valid_map(t_map *map);
int have_exit(t_map *map);
int have_item(t_map *map);
int have_player(t_map *map);
int have_other(t_map *map);

//! map utils
int	count_lines(char *map_name);
int	count_width(char *map_name);
int	count_item(t_map *map);
int	count_exit(t_map *map);
int	count_player(t_map *map);
void free_map(t_map *map);

//! find_player
int find_player_x(t_map *map);
int find_player_y(t_map *map);

//! find_exit
int find_exit_x(t_map *map);
int find_exit_y(t_map *map);

//! find_item
int find_item_x(t_map *map);
int find_item_y(t_map *map);

//! remove_new_line
void	remove_all_newlines(char **map);
void	remove_newline_in_line(char *line);

//! open_map
char **open_and_read_map(char *map_name);
char **read_map(int fd);
int open_new_map(char *map_name);

//! textures
void load_textures(t_textures *textures, void *mlx_ptr);
void put_textures(t_textures *textures, t_map *map, void *mlx_ptr, void *win_ptr);
//! utils
int ft_strcmp(char *s1, char *s2);
void	ft_exit_error(char* message);
int	ft_strlen(char *str);

//! wall_validation
int validate_wall(t_map *map);
int validate_rectangle(t_map map);
int validate_first_line(t_map map);
int validate_last_line(t_map map);
int validate_first_column(t_map map);
int validate_last_column(t_map map);

#endif