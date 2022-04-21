#include "so_long.h"

void	put_background_tiles(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_img	tile;
	t_ull	i;
	t_ull	j;

	tile.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/tile.xpm", &(tile.width), &(tile.height));
	if (tile.img_ptr == 0)
	{
		free_map(game);
		exit_with_error("Failure in getting tile image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, tile.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void put_wall(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_img	bush;
	t_ull	i;
	t_ull	j;

	bush.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/bush.xpm", &(bush.width), &(bush.height));
	if (bush.img_ptr == 0)
	{
		free_map(game);
		exit_with_error("Failure in getting wall image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, bush.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_collectible(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_img pokeball;
	t_ull i;
	t_ull j;

	pokeball.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/pokeball.xpm", &(pokeball.width), &(pokeball.height));
	if (pokeball.img_ptr == 0)
	{
		free_map(game);
		exit_with_error("Failure in getting collectible image");
	}
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, pokeball.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	load_character_img(void *mlx_ptr, void *win_ptr, t_game *game)
{
	t_img character;

	printf("before load right3\n");
	character.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "imgs/character/up3.xpm", &(character.width), &(character.height));
	printf("%lld, %lld\n", game->loc.y, game->loc.x);
	if (character.img_ptr == 0)
		printf("null\n");
	mlx_put_image_to_window(mlx_ptr, win_ptr, character.img_ptr, 64*(game->loc.y), 64*(game->loc.x));
	printf("after print character\n");
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
		free_map(game);
		exit_with_error("Failure in opening window");
	}
	put_background_tiles(mlx_ptr, win_ptr, game);
	put_wall(mlx_ptr, win_ptr, game);
	put_collectible(mlx_ptr, win_ptr, game);
	load_character_img(mlx_ptr, win_ptr, game);
	//mlx_hook(win_ptr, X_EVENT_PRESS_KEY, 0, press_key, &loc);
	mlx_loop(mlx_ptr);
}