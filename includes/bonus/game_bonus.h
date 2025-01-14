/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:53:55 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:54:18 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include "fonction_bonus.h"
# include "keymap_bonus.h"
# include "maps_bonus.h"
# include "monster_bonus.h"
# include "textures_bonus.h"
# include "window_bonus.h"
# include "bfs_bonus.h"

typedef struct s_bfs	t_bfs;

// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game
{
	t_map		*map;
	t_window	*window;
	t_textures	*textures;
	t_keymap	*keymap;
	t_bfs		*bfs;
	t_monster	*monster;
}	t_game;

#endif