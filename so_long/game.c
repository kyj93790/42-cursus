#include "so_long.h"

void	start_game(t_map *map_info)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	x = 0;
	y = 0;
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	if (win_ptr == 0)
	{
		free_map(map_info);
		exit_with_error("Failure in opening window");
	}
	mlx_loop(mlx_ptr);
}