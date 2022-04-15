/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:21:03 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/19 12:27:55 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnew;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start > s_len)
		len = 0;
	else if (s_len - start < len)
		len = s_len - start;
	pnew = (char *)malloc(sizeof(char) * (len + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		pnew[i] = s[start + i];
		i++;
	}
	pnew[i] = '\0';
	return (pnew);
}
