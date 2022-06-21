/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:58:53 by yejikim           #+#    #+#             */
/*   Updated: 2021/12/09 17:16:33 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	convert_percent(t_result *res, t_info op)
{
	char	*temp;
	int		max_size;
	int		i;
	char	x;

	max_size = get_max(op.width, 0, 1);
	temp = (char *)malloc(sizeof(char) * (max_size + 1));
	if (temp == NULL)
		return (-1);
	if (op.zero == 1 && op.minus == 0)
		x = '0';
	else
		x = ' ';
	i = 0;
	while (i < max_size)
		temp[i++] = x;
	temp[i] = '\0';
	if (op.minus == 1)
		temp[0] = '%';
	else
		temp[max_size - 1] = '%';
	if (ft_stradd(res, temp, max_size) < 0)
		return (-1);
	return (1);
}
