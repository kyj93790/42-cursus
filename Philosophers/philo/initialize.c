#include "philo.h"

void	check_fork(int *first_fork, int *second_fork)
{
	int	temp;

	if (*first_fork < *second_fork)
		return ;
	temp = *first_fork;
	*first_fork = *second_fork;
	*second_fork = temp;
}

// philo가 1명인 케이스도 별도로 처리해야함?
// 한 스레드에서 한 자원에 대해 lock을 두번 요청하면 어떻게 되는지 확인 필요
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
		if (gettimeofday(&(monitor->philo[i].last_eat), NULL) != 0)
		{
			free(monitor->philo);
			return (-1);
		}
		monitor->philo[i].cnt_eat = 0;
		monitor->philo[i].first_fork = i;
		monitor->philo[i].second_fork = (i + 1) % monitor->num_of_philo;
		check_fork(&(monitor->philo[i].first_fork), &(monitor->philo[i].second_fork));
		// printf("%d\n", monitor->philo[i].id);
		// printf("%d\n", monitor->philo[i].first_fork);
		// printf("%d\n\n", monitor->philo[i].second_fork);
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
		free(monitor->m_fork);
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
