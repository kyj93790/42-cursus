#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	i;
	const char	*loc;

	i = (long long)ft_strlen(s);
	loc = s;
	while (--i)
	{
		if (*(loc + i) == c)
			break ;
	}
	if (i < 0)
		return (0);
	return (loc + i);
}
