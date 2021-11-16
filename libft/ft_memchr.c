#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == *((const unsigned char *)s + i))
			return ((void *)((const unsigned char *)s + i));
		i++;
	}
	return (0);
}
