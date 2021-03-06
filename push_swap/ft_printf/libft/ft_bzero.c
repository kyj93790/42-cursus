/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:19:05 by yejikim           #+#    #+#             */
/*   Updated: 2022/03/31 16:12:27 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*curr;
	size_t	i;

	curr = (char *)s;
	i = 0;
	while (i < n)
	{
		*curr = 0;
		i++;
		curr++;
	}
}
