/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:17 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 18:20:21 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*curr;
	size_t			i;

	curr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*curr = (unsigned char)c;
		i++;
		curr++;
	}
	return (b);
}
