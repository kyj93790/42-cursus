#include "so_long.h"

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	check_filename(int argc, char *argv[])
{
	char			*extension;
	unsigned int	len;

	if (argc != 2)
		exit_with_error("ERROR in check_filename");
	len = ft_strlen(argv[1]);
	if (len < 4)
		exit_with_error("ERROR in check_filename");
	extension = ft_substr(argv[1], len-4, 4);
	if (ft_strncmp(extension, ".ber", 5) != 0)
		exit_with_error("ERROR in check_filename");
	free(extension);
}

int	main(int argc, char *argv[])
{
	int	fd;
	t_map map_info;

	check_filename(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_with_error("ERROR in main");
	// read first_line
	// 1. 첫 줄 read
	// 처음부터 아무것도 없는 파일 -> error
	// 있으면 width 저장해야 함 (이게 다른 line들의 기준점이 됨)
	// width랑 height 3이상이어야 함 (그래야 하나의 출구, 하나의 수집품, 하나의 시작점을 보유할 수 있음)
	// 전부 1이 아니면 error
	// 나머지 line을 모두 읽
	
}