#include "philo.h"

void	sleep_unit(t_monitor *monitor, long aim_time, struct timeval start_time, long unit)
{
	struct timeval	curr_time;

	while (1)
	{
		usleep(unit);
		if (gettimeofday(&(curr_time), NULL) != 0)
		{
			monitor->finish_flag = 2;
			return ;
		}
		if (calc_timeval(&(start_time), &(curr_time)) >= aim_time)
			break ;
	}
}

void	free_monitor(t_monitor *monitor)
{
	int i;
	int	status;

	i = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_join(monitor->thread[i], (void *)&status);
		i++;
	}
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
	long	diff_time;

	diff_time = (end->tv_sec - start->tv_sec) * 1e3 + (end->tv_usec - start->tv_usec) / 1e3;
	return (diff_time);
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