/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:55:14 by raphalme          #+#    #+#             */
/*   Updated: 2025/01/14 11:56:32 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

typedef struct s_game	t_game;

typedef struct s_keymap
{
	int	keycode;
	int	(*action)(t_game *game);
}						t_keymap;

#endif