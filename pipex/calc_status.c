#include "pipex.h"

int	wifexited(int status)
{
	return !(status & 0x0f);
}

int wexitstatus(int status)
{
	return (status >> 8);
}