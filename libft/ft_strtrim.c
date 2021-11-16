#include "libft.h"

int static	is_inset(char x, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == x)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pnew;
	size_t	s1_len;
	size_t	i;
	size_t	index;

	s1_len = ft_strlen(s1);
	pnew = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (pnew == 0)
		return (0);
	i = 0;
	index = 0;
	while (i < s1_len)
	{
		if (!is_inset(*(s1 + i), set))
			*(pnew + index++) = *(s1 + i);
		i++;
	}
	*(pnew + index) = '\0';
	return (pnew);
}
