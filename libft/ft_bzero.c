/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:19:05 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/17 19:48:45 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*curr;
	size_t	i;

	if (s == 0)
		return ;
	curr = (char *)s;
	i = 0;
	while (i < n)
	{
		*curr = 0;
		i++;
		curr++;
	}
}
