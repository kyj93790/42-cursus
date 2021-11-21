#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*curr;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == 0)
		return (0);
	while (1)
	{
		curr = get_next_line(fd);
		if (*curr == '\0')
			break ;
		printf("%s", curr);
	}
	system("leaks a.out");
	return (0);
}
