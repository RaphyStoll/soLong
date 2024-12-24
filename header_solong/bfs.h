#ifndef BSF_H
# define BSF_H

#include "game.h"

typedef struct s_bfs
{
	int		width;    		//Largeur de la map
	int		height;   		//Hauteur de la map
	bool	**visited;  	//Tableau 2D indiquand si une case est visiter (bool)
	int		**dist;			//Tableau 2D stock la distance
	int		found_items;	// nombre d'items decouvert
	bool	exit_found;		//indique si la sortie a ete localiser (bool)
}	t_bfs;

#endif