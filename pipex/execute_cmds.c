#include "pipex.h"

void	redirect_from_infile(t_arg arg, int **p)
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

void	redirect_to_outfile(t_arg arg, int **p)
{
	extern int	errno;
	int			fd;
	int			ret;

	fd = open(arg.outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("wc: ", 2);
		ft_putstr_fd(arg.outfile, 2);
		ft_putstr_fd(": open: No such file or directory\n", 2);
		exit(EXIT_FOPEN);
	}
	ret = dup2(fd, STDOUT_FILENO);
	if (ret < 0)
		exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	close(fd);
}

void	execute_cmd(pid_t pid, t_arg arg, int **p, int i)
{	
	extern int	errno;

	if (i == 1)
		redirect_from_infile(arg, p);
	else
	{
		if (dup2(p[i - 1][0], STDIN_FILENO) < 0)
			exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
		close(p[i - 1][0]);
	}
	if (i == arg.cmd_cnt)
		redirect_to_outfile(arg, p);
	else
	{
		if (dup2(p[i][1], STDOUT_FILENO) < 0)
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

	if (i == 0)
		return ;
	pipe(p[i - 1]);
	pid = fork();
	if (pid < 0)
		exit_with_error(EXIT_FAILURE, "failure in fork", NULL);
	if (pid == 0)
	{
		close(p[i - 1][0]); // close read fd
		execute_cmds(arg, p, i - 1);
		close(p[i - 1][1]);
		return ;
	}
	waitpid(pid, &status, 0);
	if (!WIFEXITED(status))
		exit(EXIT_FAILURE);
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
		exit_with_error(EXIT_FAILURE, "Failure in fork", NULL);
	if (pid == 0)
	{
		execute_cmds(arg, p, i);
		return ;
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(EXIT_FAILURE);
}
