#include "get_next_line.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
void check(bool succes)
{
	return ;
}

void gnl(int fd, char* expectedReturn)
{
	static int cnt = 0;

	cnt++;
	char *  gnlReturn = get_next_line(fd);
	printf("[%d]the string is [%s], [%s]\n", cnt, gnlReturn, expectedReturn);
	if (expectedReturn == NULL)
		check(gnlReturn == NULL);
	else
		check(!strcmp(gnlReturn, expectedReturn));
	free(gnlReturn);
}


int	main(void)
{
	char	*curr;
	int		fd;



	fd = open("./files/multiple_line_with_nl", O_RDONLY);
	gnl(fd, "9876543210987654321098765432109876543210\n");
		 /* 2 */ gnl(fd, "01234567890123456789012345678901234567890\n");
		 /* 3 */ gnl(fd, "987654321098765432109876543210987654321098\n");
		 /* 4 */ gnl(fd, "01234567890123456789012345678901234567890\n");
		 /* 5 */ gnl(fd, "9876543210987654321098765432109876543210\n");
		 /* 6 */ gnl(fd, NULL);
	/*
	while (1)
	{
		curr = get_next_line(fd);
		free(curr);
		printf("[%s]\n", curr);
		if (curr == 0)
			break ;
		if (*curr == '\0')
			break ;
	}
	*/
	//system("leaks a.out");
	return (0);
}
