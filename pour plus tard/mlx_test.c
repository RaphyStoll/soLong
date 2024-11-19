#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		printf("Failed to initialize mlx\n");
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 800, 400, "solong");
	if (!win_ptr)
	{
		printf("Failed to create window\n");
		return (free(mlx_ptr), 1);
	}
	printf("mlx_ptr: %p\n", mlx_ptr);
	printf("win_ptr: %p\n", win_ptr);
	printf("loop\n");
int countx = 400;
int county = 200;
	while (county < 250)
	{
		countx = 400;
		while(countx < 450)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, countx, county, 0xffffff);
			countx++;
		}
		mlx_pixel_put(mlx_ptr, win_ptr, countx, county, 0xffffff);
		county++;
	}
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}