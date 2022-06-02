#include "philo.h"

static void	routine_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->first_fork] = 0;
	print_take_fork_state(philo);
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
	philo->monitor->fork[philo->second_fork] = 0;
	print_take_fork_state(philo);
}

static void *routine_takeoff_fork(t_philo *philo)
{
	philo->monitor->fork[philo->first_fork] = 1;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->second_fork] = 1;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
	return (0);
}

static void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	print_eat_state(philo);
	if (gettimeofday(&curr_time, NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	philo->last_eat = calc_timeval(&(philo->monitor->start_time), &curr_time);
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 100);
	// usleep(philo->monitor->time_to_eat * 1000);
	(philo->cnt_eat)++;
}

static void	routine_sleep(t_philo *philo)
{
	struct timeval start_time;

	if (gettimeofday(&(start_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	print_sleep_state(philo);
	// usleep(philo->monitor->time_to_sleep * 1000);
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 100);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	if (philo->id % 2 == 1)
		usleep(philo->monitor->time_to_eat / 2 * 1e3);
	while (1)
	{
		if (philo->monitor->finish_flag != 0)
			break ;
		routine_take_fork(philo);
		routine_eat(philo);
		routine_takeoff_fork(philo);
		routine_sleep(philo);
		print_think_state(philo);
		usleep(50);
	}
	return (0);
}