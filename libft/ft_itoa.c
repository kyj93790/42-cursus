/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:04 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 18:20:06 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	get_digit(int n, int *digit, int *cnt)
{
	*digit = 1;
	*cnt = 1;
	while (n / 10 / *digit)
	{
		*digit *= 10;
		(*cnt)++;
	}
}

char	*ft_itoa(int n)
{
	char	*pnew;
	int		digit;
	int		cnt;
	int		i;

	get_digit(n, &digit, &cnt);
	pnew = (char *)malloc(sizeof(char) * (cnt + 2));
	if (pnew == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		pnew[i++] = '-';
		pnew[i++] = -1 * (n / digit) + '0';
		n = n % digit * -1;
		digit /= 10;
	}
	while (digit > 0)
	{
		pnew[i++] = (n / digit) + '0';
		n %= digit;
		digit /= 10;
	}
	pnew[i] = '\0';
	return (pnew);
}
