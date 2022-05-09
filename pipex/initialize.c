#include "pipex.h"

int	**init_pipe(int argc)
{
	int	**p;
	int	i;
	
	p = (int **)malloc(sizeof(int *) * (argc - 2));
	if (p == NULL)
		exit_with_error("Failure in allocating pipes");
	i = 0;
	while (i < argc - 2)
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

void	add_path(t_arg *arg, int curr_i)
{
	char	*temp_path;
	char	*temp_cmd;
	int		i;

	i = 0;
	while (arg->path[i])
	{
		temp_path = ft_strjoin(arg->path[i], "/");
		if (temp_path == NULL)
			exit_with_error("Failure in adding directory path to cmd");
		temp_cmd = ft_strjoin(temp_path, arg->cmd[curr_i][0]);
		free(temp_path);
		if (temp_cmd == NULL)
			exit_with_error("Failure in adding directory path to cmd");
		if (access(temp_cmd, X_OK) < 0)
			free(temp_cmd);
		else
		{
			free(arg->cmd[curr_i][0]);
			arg->cmd[curr_i][0] = temp_cmd;
			return ;
		}
		i++;
	}
}

void	init_cmd(t_arg *arg, char *argv[])
{
	int	i;

	i = 1;
	while (i <= arg->cmd_cnt)
	{
		arg->cmd[i] = ft_split(argv[i + 1], ' ');
		if (arg->cmd[i] == NULL)
			exit_with_error("Failure in spliting command");
		add_path(arg, i);
		i++;
	}
}

void	init_args(t_arg *arg, int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		exit_with_error("Failure by number of arguments");
	arg->path = init_path(envp);
	arg->envp = envp;
	arg->infile = argv[1];
	arg->cmd_cnt = argc - 3;
	arg->cmd = (char ***)malloc(sizeof(char **) * (arg->cmd_cnt + 1));
	if (arg->cmd == NULL)
		exit_with_error("Failure in allocating cmd");
	arg->cmd[0] = NULL;
	init_cmd(arg, argv);
	arg->outfile = argv[argc - 1];
}