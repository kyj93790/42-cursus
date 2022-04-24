#include "so_long.h"

void	check_filename(int argc, char *argv[])
{
	char			*extension;
	unsigned int	len;

	if (argc != 2)
		exit_with_error("Failure by argument");
	len = ft_strlen(argv[1]);
	if (len < 4)
		exit_with_error("Failure by filename");
	extension = ft_substr(argv[1], len - 4, 4);
	if (ft_strncmp(extension, ".ber", 5) != 0)
		exit_with_error("Failure by extension of file");
	free(extension);
}

int	get_file_size(char *filename)
{
	int		fd;
	int		i;
	int		size;
	char	temp[4096];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error("Failure in opening file");
	size = 0;
	while (1)
	{
		i = read(fd, temp, 4096);
		if (i < 0)
			exit_with_error("Failure in reading file");
		if (i == 0)
			break ;
		size += i;
	}
	if (size == 0)
		exit_with_error("Failure by empty file");
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
		exit_with_error("Failure in assigning buffer");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		exit_with_error("Failure in opening file");
	}
	i = read(fd, buffer, size + 1);
	if (i < 0)
	{
		free(buffer);
		exit_with_error("Failure in reading file");
	}
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
