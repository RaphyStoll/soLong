#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "monster.h"
#include "textures.h"
#include "item.h"
#include "fonction.h"


// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game {
    t_player *player;     // Informations sur le joueur
    t_textures     *textures;   // Textures pour les éléments graphiques
    t_item         *items;      // Objets à collecter
//*    t_monster  *enemies;    // Tableau d'ennemis
    int             map_width;  // Largeur de la carte
    int             map_height; // Hauteur de la carte
    char          **map;        // Représentation de la carte
} t_game;

#endif