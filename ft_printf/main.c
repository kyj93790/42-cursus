#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
/*
int temp(va_list ap)
{
	int		arg;
	int		sum;

	sum = 0;
	for(;;)
	{
		arg = va_arg(ap, int);
		if (arg == 0)
			break ;
		sum += arg;
	}
	return (sum);
}

int	test(const char *s, ...)
{
	int		sum;
	int		arg;
	va_list	ap;

	va_start(ap, s);
	sum = temp(ap);
	va_end(ap);
	return (sum);
}
*/
int main(void)
{
	printf("%08.3d", -99);
	//ft_printf("%s\n", 0);
	// printf("%d\n", printf("abcd%10.0s0000%10.0s\n", "Hello ", "Korld!"));
	// printf("%d\n", ft_printf("abcd%10.0s0000%10.0s\n", "Hello ", "Korld!"));
	// printf("\n");
	// printf("%d\n", printf("1234%-4.3s1234\n", "abcdef"));
	// printf("%d\n", ft_printf("1234%-4.3s1234\n", "abcdef"));
	return (0);
}