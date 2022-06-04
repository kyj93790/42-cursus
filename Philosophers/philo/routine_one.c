#include "philo.h"

static void	routine_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->first_fork] = 1;
	if (print_take_fork_state(philo) < 0)
	{
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		return ;
	}
	while (1)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			philo->monitor->fork[philo->first_fork] = 0;
			pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
			return ;
		}
		if (philo->monitor->fork[philo->second_fork] == 0)
		{
			pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
	}
	philo->monitor->fork[philo->second_fork] = 1;
	if (print_take_fork_state(philo) < 0)
	{
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		philo->monitor->fork[philo->second_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
		return ;
	}
}

static void routine_takeoff_fork(t_philo *philo)
{
	philo->monitor->fork[philo->first_fork] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
	philo->monitor->fork[philo->second_fork] = 0;
	pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
	return ;
}

static void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = calc_timeval(&(philo->monitor->start_time), &curr_time);
	pthread_mutex_unlock(&(philo->m_last_eat));
	if (print_eat_state(philo) < 0)
	{
		routine_takeoff_fork(philo);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 100);
	pthread_mutex_lock(&(philo->m_cnt_eat));
	(philo->cnt_eat)++;
	pthread_mutex_unlock(&(philo->m_cnt_eat));
}

static void	routine_sleep(t_philo *philo)
{
	struct timeval start_time;

	if (print_sleep_state(philo) < 0)
		return ;
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		pthread_mutex_lock(&(philo->monitor->m_finish));
		philo->monitor->finish_flag = 2;
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 100);
}

void	*routine_one(void *arg)
{
	t_philo	*philo;

	philo = arg;
	printf("herer\n");
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	while (1)
	{
		routine_take_fork(philo);
		routine_eat(philo);
		routine_takeoff_fork(philo);
		routine_sleep(philo);
		print_think_state(philo);
		pthread_mutex_lock(&(philo->monitor->m_finish));
		if (philo->monitor->finish_flag != 0)
		{
			pthread_mutex_unlock(&(philo->monitor->m_finish));
			break ;
		}
		pthread_mutex_unlock(&(philo->monitor->m_finish));
		usleep(50);
	}
	return (0);
}