/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:45:33 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 11:45:36 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "game.h"

typedef struct s_textures
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_open;
	void	*exit_closed;
	int		width;
	int		height;

}			t_textures;

#endif