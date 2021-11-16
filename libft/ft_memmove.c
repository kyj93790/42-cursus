#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src == 0 || dst == 0)
		return (0);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else
	{
		i = num - 1;
		while (i--)
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
	}
	return (dst);
}
