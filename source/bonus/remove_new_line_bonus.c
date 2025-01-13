/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_new_line_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:33:30 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:33:31 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"

void	remove_newline_in_line(char *line)
{
	int	i;
	int	j;

	if (!line)
		return ;
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != '\n')
		{
			line[j] = line[i];
			j++;
		}
		i++;
	}
	line[j] = '\0';
}

void	remove_all_newlines(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		remove_newline_in_line(map[i]);
		i++;
	}
}
