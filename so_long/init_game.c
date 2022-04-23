#include "so_long.h"

void	put_background_tiles(t_game *game)
{
	t_ull	i;
	t_ull	j;

	game->tile.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/tile.xpm", &(game->tile.width), &(game->tile.height));
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
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tile.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_wall(t_game *game)
{
	t_ull	i;
	t_ull	j;

	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/bush.xpm", &(game->wall.width), &(game->wall.height));
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_collectible(t_game *game)
{
	t_ull i;
	t_ull j;

	game->collect.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "imgs/pokeball.xpm", &(game->collect.width), &(game->collect.height));
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
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->collect.img_ptr, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	put_exits(t_game *game)
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
				put_exit(game, i, j);
		}
	}
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 64*(game->width), 64*(game->height), "so_long");
	
	if (game->win_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in opening window");
	}
	put_background_tiles(game);
	put_wall(game);
	put_collectible(game);
	load_character_img(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->character[2][0].img_ptr, 64*game->loc.x, 64*game->loc.y);
	mlx_hook(game->win_ptr, X_EVENT_PRESS_KEY, 0, press_key, game);
	mlx_loop(game->mlx_ptr);
}