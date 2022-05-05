/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:19:10 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/19 13:47:46 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pnew;
	size_t	i;

	pnew = (char *)malloc(size * count);
	if (pnew == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		*(pnew + i) = 0;
		i++;
	}
	return ((void *)pnew);
}
