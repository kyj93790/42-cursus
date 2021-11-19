/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:57 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/18 14:22:41 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_size;
	int		i;

	if (*needle == '\0')
		return ((char *)haystack);
	n_size = ft_strlen(needle);
	i = 0;
	while (n_size + i <= len)
	{
		if (*(haystack + i) == *(needle) && \
				!ft_strncmp(haystack + i, needle, n_size))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
