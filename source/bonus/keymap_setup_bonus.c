#include "../../mlx/mlx.h"
#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/keymap_bonus.h"

t_keymap	*get_keymap(void)
{
#ifdef __APPLE__
	return (get_macos_keymap());
#elif __linux__
	return (get_linux_keymap());
#else
	ft_exit_error("Error\nUnsupported OS");
	return (NULL);
#endif
}

t_keymap	*get_macos_keymap(void)
{
	static t_keymap	macos_keymap[] = {{65307, close_window}, {119,
			move_player_up}, {115, move_player_down}, {97, move_player_left},
			{100, move_player_right}, {65362, move_player_up}, {65364,
			move_player_down}, {65361, move_player_left}, {65363,
			move_player_right}, {0, NULL}};

	return (macos_keymap);
}

t_keymap	*get_linux_keymap(void)
{
	static t_keymap	linux_keymap[] = {{65307, close_window}, {119,
			move_player_up}, {115, move_player_down}, {97, move_player_left},
			{100, move_player_right}, {65362, move_player_up}, {65364,
			move_player_down}, {65361, move_player_left}, {65363,
			move_player_right}, {0, NULL}};

	return (linux_keymap);
}
