/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:40:38 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:40:40 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_cmd(t_arg arg, int **p, int i)
{	
	extern int	errno;

	if (i == 1)
		redirect_from_infile(arg);
	else
	{
		if (dup2(p[i - 1][P_READ], STDIN_FILENO) < 0)
			exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
		close(p[i - 1][P_READ]);
	}
	if (i == arg.cmd_cnt)
		redirect_to_outfile(arg);
	else
	{
		if (dup2(p[i][P_WRITE], STDOUT_FILENO) < 0)
			exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	}
	execve(arg.cmd[i][0], arg.cmd[i], arg.envp);
	if (errno == EACCESS)
		exit_with_error(EXIT_CNF, "command not found", arg.cmd[i][0]);
	else
		exit_with_error(EXIT_FAILURE, "failure by execve", NULL);
}

void	wait_child_and_execute_cmd(pid_t pid, t_arg arg, int **p, int i)
{
	int	flag;
	int	status;
	int	ret;

	flag = 0;
	while (1)
	{
		ret = waitpid(pid, &status, WNOHANG);
		if (ret && !wifexited(status))
			exit(EXIT_FAILURE);
		if (!flag)
		{
			flag = 1;
			close(p[i - 1][P_WRITE]);
			execute_cmd(arg, p, i);
		}
	}
}

void	execute_cmds(t_arg arg, int **p, int i)
{
	pid_t	pid;

	if (i == 0)
		return ;
	if (pipe(p[i - 1]) < 0)
		exit_with_error(EXIT_FAILURE, "failure in generating pipe", NULL);
	pid = fork();
	if (pid < 0)
		exit_with_error(EXIT_FAILURE, "failure in fork", NULL);
	if (pid == 0)
	{
		close(p[i - 1][P_READ]);
		execute_cmds(arg, p, i - 1);
		close(p[i - 1][P_WRITE]);
		return ;
	}
	wait_child_and_execute_cmd(pid, arg, p, i);
}

void	execute_pipex(t_arg arg, int **p, int i)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid < 0)
		exit_with_error(EXIT_FAILURE, "Failure in fork", NULL);
	if (pid == 0)
	{
		execute_cmds(arg, p, i);
		return ;
	}
	while (1)
	{
		ret = waitpid(pid, &status, WNOHANG);
		if (ret)
		{
			if (wifexited(status))
				exit(wexitstatus(status));
			else
				exit(EXIT_FAILURE);
		}
	}
}
