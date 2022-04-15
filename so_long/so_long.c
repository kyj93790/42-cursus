#include "so_long.h"

void	exit_with_error(char *message)
{
	printf("Error\n");
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*buffer;
	t_map	map_info;
	int		i;

	check_filename(argc, argv);
	buffer = read_file(argv[1]);
	map_info.map = ft_split(buffer, '\n');
	free(buffer);
	if (map_info.map == 0)
		exit_with_error("Failure in splitting buffer to map");
	//check_map(&map_info);
}
