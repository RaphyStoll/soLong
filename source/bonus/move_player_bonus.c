#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/macro_bonus.h"

int	move_player_up(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y - 1;
	//$ft_printf("target = %d %d\n",target_x,target_y);
	move_is_possible(game, target_x, target_y, 'U');
	ft_printf("Moves = %d\n",game->map->moves);
	return (false);
}

int	move_player_down(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y + 1;
	//$ft_printf("target = %d %d\n",target_x,target_y);
	move_is_possible(game, target_x, target_y, 'D');
	ft_printf("Moves = %d\n",game->map->moves);
	return (false);
}

int	move_player_left(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x - 1;
	target_y = game->map->player_y;
	//$ft_printf("target = %d %d\n",target_x,target_y);
	move_is_possible(game, target_x, target_y, 'L');
	ft_printf("Moves = %d\n",game->map->moves);
	return (false);
}

int	move_player_right(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x + 1;
	target_y = game->map->player_y;
	//$ft_printf("target = %d %d\n",game->map->player_x,game->map->player_y);
	move_is_possible(game, target_x, target_y, 'R');
	ft_printf("Moves = %d\n",game->map->moves);
	return (false);
}
