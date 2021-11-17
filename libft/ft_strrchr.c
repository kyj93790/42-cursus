/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:58 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/17 21:42:45 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*loc;
	const char	*result;

	if (s == 0)
		return (0);
	loc = s;
	result = 0;
	while (*loc)
	{
		if (*loc == (char)c)
			result = loc;
		loc++;
	}
	if (result == 0 && c != '\0')
		return (0);
	return ((char *)result);
}
