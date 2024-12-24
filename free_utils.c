#include "header_solong/game.h"
#include "header_solong/fonction.h"
#include "mlx/mlx.h"

void free_all(t_game *game)
{
	 if (game->textures)
    {
        free_textures(game);
        free(game->textures);
    }
    free_map(game);
    if (game->window)
        free(game->window);

    free(game);
}

void free_textures(t_game *game)
{
	void *mlx_ptr;

	mlx_ptr = game->window->mlx_ptr;
    if (game->textures->player)
        mlx_destroy_image(mlx_ptr,
		 game->textures->player);
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
}

void free_map(t_game *game)
{
	int i;

	if (!game->map)
		return;
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
}
