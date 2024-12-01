#include "header_solong/game.h"
#include "header_solong/fonction.h"

int	move_player_up(void *param)
{
	t_game *game;

	game = (t_game *)param;
	game->map->moves++;
	ft_printf("Player moved up\n");
	return (0);
}

int	move_player_down(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	game->map->moves++;
	ft_printf("Player moved down\n");
	return (0);
}

int	move_player_left(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	game->map->moves++;
	ft_printf("Player moved left\n");
	return (0);
}

int	move_player_right(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	game->map->moves++;
	ft_printf("Player moved right\n");
	return (0);
}
