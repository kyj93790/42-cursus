#include "philo.h"

void	sleep_unit(long time, long unit)
{
	long	curr;

	curr = 0;
	while (curr < time)
	{
		usleep(unit);
		curr += unit;
	}
}

void	print_curr_state(t_philo *philo, int status)
{
	long	time_stamp;

	time_stamp = calc_timeval(&(philo->monitor->start_time), &(philo->last_eat));
	pthread_mutex_lock(&(philo->monitor->m_print));
	if (status == TAKE_FORK)
		printf("%ld\t%d\thas taken a fork\n", time_stamp, philo->id);
	else if (status == EAT)
		printf("%ld\t%d\tis eating\n", time_stamp, philo->id);
	else if (status == SLEEP)
		printf("%ld\t%d\tis sleeping\n", time_stamp, philo->id);
	else if (status == THINK)
		printf("%ld\t%d\tis thinking\n", time_stamp, philo->id);
	else if (status == DIE)
		printf("%ld\t%d\tis died\n", time_stamp, philo->id);
	pthread_mutex_unlock(&(philo->monitor->m_print));
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&(philo->monitor->m_start));
	pthread_mutex_unlock(&(philo->monitor->m_start));
	printf("start routine : %d\n", philo->id);
	while (1)
	{
		// take fork
		pthread_mutex_lock(&(philo->monitor->m_fork[philo->first_fork]));
		philo->monitor->fork[philo->first_fork] = 1;
		print_curr_state(philo, TAKE_FORK);
		pthread_mutex_lock(&(philo->monitor->m_fork[philo->second_fork]));
		philo->monitor->fork[philo->second_fork] = 1;
		print_curr_state(philo, TAKE_FORK);
		// start eat
		if (gettimeofday(&(philo->last_eat), NULL) != 0)
			philo->error_flag = 1;
		print_curr_state(philo, EAT);
		sleep_unit(philo->monitor->time_to_eat, 10);
		(philo->cnt_eat)++;
		// take off fork
		philo->monitor->fork[philo->first_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->first_fork]));
		philo->monitor->fork[philo->second_fork] = 0;
		pthread_mutex_unlock(&(philo->monitor->m_fork[philo->second_fork]));
		print_curr_state(philo, SLEEP);
		sleep_unit(philo->monitor->time_to_sleep, 10);
		print_curr_state(philo, THINK);
	}
}