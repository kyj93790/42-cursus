/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:32 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:48:15 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_take_fork_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (-1);
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	sem_wait(philo->monitor->sem_print);
	printf("%ldms\t%d\thas taken a fork\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_eat_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (-1);
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	sem_wait(philo->monitor->sem_print);
	printf("%ldms\t%d\tis eating\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_sleep_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (-1);
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	sem_wait(philo->monitor->sem_print);
	printf("%ldms\t%d\tis sleeping\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_think_state(t_philo *philo)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (-1);
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	sem_wait(philo->monitor->sem_print);
	printf("%ldms\t%d\tis thinking\n", time_stamp, philo->id + 1);
	sem_post(philo->monitor->sem_print);
	return (0);
}

int	print_finish_state(t_philo *philo, int status)
{
	long			time_stamp;
	struct timeval	curr_time;

	if (gettimeofday(&(curr_time), NULL) != 0)
	{
		finish_with_error("fail in gettimeofday", philo->monitor);
		return (1);
	}
	time_stamp = calc_timeval(&(philo->monitor->start_time), &(curr_time));
	sem_wait(philo->monitor->sem_print);
	printf("%ldms\t%d\tis died\n", time_stamp, philo->id + 1);
	philo->monitor->finish_type = DIE;
	sem_post(philo->monitor->sem_finish);
	return (1);
}
