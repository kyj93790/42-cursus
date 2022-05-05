#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	char	*infile;
	int		cmd_cnt;
	char	**cmd;
	char	*outfile;
}	t_arg;

t_arg	init_args(int argc, char *argv[]);
int		**init_pipe(int argc);
char	**init_path(char *envp[]);

#endif
