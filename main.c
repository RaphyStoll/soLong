#include "header_solong/fonction.h"
#include "mlx/mlx.h"

//unsigned long long int = 18446744073709551615 max value
int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;

	if (argc != 2)
		ft_exit_error("Error\nInvalid number of arguments");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Solong");
	ft_printf("===initialisation===\n");
	ft_printf("mlx_ptr = %p\n", mlx_ptr);
	ft_printf("win_ptr = %p\n", win_ptr);
	ft_printf("argv = %s\n", argv[1]);
	ft_printf("====================\n");
	map = open_and_read_map(argv[1]);
	validate_wall(map, 6, 6, argv[1]);
	mlx_loop(mlx_ptr);
	return (0);
}
