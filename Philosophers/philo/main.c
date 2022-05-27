#include "philo.h"

int	generate_philos(t_monitor *monitor)
{
	int			i;
	pthread_t	*thread;

	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
	thread = malloc(sizeof(pthread_t) * monitor->num_of_philo);
	if (thread < 0)
		return (-1);
	i = 0;
	pthread_mutex_lock(&(monitor->m_start));
	while (i < monitor->num_of_philo)
	{
		if (pthread_create(&(thread[i]), NULL, routine, &(monitor->philo[i])) < 0)
		{
			monitor->num_of_philo = i;
			free(thread);
			return (-1);
		}
		i++;
	}
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
	if (generate_philos(&monitor) < 0)
	{
		printf("fail in generating philosophers\n");
		free_monitor(&monitor);
		return (0);
	}
	// main thread는 monitoring logic을 수행하도록 한다. -> 계속 계산
	while (1)
	{
		;
	}
	return (0);
}