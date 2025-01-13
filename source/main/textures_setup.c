/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:22:13 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:24:59 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/game.h"
#include "../includes/main/macro.h"
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

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_put_image_to_window(game->window->mlx_ptr,
				game->window->win_ptr, game->textures->floor, x
				* game->window->title_size, y * game->window->title_size);
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->window->mlx_ptr,
					game->window->win_ptr, game->textures->wall, x
					* game->window->title_size, y * game->window->title_size);
			else if (game->map->map[y][x] == 'C')
				mlx_put_image_to_window(game->window->mlx_ptr,
					game->window->win_ptr, game->textures->collectible, x
					* game->window->title_size, y * game->window->title_size);
			else if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->window->mlx_ptr,
					game->window->win_ptr, game->textures->player, x
					* game->window->title_size, y * game->window->title_size);
			else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 0)
				mlx_put_image_to_window(game->window->mlx_ptr,
					game->window->win_ptr, game->textures->exit_closed, x
					* game->window->title_size, y * game->window->title_size);
			else if (game->map->map[y][x] == 'E' && game->map->exit_isopen == 1)
				mlx_put_image_to_window(game->window->mlx_ptr,
					game->window->win_ptr, game->textures->exit_open, x
					* game->window->title_size, y * game->window->title_size);
			x++;
		}
		y++;
	}
}

t_textures	*textures_setup(t_game *game)
{
	game->textures->floor = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/background.xpm", &game->textures->width,
			&game->textures->height);
	game->textures->wall = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/wall.xpm", &game->textures->width,
			&game->textures->height);
	game->textures->collectible = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/collectable.xpm", &game->textures->width,
			&game->textures->height);
	game->textures->player = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/ship_up.xpm", &game->textures->width,
			&game->textures->height);
	game->textures->exit_closed = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/exit_closed.xpm", &game->textures->width,
			&game->textures->height);
	game->textures->exit_open = mlx_xpm_file_to_image(game->window->mlx_ptr,
			"textures/test1/exit.xpm", &game->textures->width,
			&game->textures->height);
	if (game->textures->floor == NULL || game->textures->wall == NULL
		|| game->textures->collectible == NULL || game->textures->player == NULL
		|| game->textures->exit_closed == NULL
		|| game->textures->exit_open == NULL)
		ft_exit_error("Error\nTextures failed to load");
	return (game->textures);
}

void	redraw(t_game *game, int target_x, int target_y)
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
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, textures->player,
		target_x * TILE_SIZE, target_y * TILE_SIZE);
}
