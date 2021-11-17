/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:20:25 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/16 18:20:27 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	print_neg(int *n, int fd, int *digit)
{
	char	x;

	write(fd, "-", 1);
	x = *n / *digit * -1 + '0';
	write(fd, &x, 1);
	*n = *n % *digit * -1;
	*digit /= 10;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	char	x;

	digit = 1;
	while (n / 10 / digit)
		digit *= 10;
	if (n < 0)
		print_neg(&n, fd, &digit);
	while (digit > 0)
	{
		x = n / digit + '0';
		write(fd, &x, 1);
		n %= digit;
		digit /= 10;
	}
}
