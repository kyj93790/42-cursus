/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:19 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/04 19:00:58 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	generate_philos(t_monitor *monitor)
{
	int			i;

	monitor->sem_start = sem_open("sem_start", O_CREAT, 0644, 1);
	monitor->sem_finish = sem_open("sem_finish", O_CREAT, 0644, 1);
	monitor->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	monitor->fork = sem_open("sem_fork", O_CREAT, 0644, monitor->num_of_philo);
	// 전부 바로 unlink진행
	sem_wait(&(monitor->sem_start));
	i = 0;
	if (gettimeofday(&(monitor->start_time), NULL) != 0)
		return (-1);
	while (i < monitor->num_of_philo)
	{
		monitor->philo[i] = fork();
		if (monitor->philo[i] < 0)
			break ;
		if (monitor->philo[i] == 0)
			routine(monitor, i); // child는 내부에서 exit 진행
		i++;
	}
	sem_post(&(monitor->sem_start));
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
		sem_wait(monitor.finish_flag);
		monitor.finish_flag = 2;
		sem_post(monitor.finish_flag);
		printf("fail in generating philosophers\n");
		return (free_monitor(&monitor));
	}
	monitor_main(&monitor);
	return (free_monitor(&monitor));
}
