#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]) {
	int fd1, fd2;

	fd1 = open("infile", O_RDONLY);
	dup2(fd1, STDIN_FILENO);
	char *args[] = {"/usr/bin/grep", "a", NULL};
	execve("/usr/bin/grep", args, envp);
	return (0);
}