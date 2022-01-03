/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:38 by yejikim           #+#    #+#             */
/*   Updated: 2022/01/03 14:46:07 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(t_ll target)
{
	t_ll	digit;
	int		cnt;

	digit = 1;
	cnt = 1;
	if (target < 0)
		target *= -1;
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

	if (op.width == 0 && op.precision == 0 && target == 0)
		return (0);
	t_len = ft_digit(target);
	if (target < 0 || op.plus == 1)
		max_size = get_max(op.width, op.precision + 1, t_len + 1);
	else
		max_size = get_max(op.width, op.precision, t_len);
	if (op.space == 1 && op.width <= t_len && target >= 0)
		max_size++;
	return (max_size);
}

static void	fill_from_front(t_ll target, char *temp, t_info op, int t_len)
{
	int		i;
	t_ll	digit;

	i = 1;
	digit = 1;
	while (i++ < t_len)
		digit *= 10;
	i = 0;
	if (target < 0)
	{
		temp[i++] = '-';
		target *= -1;
	}
	else if (op.plus == 1)
		temp[i++] = '+';
	else if (op.space == 1)
		i++;
	while (digit > 0)
	{
		temp[i++] = (target / digit) + '0';
		target %= digit;
		digit /= 10;
	}
}

static void	fill_from_rear(t_ll target, char *temp, t_info op, int t_len)
{
	int		i;
	t_ll	x;

	i = get_max_size(op, target);
	x = target;
	if (x < 0)
		x *= -1;
	while (i-- && t_len--)
	{
		temp[i] = (x % 10) + '0';
		x /= 10;
	}
	if (op.precision < 0 && op.zero == 1)
	{
		while (i >= 0)
			temp[i--] = '0';
		i++;
	}
	if (target < 0)
		temp[i] = '-';
	else if (op.plus == 1)
		temp[i] = '+';
	else if (op.space == 1)
		temp[i] = ' ';
}

int	convert_int(t_result *res, t_info op, va_list ap)
{
	char	*temp;
	t_ll	target;
	int		max_size;
	int		t_len;

	target = va_arg(ap, int);
	max_size = get_max_size(op, target);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	ft_memset(temp, ' ', max_size);
	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
	if (!(op.precision == 0 && target == 0))
	{
		if (op.minus == 1)
			fill_from_front(target, temp, op, t_len);
		else
			fill_from_rear(target, temp, op, t_len);
	}
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
