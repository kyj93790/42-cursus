#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		p[2];
	pid_t	pid;

	if (argc != 5)
	{
		perror("Failure by number of arguments : ");
		return (1);
	}
	// file1 cmd1 cmd2 file2
	// redirection 처리
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		// error message
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	// pipe 생성
	if (pipe(p) == -1)
	{
		// error message
		return (1);
	}
	// parent, child process 생성
	pid = fork();
	if (pid < 0)
	{
		close(p[0]); // read
		close(p[1]); // write
		// error message
		return (1);
	}
	if (pid == 0) // child process
	{
		close(p[0]);
		// p[1]에 write
		// dup2로 표준 출력 p[1]로
		dup2(p[1], STDOUT_FILENO);
		// argument 완성
		// execve() 실행 -> cmd1 실행
		// dup2로 인해 자동으로 pipe에 작성됨
		close(p[1]);
	}
	else // parent process
	{
		close(p[1]);
		// wait 진행 (자식 process가 끝나면 신호를 받아 진행)
		dup2(p[0], STDIN_FILENO);
		// redirection to outfile
		// argument 완성
		// execve() 실행 -> cmd2 실행
		
	}
	// 최종 redirection
	return (0);
}