#include "so_long.h"

void	exit_with_error(char *message)
{
	printf("Error\n");
	perror(message);
	exit(EXIT_FAILURE);
}

static void init(t_map *map_info)
{
	map_info->height = 0;
	map_info->width = 0;
	map_info->map = 0;
	map_info->num_of_c = 0;
	map_info->num_of_e = 0;
	map_info->num_of_p = 0;
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*buffer;
	t_map	map_info;
	int		i;

	check_filename(argc, argv);
	init(&map_info);
	buffer = read_file(argv[1]);
	map_info.map = ft_split(buffer, '\n');
	i = 0;
	while(map_info.map[i])
	{
		printf("%s\n", map_info.map[i++]);
	}
	free(buffer);
	if (map_info.map == 0)
		exit_with_error("Failure in splitting buffer to map");
	check_map(&map_info);
	start_game(&map_info);
}
