#ifndef FONCTION_H
#define FONCTION_H

# include "game.h"
# include "keymap.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

//! main
int main(int argc, char **argv);

// gestion de la map
//! map setup
t_map	*map_setup(t_game *game, char *av);
t_map	*map_init(t_game *game, char *av);

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

//!free_utils
void free_all(t_game *game);
void free_map(t_game *game);
void free_textures(t_game *game);

//! find_player
int find_player_x(t_game *game);
int find_player_y(t_game *game);

//! find_exit
int find_exit_x(t_game *game);
int find_exit_y(t_game *game);

//! find_item
int find_item_x(t_game *game);
int find_item_y(t_game *game);

//! remove_new_line
void	remove_all_newlines(char **map);
void	remove_newline_in_line(char *line);

//! open_map
char **open_and_read_map(char *map_name);
char **read_map(int fd);
int open_new_map(char *map_name);

//! textures
t_textures *textures_setup(t_game *game);
void put_textures(t_game *game);
t_textures	*textures_init(t_game *game);


//! wall_validation
int validate_wall(t_map *map);
int validate_rectangle(t_map map);
int validate_first_line(t_map map);
int validate_last_line(t_map map);
int validate_first_column(t_map map);
int validate_last_column(t_map map);

// gestion de la fenetre
//! window setup
t_window *window_init(t_game *game);
t_window *window_setup(t_game *game);
int redraw_window(void *param);

//! window close
int	close_window(t_game *game);

//! hooks setup
void setup_hooks(t_game *game);
int handle_key(int keycode, t_game *game);
int find_keycode(t_game *game);

//! keymap_setup
t_keymap *get_keymap(void);
t_keymap *get_macos_keymap(void);
t_keymap *get_linux_keymap(void);

//! open_exit
int exit_is_open(t_game *game);

//! move player
int	move_player_up(t_game *game);
int	move_player_down(t_game *game);
int	move_player_left(t_game *game);
int	move_player_right(t_game *game);

//! move utils
int		is_void_case(char **map, int x, int y);
int		is_collectible(char **map, int x, int y);
int		is_exit_close(char **map, int x, int y);
int		is_exit_open(char **map, int x, int y);
int		is_wall(char **map, int x, int y);

void	moved_in_a_void_case(t_game *game, int target_x, int target_y);
void	moved_in_a_closed_exit(t_game *game, int target_x, int target_y);
void	moved_in_an_open_exit(t_game *game, int target_x, int target_y);
void	moved_in_a_wall(t_game *game);
void	moved_in_a_collectible(t_game *game, int target_x, int target_y);

void	move_is_possible(t_game *game, int target_x, int target_y);
// utilitaire global
//! utils
int ft_strcmp(char *s1, char *s2);
void	ft_exit_error(char* message);
int	ft_strlen(char *str);
int print_keycode(int keycode, void *param);

//! run win game
void run_win_game(t_game *game);

#endif