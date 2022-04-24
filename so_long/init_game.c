/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:02:04 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 14:02:50 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tiles(t_game *game)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_tile(game, i, j);
			j++;
		}
		i++;
	}
}

void	put_walls(t_game *game)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '1')
				put_wall(game, i, j);
			j++;
		}
		i++;
	}
}

void	put_collectibles(t_game *game)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				put_collectible(game, i, j);
			j++;
		}
		i++;
	}
}

void	put_exits(t_game *game, int flag)
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
				put_exit(game, i, j, flag);
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
							64 * (game->width), 64 * (game->height), "so_long");
	if (game->win_ptr == 0)
	{
		free_game(game);
		exit_with_error("Failure in opening window");
	}
	put_tiles(game);
	put_walls(game);
	put_collectibles(game);
	put_exits(game, 0);
	load_character_img(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->character[2][0].img_ptr, 64 * game->loc.x, 64 * game->loc.y);
	game->map[game->loc.y][game->loc.x] = '0';
	mlx_hook(game->win_ptr, X_EVENT_PRESS_KEY, 0, press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_RED_CROSS, 0, press_red_cross, game);
	mlx_loop(game->mlx_ptr);
}
