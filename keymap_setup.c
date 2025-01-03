#include "header_solong/keymap.h"
#include "header_solong/fonction.h"
#include "header_solong/game.h"
#include "mlx/mlx.h"

t_keymap *get_keymap(void)
{
	#ifdef __APPLE__
	return (get_macos_keymap());
	#elif __linux__
	return (get_linux_keymap());
	#else
	ft_exit_error("Error\nUnsupported OS");
	return (NULL);
	#endif
}

t_keymap *get_macos_keymap(void)
{
	ft_printf("==get_macos_keymap==\n");
	static t_keymap macos_keymap[] = {
	{65307, close_window},       // ESC - Quitter le jeu
    {119, move_player_up},       // W - Déplacer le joueur vers le haut
    {115, move_player_down},     // S - Déplacer le joueur vers le bas
    {97, move_player_left},      // A - Déplacer le joueur vers la gauche
    {100, move_player_right},    // D - Déplacer le joueur vers la droite
    {65362, move_player_up},     // Flèche haut - Déplacer le joueur vers le haut
    {65364, move_player_down},   // Flèche bas - Déplacer le joueur vers le bas
    {65361, move_player_left},   // Flèche gauche - Déplacer le joueur vers la gauche
    {65363, move_player_right},  // Flèche droite - Déplacer le joueur vers la droite
    {0, NULL}                    // Fin du tableau
	};
	return (macos_keymap);
}

t_keymap *get_linux_keymap(void)
{
	ft_printf("==get_linux_keymap==\n");
    static t_keymap linux_keymap[] = {
        {65307, close_window},    // ESC - Quitter le jeu
        {119, move_player_up},    // W - Déplacer le joueur vers le haut
        {115, move_player_down},  // S - Déplacer le joueur vers le bas
        {97, move_player_left},   // A - Déplacer le joueur vers la gauche
        {100, move_player_right}, // D - Déplacer le joueur vers la droite
        {65362, move_player_up},  // Flèche haut - Déplacer le joueur vers le haut
        {65364, move_player_down},// Flèche bas - Déplacer le joueur vers le bas
        {65361, move_player_left},// Flèche gauche - Déplacer le joueur vers la gauche
        {65363, move_player_right},// Flèche droite - Déplacer le joueur vers la droite
        {0, NULL}                 // Fin du tableau
    };
    return (linux_keymap);
}
