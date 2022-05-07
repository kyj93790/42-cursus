#include "pipex.h"

void	redirect_from_infile(t_arg arg, int **p)
{
	int	fd;

	fd = open(arg.infile, O_RDONLY);
	if (fd < 0)
		exit_with_error("Failure in opening infile");
	dup2(fd, p[0][1]);
	// dup2 에러 처리
	close(fd);
}

void	redirect_to_outfile(t_arg arg, int **p)
{
	int fd;

	fd = open(arg.outfile, O_WRONLY | O_TRUNC | O_CREAT);
	if (fd < 0)
		exit_with_error("Failure in opening outfile");
	dup2(fd, STDOUT_FILENO);
	// dup2 에러 처리
	close(fd);
	//return (fd);
}

void	execute_cmd(pid_t pid, t_arg arg, int **p, int i)
{	
	//int outfile_fd;

	printf("parent %d\n", i);
	dup2(p[i-1][0], STDIN_FILENO);
	if (i == arg.cmd_cnt)
	{
		//outfile_fd = redirect_to_outfile(arg, p);
		redirect_to_outfile(arg, p);
		//dup2(outfile_fd, STDOUT_FILENO);)
	}
	else
		dup2(p[i][1], STDOUT_FILENO);
	// if (i == arg.cmd_cnt)
	// 	close(outfile_fd);
	execve(arg.cmd[i][0], arg.cmd[i], arg.envp);
	perror("excute error");
	// ft_putstr_fd("execute cmd ", STDERR_FILENO);
	// ft_putnbr_fd(i, STDERR_FILENO);
	// ft_putstr_fd("\n", STDERR_FILENO);
}

void	execute_cmds(t_arg arg, int **p, int i)
{
	pid_t	pid;
	int		status;

	if (i == 0) // redirection만 진행할 가장 깊숙한 child
	{
		printf("final child\n");
		redirect_from_infile(arg, p);
		return ;
	}
	pipe(p[i - 1]);
	pid = fork();
	if (pid < 0)
		exit_with_error("Failure in fork");
	if (pid == 0)
	{
		close(p[i - 1][0]); // close read fd
		printf("child %d\n", i);
		execute_cmds(arg, p, i - 1);
		//close(p[i - 1][1]);
		return ;
	}
	//wait(&status);
	waitpid(pid, &status, 0);
	close(p[i - 1][1]);
	execute_cmd(pid, arg, p, i);
	printf("finish cmd %d\n", i);
	//close(p[i - 1][0]);
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
		//close(p[i - 1][0]); // close read fd
		execute_cmds(arg, p, i);
		//close(p[i - 1][1]);
		return ;
	}
	waitpid(pid, &status, 0);
	// while (1)
	// {
	// 	exit_pid = waitpid(pid, &status, 0);
	// 	if (exit_pid == pid)
	// 		break;
	// }
}