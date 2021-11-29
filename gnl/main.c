#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*curr;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		curr = get_next_line(fd);
		printf("[%s]\n", curr);
		if (curr == 0)
			return (0);
		if (curr == '\0')
		{
			free(curr);
			return (0);
		}
		free(curr);
	}
	return (0);
}