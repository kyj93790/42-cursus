#include "so_long.h"

void	exit_with_error(char *message)
{
	printf("Error\n");
	perror(message);
	exit(EXIT_FAILURE);
}

static void init(t_game *game)
{
	game->height = 0;
	game->width = 0;
	game->map = 0;
	game->num_of_c = 0;
	game->num_of_e = 0;
	game->num_of_p = 0;
}

int	main(int argc, char *argv[])
{
	char	*buffer;
	t_game	game;
	int		i;

	check_filename(argc, argv);
	init(&game);
	buffer = read_file(argv[1]);
	game.map = ft_split(buffer, '\n');
	i = 0;
	while(game.map[i])
	{
		printf("%s\n", game.map[i++]);
	}
	free(buffer);
	if (game.map == 0)
		exit_with_error("Failure in splitting buffer to map");
	check_map(&game);
	init_game(&game);
}
