/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:57 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 21:03:38 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_same(const char *curr, const char *needle)
{
	int	i;

	i = 0;
	while (*(needle + i))
	{
		if (*(curr + i) != *(needle + i))
			return (0);
		i++;
	}
	return (1);
}

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
		if (*(haystack + i) == *(needle) && is_same(haystack + i, needle))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
