#include "philo.h"

int free_philo(t_monitor *monitor, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_destroy(&(monitor->philo[i].m_last_eat));
		pthread_mutex_destroy(&(monitor->philo[i].m_cnt_eat));
		i++;
	}
	free(monitor->philo);
	return (-1);
}

void free_fork(t_monitor *monitor, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
		pthread_mutex_destroy(&(monitor->m_fork[i++]));
	free(monitor->m_fork);
	free(monitor->fork);
}

void	free_monitor(t_monitor *monitor)
{
	int i;
	int	status;
	// 추가 해제 필요
	// m_start 등
	i = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_join(monitor->thread[i], (void *)&status);
		i++;
	}
	printf("join all \n");
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