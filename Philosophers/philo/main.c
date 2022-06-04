#include "philo.h"

int	setting_flow_mutex(t_monitor *monitor)
{
	if (pthread_mutex_init(&(monitor->m_start), NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(monitor->m_finish), NULL) != 0)
		return (-1);
	return (0);
}

static int	generate_philos(t_monitor *monitor)
{
	int			i;
	void		*target_routine;

	monitor->thread = malloc(sizeof(pthread_t) * monitor->num_of_philo);
	if (monitor->thread < 0)
		return (-1);
	i = 0;
	if (monitor->num_of_philo == 1)
		target_routine = routine_one;
	
	pthread_mutex_lock(&(monitor->m_start));
	while (i < monitor->num_of_philo)
	{
		if (pthread_create(&(monitor->thread[i]), NULL, target_routine, &(monitor->philo[i])) < 0)
		{
			monitor->num_of_philo = i;
			free(monitor->thread);
			return (-1);
		}
		i++;
	}
	i = 0;
	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
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
	if (setting_flow_mutex(&monitor) < 0)
	{
		printf("fail in init flow mutex\n");
		// monitor.num_of_philo = 0;
		// free_monitor(&monitor);
		return (0);
	}
	if (generate_philos(&monitor) < 0)
	{
		pthread_mutex_lock(&(monitor.m_finish));
		monitor.finish_flag = 2;
		pthread_mutex_unlock(&(monitor.m_finish));
		printf("fail in generating philosophers\n");
		free_monitor(&monitor);
		return (0);
	}
	monitor_philo(&monitor);
	free_monitor(&monitor);
	return (0);
}