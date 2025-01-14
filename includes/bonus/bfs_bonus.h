/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:50:09 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 12:59:14 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_BONUS_H
# define BFS_BONUS_H

# include "game_bonus.h"
# include "macro_bonus.h"

typedef struct s_bfs
{
	int		width;
	int		height;
	char	**map;
	int		**dist;
	int		*queue_x;
	int		*queue_y;
	int		start;
	int		end;
	int		queue_size;
	int		found_items;
	int		y;
	int		x;
	BOOL	exit_found;
}	t_bfs;

#endif