/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:59:03 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/10 22:52:16 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_string(char *target, char *temp, t_info op, int t_len)
{
	int	max_size;
	int	i;
	int	j;

	max_size = get_max(op.width, t_len, 0);
	if (op.minus == 1)
		i = 0;
	else
		i = max_size - t_len;
	j = 0;
	while (j < t_len)
	{
		temp[i + j] = target[j];
		j++;
	}
}

int	convert_string(t_result *res, t_info op, va_list ap)
{
	char	*target;
	char	*temp;
	int		t_len;
	int		max_size;
	int		i;

	target = va_arg(ap, char *);
	if (target == NULL)
		target = "(null)";
	t_len = ft_strlen(target);
	if (op.precision >= 0 && t_len > op.precision)
		t_len = op.precision;
	max_size = get_max(op.width, t_len, 0);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < max_size)
		temp[i++] = ' ';
	temp[i] = '\0';
	fill_string(target, temp, op, t_len);
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
