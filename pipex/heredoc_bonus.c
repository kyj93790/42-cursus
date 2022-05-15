#include "pipex_bonus.h"

void	get_infile(char *limiter)
{
	int		fd;
	size_t	len;
	char	*temp;

	fd = open("temp_file", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error(EXIT_FAILURE, "failure in generating temp file", NULL);
	len = ft_strlen(limiter);
	while (1)
	{
		temp = get_next_line(0);
		if (temp == 0)
			exit_with_error(EXIT_FAILURE, "failure in gnl", NULL);
		if (ft_strlen(temp) == len + 1 && strncmp(temp, limiter, len) == 0)
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, fd);
	}
	close(fd);
}
