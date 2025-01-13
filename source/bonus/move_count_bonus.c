#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/game_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../mlx/mlx.h"

void put_moves(t_game *game)
{
    char *moves_str;
    moves_str = ft_itoa(game->map->moves);
    if (!moves_str)
        ft_exit_error("Error\nFailed to convert moves to string");
    int bg_x = 95;
    int bg_y = 5;
    int text_color = 0xFFFFFF;
    draw_rectangle(game, bg_x, bg_y);
    mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 100, 20, text_color, "Moves =");
    mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 150, 20, text_color, moves_str);
    free(moves_str);
}

void draw_rectangle(t_game *game, int x, int y)
{
    int i, j;
	int width, height;

    i = 0;

	width = 130;
	height = 20;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            mlx_pixel_put(game->window->mlx_ptr, game->window->win_ptr, x + j, y + i, 0x000000);
            j++;
        }
        i++;
    }
}