#include "pipex_bonus.h"

int	wifexited(int status)
{
	return (status != 0);
}

int wexitstatus(int status)
{
	return (status >> 8);
}