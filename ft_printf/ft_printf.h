/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:35:55 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/29 20:11:33 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_info {
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int width;
	int precision;
} t_info;

int	ft_printf(const char * s, ...);

#endif