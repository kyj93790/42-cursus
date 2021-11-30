/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:35:55 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/30 15:56:35 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

char	*g_result;

typedef struct s_info {
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int width;
	int precision;
} t_info;

int		ft_printf(const char * s, ...);
void	init_flag(t_info *op);
int		get_max(int a, int b, int c);
int		ft_stradd(char *x);
int		check_flag(const char *s, int i, t_info *op);
int 	calc_field(const char *s, int *i);
int		check_type(const char *s, int i, t_info op, va_list ap);
int		ft_convert(const char *s, int *i, va_list ap);
int		convert_char(t_info op, va_list ap);
void	print_result(void);
void 	free_mem(void);

#endif