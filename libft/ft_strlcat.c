/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:43 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 18:20:44 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	dst_l;
	size_t	src_l;

	dst_l = ft_strlen((const char *)dst);
	src_l = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dst_l)
		return (src_l + dstsize);
	dst_i = dst_l;
	src_i = 0;
	while (dst_i + 1 < dstsize && *(src + src_i))
	{
		*(dst + dst_i) = *(src + src_i);
		src_i++;
		dst_i++;
	}
	*(dst + dst_i) = '\0';
	return (dst_l + src_l);
}
