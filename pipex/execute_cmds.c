#include "pipex.h"

void	redirect_from_infile(t_arg arg, int **p)
{
	int	fd;

	fd = open(arg.infile, O_RDONLY);
	if (fd < 0)
		exit_with_error("Failure in opening infile");
	dup2(fd, STDIN_FILENO);
	// dup2 에러 처리
	close(fd);
}

void	redirect_to_outfile(t_arg arg, int **p)
{
	int fd;

	fd = open(arg.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit_with_error("Failure in opening outfile");
	dup2(fd, STDOUT_FILENO);
	// dup2 에러 처리
	close(fd);
}

void	execute_cmd(pid_t pid, t_arg arg, int **p, int i)
{	
	if (i == 1)
		redirect_from_infile(arg, p);
	else
	{
		dup2(p[i - 1][0], STDIN_FILENO);
		close(p[i - 1][0]);
	}
	if (i == arg.cmd_cnt)
		redirect_to_outfile(arg, p);
	else
		dup2(p[i][1], STDOUT_FILENO);
	ft_putstr_fd(arg.cmd[i][0], 2);
	execve(arg.cmd[i][0], arg.cmd[i], arg.envp);
	perror("excute error");
}

void	execute_cmds(t_arg arg, int **p, int i)
{
	pid_t	pid;
	int		status;

	if (i == 0)
		return ;
	pipe(p[i - 1]);
	pid = fork();
	if (pid < 0)
		exit_with_error("Failure in fork");
	if (pid == 0)
	{
		close(p[i - 1][0]); // close read fd
		execute_cmds(arg, p, i - 1);
		close(p[i - 1][1]);
		return ;
	}
	waitpid(pid, &status, WNOHANG);
	close(p[i - 1][1]);
	execute_cmd(pid, arg, p, i);
}

void	execute_pipex(t_arg arg, int **p, int i)
{
	pid_t	pid;
	pid_t	exit_pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit_with_error("Failure in fork");
	if (pid == 0)
	{
		execute_cmds(arg, p, i);
		return ;
	}
	waitpid(pid, &status, WNOHANG);
}