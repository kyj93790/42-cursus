#include "so_long.h"

void	put_background_tiles(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_ull	i;
	t_ull	j;

	game->tile.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/tile.xpm", &(game->tile.width), &(game->tile.height));
	if (game->tile.img_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in getting tile image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, game->tile.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_wall(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_ull	i;
	t_ull	j;

	game->wall.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/bush.xpm", &(game->wall.width), &(game->wall.height));
	if (game->wall.img_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in getting wall image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, game->wall.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_collectible(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_ull i;
	t_ull j;

	game->collect.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/pokeball.xpm", &(game->collect.width), &(game->collect.height));
	if (game->collect.img_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in getting collectible image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, game->collect.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_exits(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'E')
				put_exit(mlx_ptr, win_ptr, game, i, j);
		}
	}
}

void	init_game(t_game *game)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	// window의 size를 map의 크기로 정할 것
	win_ptr = mlx_new_window(mlx_ptr, 64*(game->width), 64*(game->height), "so_long");
	
	if (win_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in opening window");
	}
	put_background_tiles(mlx_ptr, win_ptr, game);
	put_wall(mlx_ptr, win_ptr, game);
	put_collectible(mlx_ptr, win_ptr, game);
	load_character_img(mlx_ptr, win_ptr, game);
	mlx_put_image_to_window(mlx_ptr, win_ptr, game->character[2][0].img_ptr, 64*game->loc.x, 64*game->loc.y);
	mlx_hook(win_ptr, X_EVENT_PRESS_KEY, 0, press_key, game);
	mlx_loop(mlx_ptr);
}