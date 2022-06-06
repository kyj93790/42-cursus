/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:25 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:43:07 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_die(t_philo *philo)
{
	struct timeval	curr_time;
	long			time_gap;

	if (gettimeofday(&curr_time, NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (1);
	}
	sem_wait(philo->sem_last_eat);
	time_gap = calc_timeval(&(philo->monitor->start_time), &curr_time) - philo->last_eat;
	sem_post(philo->sem_last_eat);
	if (time_gap > philo->monitor->time_to_die)
		return (1);
	return (0);
}

void	*monitor_philo(void *arg)
{
	t_philo *philo;
	int		dup_flag;

	philo = arg;
	dup_flag = 0;
	while (1)
	{
		if (check_die(philo))
		{
			sem_wait(philo->monitor->sem_print);
			print_finish_state(philo, DIE);
			philo->monitor->finish_type = DIE;
			sem_post(philo->monitor->sem_finish);
		}
		if (!dup_flag && philo->monitor->must_eat_flag)
		{
			sem_wait(philo->sem_cnt_eat);
			if (philo->cnt_eat >= philo->monitor->must_eat)
			{
				sem_post(philo->monitor->sem_full);
				dup_flag = 1;
			}
			sem_post(philo->sem_cnt_eat);
		}
	}
	return (0);
}

void	*monitor_full(void *arg)
{
	t_monitor		*monitor;
	int				i;
	long			time_stamp;
	struct timeval	curr_time;

	monitor = arg;
	i = 0;
	while (i < monitor->num_of_philo)
	{
		sem_wait(monitor->sem_full);
		i++;
	}
	if (monitor->finish_type != DIE)
	{
		sem_wait(monitor->sem_print);
		if (gettimeofday(&(curr_time), NULL) != 0)
		{
			finish_with_error("fail in gettimeofday", monitor);
			return (0);
		}
		time_stamp = calc_timeval(&(monitor->start_time), &(curr_time));
		printf("%ldms\tall philosophers are full\n", time_stamp);
		sem_post(monitor->sem_finish);
	}
	return (0);
}

int monitor_main(t_monitor *monitor)
{
	pthread_t	sub_monitor;
	int			i;

	if (pthread_create(&sub_monitor, NULL, monitor_full, monitor) != 0)
		finish_with_error("fail in create in main", monitor);
	sem_wait(monitor->sem_finish);
	kill_process(monitor);
	monitor->finish_type = DIE;
	i = 0;
	while (i < monitor->num_of_philo)
	{
		sem_post(monitor->sem_full);
		i++;
	}
	pthread_join(sub_monitor, NULL);
	free_monitor();
	return (0);
}