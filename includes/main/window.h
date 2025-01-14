/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:44:24 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 11:45:01 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "game.h"

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