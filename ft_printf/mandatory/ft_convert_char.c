/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:31 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 23:29:37 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_char(t_result *res, t_info op, va_list ap)
{
	char	target;
	char	*temp;
	int		i;
	int		max_size;

	target = va_arg(ap, unsigned int);
	max_size = get_max(op.width, 1, 0);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	if (op.minus == 1)
		temp[0] = target;
	else
		temp[max_size - 1] = target;
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
