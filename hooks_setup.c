#include "header_solong/fonction.h"
#include "header_solong/keymap.h"
#include "header_solong/game.h"
#include "mlx/mlx.h"

int find_keycode(t_game *game)
{
ft_printf("==find_keycode==\n");
	int keycode;

	keycode = 0;
	keycode = mlx_hook(game->window->win_ptr, 2, 1L << 0, handle_key, NULL);
	ft_printf("keycode = %d\n", keycode);
	ft_printf("==find_keycode ok==\n");
	return (keycode);
}

int handle_key(int keycode, t_game *game)
{

    // Parcourir le keymap pour trouver la correspondance
    int i = 0;
    while (game->keymap[i].keycode)
    {
        if (game->keymap[i].keycode == keycode)
        {
            game->keymap[i].action(game);
            return (0);
        }
        i++;
    }
    return (0);
}


void setup_hooks(t_game *game)
{
	game->keymap = get_keymap();
    mlx_hook(game->window->win_ptr, 2, 1L << 0, handle_key, game); // KeyPress
    mlx_hook(game->window->win_ptr, 17, 0L, close_window, game);   // Croix
}