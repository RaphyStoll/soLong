/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:56:38 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 11:57:18 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "maps.h"
# include "window.h"
# include "textures.h"
# include "fonction.h"
# include "keymap.h"
# include "bfs.h"

// Structure de données pour le jeu qui permet de toute stocker
// dans une seule variable
typedef struct s_game {
	t_map		*map;
	t_window	*window;
	t_textures	*textures;
	t_keymap	*keymap;
	t_bfs		*bfs;
}	t_game;

#endif