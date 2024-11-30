#ifndef MAP_H
#define MAP_H

typedef struct s_map {
	char	*map_name;	// nom de la map pour pouvoir l'ovrir
	char	**map;       // map apres gnl
	int		height;    // hauteur de la map
	int		width;     // largeur de la map
	int		collected;  // 1 si tout a été collecté, 0 sinon
	int		moves;		// nombre de mouvements
	int		items;		// nombre d'items
	int		player;		// nombre de joueurs (toujours 1)
	int		player_x;	// position x du joueur
	int		player_y;	// positiomn y du joueur 
	int		exit;		//nombre d'exit disponnible ( toujour 1)
	int		exit_x;		// positiomn x de la sortie 
	int		exit_y;		// positiomn y de la sortie 
	int		exit_isopen; // 1 si sortie open, 0 sinon
} t_map;

#endif