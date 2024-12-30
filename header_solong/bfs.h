#ifndef BSF_H
# define BSF_H

#include "game.h"
#include "macro.h"

typedef struct s_bfs
{
	int		width;    		//Largeur de la map
	int		height;   		//Hauteur de la map
	char	**map;			//copy de la map pour eviter tout changent sur la map jouable
	int		**dist;			//Tableau 2D par defaut -1 = pas visiter et >0 = distance
	int		*queue_x;		//Tableau qui stock la file en x
	int		*queue_y;		//Tableau qui stock la file en y
	int		start;			//indice de debut de la file
	int		end;			//indice de fin de la file
	int		queue_size;		//Capaciter max de la file
	int		found_items;	// nombre d'items decouvert
	int		y;
	int		x;
	bool	exit_found;		//indique si la sortie a ete localiser
}	t_bfs;

#endif