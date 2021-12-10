/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:59:06 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 23:30:07 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(t_ull target)
{
	t_ull	digit;
	int		cnt;

	digit = 1;
	cnt = 1;
	while ((target / 10 / digit) > 0)
	{
		digit *= 10;
		cnt++;
	}
	return (cnt);
}

static int	get_max_size(t_info op, t_ll target)
{
	int	t_len;
	int	max_size;

	t_len = ft_digit(target);
	max_size = get_max(op.width, op.precision, t_len);
	if (op.width == 0 && op.precision == 0 && target == 0)
		max_size = 0;
	return (max_size);
}

static void	fill_from_front(t_ull target, char *temp, t_info op)
{
	int		i;
	int		t_len;
	t_ull	digit;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
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

static void	fill_from_rear(t_ull target, char *temp, t_info op)
{
	int	i;
	int	t_len;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
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
	char	*temp;
	t_ull	target;
	int		max_size;
	int		t_len;
	int		i;

	target = va_arg(ap, unsigned int);
	max_size = get_max_size(op, target);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	if (!(op.precision == 0 && target == 0))
	{
		if (op.minus == 1)
			fill_from_front(target, temp, op);
		else
			fill_from_rear(target, temp, op);
	}
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
