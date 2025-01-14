/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_valid_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphalme <raphalme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:37 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/14 11:54:12 by raphalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/macro_bonus.h"
#include "../includes/bonus/maps_bonus.h"

int	validate_rectangle(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		if ((int)ft_strlen(map.map[y]) != map.width)
			return (FALSE);
		y++;
	}
	return (TRUE);
}
