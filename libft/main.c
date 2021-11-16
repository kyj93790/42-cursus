#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	//printf("origin : %s\n", strnstr("abcdefg", "ef", 6));
	//printf("mine : %s\n", ft_strnstr("abcdefg", "ef", 6));
	
	//printf("atoi : %d\n", atoi("+0"));
	//printf("mine : %d\n", ft_atoi("+0"));

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

	printf("%d\n", ft_itoa(2147483648));
	return (0);
}
