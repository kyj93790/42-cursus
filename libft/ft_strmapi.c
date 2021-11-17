/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:50 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 18:20:51 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pnew;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	pnew = (char *)malloc(sizeof(char) * (s_len + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	while (*(s + i))
	{
		pnew[i] = f(i, s[i]);
		i++;
	}
	pnew[i] = '\0';
	return (pnew);
}
