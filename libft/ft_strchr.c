/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:32 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 19:15:41 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*loc;

	if (s == 0)
		return (0);
	loc = s;
	while (*loc)
	{
		if (*loc == c)
			break ;
		loc++;
	}
	if (c != '\0' && *loc == '\0')
		return (0);
	return ((char *)loc);
}
