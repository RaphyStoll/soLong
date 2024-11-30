#include "header_solong/textures.h"
#include "header_solong/fonction.h"
#include "mlx/mlx.h"

void free_textures(t_textures *textures, void *mlx_ptr)
{
    if (textures->player)
        mlx_destroy_image(mlx_ptr, textures->player);
    if (textures->wall)
        mlx_destroy_image(mlx_ptr, textures->wall);
    if (textures->floor)
        mlx_destroy_image(mlx_ptr, textures->floor);
    if (textures->collectible)
        mlx_destroy_image(mlx_ptr, textures->collectible);
    if (textures->exit_closed)
        mlx_destroy_image(mlx_ptr, textures->exit_closed);
    if (textures->exit_open)
        mlx_destroy_image(mlx_ptr, textures->exit_open);
}