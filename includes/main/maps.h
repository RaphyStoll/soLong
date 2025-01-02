#ifndef MAPS_H
#define MAPS_H

#include "game.h"
#include "macro.h"

typedef struct s_map {
	char	*map_name;	// nom de la map pour pouvoir l'ovrir
	char	**map;       // map apres gnl
	int		height;    // hauteur de la map
	int		width;     // largeur de la map
	int		collected;  // conte les items collecter par le joueur
	int		moves;		// nombre de mouvements
	int		objectif_moves;  //Nombre de pas minimum proposer par le BTS (sert de record a battre)
	int		items;		// nombre d'items
	int		player;		// nombre de joueurs (toujours 1)
	int		player_x;	// position x du joueur
	int		player_y;	// position y du joueur
	int		old_player_x;
	int		old_player_y;
	int		exit;		//nombre d'exit disponnible ( toujour 1)
	int		exit_x;		// position x de la sortie 
	int		exit_y;		// position y de la sortie
	bool	exit_isopen; // 1 si sortie open, 0 sinon
} t_map;

#endif