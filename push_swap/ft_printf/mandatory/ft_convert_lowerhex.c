/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lowerhex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:44 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 23:41:13 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(t_ull target)
{
	t_ull	digit;
	int		cnt;

	digit = 1;
	cnt = 1;
	while (target / 16 / digit > 0)
	{
		digit *= 16;
		cnt++;
	}
	return (cnt);
}

static int	get_max_size(t_info op, t_ll target)
{
	int	t_len;
	int	max_size;

	t_len = ft_digit(target);
	if (op.hash == 1 && target != 0)
		max_size = get_max(op.width, op.precision, t_len + 2);
	else
		max_size = get_max(op.width, op.precision, t_len);
	if (op.width == 0 && op.precision == 0 && target == 0)
		max_size = 0;
	return (max_size);
}

static void	fill_from_front(t_ull target, char *temp, t_info op)
{
	int		t_len;
	int		i;
	t_ull	digit;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
	digit = 1;
	i = 1;
	while (i++ < t_len)
		digit *= 16;
	i = 0;
	if (op.hash == 1 && target != 0)
	{
		temp[i++] = '0';
		temp[i++] = 'x';
		t_len += 2;
	}
	while (i < t_len)
	{
		temp[i++] = "0123456789abcdef"[target / digit];
		target %= digit;
		digit /= 16;
	}
}

static void	fill_from_rear(t_ull target, char *temp, t_info op, int max_size)
{
	int		i;
	int		t_len;
	t_ull	x;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
	i = max_size;
	x = target;
	while (i-- && t_len--)
	{
		temp[i] = "0123456789abcdef"[x % 16];
		x /= 16;
	}
	if (op.precision < 0 && op.zero == 1)
	{
		while (i >= 0)
			temp[i--] = '0';
		i += 2;
	}
	if (op.hash == 1 && target != 0)
	{
		temp[i--] = 'x';
		temp[i] = '0';
	}
}

int	convert_lowerhex(t_result *res, t_info op, va_list ap)
{
	char	*temp;
	t_ull	target;
	int		max_size;
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
			fill_from_rear(target, temp, op, max_size);
	}
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
