/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:02:40 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 16:05:46 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_tile(t_game *game, t_ull i, t_ull j)
{
	if (game->tile.img_ptr == NULL)
	{
		game->tile.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/tile.xpm", \
				&(game->tile.width), &(game->tile.height));
		if (game->tile.img_ptr == NULL)
		{
			free_game(game);
			exit_with_error("Failure in getting tile image");
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->tile.img_ptr, 64 * j, 64 * i);
}

void	put_wall(t_game *game, t_ull i, t_ull j)
{
	if (game->wall.img_ptr == NULL)
	{
		game->wall.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/wall.xpm", \
				&(game->wall.width), &(game->wall.height));
		if (game->wall.img_ptr == NULL)
		{
			free_game(game);
			exit_with_error("Failure in getting wall image");
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->wall.img_ptr, 64 * j, 64 * i);
}

void	put_collectible(t_game *game, t_ull i, t_ull j)
{
	if (game->collect.img_ptr == NULL)
	{
		game->collect.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/collect.xpm", &\
				(game->collect.width), &(game->collect.height));
		if (game->collect.img_ptr == NULL)
		{
			free_game(game);
			exit_with_error("Failure in getting collectible image");
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->collect.img_ptr, 64 * j, 64 * i);
}

static void	load_exit_img(t_game *game, int flag)
{
	void	*temp_ptr;

	if (flag == 0)
	{
		if (game->exit.img_ptr == NULL)
			game->exit.img_ptr = mlx_xpm_file_to_image(\
					game->mlx_ptr, "imgs/exit.xpm", \
					&(game->exit.width), &(game->exit.height));
	}
	else
	{
		temp_ptr = game->exit.img_ptr;
		game->exit.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/exit1.xpm", \
				&(game->exit.width), &(game->exit.height));
		if (temp_ptr)
			mlx_destroy_image(game->mlx_ptr, temp_ptr);
	}
}

void	put_exit(t_game *game, t_ull i, t_ull j, int flag)
{
	load_exit_img(game, flag);
	if (game->exit.img_ptr == NULL)
	{
		free_game(game);
		exit_with_error("Failure in getting exit image");
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->exit.img_ptr, 64 * j, 64 * i);
}
