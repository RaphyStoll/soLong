/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:01:50 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:02:26 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BFS_H
# define BFS_H

# include "game.h"
# include "macro.h"

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
}			t_bfs;

#endif