/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:41:10 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:41:11 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**init_pipe(int argc)
{
	int	**p;
	int	i;

	p = (int **)malloc(sizeof(int *) * (argc - 2));
	if (p == NULL)
		exit_with_error(EXIT_FAILURE, "failure in allocating pipes", NULL);
	i = 0;
	while (i < argc - 2)
	{
		p[i] = (int *)malloc(sizeof(int) * 2);
		if (p[i] == NULL)
			exit_with_error(EXIT_FAILURE, "failure in allocating a pipe", NULL);
		i++;
	}
	return (p);
}

char	**init_path(char *envp[])
{
	char	**path;
	int		i;

	if (!envp)
		exit_with_error(EXIT_FAILURE, "failure by given envp", NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		exit_with_error(EXIT_FAILURE, "failure by envp", "path doesn't exist");
	path = ft_split(&envp[i][5], ':');
	if (path == NULL)
		exit_with_error(EXIT_FAILURE, "failure in ft_split", NULL);
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
			exit_with_error(EXIT_FAILURE, "failure in adding path", NULL);
		temp_cmd = ft_strjoin(temp_path, arg->cmd[curr_i][0]);
		free(temp_path);
		if (temp_cmd == NULL)
			exit_with_error(EXIT_FAILURE, "Failure in adding path", NULL);
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
		arg->cmd[i] = ft_split(argv[i + arg->here_doc + 1], ' ');
		if (arg->cmd[i] == NULL)
			exit_with_error(EXIT_FAILURE, "failure in spliting command", NULL);
		add_path(arg, i);
		i++;
	}
}

void	init_args(t_arg *arg, int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		exit_with_error(EXIT_FAILURE, "failure by number of arguments", NULL);
	arg->path = init_path(envp);
	arg->envp = envp;
	if (strncmp("here_doc", argv[1], 9) == 0)
	{
		get_infile(argv[2]);
		arg->here_doc = 2;
		arg->infile = "temp_file";
	}
	else
	{
		arg->here_doc = 0;
		arg->infile = argv[1 + arg->here_doc];
	}
	arg->cmd_cnt = argc - arg->here_doc - 3;
	arg->cmd = (char ***)malloc(sizeof(char **) * (arg->cmd_cnt + 1));
	if (arg->cmd == NULL)
		exit_with_error(EXIT_FAILURE, "failure in allocating cmd", NULL);
	arg->cmd[0] = NULL;
	init_cmd(arg, argv);
	arg->outfile = argv[argc - 1];
}
