#include "header_solong/fonction.h"
#include "header_solong/maps.h"
#include "header_solong/textures.h"
#include "header_solong/window.h"
#include "mlx/mlx.h"

void arg_verif(int argc)
{
	if (argc != 2)
	ft_exit_error("Error\nInvalid number of arguments");
}

//unsigned long long int = 18446744073709551615 max value
int	main(int argc, char **argv)
{
	t_window	*window;
	t_textures	textures;
	t_map	*map;

	arg_verif(argc);
	window_setup(map, &window);
	map = map_init(argv[1]);
	ft_printf("mlx_ptr = %d\n", window->mlx_ptr);
	ft_printf("win_ptr = %d\n", window->win_ptr);
	ft_printf("==map is valid==\n");
	load_textures(&textures, window->mlx_ptr);
	put_textures(&textures, map, window->mlx_ptr, window->win_ptr);
	mlx_loop(window->mlx_ptr);
	mlx_destroy_display(window->mlx_ptr);
	return (0);
}
