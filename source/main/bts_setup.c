#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

t_bfs	*bfs_init(t_game *game)
{
	game->bfs = NULL;
	game->bfs = malloc(sizeof(t_bfs));
	if(!game->bfs)
		ft_exit_error("error\nt_bfs malloc failed");
	bfs_setup(game);
	return (game->bfs);
}

t_bfs	*bfs_setup(t_game *game)
{
	//$ft_printf("\n===bfs_setup===\n");
	game->bfs->width = game->map->width;
	game->bfs->height = game->map->height;
	game->bfs->queue_size = game->bfs->width * game->bfs->height;
	game->bfs->queue_x = set_queue(game, 'x');
	game->bfs->queue_y = set_queue(game, 'y');
	game->bfs->start = 0;
	game->bfs->end = 1; //1 car pose du player en queue
	game->bfs->dist = set_dist(game);
	game->bfs->map = game->map->map;
	game->bfs->found_items = 0;
	game->bfs->exit_found = false;
	game->bfs->x = -1;
	game->bfs->y = -1;
	return (game->bfs);
}

int	*set_queue(t_game *game, char a)
{
	int *queue;

	queue = malloc(sizeof(int) * game->bfs->queue_size);
	if(!queue)
		ft_exit_error("Error\nmalloc queue failed");
	if(a == 'y')
		queue[0] = game->map->player_y;
	else if (a == 'x')
		queue[0] = game->map->player_x;
	else
		ft_exit_error("Error\nqueue is'nt a x or y");
	return (queue);
}

int **set_dist(t_game *game)
{
	int	**dist;
	int	y;
	int	x;

	dist = malloc(sizeof(int *) * game->bfs->height);
	if(!dist)
		ft_exit_error("Error\nmalloc dist failed");
	y = 0;
	while (y < game->bfs->height)
	{
		dist[y] = malloc(sizeof(int) * game->bfs->width);
		if(!dist[y])
			ft_exit_error("Error\nmalloc dist[y] failed");
		x = 0;
		while (x < game->bfs->width)
			{
				dist[y][x] = 0;
				x++;
			}
			y++;
	}
	return (dist);
}
