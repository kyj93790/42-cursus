/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:57:15 by yejikim           #+#    #+#             */
/*   Updated: 2022/06/06 10:49:23 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(char *message)
{
	printf("%s\n", message);
	return (-1);
}

void	finish_with_error(char *message, t_monitor *monitor)
{
	sem_wait(monitor->sem_print);
	printf("%s\n", message);
	sem_post(monitor->sem_finish);
}
