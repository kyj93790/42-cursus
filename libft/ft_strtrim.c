/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:21:00 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/19 11:49:44 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char x, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == x)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_front(char const *s1, char const *set)
{
	long long	i;

	i = 0;
	while (s1[i] && is_inset(s1[i], set))
		i++;
	return (i);
}

static size_t	get_rear(char const *s1, char const *set)
{
	long long	i;

	i = ft_strlen(s1);
	i--;
	while (i >= 0 && is_inset(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*pnew;
	size_t		s1_len;
	long long	f;
	long long	r;
	size_t		index;

	s1_len = ft_strlen(s1);
	f = get_front(s1, set);
	r = get_rear(s1, set);
	if (f > r)
		pnew = (char *)malloc(sizeof(char));
	else
		pnew = ft_substr(s1, f, r - f + 1);
	if (pnew == 0)
		return (0);
	index = 0;
	while (f <= r)
	{
		pnew[index++] = *(s1 + f);
		f++;
	}
	pnew[index] = '\0';
	return (pnew);
}
