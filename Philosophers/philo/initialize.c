#include "philo.h"

int convert_arg_to_int(char *str)
{
	int		i;
	long	result;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result > 1e11)
			break ;
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}

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
	if (monitor->num_of_philo <= 0 || monitor->num_of_philo > 500 || monitor->time_to_die <= 0 || monitor->time_to_eat < 0 || monitor->time_to_sleep < 0)
		return (-1);
	monitor->finish_flag = 0;
	monitor->error_flag = 0;
	if (init_philo(monitor) < 0)
		return (-1);
	// fork 생성 및 mutex 생성
	// print mutex 생성
}