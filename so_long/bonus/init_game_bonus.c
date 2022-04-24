/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:02:04 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 15:23:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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