#include "philo.h"

void	print_curr_state(t_philo *philo, int status)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (philo->monitor->finish_flag != 0)
		return ;
	pthread_mutex_lock(&(philo->monitor->m_print));
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	if (status == TAKE_FORK)
		printf("%ld\t%d\thas taken a fork\n", time_stamp, philo->id);
	else if (status == EAT)
		printf("%ld\t%d\tis eating\n", time_stamp, philo->id);
	else if (status == SLEEP)
		printf("%ld\t%d\tis sleeping\n", time_stamp, philo->id);
	else if (status == THINK)
		printf("%ld\t%d\tis thinking\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

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
	long	diff_sec;

	diff_sec = (end->tv_sec - start->tv_sec) * 1e3 + (end->tv_usec - start->tv_usec) / 1e3;
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