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
	char	***cmd;
	char	*outfile;
	char	**envp;
	char	**path;
}	t_arg;

void	exit_with_error(char *message);

void	init_args(t_arg *arg, int argc, char *argv[], char *envp[]);
int		**init_pipe(int argc);
char	**init_path(char *envp[]);

void	execute_pipex(t_arg arg, int **p, int i);

#endif
