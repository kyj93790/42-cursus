/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:37:28 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/30 17:11:16 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void free_mem()
{
	if (g_result)
		free(g_result);
	g_result = NULL;
}

int	ft_stradd(char *x)
{
	char	*pnew;
	char	o_len;
	char	x_len;

	if (x == NULL)
	{
		free_mem();
		return (-1);
	}
	o_len = ft_strlen(g_result);
	x_len = ft_strlen(x);
	pnew = (char *)malloc(sizeof(char) * (o_len + x_len + 1));
	if (pnew == NULL)
	{
		free_mem();
		return (-1);
	}
	ft_strlcpy(pnew, g_result, o_len + 1);
	ft_strlcat(pnew, x, o_len + x_len + 1);
	free_mem();
	g_result = pnew;
	return (1);
}

void	init_flag(t_info *op)
{
	op->minus = 0;
	op->plus = 0;
	op->space = 0;
	op->zero = 0;
	op->hash = 0;
	op->width = 0;
	op->precision = 0;
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
		res += res * 10 + (s[*i] - '0');
		if (res > 2147483646)
			return (-1);
		(*i)++;
	}
	return (res);
}

int	check_type(const char *s, int i, t_info op, va_list ap)
{
	int	res;

	res = 0;
	if (s[i] == 'c')
		res = convert_char(op, ap);
		/*
	else if (s[i] == 's')
		res = convert_string();
	else if (s[i] == 'p')
		res = convert_ptr();
	else if (s[i] == 'd' || s[i] == 'i')
		res = convert_int();
	else if (s[i] == 'u')
		res = convert_ui();
	else if (s[i] == 'x')
		res = convert_lowerhex();
	else if (s[i] == 'X')
		res = convert_upperhex();
	else if (s[i] == '%')
		res = convert_percent();*/
	if (res < 0)
	{
		free_mem();
		return (-1);
	}
	return (1);
}

int	ft_convert(const char *s, int *i, va_list ap)
{
	t_info	op;

	init_flag(&op);
	while (check_flag(s, *i, &op))
		(*i)++;
	op.width = calc_field(s, i);
	if (op.width < 0)
		return (-1);
	if (s[*i] == '.')	// precision 있는지 여부.
	{
		(*i)++;
		calc_field(s, i);
	}
	check_type(s, (*i)++, op, ap);
	return (1);
}

void	print_result()
{
	int	i;

	i = 0;
	while (g_result[i])
	{
		write(1, &(g_result[i]), 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;

	i = -1;
	va_start(ap, s);
	g_result = NULL;
	while (s[++i])
	{
		if (s[i] != '%')
		{
			if (ft_stradd(ft_substr(s, i, 1)) < 0)
				return (-1);
		}
		else
		{
			if (ft_convert(s, &i, ap) < 0)
				return (-1);
		}
	}
	print_result();
	free_mem();
	va_end(ap);
	return (ft_strlen(g_result));
}