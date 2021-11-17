/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:18:54 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 20:51:22 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char x)
{
	if ('\t' <= x && x <= '\r')
		return (1);
	if (x == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	result;

	i = 0;
	neg = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	result = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			break ;
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	result *= neg;
	return ((int)result);
}
