#include "philo.h"

static int	check_die(t_monitor *monitor)
{
	int				i;
	struct timeval	curr_time;
	long			curr_time_stamp;

	i = 0;
	// if (gettimeofday(&curr_time, NULL) != 0)
	// {
	// 	monitor->finish_flag = 2;
	// 	return (1);
	// }
	while (i < monitor->num_of_philo)
	{
		if (gettimeofday(&curr_time, NULL) != 0)
		{
			monitor->finish_flag = 2;
			return (1);
		}
		curr_time_stamp = calc_timeval(&(monitor->start_time), &curr_time);
		if (curr_time_stamp - monitor->philo[i].last_eat > monitor->time_to_die)
		{
			monitor->finish_flag = 1;
			print_finish_state(&(monitor->philo[i]), DIE);
			return (1);
		}
		// usleep(50);
		i++;
	}
	return (0);
}

static int	check_must_eat(t_monitor *monitor)
{
	int	i;
	int	full_cnt;

	i = 0;
	full_cnt = 0;
	while (i < monitor->num_of_philo)
	{
		if (monitor->philo[i].cnt_eat >= monitor->must_eat)
			full_cnt++;
		i++;
		// usleep(50);
	}
	if (full_cnt == monitor->num_of_philo)
	{
		monitor->finish_flag = 1;
		print_finish_state(&(monitor->philo[0]), FULL);
		return (1);
	}
	return (0);
}

int	monitor_philo(t_monitor *monitor)
{
	while (1)
	{
		if (monitor->finish_flag != 0)
			break ;
		if (check_die(monitor))
			break ;
		if (monitor->must_eat_flag == 1)
		{
			if (check_must_eat(monitor))
				break ;
		}
		// usleep(50);
	}
	return (0);
}