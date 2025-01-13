/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelferreira <raphaelferreira@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:32:54 by raphaelferr       #+#    #+#             */
/*   Updated: 2025/01/13 15:32:55 by raphaelferr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus/fonction_bonus.h"
#include "../includes/bonus/maps_bonus.h"

t_map	*map_init(t_game *game, char *av)
{
	game->map = NULL;
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		ft_exit_error("Error\nt_map malloc failed");
	map_setup(game, av);
	valid_map(game->map);
	return (game->map);
}

// set les valeurs de base de la structure map
t_map	*map_setup(t_game *game, char *av)
{
	game->map->map_name = av;
	game->map->moves = 0;
	game->map->collected = 0;
	game->map->exit_isopen = 0;
	game->map->height = count_lines(game->map->map_name);
	game->map->width = count_width(game->map->map_name);
	game->map->map = open_and_read_map(game->map->map_name);
	game->map->items = count_item(game->map);
	game->map->exit = count_exit(game->map);
	game->map->player = count_player(game->map);
	game->map->player_x = find_player_x(game);
	game->map->player_y = find_player_y(game);
	game->map->old_player_x = game->map->player_x;
	game->map->old_player_y = game->map->player_y;
	game->map->exit_x = find_exit_x(game);
	game->map->exit_y = find_exit_y(game);
	return (game->map);
}
