#include "pipex.h"

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		**p;
	char	**path;
	t_arg	arg;
	int		i;

	arg = init_args(argc, argv);
	p = init_pipe(argc);
	path = init_path(envp);
	
	return 0;
}