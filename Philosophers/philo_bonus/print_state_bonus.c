/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:32 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 13:20:17 by yejikim          ###   ########.fr       */
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

int	print_finish_state(t_philo *philo)
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
	return (1);
}
