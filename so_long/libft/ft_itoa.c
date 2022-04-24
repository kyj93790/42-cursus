/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejin <yejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:04 by yejikim           #+#    #+#             */
/*   Updated: 2022/04/24 16:28:55 by yejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_digit(t_ull n, t_ull *digit, t_ull *cnt)
{
	*digit = 1;
	*cnt = 1;
	while (n / 10 / *digit)
	{
		*digit *= 10;
		(*cnt)++;
	}
}

char	*ft_itoa(t_ull n)
{
	char	*pnew;
	t_ull	digit;
	t_ull	cnt;
	t_ull	i;

	get_digit(n, &digit, &cnt);
	pnew = (char *)malloc(sizeof(char) * (cnt + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	while (digit > 0)
	{
		pnew[i++] = (n / digit) + '0';
		n %= digit;
		digit /= 10;
	}
	pnew[i] = '\0';
	return (pnew);
}
