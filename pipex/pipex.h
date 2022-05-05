#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct	s_arg
{
	char	*infile;
	char	**cmds;
	char	*outfile;
}	t_arg;

#endif
