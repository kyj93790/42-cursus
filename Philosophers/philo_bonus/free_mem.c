/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:11 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/05 19:45:30 by yejin            ###   ########.fr       */
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
		i++;
	}
	free(monitor->philo);
}
