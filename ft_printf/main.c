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
	ft_printf("%c",'a');
	return (0);
}