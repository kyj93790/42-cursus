/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lowerhex_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:44 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/09 19:25:57 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_digit(unsigned long long target)
{
	unsigned long long	digit;
	int 				cnt;

	digit = 1;
	cnt = 1;

	while (target / 16 / digit > 0)
	{
		digit *= 16;
		cnt++;
	}
	return (cnt);
}

static void	fill_from_front(unsigned long long target, char *temp, t_info op)
{
	int 				t_len;
	int					i;
	unsigned long long	digit;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
	digit = 1;
	i = 1;
	while (i++ < t_len)
		digit *= 16;
	i = 0;
	if (op.hash == 1)
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

static void	fill_from_rear(unsigned long long target, char *temp, t_info op, int max_size)
{
	int	i;
	int t_len;

	t_len = ft_digit(target);
	if (op.precision > t_len)
		t_len = op.precision;
	i = max_size;
	while (i-- && t_len--)
	{
		temp[i] = "0123456789abcdef"[target % 16];
		target /= 16;
	}
	if (op.precision < 0 && op.zero == 1)
	{
		while (i >= 0)
			temp[i--] = '0';
		i += 2;	// # flag를 처리하기 위함
	}
	if (op.hash == 1)
	{
		temp[i--] = 'x';
		temp[i] = '0';
	}
}

int	convert_lowerhex(t_result *res, t_info op, va_list ap)
{
	char					*temp;
	unsigned long long		target;
	int						max_size;
	int						t_len;
	int						i;

	target = va_arg(ap, unsigned int);
	//printf("target : %llx\n", target);
	t_len = ft_digit(target);
	printf("t_len : %d\n", t_len);
	if (op.hash == 1)
		max_size = get_max(op.width, op.precision, t_len + 2);
	else
		max_size = get_max(op.width, op.precision, t_len);
	printf("max_size : %d\n", max_size);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	if (op.minus == 1)	// 앞에서부터 채워 넣음.
		fill_from_front(target, temp, op);
	else
		fill_from_rear(target, temp, op, max_size);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
