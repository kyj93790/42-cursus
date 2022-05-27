#include "philo.h"

void	free_monitor(t_monitor *monitor)
{
	int i;

	if (monitor->philo)
		free(monitor->philo);
	i = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_mutex_destroy(&(monitor->m_fork[i]));
		i++;
	}
	if (monitor->fork)
		free(monitor->fork);
	pthread_mutex_destroy(&(monitor->m_print));
	return ;
}

long calc_timeval(struct timeval *start, struct timeval *end)
{
	long	diff_sec;

	diff_sec = (end->tv_sec - start->tv_sec) * 1e3;
	diff_sec += (end->tv_usec - start->tv_usec) / 1e3;
	return (diff_sec);
}

int convert_arg_to_int(char *str)
{
	int		i;
	long	result;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > 1e11)
			break ;
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}