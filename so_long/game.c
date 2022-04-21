#include "so_long.h"

void	put_background_tiles(void *mlx_ptr, void *win_ptr, t_map *map_info)
{
	t_img	tile;
	t_ull	i;
	t_ull	j;

	tile.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "tile.xpm", &(tile.width), &(tile.height));
	i = 0;
	while (i < map_info->height)
	{
		j = 0;
		while (j < map_info->width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, tile.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	start_game(t_map *map_info)
{
	void	*mlx_ptr;
	void	*win_ptr;
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
	// 전체 배경 tile 까는 함수 생성
	put_background_tiles(mlx_ptr, win_ptr, map_info);
	bush_ptr = mlx_xpm_file_to_image(mlx_ptr, "bush.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, bush_ptr, 0, 0);
	//mlx_hook(win_ptr, X_EVENT_PRESS_KEY, 0, press_key, &loc);
	mlx_loop(mlx_ptr);
}