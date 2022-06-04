#include "philo.h"

static int	check_die(t_monitor *monitor)
{
	int				i;
	struct timeval	curr_time;
	long			curr_time_stamp;
	long			time_gap;

	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (gettimeofday(&curr_time, NULL) != 0)
		{
			monitor->finish_flag = 2;
			return (1);
		}
		curr_time_stamp = calc_timeval(&(monitor->start_time), &curr_time);
		pthread_mutex_lock(&(monitor->philo[i].m_last_eat));
		time_gap = curr_time_stamp - monitor->philo[i].last_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_last_eat));
		if (time_gap > monitor->time_to_die)
		{
			pthread_mutex_lock(&(monitor->m_finish));
			monitor->finish_flag = 1;
			pthread_mutex_unlock(&(monitor->m_finish));
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
	int	curr_eat;
	int	full_cnt;

	i = 0;
	full_cnt = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_mutex_lock(&(monitor->philo[i].m_cnt_eat));
		curr_eat = monitor->philo[i].cnt_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_cnt_eat));
		if (curr_eat >= monitor->must_eat)
			full_cnt++;
		i++;
	}
	if (full_cnt == monitor->num_of_philo)
	{
		pthread_mutex_lock(&(monitor->m_finish));
		monitor->finish_flag = 1;
		pthread_mutex_unlock(&(monitor->m_finish));
		print_finish_state(&(monitor->philo[0]), FULL);
		return (1);
	}
	return (0);
}

int	monitor_philo(t_monitor *monitor)
{
	while (1)
	{
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