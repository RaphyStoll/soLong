/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:49:13 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:50:02 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_BONUS_H
# define MONSTER_BONUS_H

# include "game_bonus.h"

typedef struct s_monster
{
	int					id;
	int					x;
	int					y;
	int					old_x;
	int					old_y;
	int					dir;
	struct s_monster	*next;
}	t_monster;

#endif