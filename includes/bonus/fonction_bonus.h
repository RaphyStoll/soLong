/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:57:31 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:58:46 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONCTION_BONUS_H
# define FONCTION_BONUS_H

# include "../../ft_printf/ft_printf.h"
# include "../../gnl/get_next_line.h"
# include "bfs_bonus.h"
# include "game_bonus.h"
# include "keymap_bonus.h"
# include "maps_bonus.h"
# include "monster_bonus.h"
# include "textures_bonus.h"
# include "window_bonus.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

//! main
int			main(int argc, char **argv);

// gestion de la map
//! map setup
t_map		*map_setup(t_game *game, char *av);
t_map		*map_init(t_game *game, char *av);

//! map is valid
void		valid_map(t_map *map);
BOOL		have_exit(t_map *map);
BOOL		have_item(t_map *map);
BOOL		have_player(t_map *map);
BOOL		have_other(t_map *map);

//! bfs
void		run_bfs(t_game *game);
void		visit_neighbor(t_game *game, int nx, int ny);
void		check_current_cell(t_game *game, int x, int y);
t_bfs		*bfs_init(t_game *game);
t_bfs		*bfs_setup(t_game *game);
int			*set_queue(t_game *game, char a);
int			**set_dist(t_game *game);

//! map utils
int			count_lines(char *map_name);
int			count_width(char *map_name);
int			count_item(t_map *map);
int			count_exit(t_map *map);
int			count_player(t_map *map);

//! free_utils
void		free_all(t_game *game);
void		free_map(t_game *game);
void		free_textures(t_game *game);
void		free_bfs(t_game *game);
void		free_textures_bonus(t_game *game);
void		free_monsters(t_game *game);

//! find_player
int			find_player_x(t_game *game);
int			find_player_y(t_game *game);

//! find_exit
int			find_exit_x(t_game *game);
int			find_exit_y(t_game *game);

//! find_item
int			find_item_x(t_game *game);
int			find_item_y(t_game *game);

//! remove_new_line
void		remove_all_newlines(char **map);
void		remove_newline_in_line(char *line);

//! open_map
char		**open_and_read_map(char *map_name);
char		**read_map(int fd);
int			open_new_map(char *map_name);

//! textures
t_textures	*textures_setup(t_game *game);
void		put_textures(t_game *game);
t_textures	*textures_init(t_game *game);
void		redraw(t_game *game, int target_x, int target_y, char a);

//! textures setup2
void		textures_setup_monstrer(t_game *game);
void		textures_setup_player(t_game *game);

//! put_textures
void		put_player_texture(t_game *game, int target_x, int target_y,
				char a);
void		put_monster_texture(t_game *game, int target_x, int target_y);

//! wall_validation
int			validate_wall(t_map *map);
int			validate_rectangle(t_map map);
int			validate_first_line(t_map map);
int			validate_last_line(t_map map);
int			validate_first_column(t_map map);
int			validate_last_column(t_map map);

// gestion de la fenetre
//! window setup
t_window	*window_init(t_game *game);
t_window	*window_setup(t_game *game);
int			get_monitor_size(t_game *game, char a);
int			redraw_window(void *param);

//! window close
int			close_window(t_game *game);

//! hooks setup
void		setup_hooks(t_game *game);
int			handle_key(int keycode, t_game *game);
int			find_keycode(t_game *game);

//! keymap_setup
t_keymap	*get_keymap(void);
t_keymap	*get_macos_keymap(void);
t_keymap	*get_linux_keymap(void);

//! open_exit
int			exit_is_open(t_game *game);

//! move player
int			move_player_up(t_game *game);
int			move_player_down(t_game *game);
int			move_player_left(t_game *game);
int			move_player_right(t_game *game);

//! move utils
BOOL		is_void_case(char **map, int x, int y);
BOOL		is_collectible(char **map, int x, int y);
BOOL		is_exit_close(char **map, int x, int y);
BOOL		is_exit_open(char **map, int x, int y);
BOOL		is_wall(char **map, int x, int y);
BOOL		is_monster(char **map, int x, int y);

void		moved_in_a_monster(t_game *game, char a);
void		moved_in_a_void_case(t_game *game, int target_x, int target_y,
				char a);
void		moved_in_a_closed_exit(t_game *game, int target_x, int target_y,
				char a);
void		moved_in_an_open_exit(t_game *game, int target_x, int target_y,
				char a);
void		moved_in_a_wall(t_game *game, char a);
void		moved_in_a_collectible(t_game *game, int target_x, int target_y,
				char a);
void		move_is_possible(t_game *game, int target_x, int target_y, char a);

// utilitaire global
//! utils
int			ft_strcmp(char *s1, char *s2);
void		ft_exit_error(char *message);
int			ft_strlen(char *str);
int			print_keycode(int keycode, void *param);

//! run win/lose game
void		run_win_game(t_game *game);
void		run_lose_game(t_game *game);

//! monster
t_monster	*monster_init(t_game *game);
t_monster	*monster_setup(t_game *game);
t_monster	*load_monsters(t_game *game);
t_monster	*monster_add(t_game *game, int x, int y);

//! find_monster
int			find_monster_x(t_game *game);
int			find_monster_y(t_game *game);

//! monster move
void		monster_move(t_game *game);
int			is_walkable(t_game *game, int x, int y);

//! monster move utils
void		move_monster_up(t_game *game, t_monster *current);
void		move_monster_down(t_game *game, t_monster *current);
void		move_monster_left(t_game *game, t_monster *current);
void		move_monster_right(t_game *game, t_monster *current);

//! itoa
char		*ft_itoa(int n);

void		put_moves(t_game *game);
void		draw_rectangle(t_game *game, int x, int y);

//! rand
int			pseudo_random(int seed);

//! one more line

void		put_image_wall(t_game *game, int x, int y);
void		put_image_collectible(t_game *game, int x, int y);
void		put_image_exit(t_game *game, int x, int y);
void		put_image_player(t_game *game, int x, int y);
void		put_image_floor(t_game *game, int x, int y);
void		put_monster_up(t_game *game, int target_x, int target_y);

#endif