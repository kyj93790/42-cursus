/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:03:00 by yejin             #+#    #+#             */
/*   Updated: 2022/04/24 15:19:27 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_with_error(char *message)
{
	printf("Error\n");
	perror(message);
	exit(EXIT_FAILURE);
}

static void	init(t_game *game)
{
	int	i;
	int	j;

	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->height = 0;
	game->width = 0;
	game->map = 0;
	game->num_of_c = 0;
	game->num_of_e = 0;
	game->num_of_p = 0;
	game->tile.img_ptr = NULL;
	game->wall.img_ptr = NULL;
	game->collect.img_ptr = NULL;
	game->exit.img_ptr = NULL;
	game->enemy.img_ptr = NULL;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			game->character[i][j].img_ptr = NULL;
	}
	game->loc.dir = 0;
	game->cnt = 0;
}

void	start_game(t_game *game)
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
	put_enemys(game);
	game->map[game->loc.y][game->loc.x] = '0';
	mlx_hook(game->win_ptr, X_EVENT_PRESS_KEY, 0, press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_RED_CROSS, 0, press_red_cross, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char *argv[])
{
	char	*buffer;
	t_game	game;

	check_filename(argc, argv);
	init(&game);
	buffer = read_file(argv[1]);
	game.map = ft_split(buffer, '\n');
	free(buffer);
	if (game.map == 0)
		exit_with_error("Failure in splitting buffer to map");
	check_map(&game);
	start_game(&game);
}
