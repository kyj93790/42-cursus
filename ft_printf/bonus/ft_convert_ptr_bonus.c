/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:57 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 23:01:40 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

static void	fill_ptr(t_ull target, char *temp, t_info op, int t_len)
{
	int		max_size;
	int		i;
	int		j;
	t_ull	digit;

	max_size = get_max(op.width, 0, t_len);
	if (op.minus == 1)
		i = 0;
	else
		i = max_size - t_len;
	digit = 1;
	while (target / 16 / digit > 0)
		digit *= 16;
	j = 0;
	temp[i + j++] = '0';
	temp[i + j++] = 'x';
	while (j < t_len)
	{
		temp[i + j] = "0123456789abcdef"[target / digit];
		target %= digit;
		digit /= 16;
		j++;
	}
}

int	convert_ptr(t_result *res, t_info op, va_list ap)
{
	char	*temp;
	t_ull	target;
	int		max_size;
	int		t_len;
	int		i;

	target = va_arg(ap, t_ull);
	t_len = ft_digit(target) + 2;
	max_size = get_max(op.width, 0, t_len);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	fill_ptr(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
