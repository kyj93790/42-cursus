/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:47 by yejikim           #+#    #+#             */
/*   Updated: 2022/04/15 18:08:42 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull	ft_strlen(const char *s)
{
	t_ull	i;

	if (s == 0)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
