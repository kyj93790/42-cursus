/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:05:33 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 16:05:53 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy(t_game *game, t_ull i, t_ull j)
{
	if (game->enemy.img_ptr == NULL)
	{
		game->enemy.img_ptr = mlx_xpm_file_to_image(\
				game->mlx_ptr, "imgs/enemy.xpm", \
				&(game->enemy.width), &(game->enemy.height));
		if (game->enemy.img_ptr == NULL)
		{
			free_game(game);
			exit_with_error("Failure in getting enemy image");
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
							game->enemy.img_ptr, 64 * j, 64 * i);
}

void	put_enemys(t_game *game)
{
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'X')
				put_enemy(game, i, j);
			j++;
		}
		i++;
	}
}
