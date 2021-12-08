/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:37:28 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/08 14:38:46 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void free_mem(t_result *res)
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

int	ft_stradd(t_result *res, char *x, int len)
{
	char	*pnew;

	if (x == NULL)
	{
		free_mem(res);
		return (-1);
	}
	pnew = (char *)malloc(sizeof(char) * (res->cnt + len + 1));
	if (pnew == NULL)
	{
		free_mem(res);
		return (-1);
	}
	ft_memcpy(pnew, res->result, res->cnt);
	ft_memcpy(pnew + res->cnt, x, len + 1);
	if (res->result)	// x에 대한 메모리 해제도 고려. (null)인 경우는 해제 x
		free(res->result);
	if (x)
		free(x);
	res->result = pnew;
	res->cnt += len;
	return (1);
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

int calc_field(const char *s, int *i)
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

int	check_type(t_result *res, char type, t_info op, va_list ap)
{
	int	rt;

	rt = 0;
	if (type == 'c')
		rt = convert_char(res, op, ap);
	else if (type == 's')
		rt = convert_string(res, op, ap);
	else if (type == 'p')
	 	rt = convert_ptr(res, op, ap);
	else if (type == 'd' || type == 'i')
		rt = convert_int(res, op, ap);
	else if (type == 'u')
		rt = convert_uint(res, op, ap); 
	else if (type == 'x')
		rt = convert_lowerhex(res, op, ap);
	else if (type == 'X')
		rt = convert_upperhex(res, op, ap);/*
	else if (type == '%')
		rt = convert_percent(res, op, ap);*/
	if (rt < 0)
	{
		free_mem(res);
		return (-1);
	}
	return (1);
}

int	ft_convert(t_result *res, const char *s, int *i, va_list ap)
{
	t_info	op;

	init_flag(&op);
	while (check_flag(s, ++(*i), &op))
		;
	op.width = calc_field(s, i);
	if (op.width < 0)
		return (-1);
	if (s[*i] == '.')	// precision 있는지 여부.
	{
		(*i)++;
		op.precision = calc_field(s, i);
		if (op.precision < 0)
			return (-1);
	}
	check_type(res, s[(*i)], op, ap);
	return (1);
}

void	print_result(t_result *res)
{
	int	i;

	i = 0;
	write(1, res->result, res->cnt);
}

int	ft_printf(const char *s, ...)
{
	t_result res;
	int		i;
	int		cnt;
	va_list	ap;

	i = -1;
	va_start(ap, s);
	res.result = NULL;
	res.cnt = 0;
	while (s[++i])
	{
		if (s[i] != '%')
		{
			if (ft_stradd(&res, ft_substr(s, i, 1), 1) < 0)
				return (-1);
		}
		else
		{
			if (ft_convert(&res, s, &i, ap) < 0)
				return (-1);
		}
	}
	print_result(&res);
	cnt = res.cnt;
	free_mem(&res);
	va_end(ap);
	return (cnt);
}