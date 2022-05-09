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
	printf("---------------------[envp]---------------------\n");
	int i = 0;
	while (arg.envp[i])
		printf("%s\n", arg.envp[i++]);
	printf("---------------------[path]---------------------\n");
	i = 0;
	while (arg.path[i])
		printf("%s\n", arg.path[i++]);
	execute_pipex(arg, p, arg.cmd_cnt);
	return (0);
}