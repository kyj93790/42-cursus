#include "philo.h"

int	init_philo(t_monitor *monitor)
{
	int	i;

	monitor->philo = malloc(sizeof(t_philo) * monitor->num_of_philo);
	if (monitor->philo == NULL)
		return (-1);
	i = 0;
	while (i < monitor->num_of_philo)
	{
		monitor->philo[i].id = i;
		monitor->philo[i].last_eat = 0;
		monitor->philo[i].cnt_eat = 0;
		monitor->philo[i].die_flag = 0;
		monitor->philo[i].first_fork = i;
		monitor->philo[i].second_fork = (i + 1) % monitor->num_of_philo;
		monitor->philo[i].monitor = monitor;
		i++;
	}
	return (0);
}

int	init_fork(t_monitor *monitor)
{
	int	i;

	monitor->fork = malloc(sizeof(int) * monitor->num_of_philo);
	if (monitor->fork == NULL)
	{
		free(monitor->philo);
		return (-1);
	}
	i = 0;
	while (i < monitor->num_of_philo)
	{
		monitor->fork[i] = 1;
		i++;
	}
	return (0);
}

int	init_m_fork(t_monitor *monitor)
{
	int	i;
	int	j;

	monitor->m_fork = malloc(sizeof(pthread_mutex_t) * monitor->num_of_philo);
	if (monitor->m_fork == NULL)
	{
		free(monitor->philo);
		free(monitor->fork);
		return (-1);
	}
	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (pthread_mutex_init(&(monitor->m_fork[i]), NULL) != 0)
		{
			j = 0;
			while (j < i)
				pthread_mutex_destroy(&(monitor->m_fork[j++]));
			free(monitor->philo);
			free(monitor->fork);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_m_print(t_monitor *monitor)
{
	int	i;

	if (pthread_mutex_init(&(monitor->m_print), NULL) != 0)
	{
		free(monitor->philo);
		free(monitor->fork);
		i = 0;
		while (i < monitor->num_of_philo)
		{
			pthread_mutex_destroy(&(monitor->m_fork[i++]));
			i++;
		}
		return (-1);
	}
	return (0);
}

int	init_monitor(t_monitor *monitor, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (-1);
	monitor->num_of_philo = convert_arg_to_int(argv[1]);
	monitor->time_to_die = convert_arg_to_int(argv[2]);
	monitor->time_to_eat = convert_arg_to_int(argv[3]);
	monitor->time_to_sleep = convert_arg_to_int(argv[4]);
	monitor->must_eat_flag = 0;
	if (argc == 6)
	{
		monitor->must_eat_flag = 1;
		monitor->must_eat = convert_arg_to_int(argv[5]);
	}
	if (monitor->num_of_philo <= 0 || monitor->time_to_die <= 0 || \
		monitor->time_to_eat < 0 || monitor->time_to_sleep < 0)
		return (-1);
	monitor->finish_flag = 0;
	if (init_philo(monitor) < 0)
		return (-1);
	if (init_fork(monitor) < 0)
		return (-1);
	if (init_m_fork(monitor) < 0)
		return (-1);
	if (init_m_print(monitor) < 0)
		return (-1);
	return (0);
}
