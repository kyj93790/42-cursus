/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:59:06 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 16:01:36 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_digit(unsigned long long target)
{
	unsigned long long	digit;
	int			 		cnt;

	digit = 1;
	cnt = 1;
	while ((target / 10 / digit) > 0)
	{
		digit *= 10;
		cnt++;
	}
	return (cnt);
}

static void fill_from_front(unsigned long long target, char *temp, t_info op, int t_len)
{
	int					i;
	unsigned long long	digit;

	if (op.precision == 0 && target == 0)
		return ;
	i = 1;
	digit = 1;
	while (i++ < t_len)
		digit *= 10;
	i = 0;
	while (digit > 0)
	{
		temp[i++] = (target / digit) + '0';
		target %= digit;
		digit /= 10;
	}
}

static void	fill_from_rear(unsigned long long target, char *temp, t_info op, int t_len)
{
	int	i;

	if (op.precision == 0 && target == 0)
		return ;
	i = get_max(op.width, op.precision, t_len);
	while (i-- && t_len--)
	{
		temp[i] = (target % 10) + '0';
		target /= 10;
	}
	if (op.precision < 0 && op.zero == 1)
	{
		while (i >= 0)
			temp[i--] = '0';
	}
}

int	convert_uint(t_result *res, t_info op, va_list ap)
{
	char				*temp;
	unsigned long long	target;
	int					max_size;
	int					t_len;	// 알맹이의 길이
	int					i;

	target = va_arg(ap, unsigned int);
	t_len = ft_digit(target);
	max_size = get_max(op.width, op.precision, t_len);
	if (op.width == 0 && op.precision == 0 && target == 0)
		max_size = 0;
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	if (op.precision > t_len)
		t_len = op.precision;
	if (op.minus == 1)	// 앞에서부터 채워 넣음.
		fill_from_front(target, temp, op, t_len);
	else
		fill_from_rear(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
