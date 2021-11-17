/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejikim <yejikim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:21:14 by yejikim           #+#    #+#             */
/*   Updated: 2021/11/17 20:16:07 by yejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
/*
char	f(unsigned int i, char c)
{
	int	a;

	a = i;
	return (c + 1);
}
*/

void	f(unsigned int i, char *c)
{
	unsigned int a;
	a = i;
	*c += 1;
}

int	main(void)
{
	//printf("origin : %s\n", strnstr("lorem ipsum dolor sit sit amet", "", 10));
	//printf("ft : %s\n", ft_strnstr("lorem ipsum dolor sit sit amet", "", 10));
	//printf("mine : %s\n", ft_strnstr("abcdefg", "ef", 6));
	
	//printf("atoi : %d\n", atoi("\n\n\n  -46\b9 \n5d6"));
	//printf("ftatoi : %d\n", ft_atoi("\n\n\n  -46\b9 \n5d6"));
	//printf("substr : %s\n", ft_substr("abcdefg", 2, 8));

	//printf("strjoin : %s\n", ft_strjoin("abcde", "fghijk"));
	
	/*
	int	i = 0;
	char s[100] = "ab dksldkf ddksl dkdkdk";
	char **result;
	result = ft_split(s, ' ');
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	*/
	/*
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2));
	printf("%s\n", ft_itoa(0));
	*/

	/*
	char const	*s = "abcdefg";
	printf("%s\n", ft_strmapi(s, f));
	*/
	
	/*
	char s[] = "abcdefg";
	ft_striteri(s, f);
	printf("%s\n", s);
	*/

	/*
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('a', fd);
	*/

	/*
	int fd;

	fd = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(2147483647, fd);

	fd = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(-2147483648, fd);

	fd = open("test3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(0, fd);
	*/

	//printf("%s\n", ft_strrchr("bonjour", 's'));
	/*	
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	*/

	/*	
	char str[] = "lorem ipsum dolor sit amet";
	//printf("%s\n",ft_substr(str, 400, 20));
	
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	//printf("%s\n", ft_strtrim(s1, " "));
	

	printf("%s\n", ft_strtrim("", "anc"));
	*/
/*	
	char **result;

	result = ft_split("          ", ' ');
	int	i = 0;
	while (result[i])
		printf("%s\n", result[i++]);
*/
	printf("%lu\n", strlcat(0, "abc", 5));
	return (0);
}
