#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define EACCESS 2
# define EXIT_FOPEN 1
# define EXIT_CNF 127
# define P_READ 0
# define P_WRITE 1

typedef struct s_arg
{
	char	*infile;
	int		cmd_cnt;
	char	***cmd;
	char	*outfile;
	char	**envp;
	char	**path;
}	t_arg;

void	exit_with_error(int exit_num, char *message, char *filename);

void	init_args(t_arg *arg, int argc, char *argv[], char *envp[]);
int		**init_pipe(int argc);
char	**init_path(char *envp[]);

void	execute_pipex(t_arg arg, int **p, int i);

int		wifexited(int status);
int 	wexitstatus(int status);

#endif
