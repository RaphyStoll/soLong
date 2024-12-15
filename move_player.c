#include "header_solong/game.h"
#include "header_solong/fonction.h"

int	move_player_up(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y - 1;
	move_is_possible(game, target_x, target_y);
	redraw_window(game);
	return (0);
}

int	move_player_down(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x;
	target_y = game->map->player_y + 1;
	move_is_possible(game, target_x, target_y);
	redraw_window(game);
	return (0);
}

int	move_player_left(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x - 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y);
	redraw_window(game);
	return (0);
}

int	move_player_right(t_game *game)
{
	int target_x;
	int target_y;

	target_x = game->map->player_x + 1;
	target_y = game->map->player_y;
	move_is_possible(game, target_x, target_y);
	redraw_window(game);
	return (0);
}
