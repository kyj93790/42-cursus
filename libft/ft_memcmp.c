/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:10 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 21:05:43 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i + 1 < n && *(c1 + i) && *(c2 + i))
	{
		if (*(c1 + i) != *(c2 + i))
			break ;
		i++;
	}
	return (*(c1 + i) - *(c2 + i));
}
