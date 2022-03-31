/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:37:28 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 23:44:41 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_mem(t_result *res)
{
	if (res->result)
		free(res->result);
	res->result = NULL;
	res->cnt = 0;
}

int	get_max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= c)
		return (b);
	else
		return (c);
}

void	init_flag(t_info *op)
{
	op->minus = 0;
	op->plus = 0;
	op->space = 0;
	op->zero = 0;
	op->hash = 0;
	op->width = -1;
	op->precision = -1;
}

int	check_flag(const char *s, int i, t_info *op)
{
	if (s[i] == '-')
		op->minus = 1;
	else if (s[i] == '+')
		op->plus = 1;
	else if (s[i] == ' ')
		op->space = 1;
	else if (s[i] == '0')
		op->zero = 1;
	else if (s[i] == '#')
		op->hash = 1;
	else
		return (0);
	return (1);
}

int	calc_field(const char *s, int *i)
{
	long long	res;

	res = 0;
	while ('0' <= s[*i] && s[*i] <= '9')
	{
		res = res * 10 + (s[*i] - '0');
		if (res > 2147483646)
			return (-1);
		(*i)++;
	}
	return (res);
}
