#include "pipex.h"

void	execute_cmd(pid_t pid, t_arg arg, int **p, int i)
{	
	int		status;

	waitpid(pid, &status, 0);
	dup2(p[i-1][0], STDIN_FILENO);
	if (i == arg.cmd_cnt)
		redirect_to_outfile(arg, p);
	dup2(p[i][1], STDOUT_FILENO);
	// execve진행
	// execve의 반환값에 대한 예외처리도 필요
	// ft_putstr_fd("execute cmd ", STDERR_FILENO);
	// ft_putnbr_fd(i, STDERR_FILENO);
	// ft_putstr_fd("\n", STDERR_FILENO);
}

void	execute_pipex(t_arg arg, int **p, int i)
{
	pid_t	pid;

	if (i == 0) // redirection만 진행할 가장 깊숙한 child
	{
		redirect_from_infile(arg, p);
		return ;
	}
	pipe(p[i-1]);
	pid = fork();
	if (pid < 0)
		exit_with_error("Failure in fork");
	if (pid == 0)
	{
		close(p[i-1][0]); // close read fd
		execute_pipex(arg, p, i-1);
		close(p[i-1][1]);
		return ;
	}
	close(p[i-1][1]);
	execute_cmd(pid, arg, p, i);
	close(p[i-1][0]);
}