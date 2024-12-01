#ifndef WINDOW_H
#define WINDOW_H

#include "game.h"

typedef struct s_window {
	void	*mlx_ptr; // Identifiant de la connexion MiniLibX
	void	*win_ptr; // Identifiant de la fenêtre
	int		win_width; // Largeur de la fenêtre
	int		win_height; // Hauteur de la fenêtre
	int		title_size; // Taille d'une case (ex: 32x32 pixels)
} t_window;

#endif