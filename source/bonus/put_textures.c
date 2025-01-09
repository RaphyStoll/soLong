#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void put_player_texture(t_game *game, int target_x, int target_y, char a)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	if (a == 'U')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_up, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'D')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_down, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'L')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_left, target_x * TILE_SIZE, target_y * TILE_SIZE);
	else if (a == 'R')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player_right, target_x * TILE_SIZE, target_y * TILE_SIZE);
}

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"



void put_monster_texture(t_game *game, int target_x, int target_y)
{
	int rand;
	static int seed;

	rand = pseudo_random(seed++) % 4;

	 if (rand == 0)
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->monster_0, target_x * TILE_SIZE, target_y * TILE_SIZE);
    else if (rand == 1)
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->monster_1, target_x * TILE_SIZE, target_y * TILE_SIZE);
    else if (rand == 2)
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->monster_2, target_x * TILE_SIZE, target_y * TILE_SIZE);
    else if (rand == 3)
        mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, game->textures_, target_x * TILE_SIZE, target_y * TILE_SIZE);

	
}