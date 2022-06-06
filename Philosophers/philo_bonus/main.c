/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:19 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:24:14 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	generate_philos(t_monitor *monitor)
{
	int			i;

	sem_wait(monitor->sem_start);
	i = 0;
	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
	while (i < monitor->num_of_philo)
	{
		monitor->philo[i].pid = fork();
		if (monitor->philo[i].pid < 0)
			break ;
		if (monitor->philo[i].pid == 0)
		{
			routine(monitor, i);
			return (0);
		}
		i++;
	}
	sem_post(monitor->sem_start);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_monitor	monitor;

	if (init_monitor(&monitor, argc, argv) < 0)
	{
		printf("fail in initialize_monitor\n");
		return (0);
	}
	if (generate_philos(&monitor) < 0)
	{
		sem_wait(monitor.sem_print);
		printf("fail in generating philosophers\n");
		sem_post(monitor.sem_finish);
	}
	monitor_main(&monitor);
	return (0);
}
