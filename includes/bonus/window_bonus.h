/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:44:24 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:40:48 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BONUS_H
# define WINDOW_BONUS_H

# include "game_bonus.h"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		title_size;
	int		max_w;
	int		max_h;

}			t_window;

#endif