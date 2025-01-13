/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:32:29 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:38:31 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../mlx/mlx.h"

void	free_bfs(t_game *game)
{
	t_bfs	*bfs;
	int		i;

	if (!game || !game->bfs)
		return ;
	bfs = game->bfs;
	if (bfs->dist)
	{
		i = 0;
		while (i < bfs->height)
		{
			if (bfs->dist[i])
				free(bfs->dist[i]);
			i++;
		}
		free(bfs->dist);
	}
	if (bfs->queue_x)
		free(bfs->queue_x);
	if (bfs->queue_y)
		free(bfs->queue_y);
	free(bfs);
	game->bfs = NULL;
}

void	free_all(t_game *game)
{
	if (game->textures)
	{
		free_textures(game);
		free(game->textures);
	}
	free_map(game);
	if (game->window)
		free(game->window);
	free_monsters(game);
	free(game);
	game = NULL;
}

void	free_textures(t_game *game)
{
	void	*mlx_ptr;

	mlx_ptr = game->window->mlx_ptr;
	if (game->textures->player_up)
		mlx_destroy_image(mlx_ptr, game->textures->player_up);
	if (game->textures->player_down)
		mlx_destroy_image(mlx_ptr, game->textures->player_down);
	if (game->textures->player_left)
		mlx_destroy_image(mlx_ptr, game->textures->player_left);
	if (game->textures->player_right)
		mlx_destroy_image(mlx_ptr, game->textures->player_right);
	if (game->textures->wall)
		mlx_destroy_image(mlx_ptr, game->textures->wall);
	if (game->textures->floor)
		mlx_destroy_image(mlx_ptr, game->textures->floor);
	if (game->textures->collectible)
		mlx_destroy_image(mlx_ptr, game->textures->collectible);
	if (game->textures->exit_closed)
		mlx_destroy_image(mlx_ptr, game->textures->exit_closed);
	if (game->textures->exit_open)
		mlx_destroy_image(mlx_ptr, game->textures->exit_open);
	free_textures_bonus(game);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	if (game->map->map)
	{
		i = 0;
		while (i < game->map->height)
		{
			free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
	}
	free(game->map);
	game->map = NULL;
}

void	free_textures_bonus(t_game *game)
{
	void	*mlx_ptr;

	mlx_ptr = game->window->mlx_ptr;
	if (game->textures->monster_up)
		mlx_destroy_image(mlx_ptr, game->textures->monster_up);
	if (game->textures->monster_down)
		mlx_destroy_image(mlx_ptr, game->textures->monster_down);
	if (game->textures->monster_left)
		mlx_destroy_image(mlx_ptr, game->textures->monster_left);
	if (game->textures->monster_right)
		mlx_destroy_image(mlx_ptr, game->textures->monster_right);
}
