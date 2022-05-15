#include "pipex_bonus.h"

void	redirect_from_infile(t_arg arg)
{
	extern int	errno;
	int			fd;
	int			ret;

	fd = open(arg.infile, O_RDONLY);
	if (fd < 0)
		exit_with_error(EXIT_FOPEN, "no such file or directory", arg.infile);
	ret = dup2(fd, STDIN_FILENO);
	if (ret < 0)
		exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	close(fd);
}

void	redirect_to_outfile(t_arg arg)
{
	extern int	errno;
	int			fd;
	int			ret;

	fd = open(arg.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error(EXIT_FOPEN, "no such file or directory", arg.outfile);
	ret = dup2(fd, STDOUT_FILENO);
	if (ret < 0)
		exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	close(fd);
}

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

void	execute_cmds(t_arg arg, int **p, int i)
{
	pid_t	pid;
	int		status;
	int		ret;
	int		flag;

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
	flag = 0;
	while (1)
	{
		ret = waitpid(pid, &status, WNOHANG);
		if (ret && !wifexited(status))
			exit(EXIT_FAILURE);
		if (!flag)
		{
			close(p[i - 1][P_WRITE]);
			execute_cmd(arg, p, i);
			flag = 1;
		}
	}
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
