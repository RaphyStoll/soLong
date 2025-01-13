#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void	move_monster_up(t_game *game, t_monster *current)
{
	
	current->y -= 1;
	if (game->map->map[current->y][current->x] == 'P')
	{
		run_lose_game(game);
		return;
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->floor, current->old_x * TILE_SIZE, current->old_y * TILE_SIZE);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->monster_up, current->x * TILE_SIZE, current->y * TILE_SIZE);
	current->old_y = current->y;
}
void	move_monster_down(t_game *game, t_monster *current)
{
	current->y += 1;
	if (game->map->map[current->y][current->x] == 'P')
	{
		run_lose_game(game);
		return;
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->floor, current->old_x * TILE_SIZE, current->old_y * TILE_SIZE);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->monster_down, current->x * TILE_SIZE, current->y * TILE_SIZE);
	current->old_y = current->y;
}

void	move_monster_left(t_game *game, t_monster *current)
{
	current->x -= 1;
	if (game->map->map[current->y][current->x] == 'P')
	{
		run_lose_game(game);
		return;
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->floor, current->old_x * TILE_SIZE, current->old_y * TILE_SIZE);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->monster_left, current->x * TILE_SIZE, current->y * TILE_SIZE);
	current->old_x = current->x;
}

void	move_monster_right(t_game *game, t_monster *current)
{
	current->x += 1;
	if (game->map->map[current->y][current->x] == 'P')
	{
		run_lose_game(game);
		return;
	}
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->floor, current->old_x * TILE_SIZE, current->old_y * TILE_SIZE);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr, game->textures->monster_right, current->x * TILE_SIZE, current->y * TILE_SIZE);
	current->old_x = current->x;
}