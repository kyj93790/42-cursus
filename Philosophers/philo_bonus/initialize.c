/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:17 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:37:17 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_sem(t_monitor *monitor)
{
	sem_unlink("sem_start");
	monitor->sem_start = sem_open("sem_start", O_CREAT, 0644, 1);
	sem_unlink("sem_finish");
	monitor->sem_finish = sem_open("sem_finish", O_CREAT, 0644, 0);
	sem_unlink("sem_print");
	monitor->sem_print = sem_open("sem_print", O_CREAT, 0644, 1);
	sem_unlink("sem_fork");
	monitor->fork = sem_open("sem_fork", O_CREAT, 0644, monitor->num_of_philo);
	sem_unlink("sem_full");
	monitor->sem_full = sem_open("sem_full", O_CREAT, 0644, 0);
}

int	init_philo(t_monitor *monitor, t_philo *philo, int i)
{
	philo->id = i;
	philo->last_eat = 0;
	philo->cnt_eat = 0;
	philo->monitor = monitor;
	sem_unlink("sem_last_eat");
	philo->sem_last_eat = sem_open("sem_last_eat", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_last_eat");
	sem_unlink("sem_cnt_eat");
	philo->sem_cnt_eat = sem_open("sem_cnt_eat", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("sem_cnt_eat");
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
	monitor->full_cnt = 0;
	monitor->finish_type = 0;
	if (argc == 6)
	{
		monitor->must_eat_flag = 1;
		monitor->must_eat = convert_arg_to_int(argv[5]);
	}
	monitor->philo = malloc(sizeof(t_philo) * monitor->num_of_philo);
	if (monitor->philo == NULL)
		return (-1);
	init_sem(monitor);
	return (0);
}
