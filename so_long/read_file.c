#include "so_long.h"

void	check_filename(int argc, char *argv[])
{
	char			*extension;
	unsigned int	len;

	if (argc != 2)
		exit_with_error("ERROR in check_filename");
	len = ft_strlen(argv[1]);
	if (len < 4)
		exit_with_error("ERROR in check_filename");
	extension = ft_substr(argv[1], len - 4, 4);
	if (ft_strncmp(extension, ".ber", 5) != 0)
		exit_with_error("ERROR in check_filename");
	free(extension);
}

int	*get_file_size(char *filename)
{
	int		fd;
	int		i;
	int		size;
	char	temp[4096];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error("ERROR in get_file_size");
	size = 0;
	while (1)
	{
		i = read(fd, temp, 4096);
		if (i < 0)
			exit_with_error("ERROR in get_file_size");
		if (i == 0)
			break ;
		size += i;
	}
	if (size == 0)
		exit_with_error("ERROR in get_file_size");
	close(fd);
	return (size);
}

char	*read_file(char *filename)
{
	int		fd;
	int		i;
	int		size;
	char	*buffer;

	size = get_file_size(filename);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (buffer == 0)
		exit_with_error("ERROR in read_file");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error("ERROR in read_file");
	i = read(fd, buffer, size + 1);
	if (i < 0)
		exit_with_error("ERROR in read_file");
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}