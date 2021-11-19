/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:21:03 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/18 14:15:28 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnew;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	pnew = (char *)malloc(sizeof(char) * (len + 1));
	if (pnew == 0)
		return (0);
	i = start;
	while (i < s_len && (i < start + len))
	{
		pnew[i - start] = *(s + i);
		i++;
	}
	pnew[i - start] = '\0';
	return (pnew);
}
