#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pnew;
	int		i;

	pnew = (char *)malloc(size * count);
	if (pnew == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		*(pnew + i) = 0;
		i++;
	}
	return ((void *)pnew);
}
