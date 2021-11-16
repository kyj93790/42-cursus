#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnew;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	pnew = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	while (*(s1 + i))
	{
		*(pnew + i) = *(s1 + i);
		i++;
	}
	i = 0;
	while (*(s2 + i))
	{
		*(pnew + s1_len + i) = *(s2 + i);
		i++;
	}
	*(pnew + s1_len + i) = '\0';
	return (pnew);
}
