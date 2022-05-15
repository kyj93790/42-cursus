#include "pipex.h"

int	wifexited(int status)
{
	return (status != 0);
}

int weixtstatus(int status)
{
	return (status >> 8);
}