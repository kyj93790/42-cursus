/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:08 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/18 19:50:20 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*curr;

	i = 0;
	curr = (const unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == *(curr + i))
			return ((void *)(curr + i));
		i++;
	}
	return (0);
}
