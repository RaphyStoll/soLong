/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:19:36 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 00:19:37 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main/fonction.h"

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
