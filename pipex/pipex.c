#include "pipex.h"

void	exit_with_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

t_arg	init_args(int argc, char *argv[])
{
	t_arg	arg;
	int		i;

	if (argc != 5)
		exit_with_error("Failure by number of arguments");
	arg.infile = argv[1];
	arg.cmd_cnt = argc - 3;
	arg.cmd = (char **)malloc(sizeof(char *) * (arg.cmd_cnt + 1));
	if (arg.cmd == NULL)
		exit_with_error("Failure in allocating cmd");
	arg.cmd[0] = NULL;
	i = 0;
	while (++i <= arg.cmd_cnt)
		arg.cmd[i] = argv[i + 1];
	arg.outfile = argv[++i];
	return (arg);
}

int	**init_pipe(int argc)
{
	int	**p;
	int	i;
	int	j;
	
	p = (int **)malloc(sizeof(int *) * (argc - 1));
	if (p == NULL)
		exit_with_error("Failure in allocating pipes");
	i = 0;
	while (i < argc - 1)
	{
		p[i] = (int *)malloc(sizeof(int) * 2);
		if (p[i] == NULL)
			exit_with_error("Failure in allocating a pipe");
		i++;
	}
	return (p);
}

char	**init_path(char *envp[])
{
	char	**path;
	int		i;

	if (!envp)
		exit_with_error("Failure by given envp");
	i = 0;
	while (envp[i])
	{
		
		i++;
	}
	if (envp[i] == NULL)
	{
		perror("")
	}
	
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	int		**p;
	char	**path;
	t_arg	arg;
	
	arg = init_args(argc, argv);
	p = init_pipe(argc);
	path = init_path(envp);
	return 0;
}