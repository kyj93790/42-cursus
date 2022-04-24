/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:01:54 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 16:40:21 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	refresh_curr_pos(t_game *game, t_ull curr_x, t_ull curr_y)
{
	put_tile(game, curr_y, curr_x);
	if (game->map[curr_y][curr_x] == 'E')
	{
		if (game->cnt == game->num_of_c)
			put_exit(game, curr_y, curr_x, 1);
		else
			put_exit(game, curr_y, curr_x, 0);
	}
}

void	move_to_new_pos(t_game *game, t_ull new_dir, t_ull new_x, t_ull new_y)
{
	game->loc.dir = new_dir;
	if (game->map[new_y][new_x] != '1')
	{
		game->loc.x = new_x;
		game->loc.y = new_y;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
					game->character[game->loc.dir][game->move % 4].img_ptr, \
					64 * game->loc.x, 64 * game->loc.y);
}

void	check_new_pos(t_game *game)
{
	if (game->map[game->loc.y][game->loc.x] == 'E')
	{
		if (game->cnt == game->num_of_c)
		{
			free_game(game);
			printf("SUCCESS !\n");
			exit(EXIT_SUCCESS);
		}
	}
	else if (game->map[game->loc.y][game->loc.x] == 'C')
	{
		(game->cnt)++;
		game->map[game->loc.y][game->loc.x] = '0';
		put_tile(game, game->loc.y, game->loc.x);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->character[game->loc.dir][game->move % 4].img_ptr, \
				64 * game->loc.x, 64 * game->loc.y);
		if (game->cnt == game->num_of_c)
			put_exits(game, 1);
	}
	else if (game->map[game->loc.y][game->loc.x] == 'X')
	{
		printf("FAILURE !\n");
		press_red_cross(game);
	}
}

int	press_key(int key_in, t_game *game)
{
	if (key_in == KEY_ESC)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	if (key_in == KEY_W || key_in == KEY_A || \
		key_in == KEY_S || key_in == KEY_D)
	{
		(game->move)++;
		refresh_curr_pos(game, game->loc.x, game->loc.y);
		if (key_in == KEY_W)
			move_to_new_pos(game, 0, game->loc.x, game->loc.y - 1);
		else if (key_in == KEY_A)
			move_to_new_pos(game, 1, game->loc.x - 1, game->loc.y);
		else if (key_in == KEY_S)
			move_to_new_pos(game, 2, game->loc.x, game->loc.y + 1);
		else if (key_in == KEY_D)
			move_to_new_pos(game, 3, game->loc.x + 1, game->loc.y);
		check_new_pos(game);
		print_movements(game);
	}
	return (0);
}

int	press_red_cross(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
