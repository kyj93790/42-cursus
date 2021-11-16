#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnew;
	size_t	i;

	pnew = (char *)malloc(sizeof(char) * (len + 1));
	if (pnew == 0)
		return (0);
	i = start;
	while (i < start + len && *(s + i))
	{
		pnew[i - start] = *(s + i);
		i++;
	}
	pnew[i - start] = '\0';
	return (pnew);
}
