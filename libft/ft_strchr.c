#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*loc;

	loc = s;
	while (*loc)
	{
		if (loc == c)
			break ;
		loc++;
	}
	if (*loc == '\0')
		return (0);
	return (loc);
}
