/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:35:55 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/09 14:40:32 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

typedef struct s_result {
	char	*result;
	int		cnt;
}	t_result;

typedef struct s_info {
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int width;
	int precision;
}	t_info;

int		ft_printf(const char * s, ...);
void	init_flag(t_info *op);
size_t	ft_strlen(const char *s);
int		get_max(int a, int b, int c);
int		ft_stradd(t_result *res, char *x, int len);
int		check_flag(const char *s, int i, t_info *op);
int 	calc_field(const char *s, int *i);
int		check_type(t_result *res, char type, t_info op, va_list ap);
int		ft_convert(t_result *res, const char *s, int *i, va_list ap);
int		convert_char(t_result *res, t_info op, va_list ap);
int		convert_string(t_result *res, t_info op, va_list ap);
int		convert_ptr(t_result *res, t_info op, va_list ap);
int		convert_int(t_result *res, t_info op, va_list ap);
int		convert_uint(t_result *res, t_info op, va_list ap);
int		convert_lowerhex(t_result *res, t_info op, va_list ap);
int		convert_upperhex(t_result *res, t_info op, va_list ap);
int		convert_percent(t_result *res, t_info op);
void	print_result(t_result *res);
void 	free_mem(t_result *res);

#endif