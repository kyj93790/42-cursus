/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:38 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:34:41 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	routine_take_fork(t_philo *philo)
{
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
	sem_wait(philo->monitor->fork);
	print_take_fork_state(philo);
}

static void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return ;
	}
	sem_wait(philo->sem_last_eat);
	philo->last_eat = calc_timeval(&(philo->monitor->start_time), &curr_time);
	sem_post(philo->sem_last_eat);
	print_eat_state(philo);
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 200);
	sem_wait(philo->sem_cnt_eat);
	(philo->cnt_eat)++;
	sem_post(philo->sem_cnt_eat);
}

static void	routine_sleep(t_philo *philo)
{
	struct timeval	start_time;

	print_sleep_state(philo);
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 200);
}

void	routine(t_monitor *monitor, int i)
{
	pthread_t	sub_monitor;
	
	init_philo(monitor, &(monitor->philo[i]), i);
	sem_wait(monitor->sem_start);
	sem_post(monitor->sem_start);
	if (pthread_create(&sub_monitor, NULL, monitor_philo, &(monitor->philo[i])) != 0)
		finish_with_error("fail in create sub_monitor in philo", monitor);
	if (monitor->philo[i].id % 2 == 1)
		usleep(monitor->time_to_eat / 2 * 1e3);
	while (1)
	{
		routine_take_fork(&(monitor->philo[i]));
		routine_eat(&(monitor->philo[i]));
		routine_takeoff_fork(&(monitor->philo[i]));
		routine_sleep(&(monitor->philo[i]));
		print_think_state(&(monitor->philo[i]));
		usleep(50);
	}
}
