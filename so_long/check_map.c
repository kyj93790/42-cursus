#include "so_long.h"

void	free_map(t_game *game)
{
	t_ull	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

static void	get_game_size(t_game *game)
{
	t_ull	i;

	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	game->width = ft_strlen(game->map[0]);
	if (game->height < 3 || game->width < 3)
	{
		free_map(game);
		exit_with_error("Failure by map size");
	}
	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != game->width)
		{
			free_map(game);
			exit_with_error("Failure by feature of map");
		}
		i++;
	}
}

static int	check_outline(t_game *game)
{
	t_ull	i;
	t_ull	h;
	t_ull	w;

	h = game->height;
	w = game->width;
	i = -1;
	while (++i < h)
	{
		if (game->map[i][0] != '1' || game->map[i][w - 1] != '1')
			return (1);
	}
	i = -1;
	while (++i < w)
	{
		if (game->map[0][i] != '1' || game->map[h - 1][i] != '1')
			return (1);
	}
	return (0);
}

static int	check_contents(t_game *game)
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
				(game->num_of_c)++;
			else if (game->map[i][j] == 'E')
				(game->num_of_e)++;
			else if (game->map[i][j] == 'P')
			{
				(game->num_of_p)++;
				game->loc.x = j;
				game->loc.y = i;
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	get_game_size(game);
	if (check_outline(game) || check_contents(game))
	{
		free_map(game);
		exit_with_error("Failure by format of map");
	}
	if (game->num_of_c < 1)
	{
		free_map(game);
		exit_with_error("Failure by number of collectible");
	}
	if (game->num_of_e < 1)
	{
		free_map(game);
		exit_with_error("Failure by number of exit");
	}
	if (game->num_of_p != 1)
	{
		free_map(game);
		exit_with_error("Failure by number of starting position");
	}
}