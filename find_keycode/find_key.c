#include "../mlx/mlx.h"
#include <stdio.h>

int print_keycode(int keycode, void *param)
{
    (void)param; // Si vous n'utilisez pas de paramètres
    printf("Key pressed: %d\n", keycode);
    return (0);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Keycode Debugger");

    mlx_key_hook(win_ptr, print_keycode, NULL); // Attache la fonction au hook
    mlx_loop(mlx_ptr); // Lancement de la boucle d'événements
    return (0);
}
