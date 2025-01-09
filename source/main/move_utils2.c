#include "../includes/main/fonction.h"
#include "../includes/main/game.h"

void	moved_in_a_void_case(t_game *game, int target_x, int target_y)
{
	game->map->moves++;
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->player_y = target_y;
	game->map->player_x = target_x;
	game->map->map[target_y][target_x] = 'P';
	redraw(game, target_x, target_y);
}

void	moved_in_a_closed_exit(t_game *game, int target_x, int target_y)
{
	game->map->moves++;
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->player_y = target_y;
	game->map->player_x = target_x;
	game->map->map[target_y][target_x] = 'P';
	redraw(game, target_x, target_y);
	return ;
}

void	moved_in_an_open_exit(t_game *game, int target_x, int target_y)
{
	game->map->moves++;
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->player_y = target_y;
	game->map->player_x = target_x;
	game->map->map[target_y][target_x] = 'P';
	redraw(game, target_x, target_y);
	run_win_game(game);
	return ;
}

void	moved_in_a_wall(t_game *game)
{
	(void)game;
	ft_printf("\033[31mPlayer is on a wall\033[0m\n");
	return ;
}

void	moved_in_a_collectible(t_game *game, int target_x, int target_y)
{
	int	y;
	int	x;

	game->map->collected++;
	game->map->moves++;
	game->map->map[game->map->player_y][game->map->player_x] = '0';
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->player_y = target_y;
	game->map->player_x = target_x;
	game->map->map[target_y][target_x] = 'P';
	if (exit_is_open(game))
	{
		y = 0;
		x = 0;
		while (x < game->map->height)
		{
			y = 0;
			while (y < game->map->width)
			{
				ft_printf("%c", game->map->map[x][y]); //$
				y++;
			}
			ft_printf("\n"); //$
			x++;
		}
	}
	redraw(game, target_x, target_y);
	ft_printf("\n\033[32mnew item collected total : %d\033[0m\n",
		game->map->collected);
}
