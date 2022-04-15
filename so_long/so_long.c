#include "so_long.h"

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*buffer;
	t_map	map_info;

	check_filename(argc, argv);
	buffer = read_file(argv[1]);
	map_info.map = ft_split(read_file(argv[1]), '\n');
	check_map(&map_info);
	// 있으면 width 저장해야 함 (이게 다른 line들의 기준점이 됨)
	// width랑 height 3이상이어야 함 (그래야 하나의 출구, 하나의 수집품, 하나의 시작점을 보유할 수 있음)
	// 전부 1이 아니면 error
	// 나머지 line을 모두 읽
}
