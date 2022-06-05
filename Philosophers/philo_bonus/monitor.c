/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:25 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/05 19:54:19 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_die(t_philo *philo)
{
	struct timeval	curr_time;
	long			time_gap;

	if (gettimeofday(&curr_time, NULL) != 0)
		return (1);
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

	philo = arg;
	while (1)
	{
		if (check_die(philo))
		{
			sem_wait(philo->monitor->sem_print);
			print_finish_state(philo, DIE);
			// post는 하지 않음 (다른 출력 방지)
			sem_post(philo->monitor->sem_finish);
		}
		// must eat check
	}
	return (0);
}

int monitor_main(t_monitor *monitor)
{
	int	finish_cnt;
	int	full_cnt;

	finish_cnt = 0;
	full_cnt = 0;
	while (1)
	{
		if (monitor->sem_finish > 0)
		{
			sem_wait(monitor->sem_finish);
			kill_process(monitor);
			break ;
		}
		if (monitor->sem_full > 0)
		{
			sem_wait(monitor->sem_full);
			full_cnt++;
		}
		if (full_cnt == monitor->num_of_philo)
		{
			// 문구 출력 후 전부 종료
		}
	}
	return (0);
}