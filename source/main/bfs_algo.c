#include "../includes/main/fonction.h"
#include "../includes/main/game.h"
#include "../includes/main/macro.h"

void	run_bfs(t_game *game)
{
	t_bfs	*bfs;

	bfs = game->bfs;
	while (bfs->start < bfs->end)
	{
		bfs->x = bfs->queue_x[bfs->start];
		bfs->y = bfs->queue_y[bfs->start];
		bfs->start++;
		check_current_cell(game, bfs->x, bfs->y);
		visit_neighbor(game, bfs->x + 1, bfs->y);
		visit_neighbor(game, bfs->x - 1, bfs->y);
		visit_neighbor(game, bfs->x, bfs->y + 1);
		visit_neighbor(game, bfs->x, bfs->y - 1);
	}
	if (bfs->found_items == game->map->items && bfs->exit_found == true)
	{
		ft_printf("bfs is valid\n");
		free_bfs(game);
	}
	else
		ft_exit_error("Error\nmap bfs is invalid\n");
}
//$ px = player x
//$ py = player y
//$	nx = new x
//$ ny = new y

void	visit_neighbor(t_game *game, int nx, int ny)
{
	t_bfs	*bfs;

	bfs = game->bfs;
	if (nx < 0 || nx >= bfs->width || ny < 0 || ny >= bfs->height)
		return ;
	if (bfs->map[ny][nx] == '1')
		return ;
	if (bfs->dist[ny][nx] == 1)
		return ;
	bfs->dist[ny][nx] = 1;
	bfs->queue_x[bfs->end] = nx;
	bfs->queue_y[bfs->end] = ny;
	bfs->end++;
}

void	check_current_cell(t_game *game, int x, int y)
{
	char c;

	c = game->bfs->map[y][x];
	if (c == 'C')
		game->bfs->found_items++;
	else if (c == 'E')
		game->bfs->exit_found = true;
}