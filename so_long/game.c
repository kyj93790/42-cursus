#include "so_long.h"

void	start_game(t_map *map_info)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*tile_ptr;
	void	*bush_ptr;
	int		width;
	int		height;
	t_loc	loc;

	mlx_ptr = mlx_init();
	loc.x = 0;
	loc.y = 0;
	// window의 size를 map의 크기로 정할 것
	win_ptr = mlx_new_window(mlx_ptr, 64*(map_info->width), 64*(map_info->height), "so_long");
	if (win_ptr == 0)
	{
		free_map(map_info);
		exit_with_error("Failure in opening window");
	}
	tile_ptr = mlx_xpm_file_to_image(mlx_ptr, "tile.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, tile_ptr, 0, 0);
	bush_ptr = mlx_xpm_file_to_image(mlx_ptr, "bush.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, bush_ptr, 0, 0);
	//mlx_hook(win_ptr, X_EVENT_PRESS_KEY, 0, press_key, &loc);
	mlx_loop(mlx_ptr);
}