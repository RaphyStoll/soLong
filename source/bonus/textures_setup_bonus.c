/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:32 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:29:01 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

t_textures	*textures_init(t_game *game)
{
	game->textures = NULL;
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
		ft_exit_error("Error\nt_textures malloc failed");
	game->textures = textures_setup(game);
	put_textures(game);
	return (game->textures);
}

void	put_textures(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (y++, y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			put_image_floor(game, x, y);
			if (game->map->map[y][x] == '1')
				put_image_wall(game, x, y);
			else if (game->map->map[y][x] == 'C')
				put_image_collectible(game, x, y);
			else if (game->map->map[y][x] == 'P')
				put_image_player(game, x, y);
			else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 0)
				put_image_exit(game, x, y);
			else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 1)
				put_image_exit(game, x, y);
			else if (game->map->map[y][x] == 'M')
				put_monster_texture(game, x, y);
			x++;
		}
	}
}

t_textures	*textures_setup(t_game *game)
{
	t_window	*win;
	t_textures	*textures;

	win = game->window;
	textures = game->textures;
	textures->floor = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/background.xpm", &textures->width,
			&textures->height);
	textures->wall = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/wall.xpm", &textures->width, &textures->height);
	textures->collectible = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/collectable.xpm", &textures->width,
			&textures->height);
	textures->exit_closed = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/exit_closed.xpm", &textures->width,
			&textures->height);
	textures->exit_open = mlx_xpm_file_to_image(win->mlx_ptr,
			"textures/test1/exit.xpm", &textures->width, &textures->height);
	if (!textures->floor || !textures->wall || !textures->collectible
		|| !textures->exit_closed || !textures->exit_open)
		ft_exit_error("Error\ntextures_setup failed");
	textures_setup_player(game);
	textures_setup_monstrer(game);
	return (game->textures);
}

void	redraw(t_game *game, int target_x, int target_y, char a)
{
	t_map		*map;
	t_window	*win;
	t_textures	*textures;
	char		old_cell;
	char		new_cell;

	map = game->map;
	win = game->window;
	textures = game->textures;
	old_cell = map->map[map->old_player_y][map->old_player_x];
	new_cell = map->map[map->player_y][map->player_x];
	if (old_cell == '0')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->floor,
			map->old_player_x * TILE_SIZE, map->old_player_y * TILE_SIZE);
	else if (old_cell == 'C')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			textures->collectible, map->old_player_x * TILE_SIZE,
			map->old_player_y * TILE_SIZE);
	else if (old_cell == 'E')
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			textures->exit_closed, map->old_player_x * TILE_SIZE,
			map->old_player_y * TILE_SIZE);
	if (new_cell == '1')
		return ;
	put_player_texture(game, target_x, target_y, a);
}
