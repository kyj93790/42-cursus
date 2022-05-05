#include "pipex.h"

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
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (envp[i] == NULL)
		exit_with_error("Failure by given envp : path doesn't exist");
	path = ft_split(&envp[i][5], ':');
	if (path == NULL)
		exit_with_error("Failure in ft_split");
	return (path);
}