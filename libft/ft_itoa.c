#include "libft.h"



char	*ft_itoa(int n)
{
	char	*pnew;
	int		digit;
	int		cnt;
	int		i;

	cnt = 1;
	digit = 1;
	while (n / 10 / digit)
	{
		digit *= 10;
		cnt++;
	}
	pnew = (char *)malloc(sizeof(char) * (cnt + 2));
	if (pnew == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		pnew[i++] = '-';
		
	}
	while (digit > 0)
	{
		pnew[i++] = (n / digit) + '0';
		n %= digit;
		digit /= 10;
	}
	pnew[i] = '\0';
	return (pnew);
}
