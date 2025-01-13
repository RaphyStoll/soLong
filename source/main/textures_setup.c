/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:22:13 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:09:00 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/game.h"
#include "../includes/main/fonction.h"
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
	char		old_cell;
	char		new_cell;

	map = game->map;
	old_cell = map->map[map->old_player_y][map->old_player_x];
	new_cell = map->map[map->player_y][map->player_x];
	if (old_cell == '0')
		put_image_floor(game, map->old_player_x, map->old_player_y);
	else if (old_cell == 'C')
		put_image_collectible(game, map->old_player_x, map->old_player_y);
	else if (old_cell == 'E')
		put_image_exit(game, map->old_player_x, map->old_player_y);
	if (new_cell == '1')
		return ;
	put_image_player(game, target_x, target_y);
}
