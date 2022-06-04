/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:38 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/04 19:07:38 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	routine_take_fork(t_philo *philo)
{
	sem_wait(philo->monitor->fork);
	if (print_take_fork_state(philo) < 0)
	{
		sem_post(philo->monitor->fork);
		return ;
	}
	sem_wait(philo->monitor->fork);
	if (print_take_fork_state(philo) < 0)
	{
		sem_post(philo->monitor->fork);
		sem_post(philo->monitor->fork);
		return ;
	}
}

static void	routine_eat(t_philo *philo)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		sem_wait(philo->monitor->fork);
		philo->monitor->finish_flag = 2;
		sem_post(philo->monitor->fork);
		return ;
	}
	sem_wait(philo->sem_last_eat);
	philo->last_eat = calc_timeval(&(philo->monitor->start_time), &curr_time);
	sem_post(philo->sem_last_eat);
	if (print_eat_state(philo) < 0)
	{
		routine_takeoff_fork(philo);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_eat, curr_time, 200);
	sem_wait(philo->sem_cnt_eat);
	(philo->cnt_eat)++;
	sem_post(philo->sem_cnt_eat);
}

static void	routine_sleep(t_philo *philo)
{
	struct timeval	start_time;

	if (print_sleep_state(philo) < 0)
		return ;
	if (gettimeofday(&(start_time), NULL) != 0)
	{
		sem_wait(philo->monitor->sem_finish);
		philo->monitor->finish_flag = 2;
		sem_post(philo->monitor->sem_finish);
		return ;
	}
	sleep_unit(philo->monitor, philo->monitor->time_to_sleep, start_time, 200);
}

void	routine(t_monitor *monitor, int id)
{
	pthread_t	sub_monitor;
	t_philo		philo;
	
	sem_wait(monitor->sem_start);
	sem_post(monitor->sem_start);
	// 철학자에 대한 monitor thread 띄우기
	philo.id = id;
	philo.last_eat = 0;
	philo.cnt_eat = 0;
	philo.monitor = monitor;
	philo.sem_last_eat = sem_open("sem_last_eat", O_CREAT | O_EXCL, 0644, 1);
	philo.sem_cnt_eat = sem_open("sem_cnt_eat", O_CREAT | O_EXCL, 0644, 1);
	// 내부 sem도 바로 Unlink진행
	pthread_create(&sub_monitor, NULL, monitor_philo, &philo);
	while (1)
	{
		routine_take_fork(&philo);
		routine_eat(&philo);
		routine_takeoff_fork(&philo);
		routine_sleep(&philo);
		print_think_state(&philo);
		usleep(50);
	}
	return (0);
}
