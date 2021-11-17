/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:54 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 21:15:02 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	i = 0;
	while (i + 1 < n && *(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	c1 = *(s1 + i);
	c2 = *(s2 + i);
	return (c1 - c2);
}
