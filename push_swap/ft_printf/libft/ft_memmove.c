/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:11:11 by yejin             #+#    #+#             */
/*   Updated: 2021/11/19 09:23:20 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (d <= s)
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i--)
			d[i] = s[i];
	}
	return (dst);
}
