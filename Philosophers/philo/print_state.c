#include "philo.h"

void	print_take_fork_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_print));
	if (philo->monitor->finish_flag != 0)
	{
		pthread_mutex_unlock(&(philo->monitor->m_print));
		return ;
	}
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	printf("%ldms\t%d\thas taken a fork\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

void	print_eat_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_print));
	if (philo->monitor->finish_flag != 0)
	{
		pthread_mutex_unlock(&(philo->monitor->m_print));
		return ;
	}
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	printf("%ldms\t%d\tis eating\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

void	print_sleep_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_print));
	if (philo->monitor->finish_flag != 0)
	{
		pthread_mutex_unlock(&(philo->monitor->m_print));
		return ;
	}
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	printf("%ldms\t%d\tis sleeping\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

void	print_think_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	pthread_mutex_lock(&(philo->monitor->m_print));
	if (philo->monitor->finish_flag != 0)
	{
		pthread_mutex_unlock(&(philo->monitor->m_print));
		return ;
	}
	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		philo->monitor->finish_flag = 2;
		return ;
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	printf("%ldms\t%d\tis thinking\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}


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
		printf("%ldms\t%d\tis died\n", time_stamp, philo->id);
	else if (status == FULL)
		printf("%ldms\tall philosophers are full\n", time_stamp);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}