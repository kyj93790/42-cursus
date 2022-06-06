/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:11 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:41:50 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_process(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->num_of_philo)
	{
		if (monitor->philo[i].pid > 0)
			kill(monitor->philo[i].pid, SIGTERM);
		else
			break ;
		i++;
	}
	free(monitor->philo);
}

void	free_monitor(void)
{
	sem_unlink("sem_start");
	sem_unlink("sem_finish");
	sem_unlink("sem_print");
	sem_unlink("sem_fork");
	sem_unlink("sem_full");
}