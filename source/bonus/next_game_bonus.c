#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../mlx/mlx.h"

void	run_win_game(t_game *game)
{
	void *mlx_ptr;
	void *win_ptr;

	win_ptr = game->window->win_ptr;
	mlx_ptr = game->window->mlx_ptr;
	ft_printf("\033[1;32mYou win\033[0m\n");
	ft_printf("\033[1;32mTotal moves = %d\033[0m\n", game->map->moves);
	free_all(game);
	mlx_destroy_window(mlx_ptr, win_ptr);
	exit(0);
}

void	run_lose_game(t_game *game)
{
	void *mlx_ptr;
	void *win_ptr;

	win_ptr = game->window->win_ptr;
	mlx_ptr = game->window->mlx_ptr;
	ft_printf("\033[1;31mYou lose\033[0m\n");
	free_all(game);
	mlx_destroy_window(mlx_ptr, win_ptr);
	exit(0);
}