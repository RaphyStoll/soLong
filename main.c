#include "header_solong/fonction.h"
#include "header_solong/maps.h"
#include "header_solong/textures.h"
#include "mlx/mlx.h"

void arg_verif(int argc)
{
	if (argc != 2)
	ft_exit_error("Error\nInvalid number of arguments");
}

//unsigned long long int = 18446744073709551615 max value
int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_textures	textures;
	t_map	*map;

	arg_verif(argc);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Solong");
	map = map_init(argv[1]);
	ft_printf("mlx_ptr = %d\n", mlx_ptr);
	ft_printf("win_ptr = %d\n", win_ptr);
	ft_printf("==map is valid==\n");
	load_textures(&textures, mlx_ptr);
	put_textures(&textures, map, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	return (0);
}
