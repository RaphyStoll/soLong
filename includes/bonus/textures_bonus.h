/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:41:26 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:48:53 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

# include "game_bonus.h"

typedef struct s_textures {
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_open;
	void	*exit_closed;
	void	*monster_up;
	void	*monster_down;
	void	*monster_left;
	void	*monster_right;
	int		width;
	int		height;

}	t_textures;

#endif