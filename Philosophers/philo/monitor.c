#include "philo.h"

void	print_finish_state(t_philo *philo, int status)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_print));
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	if (status == DIE)
		printf("%ld\t%d\tis died\n", time_stamp, philo->id);
	else if (status == FULL)
		printf("%ld\tall philosophers are full\n", time_stamp);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

static int	check_die(t_monitor *monitor)
{
	int				i;
	struct timeval	curr_time;
	long			time_gap;

	i = 0;
	if (gettimeofday(&curr_time, NULL) != 0)
	{
		monitor->finish_flag = 2;
		return (1);
	}
	while (i < monitor->num_of_philo)
	{
		time_gap = calc_timeval(&(monitor->philo[i].last_eat), &curr_time);
		if (time_gap > monitor->time_to_die)
		{
			// pthread_mutex_lock(&(monitor->m_start));
			// printf("time gap : %ld\n", time_gap);
			// pthread_mutex_unlock(&(monitor->m_start));
			monitor->finish_flag = 1;
			print_finish_state(&(monitor->philo[i]), DIE);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_must_eat(t_monitor *monitor)
{
	int	i;
	int	full_cnt;

	i = 0;
	full_cnt = 0;
	while (i < monitor->num_of_philo)
	{
		if (monitor->philo[i].cnt_eat >= monitor->must_eat)
			full_cnt++;
		i++;
	}
	if (full_cnt == monitor->num_of_philo)
	{
		monitor->finish_flag = 1;
		print_curr_state(&(monitor->philo[0]), FULL);
		return (1);
	}
	return (0);
}

int	monitor_philo(t_monitor *monitor)
{
	while (1)
	{
		if (monitor->finish_flag != 0)
			break ;
		if (check_die(monitor))
			break ;
		if (monitor->must_eat_flag == 1)
		{
			if (check_must_eat(monitor))
				break ;
		}
	}
	return (0);
}