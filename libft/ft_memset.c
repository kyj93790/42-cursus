#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*curr;
	size_t			i;

	curr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*curr = (unsigned char)c;
		i++;
		curr++;
	}
	return (b);
}
