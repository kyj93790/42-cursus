#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	i = 0;
	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	while (i < n - 1 && *(c1 + i) && *(c2 + i))
	{
		if (*(c1 + i) != *(c2 + i))
			break ;
		i++;
	}
	return (*(c1 + i) - *(c2 + i));
}
