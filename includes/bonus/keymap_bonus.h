/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:52:56 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 12:53:32 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_BONUS_H
# define KEYMAP_BONUS_H

typedef struct s_game	t_game;

typedef struct s_keymap {
	int	keycode;
	int	(*action)(t_game *game);
}	t_keymap;

#endif