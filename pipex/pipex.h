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
	char	**envp;
	char	**path;
}	t_arg;

void	exit_with_error(char *message);

t_arg	init_args(int argc, char *argv[]);
int		**init_pipe(int argc);
char	**init_path(char *envp[]);

void	execute_pipex(t_arg arg, int **p, int i);

void	redirect_from_infile(t_arg arg, int **p);
void	redirect_to_outfile(t_arg arg, int **p);

#endif
