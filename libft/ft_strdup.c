#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*pnew;

	len = ft_strlen(s1);
	pnew = (char *)malloc(sizeof(char) * (len + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	while (i <= len)
	{
		*(pnew + i) = *(s1 + i);
		i++;
	}
	return (pnew);
}
