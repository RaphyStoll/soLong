/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:34:57 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:34:58 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../mlx/mlx.h"

int	print_keycode(int keycode, void *param)
{
	(void)param;
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
	if (!game)
		ft_exit_error("Error\nt_game malloc failed");
	game->map = map_init(game, argv[1]);
	game->window = window_init(game);
	game->textures = textures_init(game);
	game->keymap = get_keymap();
	game->bfs = bfs_init(game);
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
