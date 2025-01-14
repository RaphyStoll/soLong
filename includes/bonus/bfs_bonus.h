/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:50:09 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 16:56:15 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSF_BONUS_H
# define BSF_BONUS_H

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
	bool	exit_found;
}	t_bfs;

#endif