/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 23:40:30 by yejin             #+#    #+#             */
/*   Updated: 2022/05/15 23:40:35 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	wifexited(int status)
{
	return (!(status & 0x0f));
}

int	wexitstatus(int status)
{
	return (status >> 8);
}
