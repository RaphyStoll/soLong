#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../mlx/mlx.h"

int	print_keycode(int keycode, void *param)
{
	(void)param; // Si vous n'utilisez pas de paramètres
	ft_printf("Key pressed: %d\n", keycode);
	return (0);
}

void	arg_verif(int argc)
{
	if (argc != 2)
		ft_exit_error("Error\nInvalid number of arguments");
}

t_game	*game_init(char **argv, t_game *game)
{
	game = NULL;
	game = malloc(sizeof(t_game));
	game->map = map_init(game, argv[1]);
	game->window = window_init(game);
	ft_printf("==win_1_init_end==\n"); //$
	game->textures = textures_init(game);
	ft_printf("==texture_1_init_end==\n"); //$
	game->monster = monster_init(game);
	ft_printf("==monster_1_init_end==\n"); //$
	game->keymap = get_keymap();
	ft_printf("==keymap_1_init_end==\n"); //$
	game->bfs = bfs_init(game);
	ft_printf("==bfs_1_init_end==\n"); //$

	ft_printf("==game_init end==\n"); //$
	if (!game || !game->map || !game->monster || !game->window
		|| !game->textures || !game->keymap || !game->bfs)
		ft_exit_error("Error\nt_game malloc failed");
	return (game);
}

// unsigned long long int = 18446744073709551615 max value
int	main(int argc, char **argv)
{
	t_game	*game;

	arg_verif(argc);
	game = NULL;
	game = game_init(argv, game);
	run_bfs(game);
	setup_hooks(game);
	mlx_loop(game->window->mlx_ptr);
	mlx_destroy_display(game->window->mlx_ptr);
	return (0);
}
