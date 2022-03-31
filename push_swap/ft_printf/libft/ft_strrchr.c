/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:58 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/18 19:54:29 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*loc;
	const char	*result;

	loc = s;
	result = 0;
	while (*loc)
	{
		if (*loc == (char)c)
			result = loc;
		loc++;
	}
	if (result == 0)
	{
		if (c != '\0')
			return (0);
		else
			result = loc;
	}
	return ((char *)result);
}
