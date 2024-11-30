#ifndef GAME_H
#define GAME_H

#include "maps.h"
#include "window.h"
#include "textures.h"
#include "fonction.h"


// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game {
    t_map	   *map;
	t_window   *window;
	t_textures *textures;
} t_game;

#endif