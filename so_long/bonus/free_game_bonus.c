/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:02:00 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 15:19:14 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_imgs(t_game *game)
{
	t_ull	i;
	t_ull	j;

	if (game->tile.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->tile.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	if (game->collect.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collect.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (game->character[i][j].img_ptr)
				mlx_destroy_image(game->mlx_ptr, game->character[i][j].img_ptr);
		}
	}
}

void	free_game(t_game *game)
{
	t_ull	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	free_imgs(game);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}
