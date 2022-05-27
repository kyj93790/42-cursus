#include "philo.h"

static void	routine_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->first_fork] = 0;
	print_curr_state(philo, TAKE_FORK);
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
	philo->monitor->fork[philo->second_fork] = 0;
	print_curr_state(philo, TAKE_FORK);
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
	print_curr_state(philo, EAT);
	if (gettimeofday(&(philo->last_eat), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	//
	// pthread_mutex_lock(&(philo->monitor->m_start));
	// printf("sec : %ld, usec : %d\n", philo->last_eat.tv_sec, philo->last_eat.tv_usec);
	// pthread_mutex_unlock(&(philo->monitor->m_start));
	//
	// usleep(philo->monitor->time_to_eat * 1e3);
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, philo->last_eat, 100);
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
	print_curr_state(philo, SLEEP);
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 100);
	// usleep(philo->monitor->time_to_sleep * 1e3);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	if (philo->id % 2 == 0)
		usleep(philo->monitor->time_to_eat / 2 * 1e3);
	while (1)
	{
		// if (philo->monitor->finish_flag != 0)
		// 	break ;
		routine_take_fork(philo);
		if (philo->monitor->finish_flag != 0)
			return (routine_takeoff_fork(philo));
		routine_eat(philo);
		if (philo->monitor->finish_flag != 0)
			return (routine_takeoff_fork(philo));
		routine_takeoff_fork(philo);
		// if (philo->monitor->finish_flag != 0)
		// 	break ;
		routine_sleep(philo);
		// if (philo->monitor->finish_flag != 0)
		// 	break ;
		print_curr_state(philo, THINK);
		usleep(1000);
	}
	return (0);
}