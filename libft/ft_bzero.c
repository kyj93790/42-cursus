#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*curr;
	size_t	i;

	curr = (char *)s;
	i = 0;
	while (i < n)
	{
		*curr = 0;
		i++;
		curr++;
	}
}
