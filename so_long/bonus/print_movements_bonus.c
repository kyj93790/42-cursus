#include "so_long_bonus.h"

static void	refresh_first_line(t_game *game)
{
	t_ull	j;

	j = 0;
	while (j < game->width)
	{
		put_tile(game, 0, j);
		put_wall(game, 0, j);
		j++;
	}
}

void	print_movements(t_game *game)
{
	char	*num;
	char	*message;

	num = ft_itoa(game->move);
	message = ft_strjoin("current number of move : ", num);
	if (message == 0)
	{
		free_game(game);
		exit_with_error("Failure in printing number of movements");
	}
	free(num);
	refresh_first_line(game);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 32, 32, 0xFF0000, message);
	free(message);
}
