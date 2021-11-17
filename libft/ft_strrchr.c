/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:58 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 20:16:02 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	i;
	const char	*loc;

	i = (long long)ft_strlen(s);
	loc = s;
	while (i >= 0)
	{
		if (*(loc + i) == c)
			break ;
		i--;
	}
	if (i < 0)
		return (0);
	return ((char *)(loc + i));
}
