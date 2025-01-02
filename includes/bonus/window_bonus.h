#ifndef WINDOW_BONUS_H
#define WINDOW_BONUS_H

#include "game_bonus.h"

typedef struct s_window {
	void	*mlx_ptr;		// Identifiant de la connexion MiniLibX
	void	*win_ptr;		// Identifiant de la fenêtre
	int		win_width;		// Largeur de la fenêtre
	int		win_height;		// Hauteur de la fenêtre
	int		title_size;		// Taille d'une case (ex: 32x32 pixels)
	int		max_w;			// Largeur de l'ecran du pc (largeur max accepter)
	int		max_h;			// Hauteur de l'ecran du pc (hauteur max accepter)

} t_window;

#endif