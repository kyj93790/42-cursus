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

	fd = open(arg.outfile, O_WRONLY);
	if (fd < 0)
		exit_with_error("Failure in opening outfile");
	dup2(fd, p[arg.cmd_cnt][1]);
	// dup2 에러 처리
	close(fd);
}