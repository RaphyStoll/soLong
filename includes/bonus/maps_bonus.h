/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:49:13 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:52:12 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_BONUS_H
# define MAPS_BONUS_H

# include "game_bonus.h"
# include "macro_bonus.h"

typedef struct s_map
{
	char	*map_name;
	char	**map;
	int		height;
	int		width;
	int		collected;
	int		moves;
	int		objectif_moves;
	int		items;
	int		player;
	int		player_x;
	int		player_y;
	int		old_player_x;
	int		old_player_y;
	int		exit;
	int		exit_x;
	int		exit_y;
	BOOL	exit_isopen;
}	t_map;

#endif