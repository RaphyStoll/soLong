#ifndef GAME_H
#define GAME_H

#include "maps.h"
#include "window.h"
#include "textures.h"
#include "fonction.h"
#include "keymap.h"
#include "bfs.h"

// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game {
    t_map		*map;
	t_window	*window;
	t_textures	*textures;
	t_keymap	*keymap;
	t_bfs		*bfs;
} t_game;

#endif