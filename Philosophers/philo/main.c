#include "philo.h"

static int	generate_philos(t_monitor *monitor)
{
	int			i;

	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
	monitor->thread = malloc(sizeof(pthread_t) * monitor->num_of_philo);
	if (monitor->thread < 0)
		return (-1);
	i = 0;
	pthread_mutex_lock(&(monitor->m_start));
	while (i < monitor->num_of_philo)
	{
		monitor->philo[i].last_eat = monitor->start_time;
		if (pthread_create(&(monitor->thread[i]), NULL, routine, &(monitor->philo[i])) < 0)
		{
			monitor->num_of_philo = i;
			free(monitor->thread);
			return (-1);
		}
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&(monitor->m_start));
	return (0);
}

int main(int argc, char *argv[])
{
	t_monitor	monitor;

	if (init_monitor(&monitor, argc, argv) < 0)
	{
		printf("fail in initialize_monitor\n");
		return (0);
	}
	if (pthread_mutex_init(&(monitor.m_start), NULL) != 0)
	{
		printf("fail in init m_start\n");
		monitor.num_of_philo = 0;
		free_monitor(&monitor);
		return (0);
	}
	if (generate_philos(&monitor) < 0)
	{
		printf("fail in generating philosophers\n");
		free_monitor(&monitor);
		return (0);
	}
	monitor_philo(&monitor);
	free_monitor(&monitor);
	return (0);
}