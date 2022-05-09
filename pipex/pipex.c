#include "pipex.h"

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		**p;
	t_arg	arg;

	init_args(&arg, argc, argv, envp);
	p = init_pipe(argc);
	execute_pipex(arg, p, arg.cmd_cnt);
	return (0);
}