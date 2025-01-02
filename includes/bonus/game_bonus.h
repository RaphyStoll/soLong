#ifndef GAME_BONUS_H
#define GAME_BONUS_H

#include "maps_bonus.h"
#include "window_bonus.h"
#include "textures_bonus.h"
#include "fonction_bonus.h"
#include "keymap_bonus.h"
#include "monster_bonus.h"
#include "bfs_bonus.h"

// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game {
    t_map		*map;
	t_window	*window;
	t_textures	*textures;
	t_keymap	*keymap;
	t_bfs		*bfs;
	t_monster	*monster;
} t_game;

#endif