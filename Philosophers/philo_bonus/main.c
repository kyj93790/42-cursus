/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:19 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/05 20:27:01 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	generate_philos(t_monitor *monitor)
{
	int			i;

	sem_unlink("sem_start");
	monitor->sem_start = sem_open("sem_start", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_finish");
	monitor->sem_finish = sem_open("sem_finish", O_CREAT | O_EXCL, 0644, 0);
	sem_unlink("sem_print");
	monitor->sem_print = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_fork");
	monitor->fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, monitor->num_of_philo);
	sem_unlink("sem_full");
	monitor->sem_full = sem_open("sem_full", O_CREAT | O_EXCL, 0644, 0);
	// 전부 바로 unlink진행
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
		sem_post(monitor.sem_finish);
		printf("fail in generating philosophers\n");
		return (0);
	}
	monitor_main(&monitor);
	return (0);
}
