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

	arg = init_args(argc, argv);
	p = init_pipe(argc);
	arg.path = init_path(envp);
	execute_cmds(arg, path, p, arg.cmd_cnt);
	return (0);
}