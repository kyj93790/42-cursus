#include "philo.h"

void	sleep_unit(t_monitor *monitor, long aim_time, struct timeval start_time, long unit)
{
	struct timeval	curr_time;

	while (1)
	{
		if (gettimeofday(&(curr_time), NULL) != 0)
		{
			monitor->finish_flag = 2;
			return ;
		}
		if (calc_timeval(&(start_time), &(curr_time)) >= aim_time)
			break ;
		pthread_mutex_lock(&(monitor->m_finish));
		if (monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(monitor->m_finish));
			return ;
		}
		pthread_mutex_unlock(&(monitor->m_finish));
		usleep(unit);
	}
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
			return (print_error("error : numeric argument required"));
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
		return (print_error("error : argument range"));
	return (result);
}