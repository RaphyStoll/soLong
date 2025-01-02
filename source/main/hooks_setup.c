#include "../includes/main/fonction.h"
#include "../includes/main/keymap.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"
#include "../mlx/mlx.h"

int handle_key(int keycode, t_game *game)
{
    int i = 0;
    while (game->keymap[i].keycode)
    {
		//$ft_printf("Comparaison : keymap[%d].keycode = %d\n", i, game->keymap[i].keycode);
        if (game->keymap[i].keycode == keycode)
        {
			//$ft_printf("Action trouvée pour keycode = %d\n", keycode);
            game->keymap[i].action(game);
            return (false);
        }
        i++;
    }
	ft_printf("keycode non mappée= %d\n", keycode);
    return (false);
}


void setup_hooks(t_game *game)
{
    mlx_hook(game->window->win_ptr, 2, 1L << 0, handle_key, game); // KeyPress
	mlx_hook(game->window->win_ptr, 12, 1L << 15, redraw_window, game); // Expose
    mlx_hook(game->window->win_ptr, 17, 0L, close_window, game);   // Croix
}