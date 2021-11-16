#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	result;

	i = 0;
	neg = 1;
	if (*str == '+' || *str == '-')
	{
		i++;
		if (*str == '-')
			neg = -1;
	}
	result = 0;
	while (*(str + i))
	{
		if (*(str + i) < '0' || *(str + i) > '9')
			break ;
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	result *= neg;
	return ((int)result);
}
