#ifndef BSF_BONUS_H
# define BSF_BONUS_H

#include "game_bonus.h"
#include "macro_bonus.h"

typedef struct s_bfs
{
	int		width;    		//Largeur de la map
	int		height;   		//Hauteur de la map
	char	**map;			//copy de la map pour eviter tout changent sur la map jouable
	int		**dist;
	int		*queue_x;
	int		*queue_y;
	int		start;
	int		end;
	int		queue_size;
	int		found_items;
	int		y;
	int		x;
	bool	exit_found;
}	t_bfs;

#endif