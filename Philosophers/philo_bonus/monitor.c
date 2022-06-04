/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:25 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/04 19:12:05 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_die(t_monitor *monitor)
{
	int				i;
	struct timeval	curr_time;
	long			time_gap;

	i = -1;
	while (++i < monitor->num_of_philo)
	{
		if (gettimeofday(&curr_time, NULL) != 0)
		{
			pthread_mutex_lock(&(monitor->m_finish));
			monitor->finish_flag = 2;
			pthread_mutex_unlock(&(monitor->m_finish));
			return (1);
		}
		pthread_mutex_lock(&(monitor->philo[i].m_last_eat));
		time_gap = calc_timeval(&(monitor->start_time), &curr_time) \
							- monitor->philo[i].last_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_last_eat));
		if (time_gap > monitor->time_to_die)
			return (print_finish_state(&(monitor->philo[i]), DIE));
	}
	return (0);
}

static int	check_must_eat(t_monitor *monitor)
{
	int	i;
	int	curr_eat;
	int	full_cnt;

	i = 0;
	full_cnt = 0;
	while (i < monitor->num_of_philo)
	{
		pthread_mutex_lock(&(monitor->philo[i].m_cnt_eat));
		curr_eat = monitor->philo[i].cnt_eat;
		pthread_mutex_unlock(&(monitor->philo[i].m_cnt_eat));
		if (curr_eat >= monitor->must_eat)
			full_cnt++;
		i++;
	}
	if (full_cnt == monitor->num_of_philo)
		return (print_finish_state(&(monitor->philo[0]), FULL));
	return (0);
}

int	monitor_philo(t_monitor *monitor)
{
	while (1)
	{
		if (check_die(monitor))
			break ;
		if (monitor->must_eat_flag == 1)
		{
			if (check_must_eat(monitor))
				break ;
		}
	}
	return (0);
}

// 이걸 하나로 합친 정보를 philo에 넘긴다 (philo에 monitor 정보를 넘김)
int	monitor_philo(t_philo *philo)
{
	while (1)
	{
		if (philo->monitor->must_eat_flag == 1)
		{
			// 다 먹었는지 체크에 대한 고민이 필요함
		}
	}
	// 반복해서 시간 체크 (finish flag를 세우고 finish state 출력 진행)
	// 출력 먼저 진행하고 flag 세우기
	// 그렇지 않으면 kill될 수 있음
}

int monitor_main(t_monitor *monitor)
{
	int	i;
	
	while (1)
	{
		sem_wait(monitor->finish_flag);
		if (monitor->finish_flag > 0)
		{
			i = 0;
			while (i < monitor->num_of_philo)
			{
				if (monitor->philo[i] > 0)
					kill(monitor->philo[i], SIGTERM);
				i++;
			}
			sem_post(monitor->finish_flag);
			break ;
		}
		sem_post(monitor->finish_flag);
	}
	return (0);
}